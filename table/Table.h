#ifndef Table_H
#define Table_H

#include "../myUtil/myUtil.h"
#include "../website/Website.h"

/**
 * The Node of the table.
 */
struct Node {
  Node(const Website& data) {
    this->data = new Website(data);
    this->next = nullptr;
  }

  ~Node() {
    if (this->data) {
      delete this->data;
    }
  }

  Website* data;
  Node* next;
};


/**
 * This class represents a table of websites' information.
 */
class Table {
  private:
    /**
     * A dynamic array contains websites' information.
     */
    Node** aTable;

    /**
     * The size of the table.
     */
    int size;

    /**
     * The capacity of the table.
     */
    int capacity;

  public:
    /**
     * Default constructor.
     */
    Table();

    /**
     * Destructor.
     */
    ~Table();

    /**
     * Insert a new website by topic.
     *
     * @param website The website to add.
     * @return        void
     */
    void insert(const Website& website);

    /**
     * Retrieve all websites based on a topic keyword.
     *
     * @param       topicKeyword  The topic keyword to search for.
     * @param[out]  results       The array of websites that match the topic
     *                            keyword.
     * @param[out]  totalResults  The total number of websites that match the
     *                            topic keyword.
     * @return                    True if there is a match, false otherwise.
     */
    bool retrieve(const char* topicKeyword, Website results[],
                  int& totalResults) const;

    /**
     * Modify the review and rating for a particular topic and website match.
     * @param topicKeyword  The topic keyword to search for.
     * @param address       The address of the website.
     * @param review        The review to modify.
     * @param rating        The rating to modify.
     * @return              void
     */
    void edit(const char* topicKeyword, const char* address,
                const char* review, unsigned short int rating);

    /**
     * Remove all websites with a 1 star rating.
     * @return The removed websites.
     */
    const Website* removeOneStar();

    /**
     * Display website matches based on the topic keyword.
     *
     * @param topicKeyword  The topic keyword to search for.
     * @param out           The output stream.
     * @return              void
     */
    void display(const char* topicKeyword, ostream& out) const;

    /**
     * Display all websites in the table.
     * @param out       The output stream.
     * @return          void
     */
    void displayAll(ostream& out) const;

    /**
     * Display each chain's length.
     *
     * @param out The output stream.
     * @return    void
     */
    void displayChainLength(ostream& out) const;

    /**
     * Loads data from a file into the table.
     *
     * @param fileName  The name of the file to load data from.
     * @return          The number of records loaded, returns ERROR in case
     *                  the data can not be loaded.
     */
    int loadData(const char* fileName);

    /**
     * Writes data from the table to a file.
     *
     * @param fileName  The name of the file to write data to.
     * @return          Whether the data is written successfully.
     */
    bool writeData(const char* fileName) const;

  private:
    /**
     * Initialize the table's data.
     */
    void init();

    /**
     * Calculates a hash value for the given string.
     *
     * @param key The string to calculate the hash for.
     * @return    The computed hash value.
     */
    int hash(const char* key) const;

    /**
     * Destroys the table.
     *
     * @return void
     */
    void destroy();

    /**
     * Destroy the elements of one chain of the table.
     *
     * @return void
     */
    void destroyChain(Node*& head);
};

#endif

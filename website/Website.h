//
// Created by Tony Le on 2/11/24.
//

#ifndef MY_PROJECT_WEBSITE_H
#define MY_PROJECT_WEBSITE_H


class Website {
  public:
    /**
     * Constructor with parameters
     */
    Website(const char* topic, const char* address, const char* summary,
            const char* review, unsigned short int rating);

  private:
    /**
     * Topic name (e.g., “Data Structures”)
     */
    char* topic;

    /**
     * URL of the website
     */
    char* address;

    /**
     * Summary of the website
     */
    char* summary;

    /**
     * Review about the website
     */
    char* review;

    /**
     * Rating of the website (1-5 stars – 1 being not very useful, 5 being
     * very useful)
     */
    unsigned short int rating;
};


#endif //MY_PROJECT_WEBSITE_H

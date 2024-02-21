#include "Table.h"

// Default constructor.
Table::Table() {
  this->init();
}

// Destructor.
Table::~Table() {
  this->destroy();
}

// Insert a new website by topic.
void Table::insert(const Website& website) {
  int index = this->hash(website.getTopic());

  if (this->aTable[index]) {
    Node* temp = this->aTable[index];

    while (temp->next) {
      temp = temp->next;
    }

    temp->next = new Node(website);
  } else {
    this->aTable[index] = new Node(website);
  }

  this->size++;
}

// Retrieve all websites based on a topic keyword.
bool Table::retrieve(const char* topicKeyword, Website* results[],
                     int& totalResults) const {
  int index = this->hash(topicKeyword);

  if (this->aTable[index]) {
    Node* temp = this->aTable[index];
    totalResults = 0;

    while (temp) {
      if (strstr(temp->data->getTopic(), topicKeyword) != nullptr) {
        results[totalResults] = temp->data;
        totalResults++;
      }

      temp = temp->next;
    }

    return true;
  }

  return false;
}

// Modify the review and rating for a particular topic and website match.
void Table::edit(const char* topicKeyword, const char* review,
                 unsigned short int rating) {
  int index = this->hash(topicKeyword);

  if (this->aTable[index]) {
    Node* temp = this->aTable[index];
    bool isFound = false;

    while (temp && !isFound) {
      if (strstr(temp->data->getTopic(), topicKeyword) != nullptr) {
        temp->data->setReview(review);
        temp->data->setRating(rating);
      }

      temp = temp->next;
    }
  }
}

// Remove all websites with a 1 star rating.
void Table::removeOneStar() {
  for (int i = 0; i < this->capacity; i++) {
    Node* temp = this->aTable[i];
    Node* prev = nullptr;

    while (temp) {
      if (temp->data->getRating() == 1) {
        this->removeNode(temp, prev);
      }

      prev = temp;
      temp = temp->next;
    }
  }
}

// Display website matches based on the topic keyword.
void Table::display(const char* topicKeyword, ostream& out) const {
  int index = this->hash(topicKeyword);

  if (this->aTable[index]) {
    Node* temp = this->aTable[index];

    while (temp) {
      if (strstr(temp->data->getTopic(), topicKeyword) != nullptr) {
        temp->data->printInformation(out);
        out << endl;
      }

      temp = temp->next;
    }
  }
}

// Display all websites in the table.
void Table::displayAll(ostream& out) const {
  for (int i = 0; i < this->capacity; i++) {
    Node* temp = this->aTable[i];

    while (temp) {
      temp->data->printInformation(out);
      out << endl;
      temp = temp->next;
    }
  }
}

// Display each chain's length.
void Table::displayChainLength(ostream& out) const {
  for (int i = 0; i < this->capacity; i++) {
    Node* temp = this->aTable[i];
    int count = 0;

    while (temp) {
      count++;
      temp = temp->next;
    }

    out << "Chain " << i << " has " << count << " elements." << endl;
  }
}

// Loads data from a file into the table.
int Table::loadData(const char* fileName) {
  ifstream inFile;
  inFile.open(fileName);

  if (!inFile) {
    return ERROR;
  }

  char topic[STR_SIZE];
  char address[STR_SIZE];
  char summary[STR_SIZE];
  char review[STR_SIZE];
  unsigned short int rating;

  inFile.ignore(numeric_limits<streamsize>::max(), '\n');
  inFile.getline(topic, STR_SIZE, ';');

  while (!inFile.eof()) {
    inFile.getline(address, STR_SIZE, ';');
    inFile.getline(summary, STR_SIZE, ';');
    inFile.getline(review, STR_SIZE, ';');

    inFile >> rating;
    inFile.ignore(numeric_limits<streamsize>::max(), '\n');

    this->insert(Website(topic, address, summary, review, rating));

    inFile.getline(topic, STR_SIZE, ';');
  }

  inFile.close();

  return this->size;
}

// Writes data from the table to a file.
bool Table::writeData(const char* fileName) const {
  ofstream outFile;
  outFile.open(fileName);

  if (!outFile) {
    return false;
  }

  outFile << "Topic name; Website address; Summary; Review; Rating" << endl;

  for (int i = 0; i < this->capacity; i++) {
    Node* temp = this->aTable[i];

    while (temp) {
      temp->data->printInformation(outFile);
      temp = temp->next;
    }
  }

  outFile.close();

  return true;
}

// Destroys the table.
void Table::destroy() {
  for (int i = 0; i < this->capacity; i++) {
    if (this->aTable[i]) {
      destroyChain(this->aTable[i]);
    }
  }

  delete[] this->aTable;
}

// Destroy the elements of one chain of the table.
void Table::destroyChain(Node*& head) {
  if (head) {
    this->destroyChain(head->next);
    delete head;
  }
}

// Calculates a hash value for the given string.
int Table::hash(const char* key) const {
  int val = 0;
  const char* temp = key;
  int i = 1;

  while (*temp != '\0') {
    val += *temp * i;
    i++;
    temp++;
  }

  return val % capacity;
}

// Initialize the table's data.
void Table::init() {
  this->size = 0;
  this->capacity = INIT_CAP;
  this->aTable = new Node*[this->capacity];

  for (int i = 0; i < this->capacity; i++) {
    this->aTable[i] = nullptr;
  }
}

// Removes a node from the chain.
void Table::removeNode(Node*& curNode, Node*& prevNode) {
  Node* temp = curNode;

  if (prevNode) {
    prevNode->next = curNode->next;
  } else {
    curNode = curNode->next;
  }

  delete temp;
}

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
bool Table::writeData(const char* fileName) const {}

// Initialize the table's data.
void Table::init() {
  this->size = 0;
  this->capacity = INIT_CAP;
  this->aTable = new Node*[this->capacity];

  for (int i = 0; i < this->capacity; i++) {
    this->aTable[i] = nullptr;
  }
}

// Calculates a hash value for the given string.
int Table::hash(const char* key) const {}

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

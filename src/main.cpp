/*****************************************************************************
# Author:           Tony Le
# Project:          Project 3
# Date:             Feb 11, 2024
# Description:      This program will help you save favorite websites using
#                   a hash table.
# Sources:          Project 3 specifications
#****************************************************************************/

#include "main.h"

int main() {
  Table hashTable;
  int option = -1;

  int loadResult = hashTable.loadData(DATA_FILE);

  welcome();

  if (loadResult != ERROR) {
    cout << loadResult << " websites were loaded." << endl;

    do {
      displayMenu();

      getNumber("", "Please choose the option from 1 to 8!", 1, 8, option);

      exeOption(option, hashTable);
    } while (option != 8);

    goodbye();
  }
}

// This function prints a welcome message.
void welcome() {
  cout << "Welcome to Favorite Websites program!" << endl;
  cout << "This program will help you keeping track of your favorite websites.";
  cout << endl << endl;
}

// This function prints a goodbye message.
void goodbye() {
  cout << endl;
  cout << "Thank you for using the program!!";
}

// This function displays the menu to the user.
void displayMenu() {
  cout << "Pick an option from below: " << endl << endl;
  cout << "1. Insert a new website" << endl;
  cout << "2. Retrieve all websites based on the topic keyword" << endl;
  cout << "3. Modify the review and rating for a particular topic and "
          "website match"
       << endl;
  cout << "4. Remove all websites with a 1 star rating" << endl;
  cout << "5. Display websites based on a topic keyword" << endl;
  cout << "6. Display all" << endl;
  cout << "7. Display each chain length" << endl;
  cout << "8. Quit" << endl;
  cout << endl;
}

// This function executes the option that the user chooses.
void exeOption(int option, Table& hashTable) {
  switch (option) {
    case 1:
      insertWebsite(hashTable);
      break;
    case 2:
      retrieve(hashTable);
      break;
    case 3:
      edit(hashTable);
      break;
    case 4:
      removeOneStar(hashTable);
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:
      hashTable.displayChainLength(cout);
      break;
    case 8:
      break;
    default:
      cout << "Invalid option!! Please try again!!!" << endl << endl;
  }
}

// Prompts for the website's information and adds a new website into the hash
// table.
void insertWebsite(Table& hashTable) {
  char* topic = nullptr;
  char* address = nullptr;
  char* summary = nullptr;
  char* review = nullptr;
  unsigned short int rating;

  cout << "Enter the topic: " << endl;
  cin.getline(topic, STR_SIZE);

  cout << "Enter the address: " << endl;
  cin.getline(address, STR_SIZE);

  cout << "Enter the summary: " << endl;
  cin.getline(summary, STR_SIZE);

  cout << "Enter the review: " << endl;
  cin.getline(review, STR_SIZE);

  getNumber<unsigned short int>(
    "Enter the rating (1-5 stars – 1 being not very useful, 5 being very "
    "useful): ",
    "Please enter a valid rating!", 1, 5, rating);

  hashTable.insert(Website(topic, address, summary, review, rating));
}

// Prompts for the keyword and displays all websites based on that keyword.
void retrieve(Table& hashTable) {
  char* topicKeyword = nullptr;
  Website* results;
  int totalResults = 0;

  cout << "Enter the topic keyword: " << endl;
  cin.getline(topicKeyword, STR_SIZE);

  if (hashTable.retrieve(topicKeyword, results, totalResults)) {
    for (int i = 0; i < totalResults; i++) {
      results[i]->printInformation(cout);
      cout << endl;
    }
  } else {
    cout << "No match found!!" << endl;
  }
}

// Modifies the review and rating for a particular topic and website match.
void edit(Table& hashTable) {
  char* topicKeyword = nullptr;
  char* review = nullptr;
  unsigned short int rating;

  cout << "Enter the topic keyword: " << endl;
  cin.getline(topicKeyword, STR_SIZE);

  cout << "Enter the review: " << endl;
  cin.getline(review, STR_SIZE);

  getNumber<unsigned short int>(
    "Enter the rating (1-5 stars – 1 being not very useful, 5 being very "
    "useful): ",
    "Please enter a valid rating!", 1, 5, rating);

  if (hashTable.edit(topicKeyword, review, rating)) {
    cout << "The review and rating have been modified successfully!!" << endl;
  } else {
    cout << "No match found!!" << endl;
  }
}

// Removes all websites with a 1 star rating.
void removeOneStar(hashTable) {
  Website* results;
  int totalResults = 0;

  if (hashTable.removeOneStar(results, totalResults)) {
    cout << "The following websites have been removed: " << endl;

    for (int i = 0; i < totalResults; i++) {
      results[i]->printInformation(cout);
      cout << endl;
    }
  } else {
    cout << "No website with a 1 star rating found!!" << endl;
  }
}

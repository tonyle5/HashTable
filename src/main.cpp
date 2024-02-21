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

      getNumber("", "Please choose the option from 1 to 10!", 1, 10, option);

      exeOption(option, hashTable);
    } while (option != 10);

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
  cout << "1. Add a new group to the queue" << endl;
  cout << "2. Remove the first group from the queue" << endl;
  cout << "10. Quit" << endl;
  cout << endl;
}

// This function executes the option that the user chooses.
void exeOption(int option, Table& hashTable) {
  switch (option) {
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:
      hashTable.displayChainLength(cout);
      break;
    default:
      cout << "Invalid option!! Please try again!!!" << endl << endl;
  }
}

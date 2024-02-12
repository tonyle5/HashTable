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
  int option = -1;

  welcome();

  if (groupLoadResult != ERROR) {
    cout << groupLoadResult << " group(s) added to the queue." << endl;
    cout << stack.getSize() << " customer(s) added to the stack." << endl
         << endl;

    do {
      displayMenu();

      getNumber("", "Please choose the option from 1 to 10!", 1, 10, option);

      exeOption(option, restaurantQueue, stack);
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
void exeOption(int option, RestaurantQueue& restaurantQueue, Stack& stack) {
  switch (option) {
    case 1:
      addGroup(restaurantQueue, stack);
      restaurantQueue.display();
      break;
    case 2:
      restaurantQueue.dequeue();
      cout << endl;
      restaurantQueue.display();
      break;
    case 3:
      peekQueue(restaurantQueue);
      break;
    case 4:
      restaurantQueue.display();
      break;
    case 5:
      popCustomer(stack);
      break;
    case 6:
      peekCustomer(stack);
      break;
    case 7:
      cout << "The stack contains " << stack.getSize() << " customers."
           << endl
           << endl;
      break;
    case 8:
      cout << "The stack is " << (stack.isEmpty() ? "" : "not ") << "empty."
           << endl
           << endl;
      break;
    case 9:
      cout << stack << endl;
      break;
    case 10:
      if (!restaurantQueue.writeData(DATA_QUEUE)) {
        cout << "Error writing groups to the file!!" << endl;
      }

      if (!stack.writeData(DATA_STACK)) {
        cout << "Error writing customers to the file!!" << endl;
      }
      break;
    default:
      cout << "Invalid option!! Please try again!!!" << endl << endl;
  }
}

/* Name: Tony Le
 * Class: CS260 - 12720
 * Project: #3
 * Date: Feb 11, 2024
 * Description: This is the header file for the main program.
 */

#ifndef MAIN_H
#define MAIN_H

#include "myUtil/myUtil.h"
#include "table/Table.h"

const char* DATA_FILE = "websites.txt";

// Function prototypes

/**
 * This function prints a welcome message.
 *
 * @return void
 */
void welcome();

/**
 * This function prints a goodbye message.
 *
 * @return void
 */
void goodbye();

/**
 * This function displays the menu to the user.
 *
 * @return void
 */
void displayMenu();

/**
 * This function executes the option that the user chooses.
 *
 * @param option The option that the user chooses.
 * @param hashTable The instance of table ADT.
 * @return void
 */
void exeOption(int option, Table& hashTable);

/**
 * Prompts for the website's information and adds a new website into the hash
 * table.
 *
 * @param hashTable The instance of table ADT.
 * @return void
 */
void insertWebsite(Table& hashTable);

/**
 * Prompts for the keyword and displays all websites based on that keyword.
 *
 * @param hashTable The instance of table ADT.
 * @return void
 */
void retrieve(Table& hashTable);

/**
 * Modifies the review and rating for a particular topic and website match.
 *
 * @param hashTable The instance of table ADT.
 * @return void
 */
void edit(Table& hashTable);

/**
 * Removes all websites with a 1 star rating.
 *
 * @param hashTable The instance of table ADT.
 * @return void
 */
void removeOneStar(Table& hashTable);

#endif

/* Name: Tony Le
 * Class: CS260 - 12720
 * Project: #3
 * Date: Feb 11, 2024
 * Description: This is the header file for the main program.
 */

#ifndef MAIN_H
#define MAIN_H

#include "myUtil/myUtil.h"

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
 * @return void
 */
void exeOption(int option);

#endif

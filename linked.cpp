/*********************************************************************
** Program name: Circular Linked List Functions
** Author: Jay Lin
** Date: 05/15/2019
** Description: This program generates a circular linked list and contains
** 4 functions to print the list, add a node to the back (append), remove a node
** at the front, print the first node's value.
** To start, extract all files. Type "make" to compile the program.
** Then type "./linked" to run the program.
*********************************************************************/
#include <iostream>
#include "menu.hpp"
#include "queue.hpp"
using std::cin;
using std::cout;
using std::endl;

int main()
{
    //Declare required class objects and pointer
    Menu menu1;
    Queue queue1;
    Queue *pQueue = &queue1;

    //Display main menu and get user choice to start or quit
    menu1.displayMenu();
    menu1.validateStartChoice();

    //Continues to run program while user does not enter q to quit, or select 8 in menuChoice()
    while (menu1.startCheck())
    {
        //Displays main menu options
        menu1.displayMenu2();

        //Gets menu option and runs functions from class LinkedList. If menuChoice returns 1, breaks
        //from while loop and quits program.
        if (menu1.menuChoice(pQueue) == 1)
        {
            break;
        }

        //Display menu to continue running
        menu1.displayMenu();
        menu1.validateStartChoice();
    }

    return 0;
}
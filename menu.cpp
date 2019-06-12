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
#include <string>
#include "menu.hpp"
#include "queue.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

//displayMenu()
//Displays menu for the game, prompts user to start or quit. Provides a
//quick description of the game. Displays menu to rerun as well.
void Menu::displayMenu()
{
    //Times run checks if this is the first time running.
    //The welcome message will only be displayed if timesRun is 0.
    if (timesRun == 0)
    {
        //gameName is set by getProgramName() in the constructor.
        cout << "Welcome to " << getProgramName() << "." << endl;

        cout << "This is a program that implements functions for circular linked lists." << endl;

        cout << "Please enter 's' to start, or 'q' to quit. " << endl;
    }
    //Displays rerun prompt if timesRun is > 0.
    else if (timesRun > 0)
    {
        cout << "Continue with " << getProgramName() << "? "
             << "Enter 's' to start, 'q' to quit." << endl;
    }
    setTimesRun(getTimesRun() + 1);
}

//displayMenu2()
//Displays the second menu containing all function options.
//Players will have 5 options:
//1. Append new node
//2. Display front node's value
//3. Remove node at the front
//4. Display all elements of the list
//5. Quit.
void Menu::displayMenu2()
{
    cout << endl;
    cout << "Which option would you like to choose? " << endl;
    for (int i = 0; i < 45; i++)
    {
        cout << '=';
    }
    cout << endl;

    cout << "Enter '1' to append a value to the back of the queue. " << endl;
    cout << "Enter '2' to display the value at the front of the queue. " << endl;
    cout << "Enter '3' to remove the node at the front of the queue. " << endl;
    cout << "Enter '4' to display the queue's content. " << endl;
    cout << "Enter '5' to quit. " << endl;
}

//Displays the second menu containing all function options.
//Players will have 5 options:
//1. Append new node
//2. Display front node's value
//3. Remove node at the front
//4. Display all elements of the list
//5. Quit.
//Takes a Queue pointer for access to functions. Returns a value of 1 if user quits the program (case 5),
//which allows for the function to break out of the while loop in linked.cpp.
int Menu::menuChoice(Queue *pQueue)
{
    //Gets and validates user integer input for menu options 1-8.
    int userChoice = validateInt(1);
    //Used as desired values in LinkedList functions
    int userInt = 0;

    //Menu options for user, gets required user input, runs functions.
    switch (userChoice)
    {
    case 1:
        cout << "Please enter a valid positive integer (1 - 32767): " << endl;
        userInt = validateInt(2);
        pQueue->addBack(userInt);
        break;

    case 2:
        cout << "The value of HEAD is: " << pQueue->getFront() << endl;
        break;

    case 3:
        pQueue->removeFront();
        break;

    case 4:
        pQueue->printQueue();
        break;

    case 5:
        cout << "Goodbye." << endl;
        return 1;
    }
}

//validateInt(int range)
//Validates user integer input for a variety of functinos in Menu. Takes an integer parameter to
//determine the range of acceptable inputs from the user. Returns an integer as a choice for
//corresponding menu functions.
int Menu::validateInt(int range)
{
    //Float validation adapted from: https://www.quora.com/How-do-I-check-if-a-number-is-float-on-C++
    double choice = 0.0;
    int floatTest = 0;

    int upperLim = 0;
    int lowerLim = 0;
    string message;

    //Range for main menu choice, 1 - 6
    if (range == 1)
    {
        message = "Please enter a valid integer 1, 2, 3, 4, or 5.";
        upperLim = 5;
        lowerLim = 1;
    }
    //Range for steps, rows and columns, 1 - 32767
    else if (range == 2)
    {
        message = "Please enter a valid integer > 1, < 32767. ";
        upperLim = 32767;
        lowerLim = 1;
    }

    while (true)
    {
        //Detects invalid string/char input and reprompts user
        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << message << endl;
        }
        //Detects float input, out of range input
        floatTest = choice * 100000000.0;
        if (((floatTest % 100000000) > 0) || choice < lowerLim || choice > upperLim)
        {
            //Clears extraction failure flag
            cin.clear();
            //Ignores next 10000 inputs in the buffer until \n
            cin.ignore(10000, '\n');
            cout << message << endl;
        }
        //Valid input, returns integer
        else
        {
            cin.ignore(10000, '\n');
            return choice;
        }
    }
}

//validateStartChoice()
//Validates menu input choice to start the program or quit.
//Ensures that input is a character of 's' to start or
//'q' to quit. Returns a character of 's' or 'q'.
char Menu::validateStartChoice()
{
    string choice;
    while (true)
    {
        cin >> (choice);
        //Character array to validate user input for a character, other inputs are
        //invalid.
        char newChoice[1];
        newChoice[0] = choice[0];
        cin.ignore(10000, '\n');
        if (choice.length() > 1)
        {
            cout << "Please enter 's' to start or 'q' to quit." << endl;
        }
        else if (newChoice[0] == 's' || newChoice[0] == 'q')
        {
            setStartChoice(newChoice[0]);
            return newChoice[0];
        }
        else
        {
            cout << "Please enter 's' to start or 'q' to quit." << endl;
        }
    }
}

//startCheck()
//Prompts user for menu input to start or quit, using
//getMenuChoice(). Quits if user input is 'q'. Returns a bool of true (s) or false (q).
bool Menu::startCheck()
{
    if (getStartChoice() == 'q')
    {
        return false;
    }
    else
    {
        return true;
    }
}

//displayLine()
//Displays a line of '~' characters, 90 characters long.
void Menu::displayLine()
{
    for (int i = 0; i < 90; i++)
    {
        cout << '~';
    }
    cout << endl;
}

//displayContinue()
//Asks user to press any key and/or ENTER/RETURN to continue.
void Menu::displayContinue()
{
    std::string anyKey;
    cout << "Press any key and/or ENTER/RETURN to continue. " << endl;
    getline(cin, anyKey);
}
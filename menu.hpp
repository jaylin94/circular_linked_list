#ifndef MENU_HPP
#define MENU_HPP
#include <string>
#include "queue.hpp"

class Menu
{
private:
    int timesRun;
    char startChoice;
    std::string programName;

public:
    Menu()
    {
        timesRun = 0;
        startChoice = 's';
        programName = "Circular Linked List Functions";
    }

    //Menu functions to display and check to start or quit
    void displayMenu();
    void displayMenu2();
    int menuChoice(Queue *pQueue);
    void displayLine();
    void displayContinue();

    //Menu functions to get choice and validate input
    bool startCheck();

    //Validates user start choice and integer input
    char validateStartChoice();
    int validateInt(int range);

    //Get functions for variables
    int getTimesRun()
    {
        return timesRun;
    }
    char getStartChoice()
    {
        return startChoice;
    }
    std::string getProgramName()
    {
        return programName;
    }

    //Set functions for variables
    void setTimesRun(int timesRun)
    {
        this->timesRun = timesRun;
    }
    void setStartChoice(char startChoice)
    {
        this->startChoice = startChoice;
    }
    void setProgramName(std::string programName)
    {
        this->programName = programName;
    }
};

#endif
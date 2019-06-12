#include <iostream>
#include "menu.hpp"
#include "linkedList.hpp"
using std::cin;
using std::cout;
using std::endl;

int main()
{
    Menu menu1;
    LinkedList list1;
    LinkedList *pList = &list1;

    menu1.displayMenu();
    menu1.validateStartChoice();

    while (menu1.startCheck())
    {
        menu1.displayMenu2();
        if (menu1.menuChoice(pList) == 1)
        {
            break;
        }

        //Display menu to continue running
        menu1.displayMenu();
        menu1.validateStartChoice();
    }
    pList->delAll();

    return 0;
}
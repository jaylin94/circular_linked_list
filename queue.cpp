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
#include "queue.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

//Prints the entire queue of list values. Will print error message if the list is empty.
//Contains logic for one node, two nodes, or more than two nodes.
void Queue::printQueue()
{
    QueueNode *temp = getHead();

    //If empty, output empty message
    if (isEmpty() == true)
    {
        cout << "The queue is empty." << endl;
        return;
    }
    //If not empty, print queue
    else if (isEmpty() == false)
    {
        cout << "Your linked list: ";
        //If there is only one node print head
        if (getHead()->prev == nullptr && getHead()->next == nullptr)
        {
            cout << getHead()->val << endl;
            return;
        }
        else if (getHead()->prev == getHead()->next)
        {
            cout << getHead()->val;
            cout << " ";
            cout << getHead()->next->val;
            cout << endl;
            return;
        }
        //If there are more than two nodes, print all
        else if (getHead()->next != getHead()->prev)
        {
            cout << getHead()->val;
            //Traverse circular linked list and print all values
            while (temp->next != getHead())
            {
                cout << " ";
                cout << temp->next->val;
                temp = temp->next;
            }
            cout << endl;
            return;
        }
    }
}

//Adds a Node to the back of the list. Takes an integer parameter
//to set for the new Node value. Called in menuChoice().
void Queue::addBack(int userInt)
{
    QueueNode *pQueueNode = new QueueNode;
    pQueueNode->val = userInt;
    QueueNode *temp = getHead();

    //If list is empty, set head to new node, set prev and next to nullptr
    if (isEmpty() == true)
    {
        setHead(pQueueNode);
        getHead()->prev = nullptr;
        getHead()->next = nullptr;
        return;
    }
    //If list is not empty
    else if (isEmpty() == false)
    {
        //If there is one node set new node to head->next
        if (getHead()->prev == nullptr && getHead()->next == nullptr)
        {
            getHead()->next = pQueueNode;
            pQueueNode->prev = getHead();
            pQueueNode->next = getHead();
            getHead()->prev = pQueueNode;
            return;
        }
        //If there are two nodes, append 3rd node
        else if (getHead()->prev == getHead()->next)
        {
            temp = getHead()->next;
            temp->next = pQueueNode;
            pQueueNode->prev = temp;
            pQueueNode->next = getHead();
            getHead()->prev = pQueueNode;
            return;
        }
        //If more than one node, append new node to last node
        else if (getHead()->next != getHead()->prev)
        {
            //Traverse all nodes and append new node
            while (temp->next != getHead())
            {
                temp = temp->next;
            }
            temp->next = pQueueNode;
            pQueueNode->prev = temp;
            pQueueNode->next = getHead();
            getHead()->prev = pQueueNode;
            return;
        }
    }
}

//Removes the HEAD of the node and sets the HEAD to the old head->next
//Sets all other pointers accordingly.
void Queue::removeFront()
{
    QueueNode *temp = getHead();
    if (isEmpty() == true)
    {
        cout << "The list is empty. " << endl;
        return;
    }
    //If list is not empty
    else if (isEmpty() == false)
    {
        //If there is one node, delete it, set HEAD to nullptr
        if (getHead()->next == nullptr && getHead()->prev == nullptr)
        {
            delete getHead();
            setHead(nullptr);
            return;
        }
        //If there are 2 nodes, delete first node
        else if (getHead()->next == getHead()->prev)
        {
            setHead(temp->next);
            getHead()->next = nullptr;
            getHead()->prev = nullptr;
            delete temp;
            return;
        }
        //If there are more than 2 nodes, delete first node, set prev and next accordingly
        else if (getHead()->next != getHead()->prev)
        {
            setHead(temp->next);
            getHead()->prev = temp->prev;
            temp->prev->next = getHead();
            delete temp;
            return;
        }
    }
}

//Returns the int value of the front node of the list if the list is not empty.
int Queue::getFront()
{
    if (isEmpty() == true)
    {
        cout << "The list is empty. ";
        return 0;
    }
    else if (isEmpty() == false)
    {
        return getHead()->val;
    }
}

//Returns a bool value of true of the list is empty, determined with getHead() == nullptr.
//Returns a bool value of false if list is not empty.
bool Queue::isEmpty()
{
    if (getHead() == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Destructor to deallocate memory allocated at runtime. Deletes for one node, two nodes, or more than two nodes.
Queue::~Queue()
{
    QueueNode *temp;

    if (isEmpty() == true)
    {
        return;
    }
    else if (isEmpty() == false)
    {
        //If there is one node, delete it and return
        if (getHead()->next == nullptr && getHead()->prev == nullptr)
        {
            delete getHead();
            setHead(nullptr);
            return;
        }
        //If there are two or more nodes, delete all nodes
        while (getHead()->next != getHead()->prev)
        {
            temp = getHead();
            setHead(temp->next);
            getHead()->prev = temp->prev;
            delete temp;
            temp = nullptr;
        }
        //Delete the 2nd to last node and last node
        if (getHead()->next == getHead()->prev)
        {
            temp = getHead();
            setHead(getHead()->next);
            getHead()->next = nullptr;
            getHead()->prev = nullptr;
            delete temp;
            delete getHead();
            setHead(nullptr);
            temp = nullptr;
        }
    }
}
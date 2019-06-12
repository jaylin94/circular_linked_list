#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <string>
#include "queueNode.hpp"

class Queue
{
private:
    QueueNode *head;

public:
    Queue()
    {
        setHead(nullptr);
    }

    //Main functions to add Queues, delete Queues, print list values
    void addBack(int userInt);
    int getFront();
    void removeFront();
    void printQueue();
    bool isEmpty();

    //Get functions for LinkedList variables
    QueueNode *getHead()
    {
        return head;
    }

    //Set functions for LinkedList variables
    void setHead(QueueNode *head)
    {
        this->head = head;
    }

    ~Queue();
};

#endif
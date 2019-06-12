#ifndef QUEUENODE_HPP
#define QUEUENODE_HPP

struct QueueNode
{
    QueueNode *next;
    QueueNode *prev;
    int val;
};

#endif
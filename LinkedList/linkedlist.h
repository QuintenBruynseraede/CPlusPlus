#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <LinkedList/llnode.h>

class LinkedList
{
public:
    LinkedList();

    int getValue(int index);
    int getLength();
    LLNode* getFirst();
    LLNode* getLast();
    LinkedList copy();


    void add(int value);
    void clear();
    void print();

    LinkedList operator+(LinkedList l2);
private:
    LLNode* first;
};

#endif // LINKEDLIST_H

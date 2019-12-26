#include "linkedlist.h"
#include <cstddef>
#include <iostream>
LinkedList::LinkedList()
{
    this->first = nullptr;
}

LinkedList LinkedList::copy() {
    LinkedList* l = new LinkedList();
    LLNode* i = this->getFirst();
    while(i->getNext() != nullptr) {
        l->add(i->getValue());
        i = i->getNext();
    }
    l->add(i->getValue());
    return *l;
}

void LinkedList::add(int value){
    if (this->first == nullptr) {
        this->first = new LLNode(value);
    }
    else {
        this->first->add(value);
    }
}

void clear(){}

int LinkedList::getLength() {
    int l = 1;
    if (this->first == nullptr)
        return 0;
    LLNode* i = this->first;
    while (i->getNext() != nullptr) {
        i = i->getNext();
        l++;
    }
    return l;
}

void LinkedList::print() {
    std::cout << "[";
    this->first->print();
}

LLNode* LinkedList::getFirst() {
    return this->first;
}

LLNode* LinkedList::getLast() {
    LLNode* i = this->first;
    while(i->getNext() != nullptr) {
        i = i->getNext();
    }
    return i;
}

void LinkedList::clear() {
    LLNode* i = this->getFirst();
    LLNode* iprev = i;
    while (i->getNext() != nullptr) {
        iprev = i;
        i = i->getNext();
        delete iprev;
    }
    this->first = nullptr;
}

LinkedList LinkedList::operator+ (LinkedList l2) {
    LinkedList l = this->copy();
    l.getLast()->setNext(l2.getFirst());
    return l;
}





#include "llnode.h"
#include <iostream>

LLNode::LLNode()
{
    this->value = 0;
    this->next = nullptr;
}

LLNode::LLNode(int value) {
    this->value = value;
    this->next = nullptr;
}

int LLNode::getValue() {
    return this->value;
}

LLNode* LLNode::getNext() {
    return this->next;
}

void LLNode::add(int value) {
    if (this->next == nullptr) {
        this->next = new LLNode(value);
    }
    else {
        this->next->add(value);
    }
}

void LLNode::print() {
    std::cout << this->value << " ";
    if (this->next == nullptr)
        std::cout << "]\n";
    else {
        this->next->print();
    }
}

void LLNode::setNext(LLNode* n) {
    this->next = n;
}

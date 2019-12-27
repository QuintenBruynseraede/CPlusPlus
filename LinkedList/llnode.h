#ifndef LLNODE_H
#define LLNODE_H


class LLNode
{
public:
    LLNode();
    LLNode(int value);
    int getValue();
    LLNode* getNext();
    void setNext(LLNode* n);
    void add(int value);
    void print();
private:
    int value;
    LLNode* next;
};

#endif // LLNODE_H

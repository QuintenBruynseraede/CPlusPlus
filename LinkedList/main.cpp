#include <QCoreApplication>
#include <iostream>
#include <linkedlist.h>
#include <llnode.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    LinkedList l = LinkedList();
    l.add(1);
    l.add(2);
    l.add(3);

    LinkedList l2 = LinkedList();
    l2.add(4);
    l2.add(5);
    l2.add(6);

    l.print();
    l2.print();

    LinkedList l3 = l + l2;
    l3.print();

    l3.clear();
    l3.print();

    return a.exec();
}


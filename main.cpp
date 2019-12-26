#include <QCoreApplication>
#include <iostream>
#include <LinkedList/linkedlist.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    LinkedList l = LinkedList();
    l.add(234);
    l.print();

    return a.exec();
}


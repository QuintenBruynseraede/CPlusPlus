#include <QCoreApplication>
#include <iostream>
#include <LinkedList/linkedlist.h>
#include <Matrix/matrix.h>
#include <vector>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Matrix x = Matrix(10,5);
    std::vector<int> size = x.getSize();

    for (std::vector<int>::iterator it = size.begin(); it!=size.end();++it) {
        std::cout << (*it) << " ";
    }
    std::cout << std::endl;

    std :: cout << x.getElementAt(1,2) << std::endl;

    return a.exec();
}

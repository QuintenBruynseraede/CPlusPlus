#include <QCoreApplication>
#include <iostream>
#include <LinkedList/linkedlist.h>
#include <Matrix/matrix.h>
#include <vector>
#include <cmath>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Matrix x = Matrix(5,5);

    for (int i=0;i<25;i++) {
        x.setElementAt(i/5+1,i%5+1,i+1);
    }

    Matrix y = x.subMatrix(1,1,3,3);
    // 1  2  3
    // 6  7  8
    //11 12 13

    std::cout << x.det() << std::endl;

    return a.exec();
}

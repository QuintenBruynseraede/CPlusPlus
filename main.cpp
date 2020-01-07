#include <QCoreApplication>
#include <iostream>
#include <LinkedList/linkedlist.h>
#include <Matrix/matrix.h>
#include <vector>
#include <cmath>
#include <random>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Matrix x = Matrix(5,5);

    for (int i=0;i<25;i++) {
        x.setElementAt(i/5+1,i%5+1,random()/(RAND_MAX/10));
    }
    x.print();
    std::cout << "Determinant: " << x.det() << std::endl;

    Matrix z = x.subMatrix(1,1,3,3);
    z.print();

    std::cout << "Determinant: " << z.det() << std::endl;

    return a.exec();
}

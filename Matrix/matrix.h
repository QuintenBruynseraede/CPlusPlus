#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix
{
public:
    Matrix(int rows, int columns);

    std::vector<int> getSize();
    int getElementAt(int row, int column);
    void setElementAt(int row, int column, int value);
    int det();

    void print();


private:
    std::vector<std::vector<int>> data;
};

#endif // MATRIX_H

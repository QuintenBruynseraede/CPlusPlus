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
    Matrix subMatrix(int row, int col, int rowSize, int colSize);
    int det();
    int getMax();
    void print();


private:
    std::vector<std::vector<int>> data;
};

#endif // MATRIX_H

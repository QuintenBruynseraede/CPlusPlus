#include "matrix.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <cmath>

/**
 * @brief Matrix::Matrix    Creates a matrix with dimensions rows x columns
 * @param rows
 * @param columns
 */
Matrix::Matrix(const int rows, const int columns)
{
    this->data.resize(rows);
    for (std::vector<std::vector<int>>::iterator it = data.begin();it != data.end();++it) {
        (*it).resize(columns);
    }
}

void print_vector(std::vector<int> x, int pad) {
    for (std::vector<int>::iterator it = x.begin(); it!=x.end();++it) {
        std::cout << std::setw (pad) << (*it) << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Matrix::getSize   Returns the dimensions of this matrix
 * @return 2-element vector containing (rows, columns)
 */
std::vector<int> Matrix::getSize() {
    std::vector<int> x;
    x.push_back(this->data.size());
    x.push_back(this->data.begin()->size());
    return x;
}

/**
 * @brief Matrix::print     Prints the matrix row by row, column by column
 */
void Matrix::print() {
    for (std::vector<std::vector<int>>::iterator it = this->data.begin();it != this->data.end();++it) {
        int pad = log10((double) this->getMax())+1;
        print_vector(*it,pad);
    }
}

/**
 * @brief Matrix::getMax    Returns the value of the largest element in this matrix
 */
int Matrix::getMax() {
    int rows = this->getSize().at(0);
    int cols = this->getSize().at(1);
    int max = 0;

    for (int i=1;i<=rows;i++) {
        for (int j=1;j<=cols;j++) {
            if (this->getElementAt(i,j) > max)
                    max = this->getElementAt(i,j);
        }
    }
    return max;
}

/**
 * @brief Matrix::subMatrix     Returns a matrix that is a submatrix of this matrix.
 *                              It has identical values starting from (row, col) and sizes rowSize, colSize
 */
Matrix Matrix::subMatrix(int row, int col, int rowSize, int colSize) {
    if (row+rowSize > this->getSize().at(0) ||
            col+colSize > this->getSize().at(1))
        throw std::invalid_argument("Matix index out of bound.");


    Matrix m = Matrix(rowSize,colSize);
    for (int i=row;i<=row+rowSize-1;i++) {
        for (int j=col;j<=col+colSize-1;j++) {
            m.setElementAt(i-row+1,j-col+1,this->getElementAt(i,j));
        }
    }
    return m;
}



/**
 * @brief Matrix::getElementAt      Returns the value at position row, column. Note that indexing starts at 1.
 */
int Matrix::getElementAt(int row, int column) {
    if (row < 1 || column < 1)
        throw std::invalid_argument("Invalid position index");

    return this->data.at(row-1).at(column-1);
}

void Matrix::setElementAt(int row, int column, int value) {
    this->data.at(row-1).at(column-1) = value;
}

int Matrix::det() {
    int determinant = 0;
    int rows = this->getSize().at(0);
    int cols = this->getSize().at(1);

    if (rows == 2 && cols == 2) {
        return (this->getElementAt(1,1)*this->getElementAt(2,2)-this->getElementAt(1,2)*this->getElementAt(2,1));
    }

    for (int i=1;i<=cols;i++) {
        //Construct submatrix ecluding row 1, column i;
        Matrix s = Matrix(rows-1,cols-1);
        int copied = 0;
        for (int row=2;row<=rows;row++) {
            for (int col=1;col<=cols;col++) {
                if (col != i) {
                    //Add to position
                    s.setElementAt(1+copied/(rows-1),1+copied%(cols-1),this->getElementAt(row,col));
                    copied++;
                }
            }
        }


        int neg = (i % 2 == 0 ? -1 : 1);
        determinant += neg * this->getElementAt(1,i)*s.det();
    }
    return determinant;
}





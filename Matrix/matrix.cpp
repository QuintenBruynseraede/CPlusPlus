#include "matrix.h"
#include <iostream>
#include <vector>

Matrix::Matrix(const int rows, const int columns)
{
    this->data.resize(rows);
    for (std::vector<std::vector<int>>::iterator it = data.begin();it != data.end();++it) {
        (*it).resize(columns);
    }
}

void print_vector(std::vector<int> x) {
    for (std::vector<int>::iterator it = x.begin(); it!=x.end();++it) {
        std::cout << (*it) << " ";
    }
    std::cout << std::endl;
}

std::vector<int> Matrix::getSize() {
    std::vector<int> x;
    x.push_back(this->data.size());
    x.push_back(this->data.begin()->size());
    return x;
}

void Matrix::print() {
    for (std::vector<std::vector<int>>::iterator it = this->data.begin();it != this->data.end();++it) {
        print_vector(*it);
    }
}

int Matrix::getElementAt(int row, int column) {
    return this->data.at(row).at(column);
}

void Matrix::setElementAt(int row, int column, int value) {

}





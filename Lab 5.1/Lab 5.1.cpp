#include <iostream>
#include "array.h"

int main() {
    Array matr1;
    matr1.input();
    matr1.print();
    std::cout << matr1.trace(matr1.matr, matr1.get_rows()) << std::endl;
    Array matr2;
    matr2.input();
    matr2.print();
    Array matr3;
    matr3.matrixsum(matr1.matr, matr2.matr, matr1.get_columns(), matr2.get_rows());
    matr3.print();
    matr3.matrixmult(matr1.matr, matr1.get_columns(), matr1.get_rows(), matr2.matr, matr2.get_columns(), matr2.get_rows());
    matr3.print();
    return 0;
}
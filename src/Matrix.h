//
// Created by justnik on 20.12.2020.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <iostream>

class Matrix {
private:
    double ** data;
    uint32_t n;
    uint32_t m;
public:
    explicit Matrix(uint32_t n);

    Matrix(uint32_t n, uint32_t m);

    Matrix(const Matrix &m);

    Matrix(Matrix &&m) noexcept ;

    Matrix &operator=(const Matrix &m);

    Matrix &operator=(Matrix &&m) noexcept;

};


#endif //MATRIX_MATRIX_H

//
// Created by justnik on 20.12.2020.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <iostream>

class Matrix {
private:
    double **data;
    uint32_t n;
    uint32_t m;
public:
    explicit Matrix(uint32_t n);

    Matrix(uint32_t n, uint32_t matrix);

    Matrix(const Matrix &matrix);

    Matrix(Matrix &&matrix) noexcept;

    Matrix &operator=(const Matrix &matrix);

    Matrix &operator=(Matrix &&matrix) noexcept;

    virtual ~Matrix();

    Matrix &operator+=(const Matrix &r);

    Matrix &operator-=(const Matrix &r);

    Matrix &operator*=(const Matrix &r);

    double *operator[](uint32_t ind);

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);
};

#endif //MATRIX_MATRIX_H

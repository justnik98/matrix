//
// Created by justnik on 20.12.2020.
//

#include "Matrix.h"

Matrix::Matrix(uint32_t n) : n(n), m(n) {
    uint32_t size = n * n;
    data = new double *[n];
    data[0] = new double[size];
    for (int i = 1; i < n; ++i) {
        data[i] = &data[0][i * m];
    }
}

Matrix::Matrix(uint32_t n, uint32_t m) : n(n), m(m) {
    uint32_t size = n * n;
    data = new double *[n];
    data[0] = new double[size];
    for (int i = 1; i < n; ++i) {
        data[i] = &data[0][i * m];
    }
}

Matrix::Matrix(const Matrix &m) {

}

Matrix::Matrix(Matrix &&m) noexcept {

}

Matrix &Matrix::operator=(const Matrix &m) {
    return <#initializer#>;
}

Matrix &Matrix::operator=(Matrix &&m) noexcept {
    return <#initializer#>;
}

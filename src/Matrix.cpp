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
    uint32_t size = n * m;
    data = new double *[n];
    data[0] = new double[size];
    for (int i = 1; i < n; ++i) {
        data[i] = &data[0][i * m];
    }
}

Matrix::Matrix(const Matrix &matrix) {
    n = matrix.n;
    m = matrix.m;
    uint32_t size = n * m;
    data = new double *[n];
    data[0] = new double[size];
    for (int i = 1; i < n; ++i) {
        data[i] = &data[0][i * m];
    }
    for (int i = 0; i < size; i++) {
        data[i] = matrix.data[i];
    }
}

Matrix::Matrix(Matrix &&matrix) noexcept {
    n = matrix.n;
    m = matrix.m;
    data = matrix.data;
    matrix.data = nullptr;
}

Matrix &Matrix::operator=(const Matrix &matrix) {
    return <#initializer#>;
}

Matrix &Matrix::operator=(Matrix &&matrix) noexcept {
    return <#initializer#>;
}

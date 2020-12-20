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
    for (int i = 0; i < size; ++i) {
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
    if (this == &matrix) {
        return *this;
    }
    delete[] data[0];
    delete[] data;
    n = matrix.n;
    m = matrix.m;
    uint32_t size = n * m;
    data = new double *[n];
    data[0] = new double[size];
    for (int i = 1; i < n; ++i) {
        data[i] = &data[0][i * m];
    }
    for (int i = 0; i < size; ++i) {
        data[0][i] = matrix.data[0][i];
    }
    return *this;
}

Matrix &Matrix::operator=(Matrix &&matrix) noexcept {
    if (this == &matrix) {
        return *this;
    }
    n = matrix.n;
    m = matrix.m;
    data = matrix.data;
    matrix.data = nullptr;
    return *this;
}

Matrix &Matrix::operator+=(const Matrix &r) {
    if (n != r.n || m != r.m) {
        throw (std::out_of_range("Matrix dimensions must be the same\n"));
    }
    uint32_t size = n * m;
    for (int i = 0; i < size; ++i) {
        data[0][i] += r.data[0][i];
    }
    return *this;
}

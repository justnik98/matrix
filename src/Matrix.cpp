//
// Created by justnik on 20.12.2020.
//

#include <iterator>
#include "Matrix.h"


Matrix::Matrix(uint32_t n) : Matrix(n, n) {
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
    std::copy(matrix.data[0], matrix.data[0] + size, data[0]);
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
    std::copy(matrix.data[0], matrix.data[0] + size, data[0]);
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

Matrix::~Matrix() {
    if (data) {
        delete[] data[0];
        delete[] data;
        data = nullptr;
    }
}

Matrix &Matrix::operator+=(const Matrix &r) {
    if (n != r.n || m != r.m) {
        throw (std::invalid_argument("Matrix dimensions must be the same\n"));
    }
    uint32_t size = n * m;
    for (int i = 0; i < size; ++i) {
        data[0][i] += r.data[0][i];
    }
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &r) {
    if (n != r.n || m != r.m) {
        throw (std::invalid_argument("Matrix dimensions must be the same\n"));
    }
    uint32_t size = n * m;
    for (int i = 0; i < size; ++i) {
        data[0][i] -= r.data[0][i];
    }
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &r) {
    Matrix c(n, r.m);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < r.n; ++j) {
            c.data[0][i * n + j] = 0;
            for (int k = 0; k < m; ++k) {
                c.data[0][i * n + j] += data[0][i * m + k] * r.data[0][k * n + j];
            }
        }
    }
    *this = c;
    return *this;
}

double *Matrix::operator[](uint32_t ind) {
    if (ind >= n) {
        throw (std::out_of_range("Wrong index\n"));
    }
    return data[ind];
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
    for (int i = 0; i < matrix.n; ++i) {
        for (int j = 0; j < matrix.m; ++j) {
            os << matrix.data[i][j] << ' ';
        }
        os << std::endl;
    }
    return os;
}

Matrix operator+(Matrix l, const Matrix &r) {
    l += r;
    return l;
}

Matrix operator-(Matrix l, const Matrix &r) {
    l -= r;
    return l;
}

Matrix operator*(Matrix l, const Matrix &r) {
    l *= r;
    return l;
}

Matrix Matrix::identity(uint32_t n) noexcept {
    Matrix res(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            res[i][j] = i == j ? 1 : 0;
        }
    }
    return res;
}

Matrix Matrix::inverse() const noexcept {
    Matrix ext = Matrix::identity(n);
    Matrix(*this).inverseExt(ext);
    return ext;
}

void Matrix::inverseExt(Matrix &ext) {
    if (gauss(&ext) != n) {
        throw std::invalid_argument("Cannot inverse a singular matrix");
    }
    for (unsigned i = n - 1; i != unsigned(-1); --i) {
        double coeff = 1.0 / data[i][i];
        for (unsigned j = 0; j < n; ++j) {
            (*this)[i][j] *= coeff;
        }
        for (unsigned j = 0; j < ext.n; ++j) {
            ext[i][j] *= coeff;
        }
        for (unsigned j = i + 1; j < n; j++) {
            if (data[i][j] == 0.0)
                continue;
            for (unsigned q = 0; q < ext.n; q++) {
                ext[i][q] -= ext[j][q] * (*this)[i][j];
            }
            (*this)[i][j] = double();
        }
    }
}

Matrix Matrix::operator^(uint32_t pow) const {
    Matrix res = identity(m);
    for (uint32_t i = 0; i < pow; ++i) {
        res *= *this;
    }
    return res;
}

uint32_t Matrix::gauss(Matrix *ext) {
    unsigned row = 0;
    for (unsigned col = 0; col < n; ++col) {
        for (unsigned i = row; i < m; ++i) {
            if ((*this)[i][col]) {
                if (i != row) {
                    for (unsigned j = 0; j < n; ++j) {
                        std::swap((*this)[i][j], (*this)[row][j]);
                        (*this)[i][j] = -(*this)[i][j];
                    }
                    if (ext) {
                        for (unsigned j = 0; j < ext->n; ++j) {
                            std::swap((*ext)[i][j], (*ext)[row][j]);
                            (*ext)[i][j] = -(*ext)[i][j];
                        }
                    }
                }
                break;
            }
        }
        if (!(*this)[row][col]) {
            continue;
        }
        for (unsigned i = row + 1; i < m; ++i) {
            double coeff = (*this)[i][col] / (*this)[row][col];
            for (unsigned j = 0; j < n; ++j) {
                (*this)[i][j] -= (*this)[row][j] * coeff;
            }
            if (ext) {
                for (unsigned j = 0; j < ext->n; ++j)
                    (*ext)[i][j] -= (*ext)[row][j] * coeff;
            }
        }
        if (++row == m)
            return row;
    }
    return row;
}




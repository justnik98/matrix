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

    void inverseExt(Matrix &ext);

    uint32_t gauss(Matrix *ext) noexcept;

public:
    explicit Matrix(uint32_t n);

    Matrix(uint32_t n, uint32_t m);

    Matrix(const Matrix &matrix);

    Matrix(Matrix &&matrix) noexcept;

    Matrix &operator=(const Matrix &matrix);

    Matrix &operator=(Matrix &&matrix) noexcept;

    virtual ~Matrix();

    Matrix &operator+=(const Matrix &r);

    Matrix &operator-=(const Matrix &r);

    Matrix &operator*=(const Matrix &r);

    Matrix operator^(uint32_t pow) const;

    double *operator[](uint32_t ind);

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);

    friend Matrix operator+(Matrix l, const Matrix &r);

    friend Matrix operator-(Matrix l, const Matrix &r);

    friend Matrix operator*(Matrix l, const Matrix &r);

    static Matrix identity(uint32_t n) noexcept;

    [[nodiscard]] Matrix inverse() const;

    [[nodiscard]] double det() const;

    Matrix transposed() const noexcept;
};


#endif //MATRIX_MATRIX_H

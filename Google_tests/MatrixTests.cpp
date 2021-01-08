//
// Created by justnik on 02.01.2021.
//

#include "gtest/gtest.h"
#include "Matrix.h"

TEST(InverseMatrix, IdentityMatrixInverse) {
    uint32_t n = 3;
    Matrix a = Matrix::identity(n);
    a = a.inverse();
    for (uint32_t i = 0; i < n; ++i) {
        for (uint32_t j = 0; j < n; ++j) {
            if (i == j) {
                ASSERT_EQ(a[i][j], 1);
            } else {
                ASSERT_EQ(a[i][j], 0);
            }
        }
    }
}

TEST(IdentityConstructor, CheckMatrix) {
    uint32_t n = 3;
    Matrix a = Matrix::identity(n);
    for (uint32_t i = 0; i < n; ++i) {
        for (uint32_t j = 0; j < n; ++j) {
            if (i == j) {
                ASSERT_EQ(a[i][j], 1);
            } else {
                ASSERT_EQ(a[i][j], 0);
            }
        }
    }
}

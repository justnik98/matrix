#include <iostream>
#include "src/Matrix.h"

int main() {
    int n = 2;
    int m = 2;
    Matrix a(n, m);
    Matrix b(n, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> b[i][j];
        }
    }
    a += b;
    std::cout << a;
    a -= b;
    std::cout << a;
    Matrix c(n);
    c = a + b;
    std::cout << c;
    return 0;
}

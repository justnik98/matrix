#include <iostream>
#include "src/Matrix.h"

int main() {
    using std::cout, std::cin, std::endl;
    uint32_t n = 2;
    uint32_t m = 2;
    Matrix a(n, m);
    Matrix b(n, m);
    Matrix d = Matrix::identity(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
        }
    }
    a += b;
    cout << a << endl;
    a -= b;
    cout << a << endl;
    Matrix c(n);
    c = a + b;
    cout << c << endl;
    c = a * b;
    cout << c << endl;
    c = d * d;
    cout << c << endl;
    c = a.inverse();
    cout << c << endl;
    c = a ^ 1000;
    cout << c << endl;
    cout << a.det() << endl;
    cout << a.transposed() << endl;
    return 0;
}

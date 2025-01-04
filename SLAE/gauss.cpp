#include <iostream>
#include "slae.h"

/* SLAE is System of Linear Algebraic Equations
 * Augmented Matrix is (A|B)
 * example:
 *         2 -1  1        1
 *     A = 3  0  3 ; B = -1
 *         4  2 -7        2
 *
 *           2 -1  1 |  1
 *     A|B = 3  0  3 | -1
 *           4  2 -7 |  2
*/

std::vector<std::vector<double>> augmentedMatrixRequest() {
    int n, m;
    std::cout << "Enter dimension of Augmented Matrix (A|B) of SLAE:\n";
    std::cout << "Enter count of rows:";
    std::cin >> n;
    std::cout << "Enter count of columns, including B:";
    std::cin >> m;

    std::vector<std::vector<double>> matrix(n, std::vector<double>(m));

    for (int i = 0; i < n; ++i) {
        std::cout << "Enter row number " << i+1 << ":";
        for (int j = 0; j < m; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    return matrix;
}

void matrixToTriangularForm(std::vector<std::vector<double>>& matrix, const int& n, const int& m) {
    for (int k = 0; k < n; ++k) {
        for (int j = k + 1; j < m; ++j) matrix[k][j] /= matrix[k][k];
        matrix[k][k] = 1;

        for (int i = k + 1; i < n; ++i) {
            for (int j = k + 1; j < m; ++j) matrix[i][j] -= matrix[i][k] * matrix[k][j];
            matrix[i][k] = 0;

        }
    }
}

std::vector<double> gauss(std::vector<std::vector<double>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    // 'Row reduction' or 'Forward pass'
    matrixToTriangularForm(matrix, n, m);
    // 'Back-substitution' or 'Reverse pass'
    std::vector<double> X (n);
    for (int i = n-1; i >= 0; --i) {
        X[i] = matrix[i][m-1];
        for(int k = n-1; k > i; --k) {
            X[i] -= matrix[i][k] * X[k];
        }
    }
    return X;
}
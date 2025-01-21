#include <cmath>
#include <iostream>
#include "slae.h"

double precisionRequest() {
    double eps;
    std::cout << "Enter required precision of computations:\n";
    std::cin >> eps;
    return eps;
}

double maxDelta(const std::vector<double>& X, const std::vector<double>& prevX) {
    double maxDelta = fabs(X[0] - prevX[0]);
    for (int i = 1; i < X.size(); ++i) {
        if (fabs(X[i] - prevX[i]) > maxDelta) maxDelta = fabs(X[i] - prevX[i]);
    }
    return maxDelta;
}

void cp(const std::vector<double>& from, std::vector<double>& to) {
    for (int i = 0; i < to.size(); ++i) to[i] = from[i];
}

std::vector<double> seidel(std::vector<std::vector<double>>& matrix, const double& eps) {
    const int n = matrix.size();

    for (int i = 0; i < n; ++i) { // Diagonal elements -> 1
        double val = matrix[i][i];
        for (int j = 0; j < n+1; ++j) {
            matrix[i][j] /= val;
        }
    }

    std::vector<double> X (n), prevX (n);
    for (int i = 0; i < n; ++i) X[i] = matrix[i][n]; // Initial approach

    double precision = eps * 10;
    while (precision >= eps) {
        cp(X, prevX);
        for (int i = 0; i < n; ++i) {
            X[i] = matrix[i][n];
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                X[i] -= matrix[i][j] * X[j];
            }
        }
        precision = maxDelta(X, prevX);
    }

    return X;
}

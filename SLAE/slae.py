from math import *


def gauss(M: list[list]) -> list:
    n = len(M)
    # 'Row reduction' or 'Forward pass'
    for k in range(0, n, 1):
        for j in range(k+1, n+1, 1):
            M[k][j] /= M[k][k]
        M[k][k] = 1

        for i in range(k+1, n, 1):
            for j in range(k+1, n+1, 1):
                M[i][j] -= M[i][k] * M[k][j]
            M[i][k] = 0
    X = [0] * n
    # 'Back-substitution' or 'Reverse pass'
    for i in range(n-1, -1, -1):
        X[i] = M[i][n]
        for k in range(n-1, i, -1):
            X[i] -= M[i][k] * X[k]
    return X


def seidel(M: list[list], eps: float = 0.001):
    def max_delta(X: list, X_prev: list) -> float:
        return max([fabs(X[i] - X_prev[i]) for i in range(len(X))])
    n = len(M)
    for i in range(0, n, 1):
        val = M[i][i]
        for j in range(0, n+1, 1):
            M[i][j] /= val

    X, X_prev = [M[i][n] for i in range(0, n, 1)], [] * n

    precision = eps * 10
    while precision >= eps:
        X_prev = [X[i] for i in range(len(X))]
        for i in range(0, n, 1):
            X[i] = M[i][n]
            for j in range(0, n, 1):
                if i == j:
                    continue
                X[i] -= M[i][j] * X[j]
        precision = max_delta(X, X_prev)

    return X

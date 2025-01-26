from math import *


def gauss(M: list[list]) -> list:
    n = len(M)
    for k in range(0, n, 1):
        for j in range(k+1, n+1, 1):
            M[k][j] /= M[k][k]
        M[k][k] = 1

        for i in range(k+1, n, 1):
            for j in range(k+1, n+1, 1):
                M[i][j] -= M[i][k] * M[k][j]
            M[i][k] = 0
    X = [0] * n
    for i in range(n-1, -1, -1):
        X[i] = M[i][n]
        for k in range(n-1, i, -1):
            X[i] -= M[i][k] * X[k]
    return X


def seidel():
    pass

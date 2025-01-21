#ifndef SLAE_H
#define SLAE_H

#include <vector>

std::vector<std::vector<double>> augmentedMatrixRequest();

double precisionRequest();

std::vector<double> gauss(std::vector<std::vector<double>>& matrix);

std::vector<double> seidel(std::vector<std::vector<double>>& matrix, const double& eps = 0.001); // eps - precision

#endif //SLAE_H

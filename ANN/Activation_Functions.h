#ifndef ACTIVATION_H_
#define ACTIVATION_H_

#include "matrix.h"
#include <functional>
#include <map>

double sigmoid(const double param);
double sigmoid_derivative(const double param);

double tan_h(const double param);
double tanh_derivative(const double param);

double leaky_relu(const double param);
double leaky_relu_derivative(const double param);

double swish(const double param);
double swish_derivative(const double param);

Matrix<double> Activation_Function(const std::string &string, const Matrix<double> &matrix);

#endif
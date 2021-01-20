#include "Activation_Functions.h"
using namespace System;
using namespace System::Windows::Forms;

double sigmoid(const double param) {
	return (2 / (1.0 + exp(-param))) - 1;
}

double sigmoid_derivative(const double param) {
	return 0.5*(1 - pow(sigmoid(param), 2));
}

double tan_h(const double param) {
	return (1.0 - exp(-2 * param)) / (1.0 + exp(-2 * param));
}

double tanh_derivative(const double param) {
	return (1 + tan_h(param))*(1 - tan_h(param));
}

double leaky_relu(const double param) {
	return (param <= 0 ? 0.01*param : param);
}

double leaky_relu_derivative(const double param) {
	return (param <= 0 ? 0.01 : 1);
}

double swish(const double param) {
	return param * sigmoid(param);
}

double swish_derivative(const double param) {
	return swish(param) + (sigmoid(param)*(1 - swish(param)));
}


Matrix<double> Activation_Function(const std::string &string, const Matrix<double> &matrix) {
	std::map<std::string, std::function<double(double)>> func_type =
	{
		{ "sigmoid", sigmoid},
		{"sigmoid_derivative", sigmoid_derivative},
		{"leaky_relu", leaky_relu},
		{"leaky_relu_derivative", leaky_relu_derivative},
		{"tanh", tan_h},
		{"tanh_derivative", tanh_derivative},
		{"swish", swish},
		{"swish_derivative", swish_derivative}
	};

	Matrix<double> Result(matrix.get_Row(), matrix.get_Column());
	for (int i = 0; i < matrix.get_Row(); i++) {
		for (int j = 0; j < matrix.get_Column(); j++) {
			Result.set_Element(i, j, func_type[string](matrix.get_Element(i, j)));
		}
	}
	return Result;
}




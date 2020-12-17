#ifndef ANN_H_
#define ANN_H_

#include "matrix.h"
#include <string>
#include "Activation_Functions.h"


struct Sample {
	std::vector<double> X;
	int class_id;
};

class ANN {
public:
	ANN();
	virtual ~ANN();

	void create_Network(int no_features, std::vector<int> hidden_layers, int n_classes, double learning_rate, double bias, std::string activation_type);
	void initialize_weights();
	void Feed_Forward(Sample Data);
	void Back_Propagate(Matrix<double> desired_output);
	void Back_Propagate_momentum(Matrix<double> desired_output);
	double quadratic_Cost(const Matrix<double> &true_output, const Matrix<double> &predict_output);

	Matrix<double> get_layer(int l);
	Matrix<double> get_output_layer();
	double **get_hidden_layer_equations(int nth_hidden_layer);
	double get_biases();
	double get_learning_rate();

	void print_Layers();
	void print_Weights();
	void print_Biases();
	void list_equations();

	void load_network(std::string filename);
	void save_network(std::string filename);

private:
	//Network Data
	Matrix<double> *layers;	//including input and output
	Matrix<double> *weights;
	Matrix<double> *biases;
	Matrix<double> *layers_error;
	Matrix<double> *delta_weights;
	Matrix<double> *delta_biases;



	int no_layers;
	int no_weights;
	int no_classes;
	int no_features;
	double learning_rate;
	double Bias;
	std::string activation_type;
};

#endif
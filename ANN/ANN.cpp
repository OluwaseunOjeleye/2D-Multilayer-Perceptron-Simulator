#include "ANN.h"

ANN::ANN() {

}

void ANN::create_Network(int no_features, std::vector<int> hidden_layers, int n_classes, double learning_rate, double bias, std::string hidden_activation_type, std::string output_activation_type) {
	this->no_layers = hidden_layers.size() + 2;
	this->no_weights = no_layers - 1;
	this->no_classes = n_classes;
	this->no_features = no_features;
	this->learning_rate = learning_rate;
	this->Bias = bias;
	this->hidden_activation_type = hidden_activation_type;
	this->output_activation_type = output_activation_type;

	/******* Creating Network *******/
	//initializing layers
	this->layers = new Matrix<double>[no_layers];
	//Creating H0-input
	layers[0].resize(no_features, 1);
	//Creating hidden layers
	for (int i = 0; i < hidden_layers.size(); i++) {
		layers[i + 1].resize(hidden_layers[i], 1);
	}
	//Creating Hn-output
	layers[no_layers - 1].resize(no_classes, 1);

	//Creating weights
	this->weights = new Matrix<double>[no_weights];
	weights[0].resize(hidden_layers[0], no_features); //resizing W0
	for (int i = 1; i < no_weights - 1; i++) {
		weights[i].resize(hidden_layers[i], hidden_layers[i - 1]);
	}
	weights[no_weights - 1].resize(no_classes, hidden_layers[no_weights - 2]);

	//Creating biases 
	this->biases = new Matrix<double>[no_weights];
	for (int i = 0; i < no_weights - 1; i++) {
		biases[i].resize(hidden_layers[i], 1);
	}
	biases[no_weights - 1].resize(no_classes, 1);

	//creating layers' error
	this->layers_error = new Matrix<double>[no_weights];
	for (int i = 0; i < no_weights - 1; i++) {
		layers_error[i].resize(hidden_layers[i], 1);
	}
	layers_error[no_weights - 1].resize(no_classes, 1);

	//creating change in weights
	this->delta_weights = new Matrix<double>[no_weights];
	for (int i = 0; i < no_weights; i++) {
		delta_weights[i].resize(layers_error[i].get_Row(), layers[i].get_Row());
		delta_weights[i].set_All_Elements(0);
	}

	//creating change in biases
	this->delta_biases= new Matrix<double>[no_weights];
	for (int i = 0; i < no_weights; i++) {
		delta_biases[i].resize(layers_error[i].get_Row(), layers_error[i].get_Column());
		delta_biases[i].set_All_Elements(0);
	}
}

//Initializing weights and biases
void ANN::initialize_weights() {
	//initializing weights
	weights[0].generate_Random_Elements();		//initializing W0
	for (int i = 1; i < no_weights - 1; i++) {
		weights[i].generate_Random_Elements();
	}
	weights[no_weights - 1].generate_Random_Elements();

	//initializing biases 
	for (int i = 0; i < no_weights - 1; i++) {
		biases[i].set_All_Elements(Bias);
	}
	biases[no_weights - 1].set_All_Elements(Bias);
}

ANN::~ANN() {

}

//Feed Forward for single sample
void ANN::Feed_Forward(Sample Data) {
	Matrix<double> X(Data.X);
	layers[0] = X.Transpose();	//feed forward input

	//Feed forwarding
	for (int i = 0; i < no_weights; i++) {
		if(i==no_weights-1){	//if error, check here
			layers[i + 1] = Activation_Function(output_activation_type, (weights[i] * layers[i]) + biases[i]);
		}
		else{
			layers[i + 1] = Activation_Function(hidden_activation_type, (weights[i] * layers[i]) + biases[i]);
		}
	}
}

// Back Propagation
void ANN::Back_Propagate(Matrix<double> desired_output, bool momentum) {
	for (int i = no_weights - 1; i >= 0; i--) {
		if (i == no_weights - 1) {			//last layer's error (Output error)
			layers_error[i] = (desired_output - layers[i + 1]).hadamard_Product(Activation_Function(output_activation_type +"_derivative", (weights[i] * layers[i]) + biases[i]));
		}
		else {
			layers_error[i] = (weights[i + 1].Transpose()*layers_error[i + 1]).hadamard_Product(Activation_Function(hidden_activation_type + "_derivative", (weights[i] * layers[i]) + biases[i]));
		}

		Matrix<double> delta_weight = (layers_error[i] * layers[i].Transpose()); //current delta weight
		Matrix<double> delta_bias = layers_error[i];	//current delta bias

		double beta = momentum? 0.9: 0;	//with momentum is 0.9 else 0
		
		delta_weights[i] = (delta_weights[i]*beta)  + (delta_weight*(1 - beta));	//90%old weight + 10%new weight
		weights[i] = weights[i] + (delta_weights[i]*learning_rate);

		delta_biases[i] = delta_bias * learning_rate;
		biases[i] = biases[i] + (delta_bias * learning_rate);
	}
}

//Calculating error
double ANN::quadratic_Cost(const Matrix<double> &true_output, const Matrix<double> &predict_output) {
	double cost = 0;
	Matrix<double> result = (predict_output - true_output) ^ 2;
	for (int i = 0; i < result.get_Row(); i++) {
		for (int j = 0; j < result.get_Column(); j++) {
			cost += result.get_Element(i, j);
		}
	}
	return cost * 0.5;
}

void ANN::load_network(std::string filename) {
	try {
		std::ifstream inData(filename, std::ios::in);
		if (!inData) throw std::ios::failure("Error opening file!");

		std::vector<int> layers_vec;
		std::vector<Matrix<double>> weights_vec;
		std::vector<Matrix<double>> biases_vec;

		std::string line;
		int weight = 0, bias = 0, c_layers = 0;
		while (getline(inData, line)) {
			if (line == ("Layer " + std::to_string(c_layers))) {
				int layers;
				inData >> layers;
				layers_vec.push_back(layers);
				c_layers++;
			}
			else if (line == "Hidden Layer Activation Function:") {
				inData >> this->hidden_activation_type;
			}
			else if (line == "Output Layer Activation Function:") {
				inData >> this->output_activation_type;
			}
			else if (line == "Learning Rate:") {
				inData >> this->learning_rate;
			}
			else if (line == ("Weight " + std::to_string(weight))) {
				Matrix<double> matrix;
				inData >> matrix;
				weights_vec.push_back(matrix);
				weight++;
			}
			else if (line == ("Bias " + std::to_string(bias))) {
				Matrix<double> matrix;
				inData >> matrix;
				biases_vec.push_back(matrix);
				bias++;
			}
			else {}
		}
		inData.close();

		/******* Creating Network *******/
		this->no_layers = layers_vec.size();
		this->no_weights = weights_vec.size();
		this->no_features = layers_vec[0];
		this->no_classes = layers_vec[no_layers - 1];
		this->Bias = 1;

		//creating layers
		this->layers = new Matrix<double>[no_layers];
		layers[0].resize(no_features, 1);
		for (int i = 1; i < no_layers - 1; i++) {
			layers[i].resize(layers_vec[i], 1);
		}
		layers[no_layers - 1].resize(no_classes, 1);

		//weights
		this->weights = new Matrix<double>[no_weights];
		for (int i = 0; i < no_weights; i++) {
			weights[i] = weights_vec[i];
		}

		//biases 
		this->biases = new Matrix<double>[no_weights];
		for (int i = 0; i < no_weights; i++) {
			biases[i] = biases_vec[i];
		}

		//creating layers' error
		this->layers_error = new Matrix<double>[no_weights];
		for (int i = 0; i < no_weights - 1; i++) {
			layers_error[i].resize(layers_vec[i + 1], 1);
		}
		layers_error[no_weights - 1].resize(no_classes, 1);

		//creating change in weights
		this->delta_weights = new Matrix<double>[no_weights];
		for (int i = 0; i < no_weights; i++) {
			delta_weights[i].resize(layers_error[i].get_Row(), layers[i].get_Row());
			delta_weights[i].set_All_Elements(0);
		}

		//creating change in biases
		this->delta_biases = new Matrix<double>[no_weights];
		for (int i = 0; i < no_weights; i++) {
			delta_biases[i].resize(layers_error[i].get_Row(), layers_error[i].get_Column());
			delta_biases[i].set_All_Elements(0);
		}
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void ANN::save_network(std::string filename) {
	std::ofstream outData;
	outData.open(filename);

	for (int i = 0; i < this->no_layers; i++) {
		outData << "Layer " << i << std::endl;
		outData << layers[i].get_Row() << std::endl;
	}
	outData << std::endl;

	outData << "Hidden Layer Activation Function:" << std::endl;
	outData << hidden_activation_type << std::endl << std::endl;
	outData << "Output Layer Activation Function:" << std::endl;
	outData << output_activation_type << std::endl << std::endl;
	outData << "Learning Rate:" << std::endl;
	outData << learning_rate << std::endl << std::endl;

	//Saving all weights
	for (int i = 0; i < this->no_weights; i++) {
		outData << "Weight " << i << std::endl;
		outData << weights[i];
		outData << std::endl;
	}

	//Saving all biases
	for (int i = 0; i < this->no_weights; i++) {
		outData << "Bias " << i << std::endl;
		outData << this->biases[i];
		outData << std::endl;
	}
	outData.close();
}

Matrix<double> ANN::get_layer(int l) {
	return layers[l];
}

Matrix<double> ANN::get_output_layer() {
	return get_layer(no_layers - 1);
}

double ANN::get_biases() {
	return Bias;
}

double ANN::get_learning_rate() {
	return learning_rate;
}

int ANN::get_no_Hidden_layers() {
	return no_layers-2;
}

void ANN::print_Layers() {
	std::cout << "layers: " << std::endl;
	for (int i = 0; i < no_layers; i++) {
		layers[i].print();
	}
}

void ANN::print_Weights() {
	std::cout << "weights: " << std::endl;
	for (int i = 0; i < no_weights; i++) {
		weights[i].print();
	}
}

void ANN::print_Biases() {
	std::cout << "biases: " << std::endl;
	for (int i = 0; i < no_weights; i++) {
		biases[i].print();
	}
}

//This function is only for simulator
void ANN::list_equations() {
	std::cout << layers[0].get_Row() << " inputs, one hidden layer with " << layers[1].get_Row() << " neurons(lines to divide graph) and " << layers[2].get_Row() << " outputs" << std::endl;
	std::cout << "Lines are: " << std::endl;

	for (int i = 0; i < weights[0].get_Row(); i++) {
		std::cout << "eqn " << i << ": " << weights[0].get_Element(i, 0) << "x + " << weights[0].get_Element(i, 1) << "y + " << biases[0].get_Element(i, 0) << "= 0" << std::endl;
	}
}

double **ANN::get_hidden_layer_equations(int nth_hidden_layer) {
	double **weight;
	int pos = nth_hidden_layer - 1;
	weight = new double*[weights[pos].get_Row()];
	for (int i = 0; i < weights[pos].get_Row(); i++) {
		weight[i] = new double[weights[pos].get_Column()+1]; //add 1 for bias value
	}

	for (int i = 0; i < weights[pos].get_Row(); i++) {
		for (int j = 0; j < weights[pos].get_Column(); j++) {
			weight[i][j] = weights[pos].get_Element(i, j);
		}
		weight[i][weights[pos].get_Column()] = biases[pos].get_Element(i, 0); //adding bias to last column of matrix
	}
	return weight;
}


void ANN::set_Hidden_Activation_Function(std::string hidden_activation_type){
	this->hidden_activation_type = hidden_activation_type;
}

void ANN::set_Output_Activation_Function(std::string output_activation_type){
	this->output_activation_type = output_activation_type;
}


#include "MyForm.h"

//Initializer
void Simulator::MyForm::Initialize() {
	color = gcnew array<Color>(10);
	color[0] = Color::Red; color[1] = Color::Green; color[2] = Color::Blue; color[3] = Color::Brown; color[4] = Color::Cyan;
	color[5] = Color::Yellow; color[6] = Color::Indigo; color[7] = Color::Purple; color[8] = Color::Firebrick; color[9] = Color::OrangeRed;

	Test_Sample_Size = 4;
	Test_Output = new int[((pictureBox1->Width / Test_Sample_Size) + 1)*((pictureBox1->Height/ Test_Sample_Size)+1)];

	comboBox1->DropDownStyle = ComboBoxStyle::DropDownList;
	comboBox2->DropDownStyle = ComboBoxStyle::DropDownList;
	comboBox3->DropDownStyle = ComboBoxStyle::DropDownList;
	comboBox4->DropDownStyle = ComboBoxStyle::DropDownList;


	for (int i = 2; i <= 10; i++) comboBox1->Items->Add(i.ToString());

	comboBox3->Items->Add("Bipolar Sigmoid");
	comboBox3->Items->Add("Tanh");
	comboBox3->Items->Add("Leaky ReLu");
	comboBox3->Items->Add("Swish");

	comboBox4->Items->Add("Bipolar Sigmoid");
	comboBox4->Items->Add("Tanh");
	comboBox4->Items->Add("Leaky ReLu");
	comboBox4->Items->Add("Swish");

	no_samples = 0;
	no_classes = 0;
	trained = false;
	test_state = false;

	Mean_x = 0; Mean_y = 0;
	Std_x = 1; Std_y = 1;
	//trackbar_scale = 0;
}

//Drawing Lines and Samples
void Simulator::MyForm::Draw_Samples() {
	//drawing samples
	Graphics ^graphics = pictureBox1->CreateGraphics();
	for (int i = 0; i < no_samples; i++) {
		SolidBrush ^brush = gcnew SolidBrush(color[Data[i].class_id]);
		graphics->FillRectangle(brush, (pictureBox1->Width / 2) + Data[i].X[0], (pictureBox1->Height / 2) - Data[i].X[1], 3, 3);
	}
}

void Simulator::MyForm::Draw_Lines() {
	//drawing lines
	Graphics ^graphics = pictureBox1->CreateGraphics();
	for (int i = 0; i < first_HL_no_neurons; i++) {
		Pen ^pen = gcnew Pen(color[i]);
		double w1 = weight[i][0];
		double w2 = weight[i][1];
		double w3 = weight[i][2];

		//normalizing data
		double x1 = ((double)(pictureBox1->Width / -2) - Mean_x) / Std_x;
		double x2 = ((double)(pictureBox1->Width / 2) - Mean_x) / Std_x;

		double y1 = (-(w1 *x1) - (Bias*w3)) / w2;
		double y2 = (-(w1 *x2) - (Bias*w3)) / w2;

		//denormalization of data
		y1 = (y1*Std_y) + Mean_y;
		y2 = (y2*Std_y) + Mean_y;

		graphics->DrawLine(pen, 0, (pictureBox1->Height - y1) - (pictureBox1->Height / 2), pictureBox1->Width, (pictureBox1->Height - y2) - (pictureBox1->Height / 2));
	}
}

//Adding new sample
void Simulator::MyForm::Add_Sample(int selected_class, int x, int y) {
	//drawing samples
	Graphics ^graphics = pictureBox1->CreateGraphics();
	SolidBrush ^brush = gcnew SolidBrush(color[selected_class]);
	graphics->FillRectangle(brush, x, y, 3, 3);

	Sample *temp;
	temp = Data;
	no_samples++;
	Data = new Sample[no_samples];

	//adding old elements
	for (int i = 0; i < no_samples - 1; i++) {
		Data[i].class_id = temp[i].class_id;
		Data[i].X = temp[i].X;
	}

	//adding new sample
	Data[no_samples - 1].X.push_back(x - (pictureBox1->Width / 2));
	Data[no_samples - 1].X.push_back((pictureBox1->Height / 2) - y);
	Data[no_samples - 1].class_id = selected_class;

	//Training Data
	Train_Data = new Sample[no_samples];
	for (int i = 0; i < no_samples; i++) {
		Train_Data[i] = Data[i];
	}
}

std::string Simulator::MyForm::get_Activation_Function_GUI(int SelectedIndex){
	switch (SelectedIndex) {
		case 0:
			return "sigmoid";
			break;

		case 1:
			return "tanh";
			break;

		case 2:
			return "leaky_relu";
			break;

		case 3:
			return "swish";
			break;

		default:
			return "sigmoid";
	}
}

System::Void Simulator::MyForm::randomToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	std::string layers_text = msclr::interop::marshal_as<std::string>(this->textBox3->Text);
	std::vector<int> hidden_layers;
	std::stringstream stream(layers_text);
	int n;
	while (stream >> n) {
			hidden_layers.push_back(n);
	}
	this->first_HL_no_neurons = hidden_layers[0];

	this->no_classes = no_classes;
	this->no_features = Data[0].X.size();
	this->learning_rate = Convert::ToDouble(this->textBox1->Text);
	this->Bias = Convert::ToDouble(this->textBox2->Text);
	this->trained = true;

	std::string hidden_activation_type=get_Activation_Function_GUI(this->comboBox3->SelectedIndex);
	std::string output_activation_type=get_Activation_Function_GUI(this->comboBox4->SelectedIndex);

	//Creating Network
	this->network = new ANN();
	this->network->create_Network(no_features, hidden_layers, no_classes, learning_rate, Bias, hidden_activation_type, output_activation_type);
	//initializing weights and bias
	this->network->initialize_weights();

	weight = network->get_hidden_layer_equations(1);
	pictureBox1->Refresh();
	Draw_Lines(); Draw_Samples();

}

//Batch Normalization Of Data
void Simulator::MyForm::BatchNormalize() {
	//calculating mean for x1...xn
	std::vector<double> mean(no_features, 0);
	for (int i = 0; i < no_samples; i++) {
		for (int j = 0; j < no_features; j++) {
			mean[j]+=Data[i].X[j];
		}
	}
	for (int j = 0; j < no_features; j++) {
		mean[j]/=no_samples;
	}

	//calculating variance
	std::vector<double> variance(no_features, 0);
	for (int i = 0; i < no_samples; i++) {
		for (int j = 0; j <no_features; j++) {
			variance[j] += pow(Data[i].X[j]-mean[j], 2);
		}
	}
	for (int j = 0; j < no_features; j++) {
		variance[j]= sqrt(variance[j]/no_samples);
	}

	//normalizing data
	for (int i = 0; i < no_samples; i++) {
		for (int j = 0; j < no_features; j++) {
			Train_Data[i].X[j]= (Data[i].X[j]-mean[j])/variance[j];
		}
	}
	Mean_x = mean[0]; Mean_y = mean[1];
	Std_x = variance[0]; Std_y = variance[1];
}

//Training
void Simulator::MyForm::Training(bool with_momentum){
	int n_cycles = 0; double error;
	if (checkBox1->Checked == true) {
		this->BatchNormalize();
	}
	if(!trained){
		network->set_Hidden_Activation_Function(get_Activation_Function_GUI(this->comboBox3->SelectedIndex));
		network->set_Output_Activation_Function(get_Activation_Function_GUI(this->comboBox4->SelectedIndex));
	}

	this->chart1->Series[0]->Points->Clear();
	trained = true;
	while (1) {
		error = 0;
		for (int c = 0; c < no_samples; c++) {
			//feed_forwarding input X
			network->Feed_Forward(Train_Data[c]);

			//setting desired output into matrix
			std::vector<double> d;
			for (int i = 0; i < no_classes; i++) Train_Data[c].class_id == i ? d.push_back(1) : d.push_back(0);
			Matrix<double> desired_output(d);
			desired_output = desired_output.Transpose();

			//calculating error
			error += network->quadratic_Cost(desired_output, network->get_output_layer());

			//backpropagation
			network->Back_Propagate(desired_output, with_momentum);
			weight=network->get_hidden_layer_equations(1); //get first hidden layer equation W and B
		}

		n_cycles++;
		this->label4->Text = "no of cycles: " + n_cycles.ToString();
		this->label4->Refresh();

		pictureBox1->Refresh();
		this->label8->Text = "Error: " + error.ToString();
		this->label8->Refresh();
		std::cout << "no cycles=" << n_cycles << " error=" << error << std::endl;

		this->chart1->Series["Series1"]->Points->AddXY((double)n_cycles/1000, error);
		if (n_cycles < 500 || n_cycles % 500 == 0) this->chart1->Refresh();

		if (error <= 0.01) {
			break;
		}
	}
	Draw_Lines(); Draw_Samples();
	this->chart1->Refresh();
}

//Continuous (Multilayer Delta Learning)
System::Void Simulator::MyForm::continuousToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Training(false);
}

//Training- Continuous with momentum
System::Void Simulator::MyForm::continuousWithMomentToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Training(true);
}

//Classifier
System::Void Simulator::MyForm::testToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	test_state = true;

	if (checkBox1->Checked == true) {
		this->BatchNormalize();
	}

	int i = 0;
	for (int x = 0; x < pictureBox1->Width; x += Test_Sample_Size) {
		for (int y = 0; y < pictureBox1->Height; y += Test_Sample_Size) {
			double test_x = x + (Test_Sample_Size/2);
			double test_y = y + (Test_Sample_Size/2);

			//Converting to graph scale
			test_x = test_x - (pictureBox1->Width / 2);
			test_y = (pictureBox1->Height / 2) - test_y;

			//normalizing data
			test_x = ((double)(test_x) - Mean_x) / Std_x;
			test_y = ((double)(test_y) - Mean_y) / Std_y;

			Sample data;
			data.X.push_back(test_x); data.X.push_back(test_y); data.class_id = 0;

			network->Feed_Forward(data);
			Matrix<double> output_layer = network->get_output_layer();
			int index;
			for (index = 0; index < no_classes; index++) {
				if (output_layer.get_Element(index, 0) >= 0.7) break;
			}
			Test_Output[i] = index;
			i++;
		}
	}
	//MessageBox::Show("Done");
	pictureBox1->Refresh();
}

//Load network and data from file
System::Void Simulator::MyForm::loadDataToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//creating new network;
	const char *filename="data";
	
	System::IO::DirectoryInfo^ info = gcnew System::IO::DirectoryInfo(System::IO::Directory::GetCurrentDirectory());
	msclr::interop::marshal_context ^ context = gcnew msclr::interop::marshal_context();
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		filename = context->marshal_as<const char*>(openFileDialog1->FileName);
	}
	
	network = new ANN();
	network->load_network(filename);

	//loading member data to simulator
	weight = network->get_hidden_layer_equations(1);
	this->first_HL_no_neurons = network->get_layer(1).get_Row();
	this->no_classes = network->get_output_layer().get_Row();
	this->no_features = network->get_layer(0).get_Row();
	this->learning_rate = network->get_learning_rate();
	this->Bias = network->get_biases();
	this->trained = false;

	for (int i = 1; i <= network->get_no_Hidden_layers(); i++) {
		this->textBox3->Text+= Convert::ToString(network->get_layer(i).get_Row()) + " ";
	}

	this->textBox1->Text= Convert::ToString(this->learning_rate);
	this->textBox2->Text= Convert::ToString(this->Bias);
	comboBox1->SelectedIndex = this->no_classes-2;

	//loading samples in file to initial variable
	try {
		std::ifstream inData(filename, std::ios::in);
		if (!inData) throw std::ios::failure("Error opening file!");

		std::vector<Sample> samples_vec;

		std::string line;
		int weight = 0, bias = 0, c_layers = 0;
		while (getline(inData, line)) {
			if (line == "Samples:") {
				int n_samples;
				inData >> n_samples;
				samples_vec.resize(n_samples);
				for (int i = 0; i < n_samples; i++) {
					int x, y, id; 
					inData >> x; samples_vec[i].X.push_back(x);
					inData >> y; samples_vec[i].X.push_back(y);
					inData >> id; samples_vec[i].class_id=id;
				}
			}
			else {}
		}
		inData.close();

		//load samples to sample array
		this->no_samples = samples_vec.size();
		this->Data = new Sample[no_samples];
		this->Train_Data = new Sample[no_samples];
		for (int i = 0; i < no_samples; i++) {
			Data[i] = samples_vec[i];
			Train_Data[i] = samples_vec[i];
		}

		pictureBox1->Refresh();
		Draw_Lines(); Draw_Samples();
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

//Save data and network from file
System::Void Simulator::MyForm::saveDataToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//Saving network in file
	network->save_network("data");

	//Saving Samples
	std::ofstream outData;
	outData.open("data", std::ios_base::app);

	outData << "Samples:" << std::endl;
	outData <<no_samples<< std::endl;
	for (int i = 0; i < no_samples; i++) {
		for (int j = 0; j < Data[i].X.size(); j++) {
			outData << Data[i].X[j] << " ";
		}
		outData << Data[i].class_id << std::endl;
	}
}
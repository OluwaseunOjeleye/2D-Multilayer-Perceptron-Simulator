#pragma once

#include <Windows.h>
#include <atlstr.h>
#include <vector>
#include <random>
#include <time.h>
#include "Activation_Functions.h"
#include "ANN.h"

namespace Simulator {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			//initializer for member data
			Initialize();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  processToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  trainingToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  continuousToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  initializingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  randomToolStripMenuItem;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::ToolStripMenuItem^  clearToolStripMenuItem;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::ToolStripMenuItem^  testingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  testToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadDataToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveDataToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  continuousWithMomentToolStripMenuItem;

	protected:


	

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->initializingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->randomToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->continuousToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->continuousWithMomentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(18, 43);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(800, 800);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(978, 54);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(100, 28);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedValueChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(828, 57);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(107, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"No of Classes";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(825, 107);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(150, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Select class to draw";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(981, 104);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(97, 28);
			this->comboBox2->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(884, 493);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 20);
			this->label3->TabIndex = 3;
			this->label3->Text = L"label3";
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->processToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1102, 33);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// processToolStripMenuItem
			// 
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->loadDataToolStripMenuItem,
					this->saveDataToolStripMenuItem, this->initializingToolStripMenuItem, this->trainingToolStripMenuItem, this->testingToolStripMenuItem,
					this->clearToolStripMenuItem
			});
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(84, 29);
			this->processToolStripMenuItem->Text = L"Process";
			// 
			// loadDataToolStripMenuItem
			// 
			this->loadDataToolStripMenuItem->Name = L"loadDataToolStripMenuItem";
			this->loadDataToolStripMenuItem->Size = System::Drawing::Size(252, 30);
			this->loadDataToolStripMenuItem->Text = L"Load Data";
			this->loadDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::loadDataToolStripMenuItem_Click);
			// 
			// saveDataToolStripMenuItem
			// 
			this->saveDataToolStripMenuItem->Name = L"saveDataToolStripMenuItem";
			this->saveDataToolStripMenuItem->Size = System::Drawing::Size(252, 30);
			this->saveDataToolStripMenuItem->Text = L"Save Data";
			this->saveDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveDataToolStripMenuItem_Click);
			// 
			// initializingToolStripMenuItem
			// 
			this->initializingToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->randomToolStripMenuItem });
			this->initializingToolStripMenuItem->Name = L"initializingToolStripMenuItem";
			this->initializingToolStripMenuItem->Size = System::Drawing::Size(252, 30);
			this->initializingToolStripMenuItem->Text = L"Initializing";
			// 
			// randomToolStripMenuItem
			// 
			this->randomToolStripMenuItem->Name = L"randomToolStripMenuItem";
			this->randomToolStripMenuItem->Size = System::Drawing::Size(164, 30);
			this->randomToolStripMenuItem->Text = L"Random";
			this->randomToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::randomToolStripMenuItem_Click);
			// 
			// trainingToolStripMenuItem
			// 
			this->trainingToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->continuousToolStripMenuItem,
					this->continuousWithMomentToolStripMenuItem
			});
			this->trainingToolStripMenuItem->Name = L"trainingToolStripMenuItem";
			this->trainingToolStripMenuItem->Size = System::Drawing::Size(252, 30);
			this->trainingToolStripMenuItem->Text = L"Training";
			// 
			// continuousToolStripMenuItem
			// 
			this->continuousToolStripMenuItem->Name = L"continuousToolStripMenuItem";
			this->continuousToolStripMenuItem->Size = System::Drawing::Size(298, 30);
			this->continuousToolStripMenuItem->Text = L"Continuous";
			this->continuousToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::continuousToolStripMenuItem_Click);
			// 
			// testingToolStripMenuItem
			// 
			this->testingToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->testToolStripMenuItem });
			this->testingToolStripMenuItem->Name = L"testingToolStripMenuItem";
			this->testingToolStripMenuItem->Size = System::Drawing::Size(252, 30);
			this->testingToolStripMenuItem->Text = L"Testing";
			// 
			// testToolStripMenuItem
			// 
			this->testToolStripMenuItem->Name = L"testToolStripMenuItem";
			this->testToolStripMenuItem->Size = System::Drawing::Size(126, 30);
			this->testToolStripMenuItem->Text = L"Test";
			this->testToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::testToolStripMenuItem_Click);
			// 
			// clearToolStripMenuItem
			// 
			this->clearToolStripMenuItem->Name = L"clearToolStripMenuItem";
			this->clearToolStripMenuItem->Size = System::Drawing::Size(252, 30);
			this->clearToolStripMenuItem->Text = L"Clear";
			this->clearToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::clearToolStripMenuItem_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(884, 536);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 20);
			this->label4->TabIndex = 6;
			this->label4->Text = L"label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(825, 197);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(110, 20);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Learning Rate";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(825, 240);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(40, 20);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Bias";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(978, 191);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 26);
			this->textBox1->TabIndex = 8;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(978, 234);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 26);
			this->textBox2->TabIndex = 8;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(825, 281);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->checkBox1->Size = System::Drawing::Size(177, 24);
			this->checkBox1->TabIndex = 9;
			this->checkBox1->Text = L"Batch Normalization";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(832, 621);
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(260, 69);
			this->trackBar1->TabIndex = 10;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(978, 382);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(100, 28);
			this->comboBox3->TabIndex = 11;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(828, 390);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(144, 20);
			this->label7->TabIndex = 7;
			this->label7->Text = L"Activation Function";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(884, 577);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(51, 20);
			this->label8->TabIndex = 6;
			this->label8->Text = L"label8";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(825, 154);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(111, 20);
			this->label9->TabIndex = 7;
			this->label9->Text = L"No of Neurons";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(978, 148);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 26);
			this->textBox3->TabIndex = 8;
			// 
			// continuousWithMomentToolStripMenuItem
			// 
			this->continuousWithMomentToolStripMenuItem->Name = L"continuousWithMomentToolStripMenuItem";
			this->continuousWithMomentToolStripMenuItem->Size = System::Drawing::Size(298, 30);
			this->continuousWithMomentToolStripMenuItem->Text = L"Continuous with Moment";
			this->continuousWithMomentToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::continuousWithMomentToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1102, 863);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"MyForm";
			this->Text = L"Multilayer Perceptron Simulator";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		/*******************************Member Data**************************************/
		ANN *network;

		array<Color> ^color;
		Sample *Data;
		Sample *Train_Data;
		int no_samples;

		int no_features;
		int no_neurons; //number of neuron per first hidden layer
		int no_classes;

		double **weight;
		double learning_rate;
		double Bias;
		bool trained;

		//normalization data;
		int Mean_x, Mean_y, Std_x, Std_y;

		int trackbar_scale;

		/*******************************Member Methods**************************************/
		//Initialize
		void Initialize();

		//Creating Network and Initializing weights
		System::Void randomToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		
		//Drawing lines and samples
		void Draw_Lines_n_samples();

		//Adding new sample
		void Add_Sample(int selected_class, int x, int y);

		//Batch-Normalization
		void BatchNormalize();

		//Continuous (Multilayer Delta Learning Rule)
		System::Void continuousToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void continuousWithMomentToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

		//Testing
		System::Void testToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

		//load Data
		System::Void loadDataToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

		//save Data
		System::Void saveDataToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

		// Form Methods
		//Painting PictureBox
		System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			Pen ^pen = gcnew Pen(Color::Black);
			e->Graphics->DrawLine(pen, 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height / 2);
			e->Graphics->DrawLine(pen, pictureBox1->Width / 2, 0, pictureBox1->Width / 2, pictureBox1->Height);

			for (int i = 0; i < pictureBox1->Width; i = i + 50) {
				e->Graphics->DrawString((i - (pictureBox1->Width / 2)).ToString(), gcnew System::Drawing::Font("Arial", 6), Brushes::Black, i, pictureBox1->Height / 2);
			}

			for (int i = 0; i < pictureBox1->Height; i = i + 50) {
				e->Graphics->DrawString(((pictureBox1->Height / 2) - i).ToString(), gcnew System::Drawing::Font("Arial", 6), Brushes::Black, pictureBox1->Width / 2, i);
			}

			Draw_Lines_n_samples();
		}

		//when picturebox is clicked
		System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			if (comboBox2->SelectedIndex == -1) {
				return;
			}
			int selected_class = comboBox2->SelectedIndex;
			Add_Sample(selected_class, e->X, e->Y);
		}

		//when mouse is moved
		System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			label3->Text = "(" + (e->X - (pictureBox1->Width / 2)).ToString() + ", " + ((pictureBox1->Height / 2) - e->Y).ToString() + ")";
		}

		//when combobox1 value is changed 
		System::Void comboBox1_SelectedValueChanged(System::Object^  sender, System::EventArgs^  e) {
			if (comboBox1->SelectedIndex == -1) {
				return;
			}
			comboBox2->Items->Clear();
			no_classes = comboBox1->SelectedIndex + 2;
			for (int i = 1; i <= no_classes; i++) comboBox2->Items->Add(i.ToString());
		}

		System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
			bool increase = (trackBar1->Value > trackbar_scale) ? true : false;
			int rate = 2;
			for (int i = 0; i < no_samples; i++) {
				for (int j = 0; j < no_features; j++) {
					Data[i].X[j] = increase ? Data[i].X[j] * rate : Data[i].X[j] / rate;
				}
			}
			if (trained) {
				for (int i = 0; i < no_classes; i++) {
					weight[i][no_features] = increase ? weight[i][no_features] * rate : weight[i][no_features] / rate;
				}
			}
			trackbar_scale=trackBar1->Value;
			pictureBox1->Refresh();
			Draw_Lines_n_samples();
		}

		void clear_Data() {
			for (int i = 0; i < this->no_neurons; i++) {
				delete weight[i];
			}
			delete weight;

			for (int i = 0; i < this->no_samples; i++) {
				Data[i].X.clear();
				Train_Data[i].X.clear();
			}
			if (Data != NULL) Data = NULL;
			if (Train_Data != NULL) Train_Data = NULL;
			if (network != NULL) delete network;


			no_samples = 0;
			no_classes = 0;
			no_features = 0;
			no_neurons = 0;

			learning_rate = 0;
			Bias = 1;
			trained = false;

			Mean_x = 0; Mean_y = 0;
			Std_x = 1; Std_y = 1;

			trackbar_scale = 0;


			pictureBox1->Refresh();

			comboBox1->SelectedIndex = -1;
			comboBox2->SelectedIndex = -1;
			comboBox3->SelectedIndex = -1;

			checkBox1->Checked = false;

			textBox1->Text = "";
			textBox2->Text = "";

			label3->Text = "";
			label4->Text = "";
			label8->Text = "";

		}

		System::Void clearToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			clear_Data();
		}

};
}

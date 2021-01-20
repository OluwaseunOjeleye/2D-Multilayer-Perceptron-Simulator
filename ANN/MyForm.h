#pragma once

#include <Windows.h>
#include <sstream>
#include <atlstr.h>
#include <msclr\marshal_cppstd.h>
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
	using namespace System::Windows::Forms::DataVisualization::Charting;

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
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::ComboBox^  comboBox4;

	private: System::Windows::Forms::ToolStripMenuItem^  displayToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  showSamplesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  showLinesToolStripMenuItem1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;











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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
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
			this->continuousWithMomentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->displayToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showSamplesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showLinesToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->Location = System::Drawing::Point(15, 8);
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
			this->comboBox1->Location = System::Drawing::Point(151, 50);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(100, 28);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedValueChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(107, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"No of Classes";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(18, 47);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(150, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Select class to draw";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(174, 44);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(97, 28);
			this->comboBox2->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(78, 130);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(70, 26);
			this->label3->TabIndex = 3;
			this->label3->Text = L"label3";
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->processToolStripMenuItem,
					this->displayToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1453, 33);
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
			this->loadDataToolStripMenuItem->Size = System::Drawing::Size(177, 30);
			this->loadDataToolStripMenuItem->Text = L"Load Data";
			this->loadDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::loadDataToolStripMenuItem_Click);
			// 
			// saveDataToolStripMenuItem
			// 
			this->saveDataToolStripMenuItem->Name = L"saveDataToolStripMenuItem";
			this->saveDataToolStripMenuItem->Size = System::Drawing::Size(177, 30);
			this->saveDataToolStripMenuItem->Text = L"Save Data";
			this->saveDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveDataToolStripMenuItem_Click);
			// 
			// initializingToolStripMenuItem
			// 
			this->initializingToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->randomToolStripMenuItem });
			this->initializingToolStripMenuItem->Name = L"initializingToolStripMenuItem";
			this->initializingToolStripMenuItem->Size = System::Drawing::Size(177, 30);
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
			this->trainingToolStripMenuItem->Size = System::Drawing::Size(177, 30);
			this->trainingToolStripMenuItem->Text = L"Training";
			// 
			// continuousToolStripMenuItem
			// 
			this->continuousToolStripMenuItem->Name = L"continuousToolStripMenuItem";
			this->continuousToolStripMenuItem->Size = System::Drawing::Size(298, 30);
			this->continuousToolStripMenuItem->Text = L"Continuous";
			this->continuousToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::continuousToolStripMenuItem_Click);
			// 
			// continuousWithMomentToolStripMenuItem
			// 
			this->continuousWithMomentToolStripMenuItem->Name = L"continuousWithMomentToolStripMenuItem";
			this->continuousWithMomentToolStripMenuItem->Size = System::Drawing::Size(298, 30);
			this->continuousWithMomentToolStripMenuItem->Text = L"Continuous with Moment";
			this->continuousWithMomentToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::continuousWithMomentToolStripMenuItem_Click);
			// 
			// testingToolStripMenuItem
			// 
			this->testingToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->testToolStripMenuItem });
			this->testingToolStripMenuItem->Name = L"testingToolStripMenuItem";
			this->testingToolStripMenuItem->Size = System::Drawing::Size(177, 30);
			this->testingToolStripMenuItem->Text = L"Testing";
			// 
			// testToolStripMenuItem
			// 
			this->testToolStripMenuItem->Name = L"testToolStripMenuItem";
			this->testToolStripMenuItem->Size = System::Drawing::Size(181, 30);
			this->testToolStripMenuItem->Text = L"Show Area";
			this->testToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::testToolStripMenuItem_Click);
			// 
			// clearToolStripMenuItem
			// 
			this->clearToolStripMenuItem->Name = L"clearToolStripMenuItem";
			this->clearToolStripMenuItem->Size = System::Drawing::Size(177, 30);
			this->clearToolStripMenuItem->Text = L"Clear";
			this->clearToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::clearToolStripMenuItem_Click);
			// 
			// displayToolStripMenuItem
			// 
			this->displayToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->showSamplesToolStripMenuItem,
					this->showLinesToolStripMenuItem1
			});
			this->displayToolStripMenuItem->Name = L"displayToolStripMenuItem";
			this->displayToolStripMenuItem->Size = System::Drawing::Size(82, 29);
			this->displayToolStripMenuItem->Text = L"Display";
			// 
			// showSamplesToolStripMenuItem
			// 
			this->showSamplesToolStripMenuItem->Name = L"showSamplesToolStripMenuItem";
			this->showSamplesToolStripMenuItem->Size = System::Drawing::Size(212, 30);
			this->showSamplesToolStripMenuItem->Text = L"Show Samples";
			this->showSamplesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::showSamplesToolStripMenuItem_Click);
			// 
			// showLinesToolStripMenuItem1
			// 
			this->showLinesToolStripMenuItem1->Name = L"showLinesToolStripMenuItem1";
			this->showLinesToolStripMenuItem1->Size = System::Drawing::Size(212, 30);
			this->showLinesToolStripMenuItem1->Text = L"Show Lines";
			this->showLinesToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::showLinesToolStripMenuItem1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(17, 46);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(136, 22);
			this->label4->TabIndex = 6;
			this->label4->Text = L"No Of Cycles: 0";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(24, 140);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(110, 20);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Learning Rate";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(25, 183);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(40, 20);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Bias";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(151, 134);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 26);
			this->textBox1->TabIndex = 8;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(151, 177);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 26);
			this->textBox2->TabIndex = 8;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(22, 85);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->checkBox1->Size = System::Drawing::Size(177, 24);
			this->checkBox1->TabIndex = 9;
			this->checkBox1->Text = L"Batch Normalization";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(151, 241);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(100, 28);
			this->comboBox3->TabIndex = 11;
			// 
			// label7
			// 
			this->label7->Location = System::Drawing::Point(14, 231);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(113, 81);
			this->label7->TabIndex = 7;
			this->label7->Text = L"Hidden and Output Layer Activation Function";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(17, 83);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(70, 22);
			this->label8->TabIndex = 6;
			this->label8->Text = L"Error: 0";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(24, 91);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(111, 20);
			this->label9->TabIndex = 7;
			this->label9->Text = L"Hidden Layers";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(151, 91);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 26);
			this->textBox3->TabIndex = 8;
			// 
			// chart1
			// 
			chartArea4->AxisX->MajorGrid->LineWidth = 0;
			chartArea4->AxisY->MajorGrid->LineWidth = 0;
			chartArea4->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea4);
			legend4->Name = L"Legend1";
			this->chart1->Legends->Add(legend4);
			this->chart1->Location = System::Drawing::Point(12, 17);
			this->chart1->Name = L"chart1";
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series4->IsVisibleInLegend = false;
			series4->Legend = L"Legend1";
			series4->Name = L"Series1";
			series4->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series4->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			this->chart1->Series->Add(series4);
			this->chart1->Size = System::Drawing::Size(552, 426);
			this->chart1->TabIndex = 12;
			this->chart1->Text = L"chart1";
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Location = System::Drawing::Point(151, 275);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(100, 28);
			this->comboBox4->TabIndex = 11;
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->label10);
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Controls->Add(this->comboBox4);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->comboBox3);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Location = System::Drawing::Point(1156, 49);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(275, 319);
			this->panel1->TabIndex = 13;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(33, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(179, 29);
			this->label10->TabIndex = 12;
			this->label10->Text = L"Network Config";
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->label11);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->comboBox2);
			this->panel2->Controls->Add(this->checkBox1);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Location = System::Drawing::Point(851, 51);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(286, 187);
			this->panel2->TabIndex = 14;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(42, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(138, 29);
			this->label11->TabIndex = 15;
			this->label11->Text = L"Data Config";
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->label12);
			this->panel3->Controls->Add(this->label4);
			this->panel3->Controls->Add(this->label8);
			this->panel3->Location = System::Drawing::Point(851, 244);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(286, 124);
			this->panel3->TabIndex = 15;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(60, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(147, 29);
			this->label12->TabIndex = 15;
			this->label12->Text = L"Training Info";
			// 
			// panel4
			// 
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel4->Controls->Add(this->chart1);
			this->panel4->Location = System::Drawing::Point(851, 374);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(580, 470);
			this->panel4->TabIndex = 16;
			// 
			// panel5
			// 
			this->panel5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel5->Controls->Add(this->pictureBox1);
			this->panel5->Location = System::Drawing::Point(7, 48);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(832, 824);
			this->panel5->TabIndex = 18;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->ShowHelp = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1453, 884);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximumSize = System::Drawing::Size(1475, 940);
			this->MinimumSize = System::Drawing::Size(1475, 940);
			this->Name = L"MyForm";
			this->Text = L"Multilayer Perceptron Simulator";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
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
		int first_HL_no_neurons; //number of neuron per first hidden layer
		int no_classes;

		double **weight;
		double learning_rate;
		double Bias;
		bool trained;

		//normalization data;
		double Mean_x, Mean_y, Std_x, Std_y;

		//int trackbar_scale;

		/*******************************Member Methods**************************************/
		//Initialize
		void Initialize();

		//Creating Network and Initializing weights
		System::Void randomToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		
		//Drawing lines and samples
		void Draw_Lines();
		void Draw_Samples();

		//Adding new sample
		void Add_Sample(int selected_class, int x, int y);

		//Batch-Normalization
		void BatchNormalize();

		//Continuous (Multilayer Delta Learning Rule)
		void Training(bool with_momentum);
		System::Void continuousToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void continuousWithMomentToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

		//Testing
		System::Void testToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

		//load Data
		System::Void loadDataToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

		//save Data
		System::Void saveDataToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

		// Form Methods
		std::string get_Activation_Function_GUI(int SelectedIndex);	//get combobox string

		//Painting PictureBox
		int Test_Sample_Size, *Test_Output; bool test_state;
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
			
			Draw_Lines(); Draw_Samples();

			//Adding colours to picturebox
			if (test_state) {
				int i = 0;
				for (int x = 0; x < pictureBox1->Width; x += Test_Sample_Size) {
					for (int y = 0; y < pictureBox1->Height; y += Test_Sample_Size) {
						int index = Test_Output[i];
						SolidBrush ^brush = gcnew SolidBrush(Color::FromArgb(65, color[index].R, color[index].G, color[index].B));
						e->Graphics->FillRectangle(brush, x, y, Test_Sample_Size, Test_Sample_Size);
						i++;
					}
				}
				test_state = false;
			}
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

		System::Void showSamplesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			Draw_Samples();
		}
		
		System::Void showLinesToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
			Draw_Lines();
		}

		void clear_Data() {
			for (int i = 0; i < this->first_HL_no_neurons; i++) {
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
			first_HL_no_neurons = 0;

			learning_rate = 0;
			Bias = 1;
			trained = false;

			Mean_x = 0; Mean_y = 0;
			Std_x = 1; Std_y = 1;

			//trackbar_scale = 0;


			pictureBox1->Refresh();

			comboBox1->SelectedIndex = -1;
			comboBox2->SelectedIndex = -1;
			comboBox3->SelectedIndex = -1;
			comboBox4->SelectedIndex = -1;

			checkBox1->Checked = false;

			textBox1->Text = "";
			textBox2->Text = "";
			textBox3->Text = "";

			label3->Text = "";
			label4->Text = "";
			label8->Text = "";

			this->chart1->Series[0]->Points->Clear(); 

		}

		System::Void clearToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			clear_Data();
		}
};
}

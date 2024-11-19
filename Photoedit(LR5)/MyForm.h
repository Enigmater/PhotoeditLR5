#pragma once

namespace PhotoeditLR5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	enum HIST_CHANNEL { BRIGHTNESS = 1, RED, GREEN, BLUE };

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Bitmap^ image, ^startImage;
		Rectangle selectionRectangle;
		bool isSelecting;
		Point selectionStart;
		HIST_CHANNEL currChannel = HIST_CHANNEL::BRIGHTNESS;
	private: System::Windows::Forms::Panel^ panel_image;
	private: System::Windows::Forms::Label^ label_brTitle;
	private: System::Windows::Forms::Label^ label_contrastTitle;
	private: System::Windows::Forms::TrackBar^ trackBar_contrast;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::TrackBar^ trackBar_bin;
	private: System::Windows::Forms::CheckBox^ checkBox_bin;
	private: System::Windows::Forms::CheckBox^ checkBox_grayShades;
	private: System::Windows::Forms::CheckBox^ checkBox_negative;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart_hist;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::RadioButton^ radioButton_B;
	private: System::Windows::Forms::RadioButton^ radioButton_G;
	private: System::Windows::Forms::RadioButton^ radioButton_R;
	private: System::Windows::Forms::RadioButton^ radioButton_Y;
	private: System::Windows::Forms::TrackBar^ trackBar_brightnrss;


	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_openFile;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->button_openFile = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->panel_image = (gcnew System::Windows::Forms::Panel());
			this->trackBar_brightnrss = (gcnew System::Windows::Forms::TrackBar());
			this->label_brTitle = (gcnew System::Windows::Forms::Label());
			this->label_contrastTitle = (gcnew System::Windows::Forms::Label());
			this->trackBar_contrast = (gcnew System::Windows::Forms::TrackBar());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->trackBar_bin = (gcnew System::Windows::Forms::TrackBar());
			this->checkBox_bin = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_grayShades = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_negative = (gcnew System::Windows::Forms::CheckBox());
			this->chart_hist = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->radioButton_B = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_G = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_R = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_Y = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_brightnrss))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_contrast))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_bin))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_hist))->BeginInit();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// button_openFile
			// 
			this->button_openFile->Location = System::Drawing::Point(307, 2);
			this->button_openFile->Name = L"button_openFile";
			this->button_openFile->Size = System::Drawing::Size(75, 23);
			this->button_openFile->TabIndex = 0;
			this->button_openFile->Text = L"Open Image";
			this->button_openFile->UseVisualStyleBackColor = true;
			this->button_openFile->Click += gcnew System::EventHandler(this, &MyForm::button_openFile_Click);
			// 
			// panel_image
			// 
			this->panel_image->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_image->Location = System::Drawing::Point(307, 31);
			this->panel_image->Name = L"panel_image";
			this->panel_image->Size = System::Drawing::Size(545, 242);
			this->panel_image->TabIndex = 2;
			this->panel_image->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel_image_Paint);
			this->panel_image->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel_image_MouseDown);
			this->panel_image->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel_image_MouseMove);
			this->panel_image->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel_image_MouseUp);
			// 
			// trackBar_brightnrss
			// 
			this->trackBar_brightnrss->Location = System::Drawing::Point(15, 31);
			this->trackBar_brightnrss->Maximum = 255;
			this->trackBar_brightnrss->Minimum = -255;
			this->trackBar_brightnrss->Name = L"trackBar_brightnrss";
			this->trackBar_brightnrss->Size = System::Drawing::Size(286, 45);
			this->trackBar_brightnrss->TabIndex = 3;
			this->trackBar_brightnrss->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_brightnrss_Scroll);
			// 
			// label_brTitle
			// 
			this->label_brTitle->AutoSize = true;
			this->label_brTitle->Location = System::Drawing::Point(12, 15);
			this->label_brTitle->Name = L"label_brTitle";
			this->label_brTitle->Size = System::Drawing::Size(56, 13);
			this->label_brTitle->TabIndex = 4;
			this->label_brTitle->Text = L"Brightness";
			// 
			// label_contrastTitle
			// 
			this->label_contrastTitle->AutoSize = true;
			this->label_contrastTitle->Location = System::Drawing::Point(12, 66);
			this->label_contrastTitle->Name = L"label_contrastTitle";
			this->label_contrastTitle->Size = System::Drawing::Size(46, 13);
			this->label_contrastTitle->TabIndex = 6;
			this->label_contrastTitle->Text = L"Contrast";
			// 
			// trackBar_contrast
			// 
			this->trackBar_contrast->Location = System::Drawing::Point(15, 82);
			this->trackBar_contrast->Maximum = 500;
			this->trackBar_contrast->Name = L"trackBar_contrast";
			this->trackBar_contrast->Size = System::Drawing::Size(286, 45);
			this->trackBar_contrast->TabIndex = 5;
			this->trackBar_contrast->Value = 100;
			this->trackBar_contrast->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_contrast_Scroll);
			// 
			// trackBar_bin
			// 
			this->trackBar_bin->Location = System::Drawing::Point(15, 182);
			this->trackBar_bin->Maximum = 255;
			this->trackBar_bin->Name = L"trackBar_bin";
			this->trackBar_bin->Size = System::Drawing::Size(286, 45);
			this->trackBar_bin->TabIndex = 7;
			this->trackBar_bin->Value = 127;
			this->trackBar_bin->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_bin_Scroll);
			// 
			// checkBox_bin
			// 
			this->checkBox_bin->AutoSize = true;
			this->checkBox_bin->Location = System::Drawing::Point(15, 159);
			this->checkBox_bin->Name = L"checkBox_bin";
			this->checkBox_bin->Size = System::Drawing::Size(80, 17);
			this->checkBox_bin->TabIndex = 9;
			this->checkBox_bin->Text = L"Binarization";
			this->checkBox_bin->UseVisualStyleBackColor = true;
			this->checkBox_bin->Click += gcnew System::EventHandler(this, &MyForm::checkBox_bin_CheckedChanged);
			// 
			// checkBox_grayShades
			// 
			this->checkBox_grayShades->AutoSize = true;
			this->checkBox_grayShades->Location = System::Drawing::Point(15, 233);
			this->checkBox_grayShades->Name = L"checkBox_grayShades";
			this->checkBox_grayShades->Size = System::Drawing::Size(87, 17);
			this->checkBox_grayShades->TabIndex = 10;
			this->checkBox_grayShades->Text = L"Gray Shades";
			this->checkBox_grayShades->UseVisualStyleBackColor = true;
			this->checkBox_grayShades->Click += gcnew System::EventHandler(this, &MyForm::checkBox_grayShades_CheckedChanged);
			// 
			// checkBox_negative
			// 
			this->checkBox_negative->AutoSize = true;
			this->checkBox_negative->Location = System::Drawing::Point(15, 256);
			this->checkBox_negative->Name = L"checkBox_negative";
			this->checkBox_negative->Size = System::Drawing::Size(69, 17);
			this->checkBox_negative->TabIndex = 11;
			this->checkBox_negative->Text = L"Negative";
			this->checkBox_negative->UseVisualStyleBackColor = true;
			this->checkBox_negative->Click += gcnew System::EventHandler(this, &MyForm::checkBox_negative_CheckedChanged);
			// 
			// chart_hist
			// 
			chartArea2->AxisX->Enabled = System::Windows::Forms::DataVisualization::Charting::AxisEnabled::False;
			chartArea2->AxisX->MajorGrid->Enabled = false;
			chartArea2->AxisX->MajorTickMark->Enabled = false;
			chartArea2->AxisY->Enabled = System::Windows::Forms::DataVisualization::Charting::AxisEnabled::False;
			chartArea2->AxisY->MajorGrid->Enabled = false;
			chartArea2->AxisY->MajorTickMark->Enabled = false;
			chartArea2->Name = L"ChartArea1";
			this->chart_hist->ChartAreas->Add(chartArea2);
			this->chart_hist->Location = System::Drawing::Point(5, 6);
			this->chart_hist->Name = L"chart_hist";
			series2->ChartArea = L"ChartArea1";
			series2->Name = L"Series1";
			this->chart_hist->Series->Add(series2);
			this->chart_hist->Size = System::Drawing::Size(545, 141);
			this->chart_hist->TabIndex = 12;
			this->chart_hist->Text = L"chart_gist";
			// 
			// panel1
			// 
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(302, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(569, 291);
			this->panel1->TabIndex = 13;
			// 
			// panel2
			// 
			this->panel2->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(302, 484);
			this->panel2->TabIndex = 14;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->radioButton_B);
			this->panel3->Controls->Add(this->radioButton_G);
			this->panel3->Controls->Add(this->radioButton_R);
			this->panel3->Controls->Add(this->radioButton_Y);
			this->panel3->Controls->Add(this->chart_hist);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(302, 291);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(569, 193);
			this->panel3->TabIndex = 15;
			// 
			// radioButton_B
			// 
			this->radioButton_B->AutoSize = true;
			this->radioButton_B->Location = System::Drawing::Point(122, 153);
			this->radioButton_B->Name = L"radioButton_B";
			this->radioButton_B->Size = System::Drawing::Size(32, 17);
			this->radioButton_B->TabIndex = 16;
			this->radioButton_B->Text = L"B";
			this->radioButton_B->UseVisualStyleBackColor = true;
			this->radioButton_B->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton_B_CheckedChanged);
			// 
			// radioButton_G
			// 
			this->radioButton_G->AutoSize = true;
			this->radioButton_G->Location = System::Drawing::Point(83, 153);
			this->radioButton_G->Name = L"radioButton_G";
			this->radioButton_G->Size = System::Drawing::Size(33, 17);
			this->radioButton_G->TabIndex = 15;
			this->radioButton_G->Text = L"G";
			this->radioButton_G->UseVisualStyleBackColor = true;
			this->radioButton_G->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton_G_CheckedChanged);
			// 
			// radioButton_R
			// 
			this->radioButton_R->AutoSize = true;
			this->radioButton_R->Location = System::Drawing::Point(44, 153);
			this->radioButton_R->Name = L"radioButton_R";
			this->radioButton_R->Size = System::Drawing::Size(33, 17);
			this->radioButton_R->TabIndex = 14;
			this->radioButton_R->Text = L"R";
			this->radioButton_R->UseVisualStyleBackColor = true;
			this->radioButton_R->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton_R_CheckedChanged);
			// 
			// radioButton_Y
			// 
			this->radioButton_Y->AutoSize = true;
			this->radioButton_Y->Checked = true;
			this->radioButton_Y->Location = System::Drawing::Point(6, 153);
			this->radioButton_Y->Name = L"radioButton_Y";
			this->radioButton_Y->Size = System::Drawing::Size(32, 17);
			this->radioButton_Y->TabIndex = 13;
			this->radioButton_Y->TabStop = true;
			this->radioButton_Y->Text = L"Y";
			this->radioButton_Y->UseVisualStyleBackColor = true;
			this->radioButton_Y->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton_Y_CheckedChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(871, 484);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->checkBox_negative);
			this->Controls->Add(this->checkBox_grayShades);
			this->Controls->Add(this->checkBox_bin);
			this->Controls->Add(this->trackBar_bin);
			this->Controls->Add(this->label_contrastTitle);
			this->Controls->Add(this->trackBar_contrast);
			this->Controls->Add(this->label_brTitle);
			this->Controls->Add(this->trackBar_brightnrss);
			this->Controls->Add(this->panel_image);
			this->Controls->Add(this->button_openFile);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_brightnrss))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_contrast))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_bin))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_hist))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button_openFile_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void panel_image_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);

	private: System::Void panel_image_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void panel_image_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void panel_image_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

	private: void ApplyAdjust(Rectangle rect);
	
	private: System::Void trackBar_brightnrss_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: void AdjustBrightness(Rectangle rect, int brightness);

	private: System::Void trackBar_contrast_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: void AdjustContrast(Rectangle rect, float contrastFactor);

	private: System::Void trackBar_bin_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void checkBox_bin_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: void Binarization(Rectangle rect, int binaryLevel);

	private: System::Void checkBox_grayShades_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: void GrayShades(Rectangle rect);

	private: System::Void checkBox_negative_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: void Negative(Rectangle rect);

	private: System::Void radioButton_Y_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void radioButton_R_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void radioButton_G_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void radioButton_B_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: void SetHist(int* hist, HIST_CHANNEL channel);
	private: void DrawHistogram(HIST_CHANNEL channel);
};
}

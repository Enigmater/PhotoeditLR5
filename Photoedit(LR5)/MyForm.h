#pragma once

namespace PhotoeditLR5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::Panel^ panel_image;
	private: System::Windows::Forms::Label^ label_brTitle;
	private: System::Windows::Forms::Label^ label_contrastTitle;
	private: System::Windows::Forms::TrackBar^ trackBar_contrast;
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
			this->button_openFile = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->panel_image = (gcnew System::Windows::Forms::Panel());
			this->trackBar_brightnrss = (gcnew System::Windows::Forms::TrackBar());
			this->label_brTitle = (gcnew System::Windows::Forms::Label());
			this->label_contrastTitle = (gcnew System::Windows::Forms::Label());
			this->trackBar_contrast = (gcnew System::Windows::Forms::TrackBar());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_brightnrss))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_contrast))->BeginInit();
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
			this->panel_image->Size = System::Drawing::Size(545, 380);
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(907, 484);
			this->Controls->Add(this->label_contrastTitle);
			this->Controls->Add(this->trackBar_contrast);
			this->Controls->Add(this->label_brTitle);
			this->Controls->Add(this->trackBar_brightnrss);
			this->Controls->Add(this->panel_image);
			this->Controls->Add(this->button_openFile);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_brightnrss))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_contrast))->EndInit();
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
		   
};
}

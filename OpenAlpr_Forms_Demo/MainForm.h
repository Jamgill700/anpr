#pragma once
#include "alpr.h"
#include <string>
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>

namespace OpenAlprFormsDemo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	
	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  openalpr;
	private: System::Windows::Forms::Button^  butCloseapp;
	private: System::Windows::Forms::TextBox^  infoBox1_ANPR;
	private: System::Windows::Forms::PictureBox^  dispVehicle;
	private: System::Windows::Forms::TextBox^  addBox;
	private: System::Windows::Forms::Label^  lblPath;
	private: System::Windows::Forms::Label^  lblNumPlate;
	private: System::Windows::Forms::TextBox^  bodyTypeBox;
	private: System::Windows::Forms::Label^  lblBodyType;
	private: System::Windows::Forms::TextBox^  colBox;
	private: System::Windows::Forms::Label^  lblColBox;
	private: System::Windows::Forms::Label^  lblHeading;
	private: System::Windows::Forms::TextBox^  carMakeBox;
	private: System::Windows::Forms::Label^  label1;
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
			this->openalpr = (gcnew System::Windows::Forms::Button());
			this->butCloseapp = (gcnew System::Windows::Forms::Button());
			this->infoBox1_ANPR = (gcnew System::Windows::Forms::TextBox());
			this->dispVehicle = (gcnew System::Windows::Forms::PictureBox());
			this->addBox = (gcnew System::Windows::Forms::TextBox());
			this->lblPath = (gcnew System::Windows::Forms::Label());
			this->lblNumPlate = (gcnew System::Windows::Forms::Label());
			this->bodyTypeBox = (gcnew System::Windows::Forms::TextBox());
			this->lblBodyType = (gcnew System::Windows::Forms::Label());
			this->colBox = (gcnew System::Windows::Forms::TextBox());
			this->lblColBox = (gcnew System::Windows::Forms::Label());
			this->lblHeading = (gcnew System::Windows::Forms::Label());
			this->carMakeBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dispVehicle))->BeginInit();
			this->SuspendLayout();
			// 
			// openalpr
			// 
			this->openalpr->Location = System::Drawing::Point(695, 27);
			this->openalpr->Name = L"openalpr";
			this->openalpr->Size = System::Drawing::Size(123, 41);
			this->openalpr->TabIndex = 0;
			this->openalpr->Text = L"ANPR";
			this->openalpr->UseVisualStyleBackColor = true;
			this->openalpr->Click += gcnew System::EventHandler(this, &MainForm::openalpr_Click);
			// 
			// butCloseapp
			// 
			this->butCloseapp->Location = System::Drawing::Point(696, 540);
			this->butCloseapp->Name = L"butCloseapp";
			this->butCloseapp->Size = System::Drawing::Size(122, 44);
			this->butCloseapp->TabIndex = 1;
			this->butCloseapp->Text = L"Exit";
			this->butCloseapp->UseVisualStyleBackColor = true;
			this->butCloseapp->Click += gcnew System::EventHandler(this, &MainForm::butCloseapp_Click);
			// 
			// infoBox1_ANPR
			// 
			this->infoBox1_ANPR->Location = System::Drawing::Point(696, 294);
			this->infoBox1_ANPR->Name = L"infoBox1_ANPR";
			this->infoBox1_ANPR->Size = System::Drawing::Size(116, 20);
			this->infoBox1_ANPR->TabIndex = 2;
			// 
			// dispVehicle
			// 
			this->dispVehicle->Location = System::Drawing::Point(12, 60);
			this->dispVehicle->Name = L"dispVehicle";
			this->dispVehicle->Size = System::Drawing::Size(668, 524);
			this->dispVehicle->TabIndex = 3;
			this->dispVehicle->TabStop = false;
			// 
			// addBox
			// 
			this->addBox->ForeColor = System::Drawing::SystemColors::GrayText;
			this->addBox->Location = System::Drawing::Point(12, 27);
			this->addBox->Name = L"addBox";
			this->addBox->Size = System::Drawing::Size(668, 20);
			this->addBox->TabIndex = 4;
			this->addBox->Text = L"D:\\uk-2.jpg";
			// 
			// lblPath
			// 
			this->lblPath->AutoSize = true;
			this->lblPath->Location = System::Drawing::Point(12, 11);
			this->lblPath->Name = L"lblPath";
			this->lblPath->Size = System::Drawing::Size(118, 13);
			this->lblPath->TabIndex = 5;
			this->lblPath->Text = L"Enter file path to image:";
			// 
			// lblNumPlate
			// 
			this->lblNumPlate->AutoSize = true;
			this->lblNumPlate->Location = System::Drawing::Point(692, 278);
			this->lblNumPlate->Name = L"lblNumPlate";
			this->lblNumPlate->Size = System::Drawing::Size(74, 13);
			this->lblNumPlate->TabIndex = 6;
			this->lblNumPlate->Text = L"Number Plate:";
			// 
			// bodyTypeBox
			// 
			this->bodyTypeBox->Location = System::Drawing::Point(696, 198);
			this->bodyTypeBox->Name = L"bodyTypeBox";
			this->bodyTypeBox->Size = System::Drawing::Size(116, 20);
			this->bodyTypeBox->TabIndex = 7;
			// 
			// lblBodyType
			// 
			this->lblBodyType->AutoSize = true;
			this->lblBodyType->Location = System::Drawing::Point(692, 180);
			this->lblBodyType->Name = L"lblBodyType";
			this->lblBodyType->Size = System::Drawing::Size(61, 13);
			this->lblBodyType->TabIndex = 8;
			this->lblBodyType->Text = L"Body Type:";
			// 
			// colBox
			// 
			this->colBox->Location = System::Drawing::Point(696, 152);
			this->colBox->Name = L"colBox";
			this->colBox->Size = System::Drawing::Size(116, 20);
			this->colBox->TabIndex = 9;
			// 
			// lblColBox
			// 
			this->lblColBox->AutoSize = true;
			this->lblColBox->Location = System::Drawing::Point(692, 136);
			this->lblColBox->Name = L"lblColBox";
			this->lblColBox->Size = System::Drawing::Size(37, 13);
			this->lblColBox->TabIndex = 10;
			this->lblColBox->Text = L"Colour";
			
			// 
			// lblHeading
			// 
			this->lblHeading->AutoSize = true;
			this->lblHeading->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHeading->Location = System::Drawing::Point(700, 79);
			this->lblHeading->Name = L"lblHeading";
			this->lblHeading->Size = System::Drawing::Size(117, 16);
			this->lblHeading->TabIndex = 11;
			this->lblHeading->Text = L"Vehicle Details:";
			// 
			// carMakeBox
			// 
			this->carMakeBox->Location = System::Drawing::Point(696, 247);
			this->carMakeBox->Name = L"carMakeBox";
			this->carMakeBox->Size = System::Drawing::Size(116, 20);
			this->carMakeBox->TabIndex = 12;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(692, 230);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(103, 13);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Detected Car Make:";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(830, 596);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->carMakeBox);
			this->Controls->Add(this->lblHeading);
			this->Controls->Add(this->lblColBox);
			this->Controls->Add(this->colBox);
			this->Controls->Add(this->lblBodyType);
			this->Controls->Add(this->bodyTypeBox);
			this->Controls->Add(this->lblNumPlate);
			this->Controls->Add(this->lblPath);
			this->Controls->Add(this->addBox);
			this->Controls->Add(this->dispVehicle);
			this->Controls->Add(this->infoBox1_ANPR);
			this->Controls->Add(this->butCloseapp);
			this->Controls->Add(this->openalpr);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dispVehicle))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	Bitmap^ MyImage;
	
	private: System::Void openalpr_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ path = addBox->Text;	//"D:\\us-4.jpg";	// Takes path from textbox
		
		// PERFORM ANPR		
		string spath = msclr::interop::marshal_as<std::string>(path);	// Convert from System::String to std::string
		std::wstring countryCode = L"eu";								// Country region for car --> Static in this but would need changed
		vector<string> output = aplr(spath, countryCode);				// Activate ANPR code
			
		// COLOUR
		colBox->Text = gcnew String(output[12].c_str());

		// BODY TYPE
		bodyTypeBox->Text = gcnew String(output[13].c_str());

		// MAKE
		carMakeBox->Text = gcnew String(output[14].c_str());

		// NUMBER PLATE
		infoBox1_ANPR->Text = gcnew String(output[2].c_str());

		// NUMBER PLATE COORDS
		int y0 = stoi(output[4]);
		int x0 = stoi(output[5]);
		int y1 = stoi(output[6]);
		int x1 = stoi(output[7]);
		int y2 = stoi(output[8]);
		int x2 = stoi(output[9]);
		int y3 = stoi(output[10]);
		int x3 = stoi(output[11]);
					
		// MAIN DISPLAY BOX --> VEHICLE
		if (MyImage != nullptr)
		{
			delete MyImage;
		}
		// Stretches the image to fit the pictureBox.
		dispVehicle->SizeMode = PictureBoxSizeMode::StretchImage;
		MyImage = gcnew Bitmap(path);
		System::Drawing::Rectangle numPlate = System::Drawing::Rectangle(50, 50, 100, 200);
		Graphics^ g = Graphics::FromImage(MyImage);
		
		// Create a new pen to draw around the number plate
		Pen^ limePen = gcnew Pen(Brushes::Lime);
		// Set the pen's width.
		limePen->Width = 3.0F;
		// Set the LineJoin property.
		limePen->LineJoin = System::Drawing::Drawing2D::LineJoin::Bevel;
		g->DrawLine(limePen, x0, y0, x1, y1);
		g->DrawLine(limePen, x1, y1, x2, y2);
		g->DrawLine(limePen, x2, y2, x3, y3);
		g->DrawLine(limePen, x3, y3, x0, y0);
		
		// Display image and numberplate region
		dispVehicle->ClientSize = System::Drawing::Size(668, 524);
		dispVehicle->Image = dynamic_cast<Image^>(MyImage);

	}
	
	private: System::Void butCloseapp_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}
	
};
}

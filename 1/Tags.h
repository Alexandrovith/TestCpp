#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace TestCpp {

	/// <summary>
	/// Summary for CTags
	/// </summary>
	public ref class CTags : public System::Windows::Forms::UserControl
	{
	public:
		CTags (void);
		System::Collections::ArrayList^ GetTagData (String^ asDevName);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CTags()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ PShowParams;
	public: System::Windows::Forms::OpenFileDialog^ FDOpenFl;

	public:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ LValue;

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
			this->PShowParams = (gcnew System::Windows::Forms::Panel ());
			this->FDOpenFl = (gcnew System::Windows::Forms::OpenFileDialog ());
			this->label1 = (gcnew System::Windows::Forms::Label ());
			this->label3 = (gcnew System::Windows::Forms::Label ());
			this->LValue = (gcnew System::Windows::Forms::Label ());
			this->SuspendLayout ();
			// 
			// PShowParams
			// 
			this->PShowParams->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->PShowParams->BackColor = System::Drawing::Color::SeaShell;
			this->PShowParams->Location = System::Drawing::Point (0, 20);
			this->PShowParams->Name = L"PShowParams";
			this->PShowParams->Size = System::Drawing::Size (376, 278);
			this->PShowParams->TabIndex = 0;
			// 
			// FDOpenFl
			// 
			this->FDOpenFl->FileName = L"FDOpenFl";
			this->FDOpenFl->Filter = L"\"Файлы параметров|*.prmd|Все файлы|*.*\"";
			// 
			// label1
			// 
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label1->Location = System::Drawing::Point (0, 0);
			this->label1->Name = L"label1";
			this->label1->Padding = System::Windows::Forms::Padding (0, 1, 0, 0);
			this->label1->Size = System::Drawing::Size (84, 19);
			this->label1->TabIndex = 5;
			this->label1->Text = L"RequestName";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label3->Location = System::Drawing::Point (84, 0);
			this->label3->Name = L"label3";
			this->label3->Padding = System::Windows::Forms::Padding (0, 1, 0, 0);
			this->label3->Size = System::Drawing::Size (168, 19);
			this->label3->TabIndex = 4;
			this->label3->Text = L"ParamName";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// LValue
			// 
			this->LValue->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->LValue->Location = System::Drawing::Point (252, 0);
			this->LValue->Name = L"LValue";
			this->LValue->Padding = System::Windows::Forms::Padding (0, 1, 0, 0);
			this->LValue->Size = System::Drawing::Size (124, 19);
			this->LValue->TabIndex = 4;
			this->LValue->Text = L"Значение";
			this->LValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// CTags
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF (6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::Gainsboro;
			this->Controls->Add (this->LValue);
			this->Controls->Add (this->label3);
			this->Controls->Add (this->label1);
			this->Controls->Add (this->PShowParams);
			this->Name = L"CTags";
			this->Size = System::Drawing::Size (379, 298);
			this->ResumeLayout (false);

		}
#pragma endregion
	};
}

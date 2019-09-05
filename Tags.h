#pragma once

#include "RowOutPar.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace TestCpp
{
	/// <summary>
	/// Summary for CTags
	/// </summary>
	public ref class CTags : public System::Windows::Forms::UserControl
	{
	public:
		CTags ();
		System::Collections::Hashtable^ GetRdData (System::String^ asDevName);
		System::Collections::ArrayList^ GetWrData (System::String^ asDevName);
		System::String^ GetType (int iId);
		void OutVal (int iId, System::String^ asVal);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CTags ()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Panel^ PShowParams;
	public: System::Windows::Forms::OpenFileDialog^ FDOpenFl;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ LValue;
	public: System::Windows::Forms::CheckBox^ ChBSelectAll;
	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::Windows::Forms::Label^ label2;
	private: System::ComponentModel::IContainer^ components;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent (void)
		{
			this->components = (gcnew System::ComponentModel::Container ());
			this->PShowParams = (gcnew System::Windows::Forms::Panel ());
			this->FDOpenFl = (gcnew System::Windows::Forms::OpenFileDialog ());
			this->label1 = (gcnew System::Windows::Forms::Label ());
			this->label3 = (gcnew System::Windows::Forms::Label ());
			this->LValue = (gcnew System::Windows::Forms::Label ());
			this->ChBSelectAll = (gcnew System::Windows::Forms::CheckBox ());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip (this->components));
			this->label2 = (gcnew System::Windows::Forms::Label ());
			this->SuspendLayout ();
			// 
			// PShowParams
			// 
			this->PShowParams->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->PShowParams->BackColor = System::Drawing::Color::SeaShell;
			this->PShowParams->Location = System::Drawing::Point (0, 20);
			this->PShowParams->Name = L"PShowParams";
			this->PShowParams->Size = System::Drawing::Size (402, 278);
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
			this->label1->Size = System::Drawing::Size (50, 19);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Request";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label3->Location = System::Drawing::Point (51, 0);
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
			this->LValue->Location = System::Drawing::Point (220, 0);
			this->LValue->Name = L"LValue";
			this->LValue->Padding = System::Windows::Forms::Padding (0, 1, 0, 0);
			this->LValue->Size = System::Drawing::Size (100, 19);
			this->LValue->TabIndex = 4;
			this->LValue->Text = L"Значение";
			this->LValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ChBSelectAll
			// 
			this->ChBSelectAll->AutoSize = true;
			this->ChBSelectAll->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ChBSelectAll->Location = System::Drawing::Point (384, 4);
			this->ChBSelectAll->Name = L"ChBSelectAll";
			this->ChBSelectAll->Size = System::Drawing::Size (15, 14);
			this->ChBSelectAll->TabIndex = 6;
			this->toolTip1->SetToolTip (this->ChBSelectAll, L"Выбрать все");
			this->ChBSelectAll->UseVisualStyleBackColor = true;
			this->ChBSelectAll->CheckedChanged += gcnew System::EventHandler (this, &CTags::ChBSelrctAll_CheckedChanged);
			// 
			// label2
			// 
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label2->Location = System::Drawing::Point (320, 0);
			this->label2->Name = L"label2";
			this->label2->Padding = System::Windows::Forms::Padding (0, 1, 0, 0);
			this->label2->Size = System::Drawing::Size (55, 19);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Тип";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// CTags
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF (6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::Gainsboro;
			this->Controls->Add (this->ChBSelectAll);
			this->Controls->Add (this->LValue);
			this->Controls->Add (this->label3);
			this->Controls->Add (this->label2);
			this->Controls->Add (this->label1);
			this->Controls->Add (this->PShowParams);
			this->Name = L"CTags";
			this->Size = System::Drawing::Size (405, 298);
			this->ResumeLayout (false);
			this->PerformLayout ();

		}
#pragma endregion

	private: System::Void ChBSelrctAll_CheckedChanged (System::Object^ sender, System::EventArgs^ e)
	{
		bool bState = ChBSelectAll->Checked;				// Нашли чекбокс управляющий 
		for each (auto Row in PShowParams->Controls)
		{
			CRowOutPar^ TagRow = dynamic_cast<CRowOutPar^>(Row);
			if (TagRow != nullptr)
			{
				TagRow->ChBSelectRow->Checked = bState;// Устанавливаем состояние чеков в нашей панели 
			}
		}
	}
	};
}

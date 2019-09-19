#pragma once

#include "DataForWr.h"
#include "SavePropert.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace TestCpp
{
	/// <summary>
	/// Summary for CRowOutPar
	/// </summary>
	public ref class CRowOutPar : public System::Windows::Forms::UserControl
	{
	public:	CRowOutPar (int RowNumber, CSavePropert^ SaveProp, String^ CheckTags)
	{
		InitializeComponent ();
		iRowNumber = RowNumber;
		this->SaveProp = SaveProp;
		asCheckTags = CheckTags;
	}

	public:	void FillControlByName (System::String^ asContrtolName, System::String^ asTextToWr);
					void FillCheckBox (bool bStateChB);
					System::String^ GetTagDataRow (System::String^ asDevName, int& iTagId);
					System::String^ GetTagDataRowChecked (System::String^ asDevName, int& iTagId);
					CDataForWr^ GetTagWrRowChecked (System::String^ asDevName);

					int iRowNumber;
					CSavePropert^ SaveProp;
					String^ asCheckTags;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CRowOutPar ()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::TextBox^ TBRequestName;
	public: System::Windows::Forms::TextBox^ TBParamName;
	public: System::Windows::Forms::TextBox^ TBVal;
	public: System::Windows::Forms::CheckBox^ ChBSelectRow;
	public: System::Windows::Forms::TextBox^ TBType;

	public: System::String^ asRunNumber;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent (void)
		{
			this->TBRequestName = (gcnew System::Windows::Forms::TextBox ());
			this->TBParamName = (gcnew System::Windows::Forms::TextBox ());
			this->TBVal = (gcnew System::Windows::Forms::TextBox ());
			this->ChBSelectRow = (gcnew System::Windows::Forms::CheckBox ());
			this->TBType = (gcnew System::Windows::Forms::TextBox ());
			this->SuspendLayout ();
			// 
			// TBRequestName
			// 
			this->TBRequestName->Location = System::Drawing::Point (0, 0);
			this->TBRequestName->Name = L"TBRequestName";
			this->TBRequestName->Size = System::Drawing::Size (50, 20);
			this->TBRequestName->TabIndex = 0;
			this->TBRequestName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// TBParamName
			// 
			this->TBParamName->Location = System::Drawing::Point (51, 0);
			this->TBParamName->Name = L"TBParamName";
			this->TBParamName->Size = System::Drawing::Size (168, 20);
			this->TBParamName->TabIndex = 1;
			this->TBParamName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// TBVal
			// 
			this->TBVal->Location = System::Drawing::Point (220, 0);
			this->TBVal->Name = L"TBVal";
			this->TBVal->Size = System::Drawing::Size (100, 20);
			this->TBVal->TabIndex = 1;
			this->TBVal->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// ChBSelectRow
			// 
			this->ChBSelectRow->AutoSize = true;
			this->ChBSelectRow->Location = System::Drawing::Point (384, 4);
			this->ChBSelectRow->Name = L"ChBSelectRow";
			this->ChBSelectRow->Size = System::Drawing::Size (15, 14);
			this->ChBSelectRow->TabIndex = 2;
			this->ChBSelectRow->UseVisualStyleBackColor = true;
			this->ChBSelectRow->CheckedChanged += gcnew System::EventHandler (this, &CRowOutPar::ChBSelectRow_CheckedChanged);
			// 
			// TBType
			// 
			this->TBType->Location = System::Drawing::Point (321, 0);
			this->TBType->Name = L"TBType";
			this->TBType->Size = System::Drawing::Size (55, 20);
			this->TBType->TabIndex = 0;
			this->TBType->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// CRowOutPar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF (6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->Controls->Add (this->ChBSelectRow);
			this->Controls->Add (this->TBVal);
			this->Controls->Add (this->TBParamName);
			this->Controls->Add (this->TBType);
			this->Controls->Add (this->TBRequestName);
			this->Name = L"CRowOutPar";
			this->Size = System::Drawing::Size (402, 23);
			this->ResumeLayout (false);
			this->PerformLayout ();

		}
#pragma endregion
	private: System::Void ChBSelectRow_CheckedChanged (System::Object^ sender, System::EventArgs^ e)
	{
		SaveProp->Set (asCheckTags, ChBSelectRow->Checked);
	}
	};
}

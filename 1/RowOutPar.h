#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace TestCpp {

	/// <summary>
	/// Summary for CRowOutPar
	/// </summary>
	public ref class CRowOutPar : public System::Windows::Forms::UserControl
	{
	public:
		CRowOutPar(void)
		{
			InitializeComponent();
		}
	public:	void FillControlByName (System::String^ asContrtolName, System::String^ asTextToWr);
					System::String^ GetTagDataRow (String^ asDevName);
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CRowOutPar()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::TextBox^ TBRequestName;
	public: System::Windows::Forms::TextBox^ TBParamName;
	public: System::Windows::Forms::TextBox^ textBox1;
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
			this->TBRequestName = (gcnew System::Windows::Forms::TextBox ());
			this->TBParamName = (gcnew System::Windows::Forms::TextBox ());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox ());
			this->SuspendLayout ();
			// 
			// TBRequestName
			// 
			this->TBRequestName->Location = System::Drawing::Point (0, 0);
			this->TBRequestName->Name = L"TBRequestName";
			this->TBRequestName->Size = System::Drawing::Size (84, 20);
			this->TBRequestName->TabIndex = 0;
			// 
			// TBParamName
			// 
			this->TBParamName->Location = System::Drawing::Point (84, 0);
			this->TBParamName->Name = L"TBParamName";
			this->TBParamName->Size = System::Drawing::Size (168, 20);
			this->TBParamName->TabIndex = 1;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point (252, 0);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size (124, 20);
			this->textBox1->TabIndex = 1;
			// 
			// CRowOutPar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF (6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->Controls->Add (this->textBox1);
			this->Controls->Add (this->TBParamName);
			this->Controls->Add (this->TBRequestName);
			this->Name = L"CRowOutPar";
			this->Size = System::Drawing::Size (379, 23);
			this->ResumeLayout (false);
			this->PerformLayout ();

		}
#pragma endregion
	};
}

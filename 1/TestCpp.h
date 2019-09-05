#pragma once

#include <Windows.h>
#include <string>

#include "RMG.h"
#include "Typesdef.h"
#include "Tags.h"
#include "Superflo.h"

namespace TestCpp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FTestCpp
	/// </summary>
	public ref class FTestCpp : public System::Windows::Forms::Form
	{
#pragma region //xxxxxxxxxxxxxxxxxxxxxx    П О С Т О Я Н Н Ы Е    xxxxxxxxxxxxxxxxxxxxxxxxx
#pragma endregion

#pragma region //xxxxxxxxxxxxxxxxxxxxxx    П Е Р Е М Е Н Н Ы Е    xxxxxxxxxxxxxxxxxxxxxxxxx

	private: CRMG^ RMG;
	private: CSuperflo^ Superflo;
	private: DOutMess^ PDOutMess;
	private: System::Windows::Forms::Button^ BLoadDll;
	private: System::Windows::Forms::Button^ BLoadDllSuper;
	private: System::Windows::Forms::TextBox^ TBOut;

	public: System::Windows::Forms::Panel^ PTagsSuper;
	private: System::Windows::Forms::Button^ BStartStopSuper;
	public:
	private:

	private: CTags^ Tags;

#pragma endregion		

								//xxxxxxxxxxxxxxxxxxxxxxxxxx     the  К О Д      xxxxxxxxxxxxxxxxxxxxxxxxxxxxx
	public:
		FTestCpp (void);

	private: System::Void CreateTagsFrame (System::Windows::Forms::Control^ Parent);
	public: System::Void OutMess (System::String^ asMess);
	private: System::Collections::ArrayList^ GetTagsSuper ();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FTestCpp ()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^ TPRMG;
	private: System::Windows::Forms::TabPage^ TPSuperflo;
	private: System::Windows::Forms::TabPage^ TPTags;
	private: System::Windows::Forms::TabPage^ TPClose;
	private: System::Windows::Forms::Button^ BClose;
	public: System::Windows::Forms::OpenFileDialog^ FDOpenFl;

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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl ());
			this->TPSuperflo = (gcnew System::Windows::Forms::TabPage ());
			this->BLoadDllSuper = (gcnew System::Windows::Forms::Button ());
			this->TPRMG = (gcnew System::Windows::Forms::TabPage ());
			this->BLoadDll = (gcnew System::Windows::Forms::Button ());
			this->TPTags = (gcnew System::Windows::Forms::TabPage ());
			this->TPClose = (gcnew System::Windows::Forms::TabPage ());
			this->BClose = (gcnew System::Windows::Forms::Button ());
			this->FDOpenFl = (gcnew System::Windows::Forms::OpenFileDialog ());
			this->TBOut = (gcnew System::Windows::Forms::TextBox ());
			this->PTagsSuper = (gcnew System::Windows::Forms::Panel ());
			this->BStartStopSuper = (gcnew System::Windows::Forms::Button ());
			this->tabControl1->SuspendLayout ();
			this->TPSuperflo->SuspendLayout ();
			this->TPRMG->SuspendLayout ();
			this->TPClose->SuspendLayout ();
			this->SuspendLayout ();
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add (this->TPSuperflo);
			this->tabControl1->Controls->Add (this->TPRMG);
			this->tabControl1->Controls->Add (this->TPTags);
			this->tabControl1->Controls->Add (this->TPClose);
			this->tabControl1->Location = System::Drawing::Point (0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->Padding = System::Drawing::Point (16, 5);
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size (824, 300);
			this->tabControl1->TabIndex = 0;
			// 
			// TPSuperflo
			// 
			this->TPSuperflo->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->TPSuperflo->Controls->Add (this->BStartStopSuper);
			this->TPSuperflo->Controls->Add (this->PTagsSuper);
			this->TPSuperflo->Controls->Add (this->BLoadDllSuper);
			this->TPSuperflo->Location = System::Drawing::Point (4, 28);
			this->TPSuperflo->Name = L"TPSuperflo";
			this->TPSuperflo->Padding = System::Windows::Forms::Padding (3);
			this->TPSuperflo->Size = System::Drawing::Size (816, 268);
			this->TPSuperflo->TabIndex = 1;
			this->TPSuperflo->Text = L"Superflo";
			this->TPSuperflo->UseVisualStyleBackColor = true;
			// 
			// BLoadDllSuper
			// 
			this->BLoadDllSuper->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->BLoadDllSuper->Cursor = System::Windows::Forms::Cursors::Hand;
			this->BLoadDllSuper->Location = System::Drawing::Point (648, 0);
			this->BLoadDllSuper->Name = L"BLoadDllSuper";
			this->BLoadDllSuper->Size = System::Drawing::Size (163, 28);
			this->BLoadDllSuper->TabIndex = 0;
			this->BLoadDllSuper->Text = L"Load dll Superflo";
			this->BLoadDllSuper->UseVisualStyleBackColor = true;
			this->BLoadDllSuper->Click += gcnew System::EventHandler (this, &FTestCpp::BLoadDllSuper_Click);
			// 
			// TPRMG
			// 
			this->TPRMG->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->TPRMG->Controls->Add (this->BLoadDll);
			this->TPRMG->Location = System::Drawing::Point (4, 28);
			this->TPRMG->Name = L"TPRMG";
			this->TPRMG->Padding = System::Windows::Forms::Padding (3);
			this->TPRMG->Size = System::Drawing::Size (816, 268);
			this->TPRMG->TabIndex = 0;
			this->TPRMG->Text = L"EC605";
			this->TPRMG->UseVisualStyleBackColor = true;
			// 
			// BLoadDll
			// 
			this->BLoadDll->Cursor = System::Windows::Forms::Cursors::Hand;
			this->BLoadDll->Location = System::Drawing::Point (652, 0);
			this->BLoadDll->Name = L"BLoadDll";
			this->BLoadDll->Size = System::Drawing::Size (159, 23);
			this->BLoadDll->TabIndex = 0;
			this->BLoadDll->Text = L"Load dll";
			this->BLoadDll->UseVisualStyleBackColor = true;
			this->BLoadDll->Click += gcnew System::EventHandler (this, &FTestCpp::BLoadDll_Click);
			// 
			// TPTags
			// 
			this->TPTags->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->TPTags->Location = System::Drawing::Point (4, 28);
			this->TPTags->Name = L"TPTags";
			this->TPTags->Padding = System::Windows::Forms::Padding (3);
			this->TPTags->Size = System::Drawing::Size (816, 268);
			this->TPTags->TabIndex = 2;
			this->TPTags->Text = L"Параметры";
			this->TPTags->UseVisualStyleBackColor = true;
			// 
			// TPClose
			// 
			this->TPClose->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->TPClose->Controls->Add (this->BClose);
			this->TPClose->Location = System::Drawing::Point (4, 28);
			this->TPClose->Name = L"TPClose";
			this->TPClose->Padding = System::Windows::Forms::Padding (3);
			this->TPClose->Size = System::Drawing::Size (816, 268);
			this->TPClose->TabIndex = 3;
			this->TPClose->Text = L"Выход";
			this->TPClose->UseVisualStyleBackColor = true;
			// 
			// BClose
			// 
			this->BClose->Cursor = System::Windows::Forms::Cursors::Hand;
			this->BClose->Dock = System::Windows::Forms::DockStyle::Top;
			this->BClose->Font = (gcnew System::Drawing::Font (L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BClose->Location = System::Drawing::Point (3, 3);
			this->BClose->Name = L"BClose";
			this->BClose->Size = System::Drawing::Size (806, 65);
			this->BClose->TabIndex = 0;
			this->BClose->Text = L"Конец";
			this->BClose->UseVisualStyleBackColor = true;
			this->BClose->Click += gcnew System::EventHandler (this, &FTestCpp::BClose_Click);
			// 
			// FDOpenFl
			// 
			this->FDOpenFl->FileName = L"FDOpenFl";
			this->FDOpenFl->Filter = L"\"Файлы параметров|*.prmd|Все файлы|*.*\"";
			// 
			// TBOut
			// 
			this->TBOut->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->TBOut->Location = System::Drawing::Point (0, 300);
			this->TBOut->Multiline = true;
			this->TBOut->Name = L"TBOut";
			this->TBOut->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->TBOut->Size = System::Drawing::Size (824, 112);
			this->TBOut->TabIndex = 1;
			// 
			// PTagsSuper
			// 
			this->PTagsSuper->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->PTagsSuper->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->PTagsSuper->Location = System::Drawing::Point (0, 0);
			this->PTagsSuper->Name = L"PTagsSuper";
			this->PTagsSuper->Size = System::Drawing::Size (444, 264);
			this->PTagsSuper->TabIndex = 1;
			// 
			// BStartStopSuper
			// 
			this->BStartStopSuper->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->BStartStopSuper->Cursor = System::Windows::Forms::Cursors::Hand;
			this->BStartStopSuper->Location = System::Drawing::Point (703, 32);
			this->BStartStopSuper->Name = L"BStartStopSuper";
			this->BStartStopSuper->Size = System::Drawing::Size (108, 28);
			this->BStartStopSuper->TabIndex = 2;
			this->BStartStopSuper->Text = L"Старт";
			this->BStartStopSuper->UseVisualStyleBackColor = true;
			this->BStartStopSuper->Click += gcnew System::EventHandler (this, &FTestCpp::BStartStopSuper_Click);
			// 
			// FTestCpp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF (7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size (824, 412);
			this->Controls->Add (this->TBOut);
			this->Controls->Add (this->tabControl1);
			this->Font = (gcnew System::Drawing::Font (L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Name = L"FTestCpp";
			this->Text = L"Тест драйверов на cpp";
			this->tabControl1->ResumeLayout (false);
			this->TPSuperflo->ResumeLayout (false);
			this->TPRMG->ResumeLayout (false);
			this->TPClose->ResumeLayout (false);
			this->ResumeLayout (false);
			this->PerformLayout ();

		}
#pragma endregion
	private: System::Void BClose_Click (System::Object^ sender, System::EventArgs^ e) {
		Close ();
	}
	private: System::Void BLoadDll_Click (System::Object^ sender, System::EventArgs^ e);
	private: System::Void BLoadDllSuper_Click (System::Object^ sender, System::EventArgs^ e);
private: System::Void BStartStopSuper_Click (System::Object^ sender, System::EventArgs^ e);
};
}

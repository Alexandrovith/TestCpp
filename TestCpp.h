#pragma once

#include "RMG.h"
#include "Typesdef.h"
#include "Tags.h"
#include "Superflo.h"
#include "WorkOfDevs.h"

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

	private: System::Windows::Forms::Button^ BLoadDllSuper;
	private: System::Windows::Forms::TextBox^ TBOut;
	public: System::Windows::Forms::Panel^ PTagsRdSuper;
	private: System::Windows::Forms::Button^ BStartStopSuper;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::NumericUpDown^ NUDIntervalReqSuper;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ BLoadDllRMG;
	public: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::NumericUpDown^ NUDIntervalReqRMG;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ CBComPort;
	private: System::Windows::Forms::Button^ BScanComPorts;
	private: System::Windows::Forms::ImageList^ IL24;
	private: System::Windows::Forms::GroupBox^ GBWrParam;

#pragma endregion		

					 //xxxxxxxxxxxxxxxxxxxxxxxxxx     the  К О Д      xxxxxxxxxxxxxxxxxxxxxxxxxxxxx
	public:
		FTestCpp (void);

	private: System::Void CreateTagsFrame (const System::String^ asFilePrmd, System::Windows::Forms::Control^ ParentRd, Control^ ParentWr);
					 CTags^ TagFrameNew (System::Windows::Forms::Control^ Parent);
	public: System::Void OutMess (System::String^ asMess);
	private: CDevice^ DllLoadSuper ();
	private: CDevice^ DllLoadRMG ();
	private: void ScanComPorts ();
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
	private: System::Windows::Forms::TabPage^ TPRMG;
	private: System::Windows::Forms::TabPage^ TPSuperflo;
	private: System::Windows::Forms::TabPage^ TPClose;
	private: System::Windows::Forms::Button^ BClose;
	public: System::Windows::Forms::OpenFileDialog^ FDOpenFl;
	private: System::ComponentModel::IContainer^ components;

		/// <summary>
		/// Required designer variable.
		/// </summary>
	public: String^ asPathExe;
	private: DOutMess^ PDOutMess;
	private: CWorkOfDevs^ SuperfloWork;
	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::Windows::Forms::Label^ LWaitSuper;
	private: System::Windows::Forms::Timer^ TrWaitInitDrv;

	private: CWorkOfDevs^ RMGwork;
	public: delegate void DSetIntervalTimer (int iInterval);
	private: event DSetIntervalTimer^ SetIntervalTimerSuper;
	private: event DSetIntervalTimer^ SetIntervalTimerRMG;
	private: System::Windows::Forms::Label^ rLWaitSuper_RMG;
	private: System::Windows::Forms::ComboBox^ CBDevType;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ BWrSuper;
	private: int iCountWait;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent (void)
		{
			this->components = (gcnew System::ComponentModel::Container ());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl ());
			this->TPSuperflo = (gcnew System::Windows::Forms::TabPage ());
			this->BScanComPorts = (gcnew System::Windows::Forms::Button ());
			this->CBComPort = (gcnew System::Windows::Forms::ComboBox ());
			this->BWrSuper = (gcnew System::Windows::Forms::Button ());
			this->CBDevType = (gcnew System::Windows::Forms::ComboBox ());
			this->LWaitSuper = (gcnew System::Windows::Forms::Label ());
			this->GBWrParam = (gcnew System::Windows::Forms::GroupBox ());
			this->NUDIntervalReqSuper = (gcnew System::Windows::Forms::NumericUpDown ());
			this->label3 = (gcnew System::Windows::Forms::Label ());
			this->label1 = (gcnew System::Windows::Forms::Label ());
			this->BStartStopSuper = (gcnew System::Windows::Forms::Button ());
			this->PTagsRdSuper = (gcnew System::Windows::Forms::Panel ());
			this->BLoadDllSuper = (gcnew System::Windows::Forms::Button ());
			this->TPRMG = (gcnew System::Windows::Forms::TabPage ());
			this->panel1 = (gcnew System::Windows::Forms::Panel ());
			this->NUDIntervalReqRMG = (gcnew System::Windows::Forms::NumericUpDown ());
			this->label2 = (gcnew System::Windows::Forms::Label ());
			this->button1 = (gcnew System::Windows::Forms::Button ());
			this->BLoadDllRMG = (gcnew System::Windows::Forms::Button ());
			this->TPClose = (gcnew System::Windows::Forms::TabPage ());
			this->BClose = (gcnew System::Windows::Forms::Button ());
			this->FDOpenFl = (gcnew System::Windows::Forms::OpenFileDialog ());
			this->TBOut = (gcnew System::Windows::Forms::TextBox ());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip (this->components));
			this->TrWaitInitDrv = (gcnew System::Windows::Forms::Timer (this->components));
			this->IL24 = (gcnew System::Windows::Forms::ImageList (this->components));
			this->tabControl1->SuspendLayout ();
			this->TPSuperflo->SuspendLayout ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NUDIntervalReqSuper))->BeginInit ();
			this->TPRMG->SuspendLayout ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NUDIntervalReqRMG))->BeginInit ();
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
			this->tabControl1->Controls->Add (this->TPClose);
			this->tabControl1->Location = System::Drawing::Point (0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->Padding = System::Drawing::Point (16, 5);
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size (972, 293);
			this->tabControl1->TabIndex = 0;
			// 
			// TPSuperflo
			// 
			this->TPSuperflo->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->TPSuperflo->Controls->Add (this->LWaitSuper);
			this->TPSuperflo->Controls->Add (this->BScanComPorts);
			this->TPSuperflo->Controls->Add (this->CBComPort);
			this->TPSuperflo->Controls->Add (this->BWrSuper);
			this->TPSuperflo->Controls->Add (this->CBDevType);
			this->TPSuperflo->Controls->Add (this->GBWrParam);
			this->TPSuperflo->Controls->Add (this->NUDIntervalReqSuper);
			this->TPSuperflo->Controls->Add (this->label3);
			this->TPSuperflo->Controls->Add (this->label1);
			this->TPSuperflo->Controls->Add (this->BStartStopSuper);
			this->TPSuperflo->Controls->Add (this->PTagsRdSuper);
			this->TPSuperflo->Controls->Add (this->BLoadDllSuper);
			this->TPSuperflo->Location = System::Drawing::Point (4, 28);
			this->TPSuperflo->Name = L"TPSuperflo";
			this->TPSuperflo->Padding = System::Windows::Forms::Padding (3);
			this->TPSuperflo->Size = System::Drawing::Size (964, 261);
			this->TPSuperflo->TabIndex = 1;
			this->TPSuperflo->Text = L"Superflo";
			this->TPSuperflo->UseVisualStyleBackColor = true;
			// 
			// BScanComPorts
			// 
			this->BScanComPorts->Cursor = System::Windows::Forms::Cursors::Hand;
			this->BScanComPorts->Location = System::Drawing::Point (927, 1);
			this->BScanComPorts->Name = L"BScanComPorts";
			this->BScanComPorts->Size = System::Drawing::Size (32, 26);
			this->BScanComPorts->TabIndex = 11;
			this->BScanComPorts->UseVisualStyleBackColor = true;
			this->BScanComPorts->Click += gcnew System::EventHandler (this, &FTestCpp::BScanComPorts_Click);
			// 
			// CBComPort
			// 
			this->CBComPort->FormattingEnabled = true;
			this->CBComPort->Location = System::Drawing::Point (844, 2);
			this->CBComPort->Name = L"CBComPort";
			this->CBComPort->Size = System::Drawing::Size (80, 23);
			this->CBComPort->TabIndex = 10;
			// 
			// BWrSuper
			// 
			this->BWrSuper->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->BWrSuper->Cursor = System::Windows::Forms::Cursors::Hand;
			this->BWrSuper->Location = System::Drawing::Point (844, 48);
			this->BWrSuper->Name = L"BWrSuper";
			this->BWrSuper->Size = System::Drawing::Size (115, 28);
			this->BWrSuper->TabIndex = 9;
			this->BWrSuper->Text = L"Записать";
			this->BWrSuper->UseVisualStyleBackColor = true;
			this->BWrSuper->Click += gcnew System::EventHandler (this, &FTestCpp::BWrSuper_Click);
			// 
			// CBDevType
			// 
			this->CBDevType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->CBDevType->FormattingEnabled = true;
			this->CBDevType->Items->AddRange (gcnew cli::array< System::Object^  > (3) { L"SF21RU7C", L"SF21RU6D", L"SF21RU5D" });
			this->CBDevType->Location = System::Drawing::Point (516, 40);
			this->CBDevType->Name = L"CBDevType";
			this->CBDevType->Size = System::Drawing::Size (92, 23);
			this->CBDevType->TabIndex = 8;
			// 
			// LWaitSuper
			// 
			this->LWaitSuper->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->LWaitSuper->ForeColor = System::Drawing::Color::DarkRed;
			this->LWaitSuper->Location = System::Drawing::Point (628, 37);
			this->LWaitSuper->Name = L"LWaitSuper";
			this->LWaitSuper->Size = System::Drawing::Size (32, 26);
			this->LWaitSuper->TabIndex = 7;
			this->LWaitSuper->Text = L"0";
			this->LWaitSuper->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// GBWrParam
			// 
			this->GBWrParam->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->GBWrParam->Location = System::Drawing::Point (480, 68);
			this->GBWrParam->Name = L"GBWrParam";
			this->GBWrParam->Size = System::Drawing::Size (480, 189);
			this->GBWrParam->TabIndex = 6;
			this->GBWrParam->TabStop = false;
			this->GBWrParam->Text = L"Запись";
			// 
			// NUDIntervalReqSuper
			// 
			this->NUDIntervalReqSuper->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->NUDIntervalReqSuper->Increment = System::Decimal (gcnew cli::array< System::Int32 > (4) { 100, 0, 0, 0 });
			this->NUDIntervalReqSuper->Location = System::Drawing::Point (552, 6);
			this->NUDIntervalReqSuper->Maximum = System::Decimal (gcnew cli::array< System::Int32 > (4) { 1410065407, 2, 0, 0 });
			this->NUDIntervalReqSuper->Name = L"NUDIntervalReqSuper";
			this->NUDIntervalReqSuper->Size = System::Drawing::Size (84, 21);
			this->NUDIntervalReqSuper->TabIndex = 3;
			this->NUDIntervalReqSuper->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->NUDIntervalReqSuper->ThousandsSeparator = true;
			this->NUDIntervalReqSuper->Value = System::Decimal (gcnew cli::array< System::Int32 > (4) { 1000, 0, 0, 0 });
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point (484, 44);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size (28, 15);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Тип";
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label1->Location = System::Drawing::Point (484, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size (68, 32);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Интервал опроса";
			// 
			// BStartStopSuper
			// 
			this->BStartStopSuper->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->BStartStopSuper->Cursor = System::Windows::Forms::Cursors::Hand;
			this->BStartStopSuper->Enabled = false;
			this->BStartStopSuper->Location = System::Drawing::Point (660, 36);
			this->BStartStopSuper->Name = L"BStartStopSuper";
			this->BStartStopSuper->Size = System::Drawing::Size (108, 28);
			this->BStartStopSuper->TabIndex = 2;
			this->BStartStopSuper->Text = L"Старт";
			this->BStartStopSuper->UseVisualStyleBackColor = true;
			this->BStartStopSuper->Click += gcnew System::EventHandler (this, &FTestCpp::BStartStopSuper_Click);
			// 
			// PTagsRdSuper
			// 
			this->PTagsRdSuper->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->PTagsRdSuper->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->PTagsRdSuper->Location = System::Drawing::Point (0, 0);
			this->PTagsRdSuper->Name = L"PTagsRdSuper";
			this->PTagsRdSuper->Size = System::Drawing::Size (476, 257);
			this->PTagsRdSuper->TabIndex = 1;
			// 
			// BLoadDllSuper
			// 
			this->BLoadDllSuper->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->BLoadDllSuper->Cursor = System::Windows::Forms::Cursors::Hand;
			this->BLoadDllSuper->Location = System::Drawing::Point (640, 0);
			this->BLoadDllSuper->Name = L"BLoadDllSuper";
			this->BLoadDllSuper->Size = System::Drawing::Size (147, 28);
			this->BLoadDllSuper->TabIndex = 0;
			this->BLoadDllSuper->Text = L"Load dll Superflo";
			this->BLoadDllSuper->UseVisualStyleBackColor = true;
			this->BLoadDllSuper->Click += gcnew System::EventHandler (this, &FTestCpp::BLoadDllSuper_Click);
			// 
			// TPRMG
			// 
			this->TPRMG->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->TPRMG->Controls->Add (this->panel1);
			this->TPRMG->Controls->Add (this->NUDIntervalReqRMG);
			this->TPRMG->Controls->Add (this->label2);
			this->TPRMG->Controls->Add (this->button1);
			this->TPRMG->Controls->Add (this->BLoadDllRMG);
			this->TPRMG->Location = System::Drawing::Point (4, 28);
			this->TPRMG->Name = L"TPRMG";
			this->TPRMG->Padding = System::Windows::Forms::Padding (3);
			this->TPRMG->Size = System::Drawing::Size (964, 261);
			this->TPRMG->TabIndex = 0;
			this->TPRMG->Text = L"EC605";
			this->TPRMG->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Location = System::Drawing::Point (0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size (444, 264);
			this->panel1->TabIndex = 7;
			// 
			// NUDIntervalReqRMG
			// 
			this->NUDIntervalReqRMG->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->NUDIntervalReqRMG->Increment = System::Decimal (gcnew cli::array< System::Int32 > (4) { 100, 0, 0, 0 });
			this->NUDIntervalReqRMG->Location = System::Drawing::Point (532, 104);
			this->NUDIntervalReqRMG->Maximum = System::Decimal (gcnew cli::array< System::Int32 > (4) { 1410065407, 2, 0, 0 });
			this->NUDIntervalReqRMG->Name = L"NUDIntervalReqRMG";
			this->NUDIntervalReqRMG->Size = System::Drawing::Size (120, 21);
			this->NUDIntervalReqRMG->TabIndex = 6;
			this->NUDIntervalReqRMG->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->NUDIntervalReqRMG->ThousandsSeparator = true;
			this->NUDIntervalReqRMG->Value = System::Decimal (gcnew cli::array< System::Int32 > (4) { 1000, 0, 0, 0 });
			this->NUDIntervalReqRMG->ValueChanged += gcnew System::EventHandler (this, &FTestCpp::NUDIntervalReqRMG_ValueChanged);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point (528, 88);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size (109, 15);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Интервал опроса";
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Location = System::Drawing::Point (688, 76);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size (108, 28);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Старт";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// BLoadDllRMG
			// 
			this->BLoadDllRMG->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->BLoadDllRMG->Cursor = System::Windows::Forms::Cursors::Hand;
			this->BLoadDllRMG->Location = System::Drawing::Point (633, 44);
			this->BLoadDllRMG->Name = L"BLoadDllRMG";
			this->BLoadDllRMG->Size = System::Drawing::Size (163, 28);
			this->BLoadDllRMG->TabIndex = 3;
			this->BLoadDllRMG->Text = L"Load dll RMG";
			this->BLoadDllRMG->UseVisualStyleBackColor = true;
			this->BLoadDllRMG->Click += gcnew System::EventHandler (this, &FTestCpp::BLoadDllRMG_Click);
			// 
			// TPClose
			// 
			this->TPClose->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->TPClose->Controls->Add (this->BClose);
			this->TPClose->Location = System::Drawing::Point (4, 28);
			this->TPClose->Name = L"TPClose";
			this->TPClose->Padding = System::Windows::Forms::Padding (3);
			this->TPClose->Size = System::Drawing::Size (964, 261);
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
			this->BClose->Size = System::Drawing::Size (954, 65);
			this->BClose->TabIndex = 0;
			this->BClose->Text = L"Конец - делу венец";
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
			this->TBOut->Location = System::Drawing::Point (0, 293);
			this->TBOut->Multiline = true;
			this->TBOut->Name = L"TBOut";
			this->TBOut->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->TBOut->Size = System::Drawing::Size (972, 112);
			this->TBOut->TabIndex = 1;
			// 
			// TrWaitInitDrv
			// 
			this->TrWaitInitDrv->Interval = 1000;
			// 
			// IL24
			// 
			this->IL24->ColorDepth = System::Windows::Forms::ColorDepth::Depth16Bit;
			this->IL24->ImageSize = System::Drawing::Size (24, 24);
			this->IL24->TransparentColor = System::Drawing::Color::Transparent;
			// 
			// FTestCpp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF (7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size (972, 405);
			this->Controls->Add (this->TBOut);
			this->Controls->Add (this->tabControl1);
			this->Font = (gcnew System::Drawing::Font (L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MaximumSize = System::Drawing::Size (988, 1900);
			this->Name = L"FTestCpp";
			this->Text = L"Тест драйверов (на cpp)";
			this->tabControl1->ResumeLayout (false);
			this->TPSuperflo->ResumeLayout (false);
			this->TPSuperflo->PerformLayout ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NUDIntervalReqSuper))->EndInit ();
			this->TPRMG->ResumeLayout (false);
			this->TPRMG->PerformLayout ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NUDIntervalReqRMG))->EndInit ();
			this->TPClose->ResumeLayout (false);
			this->ResumeLayout (false);
			this->PerformLayout ();

		}
#pragma endregion
	private: System::Void BClose_Click (System::Object^ sender, System::EventArgs^ e)
	{
		if (SuperfloWork != nullptr)
			SuperfloWork->Exit ();
		if (RMGwork != nullptr)
			RMGwork->Exit ();
		Close ();
	}
	private: System::Void BLoadDll_Click (System::Object^ sender, System::EventArgs^ e);
	private: System::Void BLoadDllSuper_Click (System::Object^ sender, System::EventArgs^ e);
	private: System::Void BStartStopSuper_Click (System::Object^ sender, System::EventArgs^ e);
	private: System::Void NumericUpDown1_ValueChanged (System::Object^ sender, System::EventArgs^ e);
	private: System::Void BLoadDllRMG_Click (System::Object^ sender, System::EventArgs^ e);
	private: System::Void NUDIntervalReqRMG_ValueChanged (System::Object^ sender, System::EventArgs^ e);
					 void TrWaitInitDrvOnTick (System::Object^ sender, System::EventArgs^ e);
	private: System::Void BWrSuper_Click (System::Object^ sender, System::EventArgs^ e)
	{
		SuperfloWork->Write ((CTags^)GBWrParam->Controls[0]);
	}
	private: System::Void BScanComPorts_Click (System::Object^ sender, System::EventArgs^ e) 
	{
		ScanComPorts ();
	}
};
}

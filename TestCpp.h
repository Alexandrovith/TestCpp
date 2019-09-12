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
	private: System::Windows::Forms::Button^ BStartStopRMG;


	private: System::Windows::Forms::Button^ BLoadDllRMG;
	public: System::Windows::Forms::Panel^ PTagsRdRMG;
	private:

	private: System::Windows::Forms::NumericUpDown^ NUDIntervalReqRMG;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ CBComPort;
	private: System::Windows::Forms::Button^ BScanComPorts;
	private: System::Windows::Forms::ImageList^ IL24;
	private: System::Windows::Forms::Button^ BReloadSuperTags;
	private: System::Windows::Forms::RadioButton^ RBRrequest;
	private: System::Windows::Forms::RadioButton^ RBRrequestRMG;
	private: System::Windows::Forms::TextBox^ TBWaitSuper;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ TBWaitRMG;
	private: System::Windows::Forms::Button^ BReloadRMGTags;


	private: System::Windows::Forms::Label^ LWaitRMG;
	private: System::Windows::Forms::ComboBox^ CBComPortRMG;
	private: System::Windows::Forms::Button^ BWrRMG;
	private: System::Windows::Forms::Button^ BScanComPortsRMG;




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
	private: System::Windows::Forms::TabControl^ GBWrParamRMG;
	protected:

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
	private: System::Windows::Forms::Label^ rWaitSuper_RMG;
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
						 this->GBWrParamRMG = (gcnew System::Windows::Forms::TabControl ());
						 this->TPSuperflo = (gcnew System::Windows::Forms::TabPage ());
						 this->CBComPort = (gcnew System::Windows::Forms::ComboBox ());
						 this->BLoadDllSuper = (gcnew System::Windows::Forms::Button ());
						 this->TBWaitSuper = (gcnew System::Windows::Forms::TextBox ());
						 this->RBRrequest = (gcnew System::Windows::Forms::RadioButton ());
						 this->BReloadSuperTags = (gcnew System::Windows::Forms::Button ());
						 this->LWaitSuper = (gcnew System::Windows::Forms::Label ());
						 this->BScanComPorts = (gcnew System::Windows::Forms::Button ());
						 this->BWrSuper = (gcnew System::Windows::Forms::Button ());
						 this->CBDevType = (gcnew System::Windows::Forms::ComboBox ());
						 this->GBWrParam = (gcnew System::Windows::Forms::GroupBox ());
						 this->NUDIntervalReqSuper = (gcnew System::Windows::Forms::NumericUpDown ());
						 this->label3 = (gcnew System::Windows::Forms::Label ());
						 this->label1 = (gcnew System::Windows::Forms::Label ());
						 this->BStartStopSuper = (gcnew System::Windows::Forms::Button ());
						 this->PTagsRdSuper = (gcnew System::Windows::Forms::Panel ());
						 this->TPRMG = (gcnew System::Windows::Forms::TabPage ());
						 this->BScanComPortsRMG = (gcnew System::Windows::Forms::Button ());
						 this->TBWaitRMG = (gcnew System::Windows::Forms::TextBox ());
						 this->BReloadRMGTags = (gcnew System::Windows::Forms::Button ());
						 this->LWaitRMG = (gcnew System::Windows::Forms::Label ());
						 this->CBComPortRMG = (gcnew System::Windows::Forms::ComboBox ());
						 this->BWrRMG = (gcnew System::Windows::Forms::Button ());
						 this->groupBox1 = (gcnew System::Windows::Forms::GroupBox ());
						 this->RBRrequestRMG = (gcnew System::Windows::Forms::RadioButton ());
						 this->PTagsRdRMG = (gcnew System::Windows::Forms::Panel ());
						 this->NUDIntervalReqRMG = (gcnew System::Windows::Forms::NumericUpDown ());
						 this->label2 = (gcnew System::Windows::Forms::Label ());
						 this->BStartStopRMG = (gcnew System::Windows::Forms::Button ());
						 this->BLoadDllRMG = (gcnew System::Windows::Forms::Button ());
						 this->TPClose = (gcnew System::Windows::Forms::TabPage ());
						 this->BClose = (gcnew System::Windows::Forms::Button ());
						 this->FDOpenFl = (gcnew System::Windows::Forms::OpenFileDialog ());
						 this->TBOut = (gcnew System::Windows::Forms::TextBox ());
						 this->toolTip1 = (gcnew System::Windows::Forms::ToolTip (this->components));
						 this->TrWaitInitDrv = (gcnew System::Windows::Forms::Timer (this->components));
						 this->IL24 = (gcnew System::Windows::Forms::ImageList (this->components));
						 this->GBWrParamRMG->SuspendLayout ();
						 this->TPSuperflo->SuspendLayout ();
						 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NUDIntervalReqSuper))->BeginInit ();
						 this->TPRMG->SuspendLayout ();
						 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NUDIntervalReqRMG))->BeginInit ();
						 this->TPClose->SuspendLayout ();
						 this->SuspendLayout ();
						 // 
						 // GBWrParamRMG
						 // 
						 this->GBWrParamRMG->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
							 | System::Windows::Forms::AnchorStyles::Left)
							 | System::Windows::Forms::AnchorStyles::Right));
						 this->GBWrParamRMG->Controls->Add (this->TPSuperflo);
						 this->GBWrParamRMG->Controls->Add (this->TPRMG);
						 this->GBWrParamRMG->Controls->Add (this->TPClose);
						 this->GBWrParamRMG->Location = System::Drawing::Point (0, 0);
						 this->GBWrParamRMG->Name = L"GBWrParamRMG";
						 this->GBWrParamRMG->Padding = System::Drawing::Point (16, 5);
						 this->GBWrParamRMG->SelectedIndex = 0;
						 this->GBWrParamRMG->Size = System::Drawing::Size (972, 293);
						 this->GBWrParamRMG->TabIndex = 0;
						 // 
						 // TPSuperflo
						 // 
						 this->TPSuperflo->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
						 this->TPSuperflo->Controls->Add (this->CBComPort);
						 this->TPSuperflo->Controls->Add (this->BLoadDllSuper);
						 this->TPSuperflo->Controls->Add (this->TBWaitSuper);
						 this->TPSuperflo->Controls->Add (this->RBRrequest);
						 this->TPSuperflo->Controls->Add (this->BReloadSuperTags);
						 this->TPSuperflo->Controls->Add (this->LWaitSuper);
						 this->TPSuperflo->Controls->Add (this->BScanComPorts);
						 this->TPSuperflo->Controls->Add (this->BWrSuper);
						 this->TPSuperflo->Controls->Add (this->CBDevType);
						 this->TPSuperflo->Controls->Add (this->GBWrParam);
						 this->TPSuperflo->Controls->Add (this->NUDIntervalReqSuper);
						 this->TPSuperflo->Controls->Add (this->label3);
						 this->TPSuperflo->Controls->Add (this->label1);
						 this->TPSuperflo->Controls->Add (this->BStartStopSuper);
						 this->TPSuperflo->Controls->Add (this->PTagsRdSuper);
						 this->TPSuperflo->Location = System::Drawing::Point (4, 28);
						 this->TPSuperflo->Name = L"TPSuperflo";
						 this->TPSuperflo->Padding = System::Windows::Forms::Padding (3);
						 this->TPSuperflo->Size = System::Drawing::Size (964, 261);
						 this->TPSuperflo->TabIndex = 1;
						 this->TPSuperflo->Text = L"Superflo";
						 this->TPSuperflo->UseVisualStyleBackColor = true;
						 // 
						 // CBComPort
						 // 
						 this->CBComPort->FormattingEnabled = true;
						 this->CBComPort->Location = System::Drawing::Point (856, 2);
						 this->CBComPort->Name = L"CBComPort";
						 this->CBComPort->Size = System::Drawing::Size (70, 23);
						 this->CBComPort->TabIndex = 10;
						 this->CBComPort->SelectedIndexChanged += gcnew System::EventHandler (this, &FTestCpp::CBComPort_SelectedIndexChanged);
						 // 
						 // BLoadDllSuper
						 // 
						 this->BLoadDllSuper->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
						 this->BLoadDllSuper->Cursor = System::Windows::Forms::Cursors::Hand;
						 this->BLoadDllSuper->Location = System::Drawing::Point (592, 32);
						 this->BLoadDllSuper->Name = L"BLoadDllSuper";
						 this->BLoadDllSuper->Size = System::Drawing::Size (108, 28);
						 this->BLoadDllSuper->TabIndex = 0;
						 this->BLoadDllSuper->Text = L"Load dll";
						 this->BLoadDllSuper->UseVisualStyleBackColor = true;
						 this->BLoadDllSuper->Click += gcnew System::EventHandler (this, &FTestCpp::BLoadDllSuper_Click);
						 // 
						 // TBWaitSuper
						 // 
						 this->TBWaitSuper->Font = (gcnew System::Drawing::Font (L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
							 static_cast<System::Byte>(204)));
						 this->TBWaitSuper->ForeColor = System::Drawing::Color::DarkRed;
						 this->TBWaitSuper->Location = System::Drawing::Point (564, 62);
						 this->TBWaitSuper->Name = L"TBWaitSuper";
						 this->TBWaitSuper->Size = System::Drawing::Size (28, 23);
						 this->TBWaitSuper->TabIndex = 14;
						 this->TBWaitSuper->Text = L"3";
						 this->TBWaitSuper->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
						 this->TBWaitSuper->TextChanged += gcnew System::EventHandler (this, &FTestCpp::TBWaitSuper_TextChanged);
						 // 
						 // RBRrequest
						 // 
						 this->RBRrequest->AutoSize = true;
						 this->RBRrequest->Location = System::Drawing::Point (484, 8);
						 this->RBRrequest->Name = L"RBRrequest";
						 this->RBRrequest->Size = System::Drawing::Size (14, 13);
						 this->RBRrequest->TabIndex = 13;
						 this->RBRrequest->TabStop = true;
						 this->RBRrequest->UseVisualStyleBackColor = true;
						 // 
						 // BReloadSuperTags
						 // 
						 this->BReloadSuperTags->Cursor = System::Windows::Forms::Cursors::Hand;
						 this->BReloadSuperTags->Location = System::Drawing::Point (476, 52);
						 this->BReloadSuperTags->Margin = System::Windows::Forms::Padding (1);
						 this->BReloadSuperTags->Name = L"BReloadSuperTags";
						 this->BReloadSuperTags->Size = System::Drawing::Size (56, 29);
						 this->BReloadSuperTags->TabIndex = 12;
						 this->BReloadSuperTags->Text = L"Reload";
						 this->BReloadSuperTags->UseVisualStyleBackColor = true;
						 this->BReloadSuperTags->Click += gcnew System::EventHandler (this, &FTestCpp::BReloadSuperTags_Click);
						 // 
						 // LWaitSuper
						 // 
						 this->LWaitSuper->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
						 this->LWaitSuper->ForeColor = System::Drawing::Color::DarkRed;
						 this->LWaitSuper->Location = System::Drawing::Point (700, 62);
						 this->LWaitSuper->Name = L"LWaitSuper";
						 this->LWaitSuper->Size = System::Drawing::Size (28, 23);
						 this->LWaitSuper->TabIndex = 7;
						 this->LWaitSuper->Text = L"0";
						 this->LWaitSuper->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
						 this->LWaitSuper->Click += gcnew System::EventHandler (this, &FTestCpp::LWaitSuper_Click);
						 // 
						 // BScanComPorts
						 // 
						 this->BScanComPorts->Cursor = System::Windows::Forms::Cursors::Hand;
						 this->BScanComPorts->Location = System::Drawing::Point (927, 1);
						 this->BScanComPorts->Name = L"BScanComPorts";
						 this->BScanComPorts->Size = System::Drawing::Size (32, 26);
						 this->BScanComPorts->TabIndex = 11;
						 this->toolTip1->SetToolTip (this->BScanComPorts, L"Перечитать порты");
						 this->BScanComPorts->UseVisualStyleBackColor = true;
						 this->BScanComPorts->Click += gcnew System::EventHandler (this, &FTestCpp::BScanComPorts_Click);
						 // 
						 // BWrSuper
						 // 
						 this->BWrSuper->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
						 this->BWrSuper->Cursor = System::Windows::Forms::Cursors::Hand;
						 this->BWrSuper->Location = System::Drawing::Point (844, 68);
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
						 this->CBDevType->Location = System::Drawing::Point (740, 2);
						 this->CBDevType->Name = L"CBDevType";
						 this->CBDevType->Size = System::Drawing::Size (92, 23);
						 this->CBDevType->TabIndex = 8;
						 // 
						 // GBWrParam
						 // 
						 this->GBWrParam->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
							 | System::Windows::Forms::AnchorStyles::Left));
						 this->GBWrParam->Location = System::Drawing::Point (480, 88);
						 this->GBWrParam->Name = L"GBWrParam";
						 this->GBWrParam->Size = System::Drawing::Size (480, 169);
						 this->GBWrParam->TabIndex = 6;
						 this->GBWrParam->TabStop = false;
						 this->GBWrParam->Text = L"Запись";
						 // 
						 // NUDIntervalReqSuper
						 // 
						 this->NUDIntervalReqSuper->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
						 this->NUDIntervalReqSuper->Increment = System::Decimal (gcnew cli::array< System::Int32 > (4) { 100, 0, 0, 0 });
						 this->NUDIntervalReqSuper->Location = System::Drawing::Point (592, 4);
						 this->NUDIntervalReqSuper->Maximum = System::Decimal (gcnew cli::array< System::Int32 > (4) { 1410065407, 2, 0, 0 });
						 this->NUDIntervalReqSuper->Name = L"NUDIntervalReqSuper";
						 this->NUDIntervalReqSuper->Size = System::Drawing::Size (84, 21);
						 this->NUDIntervalReqSuper->TabIndex = 3;
						 this->NUDIntervalReqSuper->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
						 this->NUDIntervalReqSuper->ThousandsSeparator = true;
						 this->NUDIntervalReqSuper->Value = System::Decimal (gcnew cli::array< System::Int32 > (4) { 1000, 0, 0, 0 });
						 this->NUDIntervalReqSuper->ValueChanged += gcnew System::EventHandler (this, &FTestCpp::NumericUpDown1_ValueChanged);
						 // 
						 // label3
						 // 
						 this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
						 this->label3->AutoSize = true;
						 this->label3->Location = System::Drawing::Point (708, 4);
						 this->label3->Name = L"label3";
						 this->label3->Size = System::Drawing::Size (28, 15);
						 this->label3->TabIndex = 2;
						 this->label3->Text = L"Тип";
						 // 
						 // label1
						 // 
						 this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
						 this->label1->Location = System::Drawing::Point (524, -2);
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
						 this->BStartStopSuper->Location = System::Drawing::Point (592, 60);
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
						 // TPRMG
						 // 
						 this->TPRMG->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
						 this->TPRMG->Controls->Add (this->BScanComPortsRMG);
						 this->TPRMG->Controls->Add (this->TBWaitRMG);
						 this->TPRMG->Controls->Add (this->BReloadRMGTags);
						 this->TPRMG->Controls->Add (this->LWaitRMG);
						 this->TPRMG->Controls->Add (this->CBComPortRMG);
						 this->TPRMG->Controls->Add (this->BWrRMG);
						 this->TPRMG->Controls->Add (this->groupBox1);
						 this->TPRMG->Controls->Add (this->RBRrequestRMG);
						 this->TPRMG->Controls->Add (this->PTagsRdRMG);
						 this->TPRMG->Controls->Add (this->NUDIntervalReqRMG);
						 this->TPRMG->Controls->Add (this->label2);
						 this->TPRMG->Controls->Add (this->BStartStopRMG);
						 this->TPRMG->Controls->Add (this->BLoadDllRMG);
						 this->TPRMG->Location = System::Drawing::Point (4, 28);
						 this->TPRMG->Name = L"TPRMG";
						 this->TPRMG->Padding = System::Windows::Forms::Padding (3);
						 this->TPRMG->Size = System::Drawing::Size (964, 261);
						 this->TPRMG->TabIndex = 0;
						 this->TPRMG->Text = L"EC605";
						 this->TPRMG->UseVisualStyleBackColor = true;
						 this->TPRMG->Click += gcnew System::EventHandler (this, &FTestCpp::TPRMG_Click);
						 // 
						 // BScanComPortsRMG
						 // 
						 this->BScanComPortsRMG->Cursor = System::Windows::Forms::Cursors::Hand;
						 this->BScanComPortsRMG->Location = System::Drawing::Point (922, 2);
						 this->BScanComPortsRMG->Name = L"BScanComPortsRMG";
						 this->BScanComPortsRMG->Size = System::Drawing::Size (32, 26);
						 this->BScanComPortsRMG->TabIndex = 21;
						 this->toolTip1->SetToolTip (this->BScanComPortsRMG, L"Перечитать порты");
						 this->BScanComPortsRMG->UseVisualStyleBackColor = true;
						 this->BScanComPortsRMG->Click += gcnew System::EventHandler (this, &FTestCpp::BScanComPorts_Click);
						 // 
						 // TBWaitRMG
						 // 
						 this->TBWaitRMG->Font = (gcnew System::Drawing::Font (L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
							 static_cast<System::Byte>(204)));
						 this->TBWaitRMG->ForeColor = System::Drawing::Color::DarkRed;
						 this->TBWaitRMG->Location = System::Drawing::Point (656, 41);
						 this->TBWaitRMG->Name = L"TBWaitRMG";
						 this->TBWaitRMG->Size = System::Drawing::Size (28, 23);
						 this->TBWaitRMG->TabIndex = 20;
						 this->TBWaitRMG->Text = L"3";
						 this->TBWaitRMG->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
						 this->TBWaitRMG->TextChanged += gcnew System::EventHandler (this, &FTestCpp::TBWaitRMG_TextChanged);
						 // 
						 // BReloadRMGTags
						 // 
						 this->BReloadRMGTags->Cursor = System::Windows::Forms::Cursors::Hand;
						 this->BReloadRMGTags->Location = System::Drawing::Point (480, 39);
						 this->BReloadRMGTags->Margin = System::Windows::Forms::Padding (1);
						 this->BReloadRMGTags->Name = L"BReloadRMGTags";
						 this->BReloadRMGTags->Size = System::Drawing::Size (56, 25);
						 this->BReloadRMGTags->TabIndex = 19;
						 this->BReloadRMGTags->Text = L"Reload";
						 this->BReloadRMGTags->UseVisualStyleBackColor = true;
						 this->BReloadRMGTags->Click += gcnew System::EventHandler (this, &FTestCpp::BReloadRMGTags_Click);
						 // 
						 // LWaitRMG
						 // 
						 this->LWaitRMG->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
						 this->LWaitRMG->ForeColor = System::Drawing::Color::DarkRed;
						 this->LWaitRMG->Location = System::Drawing::Point (792, 41);
						 this->LWaitRMG->Name = L"LWaitRMG";
						 this->LWaitRMG->Size = System::Drawing::Size (28, 23);
						 this->LWaitRMG->TabIndex = 16;
						 this->LWaitRMG->Text = L"0";
						 this->LWaitRMG->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
						 this->LWaitRMG->Click += gcnew System::EventHandler (this, &FTestCpp::LWaitRMG_Click);
						 // 
						 // CBComPortRMG
						 // 
						 this->CBComPortRMG->FormattingEnabled = true;
						 this->CBComPortRMG->Location = System::Drawing::Point (840, 4);
						 this->CBComPortRMG->Name = L"CBComPortRMG";
						 this->CBComPortRMG->Size = System::Drawing::Size (80, 23);
						 this->CBComPortRMG->TabIndex = 18;
						 this->CBComPortRMG->SelectedIndexChanged += gcnew System::EventHandler (this, &FTestCpp::ComboBox1_SelectedIndexChanged);
						 // 
						 // BWrRMG
						 // 
						 this->BWrRMG->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
						 this->BWrRMG->Cursor = System::Windows::Forms::Cursors::Hand;
						 this->BWrRMG->Location = System::Drawing::Point (848, 68);
						 this->BWrRMG->Name = L"BWrRMG";
						 this->BWrRMG->Size = System::Drawing::Size (115, 28);
						 this->BWrRMG->TabIndex = 17;
						 this->BWrRMG->Text = L"Записать";
						 this->BWrRMG->UseVisualStyleBackColor = true;
						 this->BWrRMG->Click += gcnew System::EventHandler (this, &FTestCpp::BWrRMG_Click);
						 // 
						 // groupBox1
						 // 
						 this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
							 | System::Windows::Forms::AnchorStyles::Left));
						 this->groupBox1->Location = System::Drawing::Point (482, 88);
						 this->groupBox1->Name = L"groupBox1";
						 this->groupBox1->Size = System::Drawing::Size (480, 169);
						 this->groupBox1->TabIndex = 9;
						 this->groupBox1->TabStop = false;
						 this->groupBox1->Text = L"Запись";
						 // 
						 // RBRrequestRMG
						 // 
						 this->RBRrequestRMG->AutoSize = true;
						 this->RBRrequestRMG->Location = System::Drawing::Point (484, 12);
						 this->RBRrequestRMG->Name = L"RBRrequestRMG";
						 this->RBRrequestRMG->Size = System::Drawing::Size (14, 13);
						 this->RBRrequestRMG->TabIndex = 8;
						 this->RBRrequestRMG->TabStop = true;
						 this->RBRrequestRMG->UseVisualStyleBackColor = true;
						 // 
						 // PTagsRdRMG
						 // 
						 this->PTagsRdRMG->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
							 | System::Windows::Forms::AnchorStyles::Left));
						 this->PTagsRdRMG->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
						 this->PTagsRdRMG->Location = System::Drawing::Point (0, 0);
						 this->PTagsRdRMG->Name = L"PTagsRdRMG";
						 this->PTagsRdRMG->Size = System::Drawing::Size (476, 257);
						 this->PTagsRdRMG->TabIndex = 7;
						 this->PTagsRdRMG->Paint += gcnew System::Windows::Forms::PaintEventHandler (this, &FTestCpp::Panel1_Paint);
						 // 
						 // NUDIntervalReqRMG
						 // 
						 this->NUDIntervalReqRMG->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
						 this->NUDIntervalReqRMG->Increment = System::Decimal (gcnew cli::array< System::Int32 > (4) { 100, 0, 0, 0 });
						 this->NUDIntervalReqRMG->Location = System::Drawing::Point (624, 4);
						 this->NUDIntervalReqRMG->Maximum = System::Decimal (gcnew cli::array< System::Int32 > (4) { 1410065407, 2, 0, 0 });
						 this->NUDIntervalReqRMG->Name = L"NUDIntervalReqRMG";
						 this->NUDIntervalReqRMG->Size = System::Drawing::Size (100, 21);
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
						 this->label2->Location = System::Drawing::Point (516, 8);
						 this->label2->Name = L"label2";
						 this->label2->Size = System::Drawing::Size (109, 15);
						 this->label2->TabIndex = 5;
						 this->label2->Text = L"Интервал опроса";
						 // 
						 // BStartStopRMG
						 // 
						 this->BStartStopRMG->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
						 this->BStartStopRMG->Cursor = System::Windows::Forms::Cursors::Hand;
						 this->BStartStopRMG->Location = System::Drawing::Point (684, 39);
						 this->BStartStopRMG->Name = L"BStartStopRMG";
						 this->BStartStopRMG->Size = System::Drawing::Size (108, 28);
						 this->BStartStopRMG->TabIndex = 4;
						 this->BStartStopRMG->Text = L"Старт";
						 this->BStartStopRMG->UseVisualStyleBackColor = true;
						 this->BStartStopRMG->Click += gcnew System::EventHandler (this, &FTestCpp::BStartStopRMG_Click);
						 // 
						 // BLoadDllRMG
						 // 
						 this->BLoadDllRMG->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
						 this->BLoadDllRMG->Cursor = System::Windows::Forms::Cursors::Hand;
						 this->BLoadDllRMG->Location = System::Drawing::Point (552, 39);
						 this->BLoadDllRMG->Name = L"BLoadDllRMG";
						 this->BLoadDllRMG->Size = System::Drawing::Size (92, 28);
						 this->BLoadDllRMG->TabIndex = 3;
						 this->BLoadDllRMG->Text = L"Load dll";
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
						 this->Controls->Add (this->GBWrParamRMG);
						 this->Font = (gcnew System::Drawing::Font (L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
							 static_cast<System::Byte>(204)));
						 this->MaximumSize = System::Drawing::Size (988, 1900);
						 this->Name = L"FTestCpp";
						 this->Text = L"Тест драйверов (на cpp)";
						 this->GBWrParamRMG->ResumeLayout (false);
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
	//___________________________________________________________________________

	private: System::Void BClose_Click (System::Object^ sender, System::EventArgs^ e)
	{
		if (SuperfloWork != nullptr)
			SuperfloWork->Exit ();
		if (RMGwork != nullptr)
			RMGwork->Exit ();
		Close ();
	}
	//___________________________________________________________________________

	private: System::Void BLoadDll_Click (System::Object^ sender, System::EventArgs^ e);
	private: System::Void BLoadDllSuper_Click (System::Object^ sender, System::EventArgs^ e);
	private: System::Void BStartStopSuper_Click (System::Object^ sender, System::EventArgs^ e);
	private: System::Void NumericUpDown1_ValueChanged (System::Object^ sender, System::EventArgs^ e);
	private: System::Void BLoadDllRMG_Click (System::Object^ sender, System::EventArgs^ e);
	private: System::Void NUDIntervalReqRMG_ValueChanged (System::Object^ sender, System::EventArgs^ e);
					 void TrWaitInitDrvOnTick (System::Object^ sender, System::EventArgs^ e);
					 private: void RButBlink ();
					 private: void RButBlinkRMG ();

	//___________________________________________________________________________

	private: System::Void BWrSuper_Click (System::Object^ sender, System::EventArgs^ e)
	{
		SuperfloWork->Write ((CTags^)GBWrParam->Controls[0]);
	}
	//___________________________________________________________________________

	private: System::Void BScanComPorts_Click (System::Object^ sender, System::EventArgs^ e)
	{
		ScanComPorts ();
	}
	//___________________________________________________________________________

	private: System::Void BReloadSuperTags_Click (System::Object^ sender, System::EventArgs^ e)
	{
		PTagsRdSuper->Controls->Clear ();
		GBWrParam->Controls->Clear ();
		CreateTagsFrame ("Superflo.prmd", PTagsRdSuper, GBWrParam);
	}
	private: System::Void Panel1_Paint (System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
private: System::Void BStartStopRMG_Click (System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void TBWaitSuper_TextChanged (System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void LWaitSuper_Click (System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void CBComPort_SelectedIndexChanged (System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void TPRMG_Click (System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void ComboBox1_SelectedIndexChanged (System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Button3_Click (System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void BReloadRMGTags_Click (System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void LWaitRMG_Click (System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void BWrRMG_Click (System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void TBWaitRMG_TextChanged (System::Object^ sender, System::EventArgs^ e) {
}
};
}

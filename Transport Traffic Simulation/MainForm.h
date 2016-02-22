#pragma once

#include "Way.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace ThinkGeo::MapSuite::Core;
using namespace ThinkGeo::MapSuite::DesktopEdition;

public ref class MainForm : public System::Windows::Forms::Form
{
public:
	MainForm(void);
protected:
	~MainForm();
private:
	System::ComponentModel::Container ^components;
	System::Windows::Forms::TextBox^  tbTitleCity;
	ThinkGeo::MapSuite::DesktopEdition::WinformsMap^  Map;
	System::Windows::Forms::ComboBox^  cbCities;
	System::Windows::Forms::ComboBox^  cbWays;
	System::Windows::Forms::Button^  btnLoadCity;
	System::Windows::Forms::Button^  btnSaveCity;
	System::Windows::Forms::Button^  btnDeleteCity;
	System::Windows::Forms::Button^  btnLoadWay;
	System::Windows::Forms::DataGridView^  tableWay;
	System::Windows::Forms::DataGridViewTextBoxColumn^  X;
	System::Windows::Forms::DataGridViewTextBoxColumn^  Y;
	System::Windows::Forms::DataGridViewTextBoxColumn^  Тип;
	System::Windows::Forms::DataGridViewTextBoxColumn^  Название_остановки;
	System::Windows::Forms::DataGridViewTextBoxColumn^  Код;
	System::Windows::Forms::Button^  btnTableAdd;
	System::Windows::Forms::Button^  btnTableInsert;
	System::Windows::Forms::Button^  btnTableEdit;
	System::Windows::Forms::Button^  btnTableDelete;
	System::Windows::Forms::Button^  btnTableClear;
	System::Windows::Forms::Label^  label1;
	System::Windows::Forms::TextBox^  tbTitleWay;
	System::Windows::Forms::Label^  label2;
	System::Windows::Forms::DateTimePicker^  timeStart;
	System::Windows::Forms::Label^  label3;
	System::Windows::Forms::DateTimePicker^  timeEnd;
	System::Windows::Forms::Label^  label4;
	System::Windows::Forms::DateTimePicker^  timeInterval;
	System::Windows::Forms::Label^  label5;
	System::Windows::Forms::Label^  label7;
	System::Windows::Forms::NumericUpDown^  tbQuantity;
	System::Windows::Forms::ComboBox^  cbTransportType;
	System::Windows::Forms::Button^  btnSaveWay;
	System::Windows::Forms::Button^  btnDeleteWay;
	System::Windows::Forms::Button^  btnTest;
	System::Windows::Forms::Button^  btnStartStop;
	System::Windows::Forms::Button^  btnPauseReturn;
	System::Windows::Forms::Label^  label6;
	System::Windows::Forms::TrackBar^  tbSpeed;
	System::Windows::Forms::Label^  lblSpeed;
	System::Windows::Forms::Label^  lblGlobalTime;
	System::Windows::Forms::Label^  label9;
	System::Windows::Forms::Label^  label10;
	System::Windows::Forms::Label^  lblTimeWay;
	System::Windows::Forms::Label^  lblNextStop;
	System::Windows::Forms::Label^  label8;
	System::Windows::Forms::Label^  label11;
	System::Windows::Forms::TextBox^  tbX;
	System::Windows::Forms::TextBox^  tbY;
	System::Windows::Forms::Label^  label12;
	System::Windows::Forms::Label^  label13;
	System::Windows::Forms::Label^  label14;
	System::Windows::Forms::TextBox^  tbTitleStop;
	System::Windows::Forms::ComboBox^  cbPointType;
	System::Windows::Forms::PictureBox ^Pict;
	String^ CitiesName;
	String^ CityName;
	PointShape ^pointShape;
	Way ^way;
	System::Void LoadCities(String ^);
	System::Void LoadCity(String ^);
	System::Void LoadWay(String ^);
	System::Void SaveCity(String ^);
	System::Void SaveWay(String ^);
	System::Void DeleteCity(String ^);
	System::Void DeleteWay(String ^);
	System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e);
	System::Void Map_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	System::Void btnLoadCity_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void btnSaveCity_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void btnDeleteCity_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void btnLoadWay_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void btnSaveWay_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void btnDeleteWay_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void tbSpeed_Scroll(System::Object^  sender, System::EventArgs^  e);
	System::Void tableWay_SelectionChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void btnTableAdd_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void btnTableInsert_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void btnTableEdit_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void btnTableDelete_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void btnTableClear_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void btnTest_Click(System::Object^  sender, System::EventArgs^  e);

#pragma region Windows Form Designer generated code
	void InitializeComponent(void)
	{
		this->Map = (gcnew ThinkGeo::MapSuite::DesktopEdition::WinformsMap());
		this->tbTitleCity = (gcnew System::Windows::Forms::TextBox());
		this->cbCities = (gcnew System::Windows::Forms::ComboBox());
		this->cbWays = (gcnew System::Windows::Forms::ComboBox());
		this->btnLoadCity = (gcnew System::Windows::Forms::Button());
		this->btnLoadWay = (gcnew System::Windows::Forms::Button());
		this->btnSaveCity = (gcnew System::Windows::Forms::Button());
		this->tableWay = (gcnew System::Windows::Forms::DataGridView());
		this->X = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Y = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Тип = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Название_остановки = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Код = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->btnTableAdd = (gcnew System::Windows::Forms::Button());
		this->btnTableInsert = (gcnew System::Windows::Forms::Button());
		this->btnTableEdit = (gcnew System::Windows::Forms::Button());
		this->btnTableDelete = (gcnew System::Windows::Forms::Button());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->tbTitleWay = (gcnew System::Windows::Forms::TextBox());
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->timeStart = (gcnew System::Windows::Forms::DateTimePicker());
		this->label3 = (gcnew System::Windows::Forms::Label());
		this->timeEnd = (gcnew System::Windows::Forms::DateTimePicker());
		this->label4 = (gcnew System::Windows::Forms::Label());
		this->timeInterval = (gcnew System::Windows::Forms::DateTimePicker());
		this->label5 = (gcnew System::Windows::Forms::Label());
		this->btnSaveWay = (gcnew System::Windows::Forms::Button());
		this->btnDeleteWay = (gcnew System::Windows::Forms::Button());
		this->btnTest = (gcnew System::Windows::Forms::Button());
		this->btnStartStop = (gcnew System::Windows::Forms::Button());
		this->btnPauseReturn = (gcnew System::Windows::Forms::Button());
		this->label6 = (gcnew System::Windows::Forms::Label());
		this->tbSpeed = (gcnew System::Windows::Forms::TrackBar());
		this->lblSpeed = (gcnew System::Windows::Forms::Label());
		this->lblGlobalTime = (gcnew System::Windows::Forms::Label());
		this->label9 = (gcnew System::Windows::Forms::Label());
		this->label10 = (gcnew System::Windows::Forms::Label());
		this->lblTimeWay = (gcnew System::Windows::Forms::Label());
		this->lblNextStop = (gcnew System::Windows::Forms::Label());
		this->label8 = (gcnew System::Windows::Forms::Label());
		this->label7 = (gcnew System::Windows::Forms::Label());
		this->label11 = (gcnew System::Windows::Forms::Label());
		this->tbX = (gcnew System::Windows::Forms::TextBox());
		this->tbY = (gcnew System::Windows::Forms::TextBox());
		this->label12 = (gcnew System::Windows::Forms::Label());
		this->label13 = (gcnew System::Windows::Forms::Label());
		this->label14 = (gcnew System::Windows::Forms::Label());
		this->tbTitleStop = (gcnew System::Windows::Forms::TextBox());
		this->cbPointType = (gcnew System::Windows::Forms::ComboBox());
		this->btnDeleteCity = (gcnew System::Windows::Forms::Button());
		this->tbQuantity = (gcnew System::Windows::Forms::NumericUpDown());
		this->cbTransportType = (gcnew System::Windows::Forms::ComboBox());
		this->btnTableClear = (gcnew System::Windows::Forms::Button());
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tableWay))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbSpeed))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbQuantity))->BeginInit();
		this->SuspendLayout();
		// 
		// Map
		// 
		this->Map->BackColor = System::Drawing::Color::White;
		this->Map->CompositingQuality = System::Drawing::Drawing2D::CompositingQuality::Default;
		this->Map->CurrentScale = 1128.49722;
		this->Map->DrawingQuality = ThinkGeo::MapSuite::Core::DrawingQuality::Default;
		this->Map->Location = System::Drawing::Point(0, 23);
		this->Map->MapFocusMode = ThinkGeo::MapSuite::DesktopEdition::MapFocusMode::Default;
		this->Map->MapResizeMode = ThinkGeo::MapSuite::Core::MapResizeMode::PreserveScale;
		this->Map->MapUnit = ThinkGeo::MapSuite::Core::GeographyUnit::Meter;
		this->Map->MaximumScale = 80000000000000;
		this->Map->MinimumScale = 200;
		this->Map->Name = L"Map";
		this->Map->Size = System::Drawing::Size(677, 514);
		this->Map->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::Default;
		this->Map->TabIndex = 0;
		this->Map->TextRenderingHint = System::Drawing::Text::TextRenderingHint::AntiAlias;
		this->Map->ThreadingMode = ThinkGeo::MapSuite::DesktopEdition::MapThreadingMode::Multithreaded;
		this->Map->ZoomLevelSnapping = ThinkGeo::MapSuite::DesktopEdition::ZoomLevelSnappingMode::Default;
		this->Map->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::Map_MouseClick);
		// 
		// tbTitleCity
		// 
		this->tbTitleCity->Location = System::Drawing::Point(426, 3);
		this->tbTitleCity->MaxLength = 255;
		this->tbTitleCity->Name = L"tbTitleCity";
		this->tbTitleCity->Size = System::Drawing::Size(100, 20);
		this->tbTitleCity->TabIndex = 1;
		// 
		// cbCities
		// 
		this->cbCities->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->cbCities->FormattingEnabled = true;
		this->cbCities->Location = System::Drawing::Point(0, 1);
		this->cbCities->Name = L"cbCities";
		this->cbCities->Size = System::Drawing::Size(132, 21);
		this->cbCities->TabIndex = 3;
		// 
		// cbWays
		// 
		this->cbWays->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->cbWays->FormattingEnabled = true;
		this->cbWays->Location = System::Drawing::Point(219, 1);
		this->cbWays->Name = L"cbWays";
		this->cbWays->Size = System::Drawing::Size(121, 21);
		this->cbWays->TabIndex = 4;
		// 
		// btnLoadCity
		// 
		this->btnLoadCity->Location = System::Drawing::Point(138, 0);
		this->btnLoadCity->Name = L"btnLoadCity";
		this->btnLoadCity->Size = System::Drawing::Size(75, 23);
		this->btnLoadCity->TabIndex = 5;
		this->btnLoadCity->Text = L"Загрузить";
		this->btnLoadCity->UseVisualStyleBackColor = true;
		this->btnLoadCity->Click += gcnew System::EventHandler(this, &MainForm::btnLoadCity_Click);
		// 
		// btnLoadWay
		// 
		this->btnLoadWay->Location = System::Drawing::Point(346, 1);
		this->btnLoadWay->Name = L"btnLoadWay";
		this->btnLoadWay->Size = System::Drawing::Size(75, 23);
		this->btnLoadWay->TabIndex = 6;
		this->btnLoadWay->Text = L"Загрузить";
		this->btnLoadWay->UseVisualStyleBackColor = true;
		this->btnLoadWay->Click += gcnew System::EventHandler(this, &MainForm::btnLoadWay_Click);
		// 
		// btnSaveCity
		// 
		this->btnSaveCity->Location = System::Drawing::Point(532, 1);
		this->btnSaveCity->Name = L"btnSaveCity";
		this->btnSaveCity->Size = System::Drawing::Size(71, 23);
		this->btnSaveCity->TabIndex = 7;
		this->btnSaveCity->Text = L"Сохранить город";
		this->btnSaveCity->UseVisualStyleBackColor = true;
		this->btnSaveCity->Click += gcnew System::EventHandler(this, &MainForm::btnSaveCity_Click);
		// 
		// tableWay
		// 
		this->tableWay->AllowUserToAddRows = false;
		this->tableWay->AllowUserToDeleteRows = false;
		this->tableWay->AllowUserToResizeColumns = false;
		this->tableWay->AllowUserToResizeRows = false;
		this->tableWay->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->tableWay->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
			this->X, this->Y,
				this->Тип, this->Название_остановки, this->Код
		});
		this->tableWay->Location = System::Drawing::Point(683, 1);
		this->tableWay->MultiSelect = false;
		this->tableWay->Name = L"tableWay";
		this->tableWay->ReadOnly = true;
		this->tableWay->Size = System::Drawing::Size(323, 173);
		this->tableWay->TabIndex = 8;
		this->tableWay->SelectionChanged += gcnew System::EventHandler(this, &MainForm::tableWay_SelectionChanged);
		// 
		// X
		// 
		this->X->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->X->HeaderText = L"X";
		this->X->Name = L"X";
		this->X->ReadOnly = true;
		this->X->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->X->Width = 20;
		// 
		// Y
		// 
		this->Y->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->Y->HeaderText = L"Y";
		this->Y->Name = L"Y";
		this->Y->ReadOnly = true;
		this->Y->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Y->Width = 20;
		// 
		// Тип
		// 
		this->Тип->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->Тип->HeaderText = L"Тип";
		this->Тип->Name = L"Тип";
		this->Тип->ReadOnly = true;
		this->Тип->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Тип->Width = 32;
		// 
		// Название_остановки
		// 
		this->Название_остановки->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->Название_остановки->HeaderText = L"Название остановки";
		this->Название_остановки->Name = L"Название_остановки";
		this->Название_остановки->ReadOnly = true;
		this->Название_остановки->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Название_остановки->Width = 107;
		// 
		// Код
		// 
		this->Код->HeaderText = L"Код";
		this->Код->Name = L"Код";
		this->Код->ReadOnly = true;
		this->Код->Visible = false;
		// 
		// btnTableAdd
		// 
		this->btnTableAdd->Location = System::Drawing::Point(683, 180);
		this->btnTableAdd->Name = L"btnTableAdd";
		this->btnTableAdd->Size = System::Drawing::Size(67, 23);
		this->btnTableAdd->TabIndex = 9;
		this->btnTableAdd->Text = L"Добавить";
		this->btnTableAdd->UseVisualStyleBackColor = true;
		this->btnTableAdd->Click += gcnew System::EventHandler(this, &MainForm::btnTableAdd_Click);
		// 
		// btnTableInsert
		// 
		this->btnTableInsert->Location = System::Drawing::Point(756, 180);
		this->btnTableInsert->Name = L"btnTableInsert";
		this->btnTableInsert->Size = System::Drawing::Size(62, 23);
		this->btnTableInsert->TabIndex = 10;
		this->btnTableInsert->Text = L"Вставить";
		this->btnTableInsert->UseVisualStyleBackColor = true;
		this->btnTableInsert->Click += gcnew System::EventHandler(this, &MainForm::btnTableInsert_Click);
		// 
		// btnTableEdit
		// 
		this->btnTableEdit->Location = System::Drawing::Point(824, 180);
		this->btnTableEdit->Name = L"btnTableEdit";
		this->btnTableEdit->Size = System::Drawing::Size(96, 23);
		this->btnTableEdit->TabIndex = 11;
		this->btnTableEdit->Text = L"Редактировать";
		this->btnTableEdit->UseVisualStyleBackColor = true;
		this->btnTableEdit->Click += gcnew System::EventHandler(this, &MainForm::btnTableEdit_Click);
		// 
		// btnTableDelete
		// 
		this->btnTableDelete->Location = System::Drawing::Point(926, 180);
		this->btnTableDelete->Name = L"btnTableDelete";
		this->btnTableDelete->Size = System::Drawing::Size(75, 23);
		this->btnTableDelete->TabIndex = 12;
		this->btnTableDelete->Text = L"Удалить";
		this->btnTableDelete->UseVisualStyleBackColor = true;
		this->btnTableDelete->Click += gcnew System::EventHandler(this, &MainForm::btnTableDelete_Click);
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Location = System::Drawing::Point(684, 210);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(113, 13);
		this->label1->TabIndex = 13;
		this->label1->Text = L"Название маршрута:";
		// 
		// tbTitleWay
		// 
		this->tbTitleWay->Location = System::Drawing::Point(824, 207);
		this->tbTitleWay->MaxLength = 255;
		this->tbTitleWay->Name = L"tbTitleWay";
		this->tbTitleWay->Size = System::Drawing::Size(96, 20);
		this->tbTitleWay->TabIndex = 14;
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->Location = System::Drawing::Point(684, 233);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(134, 13);
		this->label2->TabIndex = 15;
		this->label2->Text = L"Время начала движения:";
		// 
		// timeStart
		// 
		this->timeStart->Format = System::Windows::Forms::DateTimePickerFormat::Time;
		this->timeStart->Location = System::Drawing::Point(824, 230);
		this->timeStart->Name = L"timeStart";
		this->timeStart->ShowUpDown = true;
		this->timeStart->Size = System::Drawing::Size(75, 20);
		this->timeStart->TabIndex = 16;
		// 
		// label3
		// 
		this->label3->AutoSize = true;
		this->label3->Location = System::Drawing::Point(684, 257);
		this->label3->Name = L"label3";
		this->label3->Size = System::Drawing::Size(129, 13);
		this->label3->TabIndex = 17;
		this->label3->Text = L"Время конца движения:";
		// 
		// timeEnd
		// 
		this->timeEnd->Format = System::Windows::Forms::DateTimePickerFormat::Time;
		this->timeEnd->Location = System::Drawing::Point(824, 254);
		this->timeEnd->Name = L"timeEnd";
		this->timeEnd->ShowUpDown = true;
		this->timeEnd->Size = System::Drawing::Size(75, 20);
		this->timeEnd->TabIndex = 18;
		// 
		// label4
		// 
		this->label4->AutoSize = true;
		this->label4->Location = System::Drawing::Point(684, 281);
		this->label4->Name = L"label4";
		this->label4->Size = System::Drawing::Size(112, 13);
		this->label4->TabIndex = 19;
		this->label4->Text = L"Интервал движения:";
		// 
		// timeInterval
		// 
		this->timeInterval->Format = System::Windows::Forms::DateTimePickerFormat::Time;
		this->timeInterval->Location = System::Drawing::Point(824, 278);
		this->timeInterval->Name = L"timeInterval";
		this->timeInterval->ShowUpDown = true;
		this->timeInterval->Size = System::Drawing::Size(75, 20);
		this->timeInterval->TabIndex = 20;
		// 
		// label5
		// 
		this->label5->AutoSize = true;
		this->label5->Location = System::Drawing::Point(684, 307);
		this->label5->Name = L"label5";
		this->label5->Size = System::Drawing::Size(130, 13);
		this->label5->TabIndex = 21;
		this->label5->Text = L"Количество транспорта:";
		// 
		// btnSaveWay
		// 
		this->btnSaveWay->Location = System::Drawing::Point(847, 362);
		this->btnSaveWay->Name = L"btnSaveWay";
		this->btnSaveWay->Size = System::Drawing::Size(75, 23);
		this->btnSaveWay->TabIndex = 24;
		this->btnSaveWay->Text = L"Сохранить";
		this->btnSaveWay->UseVisualStyleBackColor = true;
		this->btnSaveWay->Click += gcnew System::EventHandler(this, &MainForm::btnSaveWay_Click);
		// 
		// btnDeleteWay
		// 
		this->btnDeleteWay->Location = System::Drawing::Point(926, 362);
		this->btnDeleteWay->Name = L"btnDeleteWay";
		this->btnDeleteWay->Size = System::Drawing::Size(75, 23);
		this->btnDeleteWay->TabIndex = 25;
		this->btnDeleteWay->Text = L"Удалить";
		this->btnDeleteWay->UseVisualStyleBackColor = true;
		this->btnDeleteWay->Click += gcnew System::EventHandler(this, &MainForm::btnDeleteWay_Click);
		// 
		// btnTest
		// 
		this->btnTest->Location = System::Drawing::Point(769, 321);
		this->btnTest->Name = L"btnTest";
		this->btnTest->Size = System::Drawing::Size(75, 23);
		this->btnTest->TabIndex = 26;
		this->btnTest->Text = L"Тест";
		this->btnTest->UseVisualStyleBackColor = true;
		this->btnTest->Click += gcnew System::EventHandler(this, &MainForm::btnTest_Click);
		// 
		// btnStartStop
		// 
		this->btnStartStop->Location = System::Drawing::Point(688, 399);
		this->btnStartStop->Name = L"btnStartStop";
		this->btnStartStop->Size = System::Drawing::Size(75, 23);
		this->btnStartStop->TabIndex = 27;
		this->btnStartStop->Text = L"Старт";
		this->btnStartStop->UseVisualStyleBackColor = true;
		// 
		// btnPauseReturn
		// 
		this->btnPauseReturn->Enabled = false;
		this->btnPauseReturn->Location = System::Drawing::Point(769, 399);
		this->btnPauseReturn->Name = L"btnPauseReturn";
		this->btnPauseReturn->Size = System::Drawing::Size(75, 23);
		this->btnPauseReturn->TabIndex = 28;
		this->btnPauseReturn->Text = L"Пауза";
		this->btnPauseReturn->UseVisualStyleBackColor = true;
		// 
		// label6
		// 
		this->label6->AutoSize = true;
		this->label6->Location = System::Drawing::Point(850, 404);
		this->label6->Name = L"label6";
		this->label6->Size = System::Drawing::Size(120, 13);
		this->label6->TabIndex = 29;
		this->label6->Text = L"Скорость программы:";
		// 
		// tbSpeed
		// 
		this->tbSpeed->Location = System::Drawing::Point(683, 428);
		this->tbSpeed->Maximum = 60;
		this->tbSpeed->Minimum = 1;
		this->tbSpeed->Name = L"tbSpeed";
		this->tbSpeed->Size = System::Drawing::Size(297, 45);
		this->tbSpeed->TabIndex = 30;
		this->tbSpeed->Value = 1;
		this->tbSpeed->Scroll += gcnew System::EventHandler(this, &MainForm::tbSpeed_Scroll);
		// 
		// lblSpeed
		// 
		this->lblSpeed->AutoSize = true;
		this->lblSpeed->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->lblSpeed->Location = System::Drawing::Point(979, 429);
		this->lblSpeed->Name = L"lblSpeed";
		this->lblSpeed->Size = System::Drawing::Size(18, 20);
		this->lblSpeed->TabIndex = 31;
		this->lblSpeed->Text = L"1";
		// 
		// lblGlobalTime
		// 
		this->lblGlobalTime->AutoSize = true;
		this->lblGlobalTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->lblGlobalTime->ForeColor = System::Drawing::Color::LimeGreen;
		this->lblGlobalTime->Location = System::Drawing::Point(688, 462);
		this->lblGlobalTime->Name = L"lblGlobalTime";
		this->lblGlobalTime->Size = System::Drawing::Size(84, 26);
		this->lblGlobalTime->TabIndex = 32;
		this->lblGlobalTime->Text = L"5:00:00";
		// 
		// label9
		// 
		this->label9->AutoSize = true;
		this->label9->Location = System::Drawing::Point(690, 493);
		this->label9->Name = L"label9";
		this->label9->Size = System::Drawing::Size(68, 13);
		this->label9->TabIndex = 33;
		this->label9->Text = L"Время пути:";
		// 
		// label10
		// 
		this->label10->AutoSize = true;
		this->label10->Location = System::Drawing::Point(690, 516);
		this->label10->Name = L"label10";
		this->label10->Size = System::Drawing::Size(125, 13);
		this->label10->TabIndex = 34;
		this->label10->Text = L"Следующая остановка:";
		// 
		// lblTimeWay
		// 
		this->lblTimeWay->AutoSize = true;
		this->lblTimeWay->Location = System::Drawing::Point(818, 493);
		this->lblTimeWay->Name = L"lblTimeWay";
		this->lblTimeWay->Size = System::Drawing::Size(13, 13);
		this->lblTimeWay->TabIndex = 35;
		this->lblTimeWay->Text = L"--";
		// 
		// lblNextStop
		// 
		this->lblNextStop->AutoSize = true;
		this->lblNextStop->Location = System::Drawing::Point(818, 515);
		this->lblNextStop->Name = L"lblNextStop";
		this->lblNextStop->Size = System::Drawing::Size(13, 13);
		this->lblNextStop->TabIndex = 36;
		this->lblNextStop->Text = L"--";
		// 
		// label8
		// 
		this->label8->AutoSize = true;
		this->label8->Location = System::Drawing::Point(818, 462);
		this->label8->Name = L"label8";
		this->label8->Size = System::Drawing::Size(149, 26);
		this->label8->TabIndex = 37;
		this->label8->Text = L"Нажмите на транспорт, \r\nчтобы увидеть информацию";
		// 
		// label7
		// 
		this->label7->AutoSize = true;
		this->label7->Location = System::Drawing::Point(685, 347);
		this->label7->Name = L"label7";
		this->label7->Size = System::Drawing::Size(90, 13);
		this->label7->TabIndex = 38;
		this->label7->Text = L"Тип транспорта:";
		// 
		// label11
		// 
		this->label11->AutoSize = true;
		this->label11->Location = System::Drawing::Point(905, 233);
		this->label11->Name = L"label11";
		this->label11->Size = System::Drawing::Size(17, 13);
		this->label11->TabIndex = 40;
		this->label11->Text = L"X:";
		// 
		// tbX
		// 
		this->tbX->Location = System::Drawing::Point(921, 230);
		this->tbX->MaxLength = 255;
		this->tbX->Name = L"tbX";
		this->tbX->Size = System::Drawing::Size(80, 20);
		this->tbX->TabIndex = 41;
		// 
		// tbY
		// 
		this->tbY->Location = System::Drawing::Point(921, 254);
		this->tbY->MaxLength = 255;
		this->tbY->Name = L"tbY";
		this->tbY->Size = System::Drawing::Size(80, 20);
		this->tbY->TabIndex = 43;
		// 
		// label12
		// 
		this->label12->AutoSize = true;
		this->label12->Location = System::Drawing::Point(905, 257);
		this->label12->Name = L"label12";
		this->label12->Size = System::Drawing::Size(17, 13);
		this->label12->TabIndex = 42;
		this->label12->Text = L"Y:";
		// 
		// label13
		// 
		this->label13->AutoSize = true;
		this->label13->Location = System::Drawing::Point(905, 281);
		this->label13->Name = L"label13";
		this->label13->Size = System::Drawing::Size(29, 13);
		this->label13->TabIndex = 44;
		this->label13->Text = L"Тип:";
		// 
		// label14
		// 
		this->label14->AutoSize = true;
		this->label14->Location = System::Drawing::Point(861, 307);
		this->label14->Name = L"label14";
		this->label14->Size = System::Drawing::Size(116, 13);
		this->label14->TabIndex = 46;
		this->label14->Text = L"Название остановки:";
		// 
		// tbTitleStop
		// 
		this->tbTitleStop->Location = System::Drawing::Point(864, 322);
		this->tbTitleStop->MaxLength = 255;
		this->tbTitleStop->Name = L"tbTitleStop";
		this->tbTitleStop->Size = System::Drawing::Size(137, 20);
		this->tbTitleStop->TabIndex = 47;
		// 
		// cbPointType
		// 
		this->cbPointType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->cbPointType->FormattingEnabled = true;
		this->cbPointType->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"0 - точка", L"1 - поворот", L"2 - остановка" });
		this->cbPointType->Location = System::Drawing::Point(940, 277);
		this->cbPointType->Name = L"cbPointType";
		this->cbPointType->Size = System::Drawing::Size(61, 21);
		this->cbPointType->TabIndex = 48;
		this->cbPointType->SelectedIndex = 0;
		// 
		// btnDeleteCity
		// 
		this->btnDeleteCity->Location = System::Drawing::Point(606, 1);
		this->btnDeleteCity->Name = L"btnDeleteCity";
		this->btnDeleteCity->Size = System::Drawing::Size(71, 23);
		this->btnDeleteCity->TabIndex = 49;
		this->btnDeleteCity->Text = L"Удалить город";
		this->btnDeleteCity->UseVisualStyleBackColor = true;
		this->btnDeleteCity->Click += gcnew System::EventHandler(this, &MainForm::btnDeleteCity_Click);
		// 
		// tbQuantity
		// 
		this->tbQuantity->Location = System::Drawing::Point(688, 323);
		this->tbQuantity->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
		this->tbQuantity->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
		this->tbQuantity->Name = L"tbQuantity";
		this->tbQuantity->Size = System::Drawing::Size(76, 20);
		this->tbQuantity->TabIndex = 50;
		this->tbQuantity->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
		// 
		// cbTransportType
		// 
		this->cbTransportType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->cbTransportType->FormattingEnabled = true;
		this->cbTransportType->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Автобус", L"Троллейбус", L"Другой" });
		this->cbTransportType->Location = System::Drawing::Point(689, 364);
		this->cbTransportType->Name = L"cbTransportType";
		this->cbTransportType->Size = System::Drawing::Size(124, 21);
		this->cbTransportType->TabIndex = 51;
		this->cbTransportType->SelectedIndex = 0;
		// 
		// btnTableClear
		// 
		this->btnTableClear->Location = System::Drawing::Point(926, 205);
		this->btnTableClear->Name = L"btnTableClear";
		this->btnTableClear->Size = System::Drawing::Size(75, 23);
		this->btnTableClear->TabIndex = 52;
		this->btnTableClear->Text = L"Очистить";
		this->btnTableClear->UseVisualStyleBackColor = true;
		this->btnTableClear->Click += gcnew System::EventHandler(this, &MainForm::btnTableClear_Click);
		// 
		// MainForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(1008, 537);
		this->Controls->Add(this->btnTableClear);
		this->Controls->Add(this->cbTransportType);
		this->Controls->Add(this->tbQuantity);
		this->Controls->Add(this->btnDeleteCity);
		this->Controls->Add(this->cbPointType);
		this->Controls->Add(this->tbTitleStop);
		this->Controls->Add(this->label14);
		this->Controls->Add(this->label13);
		this->Controls->Add(this->tbY);
		this->Controls->Add(this->label12);
		this->Controls->Add(this->tbX);
		this->Controls->Add(this->label11);
		this->Controls->Add(this->label7);
		this->Controls->Add(this->label8);
		this->Controls->Add(this->lblNextStop);
		this->Controls->Add(this->lblTimeWay);
		this->Controls->Add(this->label10);
		this->Controls->Add(this->label9);
		this->Controls->Add(this->lblGlobalTime);
		this->Controls->Add(this->lblSpeed);
		this->Controls->Add(this->tbSpeed);
		this->Controls->Add(this->label6);
		this->Controls->Add(this->btnPauseReturn);
		this->Controls->Add(this->btnStartStop);
		this->Controls->Add(this->btnTest);
		this->Controls->Add(this->btnDeleteWay);
		this->Controls->Add(this->btnSaveWay);
		this->Controls->Add(this->label5);
		this->Controls->Add(this->timeInterval);
		this->Controls->Add(this->label4);
		this->Controls->Add(this->timeEnd);
		this->Controls->Add(this->label3);
		this->Controls->Add(this->timeStart);
		this->Controls->Add(this->label2);
		this->Controls->Add(this->tbTitleWay);
		this->Controls->Add(this->label1);
		this->Controls->Add(this->btnTableDelete);
		this->Controls->Add(this->btnTableEdit);
		this->Controls->Add(this->btnTableInsert);
		this->Controls->Add(this->btnTableAdd);
		this->Controls->Add(this->tableWay);
		this->Controls->Add(this->btnSaveCity);
		this->Controls->Add(this->btnLoadWay);
		this->Controls->Add(this->btnLoadCity);
		this->Controls->Add(this->cbWays);
		this->Controls->Add(this->cbCities);
		this->Controls->Add(this->tbTitleCity);
		this->Controls->Add(this->Map);
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
		this->MaximizeBox = false;
		this->MinimizeBox = false;
		this->Name = L"MainForm";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L"Симуляция движения";
		this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tableWay))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbSpeed))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbQuantity))->EndInit();
		this->ResumeLayout(false);
		this->PerformLayout();

	}
#pragma endregion
};
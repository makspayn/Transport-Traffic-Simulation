#include "Transport.h"

Transport::Transport(MainForm ^form, array<CalcWay ^> ^cW, int type, String ^title)
{
	frMain = form;
	calculatedWay = cW;
	index = 0;
	Pict = gcnew System::Windows::Forms::PictureBox();
	Pict->BackColor = System::Drawing::Color::Transparent;
	frMain->Map->Controls->Add(Pict);
	Pict->Size = System::Drawing::Size(30, 30);
	Pict->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
	Pict->Click += gcnew System::EventHandler(this, &Transport::PictClick);
	switch (type) {
		case 0: catalog = "Resources\\Bus\\"; break;
		case 1: catalog = "Resources\\TrollBus\\"; break;
	}
	Pict->Image = Image::FromFile(catalog + "1.png");
	lblNumber = gcnew System::Windows::Forms::Label();
	Pict->Controls->Add(lblNumber);
	lblNumber->ForeColor = System::Drawing::Color::White;
	lblNumber->BackColor = System::Drawing::Color::Transparent;
	lblNumber->ImageAlign = System::Drawing::ContentAlignment::MiddleCenter;
	lblNumber->Location = System::Drawing::Point(7, 11);
	lblNumber->Click += gcnew System::EventHandler(this, &Transport::PictClick);
	if (title->Substring(1, 1) == "_") {
		lblNumber->Text = title->Substring(0, 1);
	}
	else {
		lblNumber->Text = title->Substring(0, 2);
	}
	go = false;
	willgo = false;
	showinfo = false;
	pause = false;
	drawThread = gcnew Thread(gcnew ThreadStart(this, &Transport::RunDraw));
	drawThread->Start();
	TimerDraw = gcnew System::Windows::Forms::Timer();
	TimerDraw->Interval = 10;
	TimerDraw->Tick += gcnew System::EventHandler(this, &Transport::Draw);
	TimerDraw->Enabled = true;
}

Transport::~Transport()
{
	drawThread->Abort();
	delete drawThread;
	delete Pict;
	delete lblNumber;
	delete TimerDraw;
}

Void Transport::RunDraw()
{
	while (true) {
		try {
			p = ExtentHelper::ToScreenCoordinate(currentExtent,
				calculatedWay[index]->x, calculatedWay[index]->y, frMain->Map->Width, frMain->Map->Height);
			Pict->Image = Image::FromFile(catalog +
				calculatedWay[index]->numPict.ToString() + ".png");
			Pict->Location = System::Drawing::Point(p.X - 15, p.Y - 15);
			if (showinfo) {
				frMain->lblTimeWay->Text = GetTime().ToLongTimeString();
				frMain->lblNextStop->Text = calculatedWay[index]->nextStop;
				frMain->lblDistanceWay->Text = ((int)calculatedWay[index]->s).ToString() + " ì.";
			}
			if (go && !pause) {
				DateTime time = DateTime::Parse(frMain->scheduler->globalTime->Value.TimeOfDay.Subtract(timeStart.TimeOfDay).ToString());
				if (index < calculatedWay->Length - 1) {
					index = time.TimeOfDay.TotalSeconds;
				}
				else {
					index = 0;
					if (willgo) {
						willgo = false;
						go = true;
						timeStart = frMain->scheduler->globalTime->Value;
					}
					else {
						go = false;
					}
				}
			}
			Thread::Sleep(1000.0 / (double)frMain->tbSpeed->Value);
		}
		catch (Exception ^e) {
			
		}
	}
}

Void Transport::Draw(System::Object ^sender, System::EventArgs ^e)
{
	currentExtent = frMain->Map->CurrentExtent;
}

Void Transport::PictClick(System::Object ^ sender, System::EventArgs ^ e)
{
	frMain->scheduler->DeselectInfo();
	showinfo = true;
}

Void Transport::SetWillgo(bool wg)
{
	willgo = wg;
}

Void Transport::SetShowInfo(bool si)
{
	showinfo = si;
}

DateTime Transport::GetTime()
{
	DateTime dt = DateTime::Parse("00:00:00");
	dt = dt.AddSeconds(index);
	return dt;
}

Void Transport::Go()
{
	if (!go) {
		timeStart = frMain->scheduler->globalTime->Value;
	}
	else {
		willgo = true;
	}
	go = true;
}

Void Transport::Pause(bool p)
{
	pause = p;
}
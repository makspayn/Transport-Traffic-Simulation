#pragma once

#include "Transport Traffic Simulation.h"

public ref class Transport
{
public:
	Transport(MainForm ^, array<CalcWay ^> ^, int, String ^);
protected:
	~Transport();
private:
	MainForm ^frMain;
	RectangleShape ^currentExtent;
	array<CalcWay ^> ^calculatedWay;
	PictureBox ^Pict;
	Label ^lblNumber;
	System::Windows::Forms::Timer ^TimerDraw;
	String ^catalog;
	Thread ^drawThread;
	DateTime timeStart;
	int index;
	int x, y;
	ScreenPointF p;
	bool go, willgo, showinfo;
	bool pause;
	Void RunDraw();
	Void Draw(System::Object ^sender, System::EventArgs ^e);
	Void PictClick(System::Object^ sender, System::EventArgs^ e);
public:
	Void Go();
	Void Pause(bool);
	DateTime GetTime();
	Void SetWillgo(bool);
	Void SetShowInfo(bool);
};
#pragma once

#include "Way.h"
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
	System::Windows::Forms::PictureBox ^Pict;
	System::Windows::Forms::Label ^lblNumber;
	System::Windows::Forms::Timer ^TimerDraw;
	String ^catalog;
	Thread ^drawThread;
	DateTime timeStart;
	int index;
	int x, y;
	ThinkGeo::MapSuite::Core::ScreenPointF p;
	bool go, willgo, showinfo;
	bool pause;
	System::Void RunDraw();
	System::Void Draw(System::Object ^sender, System::EventArgs ^e);
	System::Void PictClick(System::Object^ sender, System::EventArgs^ e);
public:
	System::Void Go();
	System::Void Pause(bool);
	DateTime GetTime();
	System::Void SetWillgo(bool);
	System::Void SetShowInfo(bool);
};
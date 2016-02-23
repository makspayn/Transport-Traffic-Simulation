#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Threading;
using namespace ThinkGeo::MapSuite::Core;
using namespace ThinkGeo::MapSuite::DesktopEdition;

public ref struct CalcWay
{
	double x, y;
	int numPict;
	double s;
	String ^nextStop;
};

public ref class Way
{
public:
	Way(ThinkGeo::MapSuite::DesktopEdition::WinformsMap ^, System::Windows::Forms::DataGridView ^);
protected:
	~Way();
private:
	ThinkGeo::MapSuite::DesktopEdition::WinformsMap ^Map;
	System::Windows::Forms::DataGridView ^tableWay;
	RectangleShape ^currentExtent;
	array <CalcWay ^> ^calculatedWay;
	System::Windows::Forms::Timer ^TimerDraw;
	Thread ^calcThread;
	Thread ^drawThread;
	Graphics ^graphWay;
	int x1, x2, y1, y2;
	ThinkGeo::MapSuite::Core::ScreenPointF p1, p2;
	int VMAX, v, a;
	int Velocity(double, double %, double %, double, double, int);
	int DefNumPict(double, double, double, double);
	System::Void RunDraw();
	System::Void RunCalc();
	System::Void Draw(System::Object ^sender, System::EventArgs ^e);
public:
	array <CalcWay ^> ^GetCalculatedWay(int);
};
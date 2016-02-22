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
	int x, y, numPict;
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
	array <CalcWay ^> ^calculatedWay;
	Thread ^calcThread;
	Thread ^drawThread;
	Graphics ^graphWay;
	int x1, x2, y1, y2;
	ThinkGeo::MapSuite::Core::ScreenPointF p1, p2;
	int VMAX, v, a;
	System::Void RunDraw(System::Object ^sender, System::EventArgs ^e);
	int Velocity(double, int %, int %, int, int, int);
	int DefNumPict(int, int, int, int);
	System::Void RunCalc();
public:
	System::Void Draw();
	array <CalcWay ^> ^GetCalculatedWay(int);
};
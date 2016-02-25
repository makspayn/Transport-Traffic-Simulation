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
	array <CalcWay ^> ^calculatedWay;
	Thread ^calcThread;
	int x1, x2, y1, y2;
	Vertex v1, v2;
	PointShape ^ps1, ^ps2;
	LineShape ^ls;
	int VMAX, v, a;
	int Velocity(double, double %, double %, double, double, int);
	int DefNumPict(double, double, double, double);
	System::Void RunCalc();
public:
	array <CalcWay ^> ^GetCalculatedWay(int);
	System::Void Draw();
};
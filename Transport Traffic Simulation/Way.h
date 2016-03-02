#pragma once

#include "Transport Traffic Simulation.h"

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
	Way(WinformsMap ^, DataGridView ^);
protected:
	~Way();
private:
	WinformsMap ^Map;
	DataGridView ^tableWay;
	array <CalcWay ^> ^calculatedWay;
	Thread ^calcThread;
	int x1, x2, y1, y2;
	Vertex v1, v2;
	PointShape ^ps1, ^ps2;
	LineShape ^ls;
	int VMAX, v, a;
	int Velocity(double, double %, double %, double, double, int);
	int DefNumPict(double, double, double, double);
	Void RunCalc();
public:
	array <CalcWay ^> ^GetCalculatedWay(int);
	Void Draw();
};
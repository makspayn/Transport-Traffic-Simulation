#pragma once

#include "Transport Traffic Simulation.h"

public ref class Scheduler
{
public:
	Scheduler(MainForm ^, String ^, DateTime ^, DateTime ^, DateTime ^, int, int);
protected:
	~Scheduler();
private:
	MainForm ^frMain;
	Thread ^scheduleThread;
	String ^title;
	DateTime ^timeStart, ^timeEnd, ^timeInterval;
	int quantity;
	int type;
	int number;
	bool canmove;
	bool launched;
	bool pause;
	array<Transport ^> ^transports;
	Void RunSchedule();
public:
	DateTimePicker ^globalTime;
	Void DeselectInfo();
	Void Start();
	Void Pause();
	Void Return();
	Void Stop();
};
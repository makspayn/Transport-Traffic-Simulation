#include "Scheduler.h"

Scheduler::Scheduler(MainForm ^form, String ^sT, DateTime ^tS, DateTime ^tE, DateTime ^tI, int q, int t)
{
	frMain = form;
	title = sT;
	timeStart = tS;
	timeEnd = tE;
	timeInterval = tI;
	quantity = q;
	type = t;
	number = 0;
	canmove = false;
	launched = false;
	pause = false;
	globalTime = gcnew DateTimePicker();
	globalTime->Value = DateTime::Parse(timeStart->TimeOfDay.ToString());
	frMain->lblGlobalTime->Text = globalTime->Value.ToLongTimeString();
	transports = gcnew array<Transport ^>(quantity);
}

Scheduler::~Scheduler()
{
	delete globalTime;
	delete transports;
	if (scheduleThread != nullptr) {
		scheduleThread->Abort();
		delete scheduleThread;
	}
}

Void Scheduler::RunSchedule()
{
	while (true) {
		try {
			if (DateTime::Parse(globalTime->Value.TimeOfDay.ToString()) == DateTime::Parse("00:00:00")) {
				launched = false;
			}
			globalTime->Value = globalTime->Value.AddSeconds(1);
			frMain->lblGlobalTime->Text = globalTime->Value.ToLongTimeString();
			if ((!launched) && (DateTime::Parse(frMain->lblGlobalTime->Text) >=
				DateTime::Parse(timeStart->TimeOfDay.ToString()))) {
				transports[0]->Go();
				number = 0;
				canmove = true;
				launched = true;
			}
			if ((canmove) && (DateTime::Parse(frMain->lblGlobalTime->Text) >=
				DateTime::Parse(timeEnd->TimeOfDay.ToString()))) {
				canmove = false;
				for (int i = 0; i < quantity; i++) {
					transports[i]->SetWillgo(false);
				}
			}
			if (canmove) {
				if (transports[number]->GetTime() >=
					DateTime::Parse(timeInterval->TimeOfDay.ToString())) {
					if (number < (quantity - 1)) {
						number++;
					}
					else {
						number = 0;
					}
					transports[number]->Go();
				}
			}
			Thread::Sleep(1000.0 / (double)frMain->tbSpeed->Value);
		}
		catch (Exception ^e) {
			
		}
	}
}

Void Scheduler::DeselectInfo()
{
	for (int i = 0; i < quantity; i++) {
		if (transports != nullptr) {
			transports[i]->SetShowInfo(false);
		}
	}
	frMain->lblDistanceWay->Text = "--";
	frMain->lblTimeWay->Text = "--";
	frMain->lblNextStop->Text = "--";
}

Void Scheduler::Start()
{
	array<CalcWay ^> ^calculatedWay = frMain->way->GetCalculatedWay(type);
	for (int i = 0; i < quantity; i++) {
		transports[i] = gcnew Transport(frMain, calculatedWay, type, title);
	}
	scheduleThread = gcnew Thread(gcnew ThreadStart(this, &Scheduler::RunSchedule));
	scheduleThread->Start();
}

Void Scheduler::Pause()
{
	scheduleThread->Suspend();
	for (int i = 0; i < quantity; i++) {
		transports[i]->Pause(true);
	}
	pause = true;
}

Void Scheduler::Return()
{
	for (int i = 0; i < quantity; i++) {
		if (transports[i]->GetTime() != DateTime::Parse("00:00:00")) {
			transports[i]->Pause(false);
		}
	}
	scheduleThread->Resume();
	pause = false;
}

Void Scheduler::Stop()
{
	if (pause) {
		scheduleThread->Resume();
		pause = false;
	}
	scheduleThread->Abort();
	delete scheduleThread;
	for (int i = 0; i < quantity; i++) {
		delete transports[i];
	}
	number = 0;
	canmove = false;
	launched = false;
	frMain->lblGlobalTime->Text = "00:00:00";
}
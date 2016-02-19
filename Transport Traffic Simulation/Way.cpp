#include "Way.h"

Way::Way(ThinkGeo::MapSuite::DesktopEdition::WinformsMap ^map, System::Windows::Forms::DataGridView ^table)
{
	Map = map;
	tableWay = table;
}

Way::~Way()
{
	if (calcThread != nullptr) {
		delete calcThread;
	}
}

System::Void Way::RunDraw(System::Object ^sender, System::EventArgs ^e)
{
	if (!tableWay->Rows->Count) {
		return;
	}
	if (graphWay != nullptr) {
		delete graphWay;
	}
	graphWay = Map->CreateGraphics();
	for (int i = 0; i < tableWay->Rows->Count; i++) {
		x1 = Convert::ToInt32(tableWay->Rows[i]->Cells[0]->Value->ToString());
		y1 = Convert::ToInt32(tableWay->Rows[i]->Cells[1]->Value->ToString());
		p1 = ExtentHelper::ToScreenCoordinate(Map->CurrentExtent, x1, y1, Map->Width, Map->Height);
		if ((int)tableWay->Rows[i]->Cells[2]->Value == 2) {
			graphWay->FillEllipse(gcnew SolidBrush(Color::BlueViolet), p1.X - 6, p1.Y - 6, 12.0, 12.0);
		}
		if (i != tableWay->Rows->Count - 1) {
			x2 = Convert::ToInt32(tableWay->Rows[i + 1]->Cells[0]->Value->ToString());
			y2 = Convert::ToInt32(tableWay->Rows[i + 1]->Cells[1]->Value->ToString());
			p2 = ExtentHelper::ToScreenCoordinate(Map->CurrentExtent, x2, y2, Map->Width, Map->Height);
			graphWay->DrawLine(gcnew Pen(Brushes::BlueViolet, 4), p1.X, p1.Y, p2.X, p2.Y);
		}
	}
}

System::Void Way::RunCalc()
{
	calculatedWay = gcnew array <CalcWay ^>(tableWay->Rows->Count);
}

System::Void Way::Draw()
{
	System::Windows::Forms::Timer ^TimerDraw = gcnew System::Windows::Forms::Timer();
	TimerDraw->Interval = 100;
	TimerDraw->Tick += gcnew System::EventHandler(this, &Way::RunDraw);
	TimerDraw->Enabled = true;
}

array<CalcWay^>^ Way::GetCalculatedWay()
{
	calcThread = gcnew Thread(gcnew ThreadStart(this, &Way::RunCalc));
	calcThread->Start();
	calcThread->Join();
	return calculatedWay;
}

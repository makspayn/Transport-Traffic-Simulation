#include "Way.h"

Way::Way(ThinkGeo::MapSuite::DesktopEdition::WinformsMap ^map, System::Windows::Forms::DataGridView ^table)
{
	Map = map;
	tableWay = table;
}

Way::~Way()
{
	if (calcThread != nullptr) {
		calcThread->Abort();
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
	x1 = Convert::ToInt32(tableWay->CurrentRow->Cells[0]->Value->ToString());
	y1 = Convert::ToInt32(tableWay->CurrentRow->Cells[1]->Value->ToString());
	p1 = ExtentHelper::ToScreenCoordinate(Map->CurrentExtent, x1, y1, Map->Width, Map->Height);
	graphWay->FillEllipse(gcnew SolidBrush(Color::Red), p1.X - 6, p1.Y - 6, 12.0, 12.0);
}

int Way::Velocity(double ds, int %x, int %y, int tempx, int tempy, int pt)
{
	int dv = v, s = v;
	int vmax;
	switch (pt) {
		case 0: vmax = 22; break;
		case 1: vmax = 12; break;
		case 2: vmax = 0; break;
	}
	if (v > vmax) {
		while ((dv - 2 * a) >= vmax) {
			dv -= 2 * a;
			s += dv;
		}
		if ((s + v - 2 * a) >= ds) {
			if ((ds < v) && (vmax == 0)) {
				x = tempx;
				y = tempy;
				return v = 0;
			}
			if ((v - a) > vmax) {
				v -= 2 * a;
			}
			else {
				v -= a;
			}
			return v;
		}
	}
	if (v < VMAX) {
		v += a;
	}
	return v;
}

int Way::DefNumPict(int x, int y, int tempx, int tempy)
{
	int dx = tempx - x;
	int dy = tempy - y;
	int sign = 1;
	if (dx) {
		sign = System::Math::Sign(dx);
	}
	double ds = System::Math::Sqrt(System::Math::Pow(dx, 2) + System::Math::Pow(dy, 2));
	int angle = 180 - sign * System::Math::Acos(dy / ds) * 180 / 3.14;
	if (angle < 23) {
		return 1;
	}
	if (angle < 68) {
		return 2;
	}
	if (angle < 113) {
		return 3;
	}
	if (angle < 158) {
		return 4;
	}
	if (angle < 203) {
		return 5;
	}
	if (angle < 248) {
		return 6;
	}
	if (angle < 293) {
		return 7;
	}
	if (angle < 338) {
		return 8;
	}
	else {
		return 1;
	}
}

System::Void Way::RunCalc()
{
	int tempx = Convert::ToInt32(tableWay->Rows[1]->Cells[0]->Value);
	int tempy = Convert::ToInt32(tableWay->Rows[1]->Cells[1]->Value);
	int pointtype = Convert::ToInt32(tableWay->Rows[1]->Cells[2]->Value);
	int i = 2;
	int cycle = 0;
	bool flag = true;
	double l = 0.0;
	double ds = 0.0;
	int k = 0;
	String ^stop = "";
	do {
		if (k != tableWay->Rows->Count) {
			k++;
		}
		else {
			k = 0;
		}
	} while ((int)tableWay->Rows[k]->Cells[2]->Value != 2);
	stop = tableWay->Rows[k]->Cells[3]->Value->ToString();
	calculatedWay = gcnew array <CalcWay ^>(1);
	calculatedWay[0] = gcnew CalcWay;
	calculatedWay[0]->x = Convert::ToInt32(tableWay->Rows[0]->Cells[0]->Value);
	calculatedWay[0]->y = Convert::ToInt32(tableWay->Rows[0]->Cells[1]->Value);
	calculatedWay[0]->nextStop = stop;
	calculatedWay[0]->numPict = DefNumPict(calculatedWay[0]->x, calculatedWay[0]->y, tempx, tempy);
	while (flag) {
		ds = System::Math::Sqrt(System::Math::Pow((calculatedWay[calculatedWay->Length - 1]->x - tempx), 2)
			+ System::Math::Pow((calculatedWay[calculatedWay->Length - 1]->y - tempy), 2));
		v = Velocity(ds, calculatedWay[calculatedWay->Length - 1]->x, calculatedWay[calculatedWay->Length - 1]->y,
			tempx, tempy, pointtype);
		if (ds > v) {
			l = (double)v / (ds - (double)v);
			double tx = ((((double)calculatedWay[calculatedWay->Length - 1]->x + l * (double)tempx)) / (1.0 + l));
			double ty = ((((double)calculatedWay[calculatedWay->Length - 1]->y + l * (double)tempy)) / (1.0 + l));
			double tds = System::Math::Sqrt(System::Math::Pow((calculatedWay[calculatedWay->Length - 1]->x - tx), 2)
				+ System::Math::Pow((calculatedWay[calculatedWay->Length - 1]->y - ty), 2));
			if (ds > tds) {
				calculatedWay->Resize(calculatedWay, calculatedWay->Length + 1);
				calculatedWay[calculatedWay->Length - 1] = gcnew CalcWay;
				calculatedWay[calculatedWay->Length - 1]->x = tx;
				calculatedWay[calculatedWay->Length - 1]->y = ty;
				calculatedWay[calculatedWay->Length - 1]->numPict =
					DefNumPict(calculatedWay[calculatedWay->Length - 1]->x, calculatedWay[calculatedWay->Length - 1]->y, tempx, tempy);
				calculatedWay[calculatedWay->Length - 1]->nextStop = stop;
				continue;
			}
		}
		if (pointtype == 2) {
			cycle = 10;
			do {
				if (k != tableWay->Rows->Count - 1) {
					k++;
				}
				else {
					k = 0;
				}
			} while ((int)tableWay->Rows[k]->Cells[2]->Value != 2);
			stop = tableWay->Rows[k]->Cells[3]->Value->ToString();
		}
		else {
			cycle = 1;
		}
		for (int j = 0; j < cycle; j++) {
			calculatedWay->Resize(calculatedWay, calculatedWay->Length + 1);
			calculatedWay[calculatedWay->Length - 1] = gcnew CalcWay;
			calculatedWay[calculatedWay->Length - 1]->x = tempx;
			calculatedWay[calculatedWay->Length - 1]->y = tempy;
			calculatedWay[calculatedWay->Length - 1]->numPict =
				DefNumPict(calculatedWay[calculatedWay->Length - 1]->x, calculatedWay[calculatedWay->Length - 1]->y, tempx, tempy);
			calculatedWay[calculatedWay->Length - 1]->nextStop = stop;
		}
		if (i == tableWay->Rows->Count) {
			flag = false;
		}
		else {
			tempx = Convert::ToInt32(tableWay->Rows[i]->Cells[0]->Value);
			tempy = Convert::ToInt32(tableWay->Rows[i]->Cells[1]->Value);
			pointtype = Convert::ToInt32(tableWay->Rows[i]->Cells[2]->Value);
			i++;
			flag = true;
		}
	}
	ds = 0.0;
	calculatedWay[0]->s = ds;
	for (i = 0; i < calculatedWay->Length - 1; i++) {
		ds += System::Math::Sqrt(System::Math::Pow(calculatedWay[i]->x - calculatedWay[i + 1]->x, 2) +
			System::Math::Pow(calculatedWay[i]->y - calculatedWay[i + 1]->y, 2));
		calculatedWay[i + 1]->s = ds / 2.0;
	}
}

System::Void Way::Draw()
{
	System::Windows::Forms::Timer ^TimerDraw = gcnew System::Windows::Forms::Timer();
	TimerDraw->Interval = 1000;
	TimerDraw->Tick += gcnew System::EventHandler(this, &Way::RunDraw);
	TimerDraw->Enabled = true;
}

array<CalcWay^>^ Way::GetCalculatedWay(int t)
{
	v = 0;
	switch (t) {
		case 0: VMAX = 32; a = 1; break;
		case 1: VMAX = 32; a = 1; break;
		case 2: VMAX = 3; a = 1; break;
	}
	calcThread = gcnew Thread(gcnew ThreadStart(this, &Way::RunCalc));
	calcThread->Start();
	calcThread->Join();
	return calculatedWay;
}
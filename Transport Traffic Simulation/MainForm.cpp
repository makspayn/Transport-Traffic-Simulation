#include "MainForm.h"

MainForm::MainForm(void)
{
	InitializeComponent();
}

MainForm::~MainForm()
{
	if (components) {
		delete components;
	}
	delete way;
}

System::Void MainForm::LoadCities(String ^titleCities)
{
	if (titleCities == "") {
		MessageBox::Show("Некорректное название базы данных городов!");
		return;
	}
	System::Data::OleDb::OleDbConnection ^qrCities = gcnew System::Data::OleDb::OleDbConnection();
	qrCities->ConnectionString =
		"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=Resources/" +
		titleCities + ".mdb;" +
		"Mode=ReadWrite;Persist Security Info=False";
	qrCities->Open();
	System::Data::OleDb::OleDbCommand^ command = gcnew System::Data::OleDb::OleDbCommand();
	command->CommandText = "select Город from Города";
	command->Connection = qrCities;
	System::Data::OleDb::OleDbDataReader^ CitiesRead = command->ExecuteReader();
	cbCities->Items->Clear();
	while (CitiesRead->Read()) {
		cbCities->Items->Add(CitiesRead["Город"]);
	}
	CitiesRead->Close();
	qrCities->Close();
	if (cbCities->Items->Count) {
		cbCities->SelectedIndex = 0;
	}
	CitiesName = titleCities;
}

System::Void MainForm::LoadCity(String ^titleCity)
{
	if (titleCity == "") {
		MessageBox::Show("Некорректное название города!");
		return;
	}
	System::Data::OleDb::OleDbConnection ^qrCities = gcnew System::Data::OleDb::OleDbConnection();
	qrCities->ConnectionString = 
		"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=Resources/" +
		CitiesName + ".mdb;" +
		"Mode=ReadWrite;Persist Security Info=False";
	qrCities->Open();
	System::Data::OleDb::OleDbCommand^ command = gcnew System::Data::OleDb::OleDbCommand();
	command->CommandText = "select Город, x1, y1, x2, y2 from Города";
	command->Connection = qrCities;
	System::Data::OleDb::OleDbDataReader^ CitiesRead = command->ExecuteReader();
	while (CitiesRead->Read()) {
		if ((String ^)CitiesRead["Город"] == titleCity) {
			Map->CurrentExtent->UpperLeftPoint->X = (int)CitiesRead["x1"];
			Map->CurrentExtent->UpperLeftPoint->Y = (int)CitiesRead["y1"];
			Map->CurrentExtent->LowerRightPoint->X = (int)CitiesRead["x2"];
			Map->CurrentExtent->LowerRightPoint->Y = (int)CitiesRead["y2"];
			break;
		}
	}
	CitiesRead->Close();
	qrCities->Close();
	Map->Refresh();
	CityName = titleCity;
	System::Data::OleDb::OleDbConnection ^qrCity = gcnew System::Data::OleDb::OleDbConnection();
	qrCity->ConnectionString = 
		"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=Resources/" +
		titleCity + ".mdb;" +
		"Mode=ReadWrite;Persist Security Info=False";
	qrCity->Open();
	command->CommandText = "select Маршрут, Время_старт, Время_конец, Интервал, Количество from Def";
	command->Connection = qrCity;
	System::Data::OleDb::OleDbDataReader^ CityRead = command->ExecuteReader();
	cbWays->Items->Clear();
	while (CityRead->Read()) {
		cbWays->Items->Add(CityRead["Маршрут"]);
	}
	CityRead->Close();
	qrCity->Close();
	if (cbWays->Items->Count) {
		cbWays->SelectedIndex = 0;
	}
}

System::Void MainForm::LoadWay(String ^titleWay)
{
	if (titleWay == "") {
		MessageBox::Show("Некорректное название маршрута!");
		return;
	}
	/*FileStream^ fs = gcnew FileStream("data.bin", FileMode::Open);
	BinaryReader^ br = gcnew BinaryReader(fs);
	String ^s = br->ReadString();
	fs->Close();*/
	System::Data::OleDb::OleDbConnection ^qrCity = gcnew System::Data::OleDb::OleDbConnection();
	qrCity->ConnectionString = 
		"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=Resources/" +
		CityName + ".mdb;" +
		"Mode=ReadWrite;Persist Security Info=False";
	qrCity->Open();
	System::Data::OleDb::OleDbCommand^ command = gcnew System::Data::OleDb::OleDbCommand();
	command->CommandText = "select Маршрут, Время_старт, Время_конец, Интервал, Количество, Тип from Def";
	command->Connection = qrCity;
	System::Data::OleDb::OleDbDataReader^ CityRead = command->ExecuteReader();
	while (CityRead->Read()) {
		if ((String ^)CityRead["Маршрут"] == titleWay) {
			tbTitleWay->Text = (String ^)CityRead["Маршрут"];
			timeStart->Value = Convert::ToDateTime(CityRead["Время_старт"]->ToString());
			timeEnd->Value = Convert::ToDateTime(CityRead["Время_конец"]->ToString());
			timeInterval->Value = Convert::ToDateTime(CityRead["Интервал"]->ToString());
			tbQuantity->Text = CityRead["Количество"]->ToString();
			cbTransportType->Text = (String ^)CityRead["Тип"];
			break;
		}
	}
	CityRead->Close();
	qrCity->Close();
	System::Data::OleDb::OleDbConnection ^qrWay = gcnew System::Data::OleDb::OleDbConnection();
	qrWay->ConnectionString = 
		"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=Resources/" +
		CityName + "Ways.mdb;" +
		"Mode=ReadWrite;Persist Security Info=False";
	qrWay->Open();
	command->CommandText = "select x, y, type, Название, Код from " + titleWay;
	command->Connection = qrWay;
	System::Data::OleDb::OleDbDataReader^ WayRead = command->ExecuteReader();
	int i = 0;
	tableWay->Rows->Clear();
	while (WayRead->Read()) {
		tableWay->Rows->Add();
		tableWay->Rows[i]->Cells[0]->Value = WayRead[0];
		tableWay->Rows[i]->Cells[1]->Value = WayRead[1];
		tableWay->Rows[i]->Cells[2]->Value = WayRead[2];
		tableWay->Rows[i]->Cells[3]->Value = WayRead[3];
		tableWay->Rows[i]->Cells[4]->Value = WayRead[4];
		i++;
	}
	WayRead->Close();
	qrWay->Close();
	tableWay->Sort(tableWay->Columns[4], ListSortDirection::Ascending);
	if (way != nullptr) {
		delete way;
	}
	way = gcnew Way(Map, tableWay);
}

System::Void MainForm::SaveCity(String ^titleCity)
{
	if (titleCity == "") {
		MessageBox::Show("Некорректное название города!");
		return;
	}
	System::Data::OleDb::OleDbConnection ^qrCities = gcnew System::Data::OleDb::OleDbConnection();
	qrCities->ConnectionString = 
		"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=Resources/" +
		CitiesName + ".mdb;" +
		"Mode=ReadWrite;Persist Security Info=False";
	qrCities->Open();
	System::Data::OleDb::OleDbCommand^ command = gcnew System::Data::OleDb::OleDbCommand();
	command->CommandText = "select Город from Города";
	command->Connection = qrCities;
	System::Data::OleDb::OleDbDataReader^ CityRead = command->ExecuteReader();
	bool exists = false;
	while (CityRead->Read()) {
		if ((String ^)CityRead["Город"] == titleCity) {
			exists = true;
			break;
		}
	}
	CityRead->Close();
	if (exists) {
		command->CommandText =
			"update Города set x1=" + int(Map->CurrentExtent->UpperLeftPoint->X).ToString() +
			", y1=" + int(Map->CurrentExtent->UpperLeftPoint->Y).ToString() +
			", x2=" + int(Map->CurrentExtent->LowerRightPoint->X).ToString() +
			", y2=" + int(Map->CurrentExtent->LowerRightPoint->Y).ToString() +
			" where Город='" + titleCity + "'";
	}
	else {
		command->CommandText = 
			"insert into Города (Город, x1, y1, x2, y2) values ('" +
			titleCity + "'," +
			int(Map->CurrentExtent->UpperLeftPoint->X).ToString() + "," +
			int(Map->CurrentExtent->UpperLeftPoint->Y).ToString() + "," +
			int(Map->CurrentExtent->LowerRightPoint->X).ToString() + "," +
			int(Map->CurrentExtent->LowerRightPoint->Y).ToString() + ")";
		File::Copy("Resources\\Temp.mdb", "Resources\\" + titleCity + ".mdb");
		File::Copy("Resources\\TempWays.mdb", "Resources\\" + titleCity + "Ways.mdb");
	}
	command->ExecuteNonQuery();
	qrCities->Close();
	LoadCities(CitiesName);
	if (exists) {
		MessageBox::Show("Город " + titleCity + " был обновлен!");
	}
	else {
		MessageBox::Show("Город " + titleCity + " был создан!");
	}
}

System::Void MainForm::SaveWay(String ^titleWay)
{
	if (CityName == "") {
		MessageBox::Show("Сначала загрузите город!");
		return;
	}
	if (titleWay == "") {
		MessageBox::Show("Некорректное название маршрута!");
		return;
	}
	if (DateTime::Parse(timeInterval->Text) > DateTime::Parse("00:59:59")) {
		MessageBox::Show("Некорректное значение интервала движения!");
		return;
	}
	if (DateTime::Parse(timeEnd->Text) <= DateTime::Parse(timeStart->Text)) {
		MessageBox::Show("Некорректное значение времени конца движения!");
		return;
	}
	System::Data::OleDb::OleDbConnection ^qrCity = gcnew System::Data::OleDb::OleDbConnection();
	qrCity->ConnectionString = 
		"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=Resources/" +
		CityName + ".mdb;" +
		"Mode=ReadWrite;Persist Security Info=False";
	qrCity->Open();
	System::Data::OleDb::OleDbCommand^ command = gcnew System::Data::OleDb::OleDbCommand();
	command->CommandText = "select Маршрут from Def";
	command->Connection = qrCity;
	System::Data::OleDb::OleDbDataReader^ CityRead = command->ExecuteReader();
	bool exists = false;
	while (CityRead->Read()) {
		if ((String ^)CityRead["Маршрут"] == titleWay) {
			exists = true;
			break;
		}
	}
	CityRead->Close();
	if (exists) {
		command->CommandText = 
			"update Def set Время_старт='" + timeStart->Text +
			"', Время_конец='" + timeEnd->Text +
			"', Интервал='" + timeInterval->Text +
			"', Количество='" + tbQuantity->Text +
			"', Тип='" + cbTransportType->Text +
			"' where Маршрут='" + titleWay + "'";
	}
	else {
		command->CommandText =
			"insert into Def (Маршрут, Время_старт, Время_конец, Интервал, Количество, Тип) values ('" +
			titleWay + "','" + timeStart->Text + "','" +
			timeEnd->Text + "','" + timeInterval->Text + "'," +
			tbQuantity->Text + ",'" + cbTransportType->Text + "')";
	}
	command->ExecuteNonQuery();
	qrCity->Close();
	System::Data::OleDb::OleDbConnection ^qrWay = gcnew System::Data::OleDb::OleDbConnection();
	qrWay->ConnectionString = 
		"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=Resources/" +
		CityName + "Ways.mdb;" +
		"Mode=ReadWrite;Persist Security Info=False";
	qrWay->Open();
	command->Connection = qrWay;
	if (exists) {
		command->CommandText = "drop table " + titleWay;
		command->ExecuteNonQuery();
	}
	command->CommandText =
		"create table " + titleWay + " (Код counter primary key, " +
		"x integer, y integer, type integer, Название char (255))";
	command->ExecuteNonQuery();
	/*FileStream^ fs = gcnew FileStream("data.bin", FileMode::Create);
	BinaryWriter^ w = gcnew BinaryWriter(fs);
	String ^s = "Ура!";
	w->Write(s);
	fs->Close();*/
	for (int i = 0; i < tableWay->RowCount; i++) {
		command->CommandText = 
			"insert into " + titleWay + " (x, y, type, Название) values (" +
			tableWay->Rows[i]->Cells[0]->Value->ToString() + "," + 
			tableWay->Rows[i]->Cells[1]->Value->ToString() + "," +
			tableWay->Rows[i]->Cells[2]->Value->ToString() + ",'" +
			tableWay->Rows[i]->Cells[3]->Value->ToString() + "')";
		
		command->ExecuteNonQuery();
	}
	qrWay->Close();
	if (exists) {
		MessageBox::Show("Маршрут " + titleWay + " был обновлен!");
	}
	else {
		MessageBox::Show("Маршрут " + titleWay + " был создан!");
	}
}

System::Void MainForm::DeleteCity(String ^titleCity)
{
	if (titleCity == "") {
		MessageBox::Show("Некорректное название города!");
		return;
	}
	System::Data::OleDb::OleDbConnection ^qrCities = gcnew System::Data::OleDb::OleDbConnection();
	qrCities->ConnectionString =
		"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=Resources/" +
		CitiesName + ".mdb;" +
		"Mode=ReadWrite;Persist Security Info=False";
	qrCities->Open();
	System::Data::OleDb::OleDbCommand^ command = gcnew System::Data::OleDb::OleDbCommand();
	command->CommandText = "select Город from Города";
	command->Connection = qrCities;
	System::Data::OleDb::OleDbDataReader^ CitiesRead = command->ExecuteReader();
	bool exists = false;
	while (CitiesRead->Read()) {
		if ((String ^)CitiesRead["Город"] == titleCity) {
			exists = true;
			break;
		}
	}
	CitiesRead->Close();
	if (exists) {
		command->CommandText = "delete from Города where Город = '" + titleCity + "'";
		command->ExecuteNonQuery();
		File::Delete("Resources\\" + titleCity + ".mdb");
		File::Delete("Resources\\" + titleCity + "Ways.mdb");
		if (titleCity == CityName) {
			CityName = "";
			cbWays->Items->Clear();
		}
		MessageBox::Show("Город " + titleCity + " был удален!");
	}
	else {
		MessageBox::Show("Город " + titleCity + " не был найден!");
	}
	qrCities->Close();
}

System::Void MainForm::DeleteWay(String ^titleWay)
{
	if (CityName == "") {
		MessageBox::Show("Сначала загрузите город!");
		return;
	}
	if (titleWay == "") {
		MessageBox::Show("Некорректное название маршрута!");
		return;
	}
	System::Data::OleDb::OleDbConnection ^qrCity = gcnew System::Data::OleDb::OleDbConnection();
	qrCity->ConnectionString =
		"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=Resources/" +
		CityName + ".mdb;" +
		"Mode=ReadWrite;Persist Security Info=False";
	qrCity->Open();
	System::Data::OleDb::OleDbCommand^ command = gcnew System::Data::OleDb::OleDbCommand();
	command->CommandText = "select Маршрут from Def";
	command->Connection = qrCity;
	System::Data::OleDb::OleDbDataReader^ CityRead = command->ExecuteReader();
	bool exists = false;
	while (CityRead->Read()) {
		if ((String ^)CityRead["Маршрут"] == titleWay) {
			exists = true;
			break;
		}
	}
	CityRead->Close();
	if (exists) {
		command->CommandText = "delete from Def where Маршрут = '" + titleWay + "'";
		command->ExecuteNonQuery();
		System::Data::OleDb::OleDbConnection ^qrWay = gcnew System::Data::OleDb::OleDbConnection();
		qrWay->ConnectionString =
			"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=Resources/" +
			CityName + "Ways.mdb;" +
			"Mode=ReadWrite;Persist Security Info=False";
		qrWay->Open();
		command->Connection = qrWay;
		command->CommandText = "drop table " + titleWay;
		command->ExecuteNonQuery();
		qrWay->Close();
		MessageBox::Show("Маршрут " + titleWay + " был удален!");
	}
	else {
		MessageBox::Show("Маршрут " + titleWay + " не был найден!");
	}
	qrCity->Close();
}

System::Void MainForm::MainForm_Load(System::Object ^sender, System::EventArgs ^e)
{
	CitiesName = "";
	CityName = "";
	LoadCities("Города");
	Map->CurrentExtent = gcnew RectangleShape(-14675838, 17885007, 11819003, -2230722);
	OpenStreetMapOverlay ^osmOverlay = gcnew OpenStreetMapOverlay;
	Map->Overlays->Add(osmOverlay);
	Map->Refresh();
}

System::Void MainForm::Map_MouseClick(System::Object ^sender, System::Windows::Forms::MouseEventArgs ^e)
{
	pointShape = ExtentHelper::ToWorldCoordinate(Map->CurrentExtent, e->X, e->Y, Map->Width, Map->Height);
	tbX->Text = int(pointShape->X).ToString();
	tbY->Text = int(pointShape->Y).ToString();
	if (scheduler != nullptr) {
		scheduler->DeselectInfo();
	}
}

System::Void MainForm::btnLoadCity_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	LoadCity(cbCities->Text);
}

System::Void MainForm::btnSaveCity_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	SaveCity(tbTitleCity->Text);
	tbTitleCity->Clear();
	LoadCities("Города");
}

System::Void MainForm::btnDeleteCity_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	DeleteCity(tbTitleCity->Text);
	tbTitleCity->Clear();
	LoadCities("Города");
}

System::Void MainForm::btnLoadWay_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	LoadWay(cbWays->Text);
}

System::Void MainForm::btnSaveWay_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	SaveWay(tbTitleWay->Text);
	if (CityName != "") {
		LoadCity(CityName);
	}
}

System::Void MainForm::btnDeleteWay_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	DeleteWay(tbTitleWay->Text);
	if (CityName != "") {
		LoadCity(CityName);
	}
}

System::Void MainForm::tbSpeed_Scroll(System::Object ^ sender, System::EventArgs ^ e)
{
	lblSpeed->Text = tbSpeed->Value.ToString();
}

System::Void MainForm::tableWay_SelectionChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (tableWay->CurrentRow->Cells[0]->Value) {
		tbX->Text = tableWay->CurrentRow->Cells[0]->Value->ToString();
		tbY->Text = tableWay->CurrentRow->Cells[1]->Value->ToString();
		cbPointType->SelectedIndex = (int)tableWay->CurrentRow->Cells[2]->Value;
		tbTitleStop->Text = tableWay->CurrentRow->Cells[3]->Value->ToString();
	}
}

System::Void MainForm::btnTableAdd_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	try {
		Convert::ToInt32(tbX->Text);
		Convert::ToInt32(tbY->Text);
	}
	catch (...) {
		MessageBox::Show("Некорректные координаты!");
		return;
	}
	tableWay->Rows->Add();
	tableWay->Rows[tableWay->Rows->Count - 1]->Cells[0]->Value = tbX->Text;
	tableWay->Rows[tableWay->Rows->Count - 1]->Cells[1]->Value = tbY->Text;
	tableWay->Rows[tableWay->Rows->Count - 1]->Cells[2]->Value = cbPointType->SelectedIndex;
	tableWay->Rows[tableWay->Rows->Count - 1]->Cells[3]->Value = tbTitleStop->Text;
}

System::Void MainForm::btnTableInsert_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	try {
		Convert::ToInt32(tbX->Text);
		Convert::ToInt32(tbY->Text);
	}
	catch (...) {
		MessageBox::Show("Некорректные координаты!");
		return;
	}
	if (tableWay->CurrentRow != nullptr) {
		tableWay->Rows->Insert(tableWay->CurrentRow->Index, 1);
		tableWay->Rows[tableWay->CurrentRow->Index - 1]->Cells[0]->Value = tbX->Text;
		tableWay->Rows[tableWay->CurrentRow->Index - 1]->Cells[1]->Value = tbY->Text;
		tableWay->Rows[tableWay->CurrentRow->Index - 1]->Cells[2]->Value = cbPointType->SelectedIndex;
		tableWay->Rows[tableWay->CurrentRow->Index - 1]->Cells[3]->Value = tbTitleStop->Text;
	}
	else {
		btnTableAdd->PerformClick();
	}
}

System::Void MainForm::btnTableEdit_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	try {
		Convert::ToInt32(tbX->Text);
		Convert::ToInt32(tbY->Text);
	}
	catch (...) {
		MessageBox::Show("Некорректные координаты!");
		return;
	}
	tableWay->Rows[tableWay->CurrentRow->Index]->Cells[0]->Value = tbX->Text;
	tableWay->Rows[tableWay->CurrentRow->Index]->Cells[1]->Value = tbY->Text;
	tableWay->Rows[tableWay->CurrentRow->Index]->Cells[2]->Value = cbPointType->SelectedIndex;
	tableWay->Rows[tableWay->CurrentRow->Index]->Cells[3]->Value = tbTitleStop->Text;
}

System::Void MainForm::btnTableDelete_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (tableWay->CurrentRow != nullptr) {
		tableWay->Rows->Remove(tableWay->CurrentRow);
	}
}

System::Void MainForm::btnTableClear_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	tableWay->Rows->Clear();
}

System::Void MainForm::btnTest_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	array<CalcWay ^> ^calculatedWay = way->GetCalculatedWay(cbTransportType->SelectedIndex);
	DateTime dt = DateTime::Parse("0:00:00"), time;
	dt = dt.AddSeconds(calculatedWay->Length - 1);
	time = dt;
	int i = 1;
	while (dt >= timeInterval->Value) {
		dt = DateTime::Parse(System::Convert::ToString(dt.Subtract(timeInterval->Value)));
		i++;
	}
	MessageBox::Show("Длина пути: " + calculatedWay[calculatedWay->Length - 1]->s.ToString() + " м.\n" +
		"Время пути: " + time.TimeOfDay.ToString() + "\n" + 
		"Рекомендуется единиц транспорта: " + i.ToString() + "\n");
}

System::Void MainForm::btnStartStop_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (btnStartStop->Text == "Старт") {
		btnStartStop->Text = "Стоп";
		btnPauseReturn->Enabled = true;
		scheduler = gcnew Scheduler(this, tbTitleWay->Text, timeStart->Value,
			timeEnd->Value, timeInterval->Value, (int)tbQuantity->Value, cbTransportType->SelectedIndex);
		scheduler->Start();
	}
	else {
		btnStartStop->Text = "Старт";
		btnPauseReturn->Text = "Пауза";
		btnPauseReturn->Enabled = false;
		scheduler->DeselectInfo();
		scheduler->Stop();
		delete scheduler;
	}
}

System::Void MainForm::btnPauseReturn_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (btnPauseReturn->Text == "Пауза") {
		btnPauseReturn->Text = "Продолжить";
		scheduler->Pause();
	}
	else {
		btnPauseReturn->Text = "Пауза";
		scheduler->Return();
	}
}

System::Void MainForm::MainForm_FormClosing(System::Object ^ sender, System::Windows::Forms::FormClosingEventArgs ^ e)
{
	if (btnStartStop->Text == "Стоп") {
		btnStartStop->PerformClick();
	}
}
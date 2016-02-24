#include "MainForm.h"

public ref struct Cities
{
	String ^titleCity;
	int x1, y1, x2, y2;
};

public ref struct City
{
	String ^titleWay, ^timeStart, ^timeEnd, ^timeInterval, ^transportType;
	int quantity;
};

public ref struct TWay
{
	int x, y, type;
	String ^titleStop;
};

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
	FileStream ^fileCities = gcnew FileStream("Resources\\" + titleCities + ".tts", FileMode::Open);
	array<Cities ^> ^arrCities = gcnew array<Cities ^>(0);
	BinaryReader ^readerCities = gcnew BinaryReader(fileCities);
	for (int i = 0; readerCities->BaseStream->Position < readerCities->BaseStream->Length; i++) {
		arrCities->Resize(arrCities, arrCities->Length + 1);
		arrCities[i] = gcnew Cities();
		arrCities[i]->titleCity = readerCities->ReadString();
		arrCities[i]->x1 = readerCities->ReadInt32();
		arrCities[i]->y1 = readerCities->ReadInt32();
		arrCities[i]->x2 = readerCities->ReadInt32();
		arrCities[i]->y2 = readerCities->ReadInt32();
	}
	readerCities->Close();
	fileCities->Close();
	cbCities->Items->Clear();
	for (int i = 0; i < arrCities->Length; i++) {
		cbCities->Items->Add(arrCities[i]->titleCity);
	}
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
	FileStream ^fileCities = gcnew FileStream("Resources\\" + CitiesName + ".tts", FileMode::Open);
	array<Cities ^> ^arrCities = gcnew array<Cities ^>(0);
	BinaryReader ^readerCities = gcnew BinaryReader(fileCities);
	for (int i = 0; readerCities->BaseStream->Position < readerCities->BaseStream->Length; i++) {
		arrCities->Resize(arrCities, arrCities->Length + 1);
		arrCities[i] = gcnew Cities();
		arrCities[i]->titleCity = readerCities->ReadString();
		arrCities[i]->x1 = readerCities->ReadInt32();
		arrCities[i]->y1 = readerCities->ReadInt32();
		arrCities[i]->x2 = readerCities->ReadInt32();
		arrCities[i]->y2 = readerCities->ReadInt32();
		if (arrCities[i]->titleCity == titleCity) {
			Map->CurrentExtent->UpperLeftPoint->X = arrCities[i]->x1;
			Map->CurrentExtent->UpperLeftPoint->Y = arrCities[i]->y1;
			Map->CurrentExtent->LowerRightPoint->X = arrCities[i]->x2;
			Map->CurrentExtent->LowerRightPoint->Y = arrCities[i]->y2;
		}
	}
	readerCities->Close();
	fileCities->Close();
	Map->Refresh();
	CityName = titleCity;
	FileStream ^fileCity = gcnew FileStream("Resources\\" + CitiesName + "\\" + titleCity + ".tts", FileMode::Open);
	array<City ^> ^arrCity = gcnew array<City ^>(0);
	BinaryReader ^readerCity = gcnew BinaryReader(fileCity);
	for (int i = 0; readerCity->BaseStream->Position < readerCity->BaseStream->Length; i++) {
		arrCity->Resize(arrCity, arrCity->Length + 1);
		arrCity[i] = gcnew City();
		arrCity[i]->titleWay = readerCity->ReadString();
		arrCity[i]->timeStart = readerCity->ReadString();
		arrCity[i]->timeEnd = readerCity->ReadString();
		arrCity[i]->timeInterval = readerCity->ReadString();
		arrCity[i]->quantity = readerCity->ReadInt32();
		arrCity[i]->transportType = readerCity->ReadString();
	}
	readerCity->Close();
	fileCity->Close();
	cbWays->Items->Clear();
	for (int i = 0; i < arrCity->Length; i++) {
		cbWays->Items->Add(arrCity[i]->titleWay);
	}
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
	array<City ^> ^arrCity = gcnew array<City ^>(0);
	FileStream ^fileCity = gcnew FileStream("Resources\\" + CitiesName + "\\" + CityName + ".tts", FileMode::Open);
	BinaryReader ^readerCity = gcnew BinaryReader(fileCity);
	for (int i = 0; readerCity->BaseStream->Position < readerCity->BaseStream->Length; i++) {
		arrCity->Resize(arrCity, arrCity->Length + 1);
		arrCity[i] = gcnew City();
		arrCity[i]->titleWay = readerCity->ReadString();
		arrCity[i]->timeStart = readerCity->ReadString();
		arrCity[i]->timeEnd = readerCity->ReadString();
		arrCity[i]->timeInterval = readerCity->ReadString();
		arrCity[i]->quantity = readerCity->ReadInt32();
		arrCity[i]->transportType = readerCity->ReadString();
		if (arrCity[i]->titleWay == titleWay) {
			tbTitleWay->Text = arrCity[i]->titleWay;
			timeStart->Value = Convert::ToDateTime(arrCity[i]->timeStart);
			timeEnd->Value = Convert::ToDateTime(arrCity[i]->timeEnd);
			timeInterval->Value = Convert::ToDateTime(arrCity[i]->timeInterval);
			tbQuantity->Text = arrCity[i]->quantity.ToString();
			cbTransportType->Text = arrCity[i]->transportType;
		}
	}
	readerCity->Close();
	fileCity->Close();
	array<TWay ^> ^arrWay = gcnew array<TWay ^>(0);
	FileStream ^fileWay = gcnew FileStream("Resources\\" + CitiesName + "\\" + CityName + "\\" + titleWay + ".tts", FileMode::Open);
	BinaryReader ^readerWay = gcnew BinaryReader(fileWay);
	tableWay->Rows->Clear();
	for (int i = 0; readerWay->BaseStream->Position < readerWay->BaseStream->Length; i++) {
		tableWay->Rows->Add();
		tableWay->Rows[i]->Cells[0]->Value = readerWay->ReadInt32();
		tableWay->Rows[i]->Cells[1]->Value = readerWay->ReadInt32();
		tableWay->Rows[i]->Cells[2]->Value = readerWay->ReadInt32();
		tableWay->Rows[i]->Cells[3]->Value = readerWay->ReadString();
	}
	readerWay->Close();
	fileWay->Close();
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
	array<Cities ^> ^arrCities = gcnew array<Cities ^>(0);
	Cities ^cities = gcnew Cities();
	cities->titleCity = titleCity;
	cities->x1 = (int)Map->CurrentExtent->UpperLeftPoint->X;
	cities->y1 = (int)Map->CurrentExtent->UpperLeftPoint->Y;
	cities->x2 = (int)Map->CurrentExtent->LowerRightPoint->X;
	cities->y2 = (int)Map->CurrentExtent->LowerRightPoint->Y;
	FileStream ^fileCities = gcnew FileStream("Resources\\" + CitiesName + ".tts", FileMode::Open);
	BinaryReader ^readerCities = gcnew BinaryReader(fileCities);
	for (int i = 0; readerCities->BaseStream->Position < readerCities->BaseStream->Length; i++) {
		arrCities->Resize(arrCities, arrCities->Length + 1);
		arrCities[i] = gcnew Cities();
		arrCities[i]->titleCity = readerCities->ReadString();
		arrCities[i]->x1 = readerCities->ReadInt32();
		arrCities[i]->y1 = readerCities->ReadInt32();
		arrCities[i]->x2 = readerCities->ReadInt32();
		arrCities[i]->y2 = readerCities->ReadInt32();
	}
	readerCities->Close();
	bool exists = File::Exists("Resources\\" + CitiesName + "\\" + titleCity + ".tts");
	if (exists) {
		for (int i = 0; i < arrCities->Length; i++) {
			if (arrCities[i]->titleCity == titleCity) {
				arrCities[i]->x1 = cities->x1;
				arrCities[i]->y1 = cities->x2;
				arrCities[i]->x2 = cities->y1;
				arrCities[i]->y2 = cities->y2;
			}
		}
		MessageBox::Show("Город " + titleCity + " был обновлен!");
	}
	else {
		arrCities->Resize(arrCities, arrCities->Length + 1);
		arrCities[arrCities->Length - 1] = cities;
		Directory::CreateDirectory("Resources\\" + CitiesName + "\\" + titleCity + "\\");
		FileStream ^fileCity = gcnew FileStream("Resources\\" + CitiesName + "\\" + titleCity + ".tts", FileMode::Create);
		fileCity->Close();
		MessageBox::Show("Город " + titleCity + " был создан!");
	}
	fileCities->Close();
	fileCities = File::Open("Resources\\" + CitiesName + ".tts", FileMode::Create);
	BinaryWriter ^writerCities = gcnew BinaryWriter(fileCities);
	for (int i = 0; i < arrCities->Length; i++) {
		writerCities->Write(arrCities[i]->titleCity);
		writerCities->Write(arrCities[i]->x1);
		writerCities->Write(arrCities[i]->y1);
		writerCities->Write(arrCities[i]->x2);
		writerCities->Write(arrCities[i]->y2);
	}
	writerCities->Close();
	fileCities->Close();
	LoadCities(CitiesName);
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
	if (DateTime::Parse(timeEnd->Text) <= DateTime::Parse(timeStart->Text)) {
		MessageBox::Show("Некорректное значение времени конца движения!");
		return;
	}
	array<City ^> ^arrCity = gcnew array<City ^>(0);
	array<TWay ^> ^arrWay = gcnew array<TWay ^>(0);
	City ^city = gcnew City();
	city->titleWay = titleWay;
	city->timeStart = timeStart->Text;
	city->timeEnd = timeEnd->Text;
	city->timeInterval = timeInterval->Text;
	city->quantity = Convert::ToInt32(tbQuantity->Text);
	city->transportType = cbTransportType->Text;
	for (int i = 0; i < tableWay->Rows->Count; i++) {
		arrWay->Resize(arrWay, arrWay->Length + 1);
		arrWay[i] = gcnew TWay();
		arrWay[i]->x = Convert::ToInt32(tableWay->Rows[i]->Cells[0]->Value);
		arrWay[i]->y = Convert::ToInt32(tableWay->Rows[i]->Cells[1]->Value);
		arrWay[i]->type = Convert::ToInt32(tableWay->Rows[i]->Cells[2]->Value);
		arrWay[i]->titleStop = tableWay->Rows[i]->Cells[3]->Value->ToString();
	}
	FileStream ^fileCity = gcnew FileStream("Resources\\" + CitiesName + "\\" + CityName + ".tts", FileMode::Open);
	BinaryReader ^readerCity = gcnew BinaryReader(fileCity);
	for (int i = 0; readerCity->BaseStream->Position < readerCity->BaseStream->Length; i++) {
		arrCity->Resize(arrCity, arrCity->Length + 1);
		arrCity[i] = gcnew City();
		arrCity[i]->titleWay = readerCity->ReadString();
		arrCity[i]->timeStart = readerCity->ReadString();
		arrCity[i]->timeEnd = readerCity->ReadString();
		arrCity[i]->timeInterval = readerCity->ReadString();
		arrCity[i]->quantity = readerCity->ReadInt32();
		arrCity[i]->transportType = readerCity->ReadString();
	}
	readerCity->Close();
	bool exists = File::Exists("Resources\\" + CitiesName + "\\" + CityName + "\\" + titleWay + ".tts");
	if (exists) {
		for (int i = 0; i < arrCity->Length; i++) {
			if (arrCity[i]->titleWay == titleWay) {
				arrCity[i]->titleWay = city->titleWay;
				arrCity[i]->timeStart = city->timeStart;
				arrCity[i]->timeEnd = city->timeEnd;
				arrCity[i]->timeInterval = city->timeInterval;
				arrCity[i]->quantity = city->quantity;
				arrCity[i]->transportType = city->transportType;
			}
		}
		File::Delete("Resources\\" + CitiesName + "\\" + CityName + "\\" + titleWay + ".tts");
		MessageBox::Show("Маршрут " + titleWay + " был обновлен!");
	}
	else {
		arrCity->Resize(arrCity, arrCity->Length + 1);
		arrCity[arrCity->Length - 1] = city;
		MessageBox::Show("Маршрут " + titleWay + " был создан!");
	}
	fileCity->Close();
	fileCity = File::Open("Resources\\" + CitiesName + "\\" + CityName + ".tts", FileMode::Create);
	BinaryWriter ^writerCity = gcnew BinaryWriter(fileCity);
	for (int i = 0; i < arrCity->Length; i++) {
		writerCity->Write(arrCity[i]->titleWay);
		writerCity->Write(arrCity[i]->timeStart);
		writerCity->Write(arrCity[i]->timeEnd);
		writerCity->Write(arrCity[i]->timeInterval);
		writerCity->Write(arrCity[i]->quantity);
		writerCity->Write(arrCity[i]->transportType);
	}
	writerCity->Close();
	fileCity->Close();
	FileStream ^fileWay = gcnew FileStream("Resources\\" + CitiesName + "\\" + CityName + "\\" + titleWay + ".tts", FileMode::Create);
	BinaryWriter ^writerWay = gcnew BinaryWriter(fileWay);
	for (int i = 0; i < arrWay->Length; i++) {
		writerWay->Write(arrWay[i]->x);
		writerWay->Write(arrWay[i]->y);
		writerWay->Write(arrWay[i]->type);
		writerWay->Write(arrWay[i]->titleStop);
	}
	writerWay->Close();
	fileWay->Close();
}

System::Void MainForm::DeleteCity(String ^titleCity)
{
	if (titleCity == "") {
		MessageBox::Show("Некорректное название города!");
		return;
	}
	bool exists = File::Exists("Resources\\" + CitiesName + "\\" + titleCity + ".tts");
	if (exists) {
		FileStream ^fileCities = gcnew FileStream("Resources\\" + CitiesName + ".tts", FileMode::Open);
		array<Cities ^> ^arrCities = gcnew array<Cities ^>(0);
		BinaryReader ^readerCities = gcnew BinaryReader(fileCities);
		for (int i = 0; readerCities->BaseStream->Position < readerCities->BaseStream->Length; i++) {
			arrCities->Resize(arrCities, arrCities->Length + 1);
			arrCities[i] = gcnew Cities();
			arrCities[i]->titleCity = readerCities->ReadString();
			arrCities[i]->x1 = readerCities->ReadInt32();
			arrCities[i]->y1 = readerCities->ReadInt32();
			arrCities[i]->x2 = readerCities->ReadInt32();
			arrCities[i]->y2 = readerCities->ReadInt32();
		}
		readerCities->Close();
		fileCities->Close();
		fileCities = File::Open("Resources\\" + CitiesName + ".tts", FileMode::Create);
		BinaryWriter ^writerCities = gcnew BinaryWriter(fileCities);
		for (int i = 0; i < arrCities->Length; i++) {
			if (arrCities[i]->titleCity != titleCity) {
				writerCities->Write(arrCities[i]->titleCity);
				writerCities->Write(arrCities[i]->x1);
				writerCities->Write(arrCities[i]->y1);
				writerCities->Write(arrCities[i]->x2);
				writerCities->Write(arrCities[i]->y2);
			}
		}
		writerCities->Close();
		fileCities->Close();
		File::Delete("Resources\\" + CitiesName + "\\" + titleCity + ".tts");
		Directory::Delete("Resources\\" + CitiesName + "\\" + titleCity + "\\", true);
		MessageBox::Show("Город " + titleCity + " был удален!");
	}
	else {
		MessageBox::Show("Город " + titleCity + " не был найден!");
	}
	LoadCities(CitiesName);
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
	bool exists = File::Exists("Resources\\" + CitiesName + "\\" + CityName + "\\" + titleWay + ".tts");
	if (exists) {
		array<City ^> ^arrCity = gcnew array<City ^>(0);
		FileStream ^fileCity = gcnew FileStream("Resources\\" + CitiesName + "\\" + CityName + ".tts", FileMode::Open);
		BinaryReader ^readerCity = gcnew BinaryReader(fileCity);
		for (int i = 0; readerCity->BaseStream->Position < readerCity->BaseStream->Length; i++) {
			arrCity->Resize(arrCity, arrCity->Length + 1);
			arrCity[i] = gcnew City();
			arrCity[i]->titleWay = readerCity->ReadString();
			arrCity[i]->timeStart = readerCity->ReadString();
			arrCity[i]->timeEnd = readerCity->ReadString();
			arrCity[i]->timeInterval = readerCity->ReadString();
			arrCity[i]->quantity = readerCity->ReadInt32();
			arrCity[i]->transportType = readerCity->ReadString();
		}
		readerCity->Close();
		fileCity->Close();
		fileCity = File::Open("Resources\\" + CitiesName + "\\" + CityName + ".tts", FileMode::Create);
		BinaryWriter ^writerCity = gcnew BinaryWriter(fileCity);
		for (int i = 0; i < arrCity->Length; i++) {
			if (arrCity[i]->titleWay != titleWay) {
				writerCity->Write(arrCity[i]->titleWay);
				writerCity->Write(arrCity[i]->timeStart);
				writerCity->Write(arrCity[i]->timeEnd);
				writerCity->Write(arrCity[i]->timeInterval);
				writerCity->Write(arrCity[i]->quantity);
				writerCity->Write(arrCity[i]->transportType);
			}
		}
		writerCity->Close();
		fileCity->Close();
		File::Delete("Resources\\" + CitiesName + "\\" + CityName + "\\" + titleWay + ".tts");
		MessageBox::Show("Маршрут " + titleWay + " был удален!");
	}
	else {
		MessageBox::Show("Маршрут " + titleWay + " не был найден!");
	}
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
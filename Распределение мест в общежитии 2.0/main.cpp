#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>

#include "userTypes.h"
#include "functions.h"
#include "menu.h"

using namespace std;

short int MASSIVE_SIZE = 0;
unsigned int MINIMAL_SALARY = 0;

// ���� ���������
void editMenu(short int, student*&);
void processingMenu(short int, short int, short int, student *&);
void searchMenu(short int, student *&);
void sortMenu(short int, student *&);
void individualTaskMenu(short int, student*&);

void inputMinimalSalary();

// ������� ��� ������ � ������� 
void getDataFromFile(student*&);
// �������� ���-�� ���� ��������, ���������� � �����
int getCountOfStructerInFile();
// ������ ���� �������� � ����
void recordDatainFile(student*);
// ������ ��������� � ����� �����
void recordDataInEndOfFile(student*);

// ������� ��� ������ ���������������� ������
void outputDataInTable(student*);

// ������� ����������
void sortStudentListByAverageMark(student*&);
void sortStudentListByStudentName(student*&);
void sortStudentListByIncome(student*&);
void sortStudentListByPriority(student*&);

// ������� ������
void searchStudentByName(student*);
void searchStudentByGroup(student*);
void searchStudentByAverageScore(student*);

// ���������� �������� � ������
student inputInfoAboutStudent();
void addStudentInList(student*&);

// ������� ��� ���������� �������� �� �����
int findIndexOfStudentByName(student*);
int getNumberOfStudent();

// ������� ��������������
void editStudentElement(student*&, int);

// ������� ��������
void deleteStudentElement(student*&, int);

bool isNumberNumeric();
int inputNumber(bool(*pFuction)(int));
bool isNumberRangeCorrectForMenu(int);
bool isNumberRangeCorrectForEditMenu(int);
bool isNumberRangeCorrectForProccesingMenu(int);
bool isNumberRangeCorrectForMark(int);
bool trueFunction(int);

int main() {
	
	setlocale(0, "");

	student* pMassive = NULL;

	while (true) {

		short int modeSelection = 0, choiceEditMode = 0, choiceProcessingMode = 0, choiceSearchMode = 0, choiceSortMode = 0;
		system("cls");

		formOfMainMenu();
		modeSelection = inputNumber(isNumberRangeCorrectForMenu);
		
		system("cls");

		switch (modeSelection) 
		{
			case modeOfProgram::edit_mode:
				editMenu(choiceEditMode, pMassive);
				break;
			case modeOfProgram::processing_mode:
				processingMenu(choiceProcessingMode, choiceSearchMode, choiceSortMode, pMassive);
				break;
			case modeOfProgram::close_program:
				delete[]pMassive;
				exit(0);
		}
	}
}

void editMenu(short int choice, student*& pMassive) {

	int index = 0;

	formOfEditMode();

	choice = inputNumber(isNumberRangeCorrectForEditMenu);

	system("cls");

	switch (choice)
	{
		case modeOfEditing::output_data:
			outputDataInTable(pMassive);
			break;
		case modeOfEditing::add_student_info:
			addStudentInList(pMassive);
			break;
		case modeOfEditing::delete_student_structer:
			outputDataInTable(pMassive);
			if (MASSIVE_SIZE == 0) break;
			index = getNumberOfStudent();
			deleteStudentElement(pMassive, index);
			break;
		case modeOfEditing::edit_student_info:
			outputDataInTable(pMassive);
			index = getNumberOfStudent();
			system("cls");
			editStudentElement(pMassive, index);
			break;
		case modeOfEditing::get_data_from_file:
			getDataFromFile(pMassive);
			break;
		case modeOfEditing::record_data_in_file:
			recordDatainFile(pMassive);
			break;
		case modeOfEditing::close_editing_menu:
			system("cls");
			return;
	}
	system("pause");
	system("cls");
}
void processingMenu(short int choiceProcessingMode, short int choiceSearchMode, short int choiceSortMode, student*& pMassive) {

	short int choiseModeOfIndTask = 0;

	formOfProcessingMenu(); // ����� ���� ���������
	
	choiceProcessingMode = inputNumber(isNumberRangeCorrectForProccesingMenu);

	system("cls");

	switch (choiceProcessingMode)
	{
		case modeOfProcessing::search_student_info:
			searchMenu(choiceSearchMode, pMassive);
			break;
		case modeOfProcessing::sort_menu:
			sortMenu(choiceSortMode, pMassive);
			break;
		case modeOfProcessing::individual_task:
			individualTaskMenu(choiseModeOfIndTask, pMassive);
			break;
		case modeOfProcessing::close_processing_mode:
			return;
	}
}
void searchMenu(short int choice, student*& pMassive) {
	bool running = true;

	if (MASSIVE_SIZE <= 0) {
		cout << "����� ����������, ��� ��� ������ ��������� ���� . . ." << endl;
		system("pause");
		return;
	}

	while (running) {
		formOfSearchMenu(); // ����� ���� ������

		choice = inputNumber(isNumberRangeCorrectForProccesingMenu);
		system("cls");

		switch (choice)
		{
		case modeOfSerching::search_by_name:
			searchStudentByName(pMassive);
			system("pause");
			break;
		case modeOfSerching::search_by_group:
			searchStudentByGroup(pMassive);
			system("pause");
			break;
		case modeOfSerching::search_by_average_number:
			searchStudentByAverageScore(pMassive);
			system("pause");
			break;
		case modeOfSerching::close_search_menu:
			return;
		}
		system("cls");
	}
}
void sortMenu(short int choice, student*& pMassive) {
	bool running = true;

	if (MASSIVE_SIZE <= 0) {
		cout << "���������� ����������, ��� ��� ������ ��������� ���� . . ." << endl;
		system("pause");
		return;
	}

	while (running) {

		formOfSortingMenu(); // ����� ���� ����������
		
		choice = inputNumber(isNumberRangeCorrectForProccesingMenu);
		system("cls");

		switch (choice)
		{
		case modeOfSorting::sort_by_name:
			sortStudentListByStudentName(pMassive);
			outputDataInTable(pMassive);
			system("pause");
			break;
		case modeOfSorting::sort_by_average_mark:
			sortStudentListByAverageMark(pMassive);
			outputDataInTable(pMassive);
			system("pause");
			break;
		case modeOfSorting::sort_by_income:
			sortStudentListByIncome(pMassive);
			outputDataInTable(pMassive);
			system("pause");
			break;
		case modeOfSorting::close_sort_menu:
			running = false;
		}
		system("cls");
	}
}
void individualTaskMenu(short int choice, student*& pMassive) {

	formOfMenuOfSettelment();

	choice = inputNumber(isNumberRangeCorrectForMenu);

	system("cls");

	switch (choice)
	{
		case modeOfIndividualTask::output_student_by_priority:
			if (MINIMAL_SALARY <= 0) {
				cout << "����� ���, ��� ������� ������, ������� �������� ����������� �������� . . .\n" << endl;
				break;
			}
			sortStudentListByPriority(pMassive);
			outputDataInTable(pMassive);
			break;
		case modeOfIndividualTask::input_minimal_salary:
			inputMinimalSalary();
			break;
		case modeOfIndividualTask::close_individual_task_menu:
			return;
	}
	system("pause");
	system("cls");
}

// ������� ��� ������ � �������
int getCountOfStructerInFile() {
	// ��������� ���� ��� ������ � �������� ������ � ���������� ��������� � ����� ����� (ios::ate)
	ifstream file("D:\\C++\\Structers of student\\file.dat", ios::ate | ios::binary);

	int numberOfStructer = file.tellg() / sizeof(student);  // ����������� ���-�� �������� � �����
	return numberOfStructer;
}
void getDataFromFile(student*& pMassive) {

	if (MASSIVE_SIZE > 0) {
		cout << "������ ���������� ��� ��� ������ �������� . . ." << endl;
		return;
	}

	ifstream file("D:\\C++\\Structers of student\\file.dat", ios::binary);

	if (file.is_open()) cout << "\n���� ������. . .\n";
	else {
		cout << "������ ��� ������� �����" << endl;
		return;
	}

	MASSIVE_SIZE = getCountOfStructerInFile();
	pMassive = new student[MASSIVE_SIZE];


	for (int i = 0; i < MASSIVE_SIZE; i++) {
		file.read((char*)&pMassive[i], sizeof(student));
	}

	cout << "������ �� ����� ������ �������. . ." << endl;

	file.close();
}
void recordDatainFile(student* pMassive) {

	ofstream file("D:\\C++\\Structers of student\\file.dat", ios::binary | ios::out);

	if (!file.is_open()) {
		cout << "������ ��� ��������. ��������� ���� �� ����������" << endl;
		return;
	}
	else {
		for (int i = 0; i < MASSIVE_SIZE; i++) file.write((char*)&pMassive[i], sizeof(student));
		cout << "������ ������ � ���� ������ ������� . . ." << endl;
	}

}
void recordDataInEndOfFile(student* pMassive) {

	ofstream file("D:\\C++\\Structers of student\\file.dat", ios::binary | ios::app);

	if (!file.is_open()) {
		cout << "������ ��� ��������. ��������� ���� �� ����������" << endl;
		return;
	}
	else file.write((char*)&pMassive[MASSIVE_SIZE - 1], sizeof(student));
}

// ������� ��� ������
void outputDataInTable(student* pMassive) {

	if (MASSIVE_SIZE == 0) {
		cout << "������ ��������� ���� . . ." << endl;
		return;
	}

	string socialActivity = "";

	cout << "+--------------------------------------------------------------------------+" << endl;
	cout << "| ����� | ��� �������� | ����� ������ | ��. ���� | ����� | C��. ���������� |" << endl;
	cout << "+--------------------------------------------------------------------------+" << endl;

	for (int i = 0; i < MASSIVE_SIZE; i++) {
		if (pMassive[i].socialActivity == 1) socialActivity = "����������";
		else socialActivity = "�� ����������";

		cout << "|" << setw(7) << i + 1 << "|" << setw(14) << pMassive[i].studentName << "|";
		cout << setw(14) << pMassive[i].groupNumber << "|" << setw(10) << pMassive[i].averageScore << "|";
		cout << setw(7) << pMassive[i].income.netIncome << "|" << setw(17) << socialActivity << "|" << endl;
		cout << "+--------------------------------------------------------------------------+" << endl;
	}
}
	
// ������� ���������� 
void sortStudentListByStudentName(student*& pMassive) {
	for (int i = 0; i < MASSIVE_SIZE; i++)
	{
		for (int j = 0; j < MASSIVE_SIZE - i - 1; j++)
		{
			if (strcmp(pMassive[j].studentName, pMassive[j + 1].studentName) > 0) swap(pMassive[j], pMassive[j + 1]);
		}
	}
}
void sortStudentListByIncome(student*& pMassive) {

	for (int i = 0; i < MASSIVE_SIZE; i++) {
		for (int j = 0; j < MASSIVE_SIZE - i - 1; j++) {

			if (pMassive[j].income.netIncome < pMassive[j + 1].income.netIncome) swap(pMassive[j], pMassive[j + 1]);
		}
	}
}
void sortStudentListByAverageMark(student*& pMassive) {

	for (int i = 0; i < MASSIVE_SIZE; i++) {
		for (int j = 0; j < MASSIVE_SIZE - i - 1; j++) {

			if (pMassive[j].averageScore < pMassive[j + 1].averageScore) swap(pMassive[j], pMassive[j + 1]);
			else if (pMassive[j].averageScore == pMassive[j + 1].averageScore) {
				if (pMassive[j].socialActivity == 2 and pMassive[j + 1].socialActivity == 1) swap(pMassive[j], pMassive[j + 1]);
			}
		}
	}
}
void sortStudentListByPriority(student*& pMassive) {

	for (int i = 0; i < MASSIVE_SIZE; i++) {
		for (int j = 0; j < MASSIVE_SIZE - i - 1; j++) {

			if (pMassive[j].averageScore < pMassive[j + 1].averageScore) swap(pMassive[j], pMassive[j + 1]);
			else if (pMassive[j].averageScore == pMassive[j + 1].averageScore) {
				if (pMassive[j].socialActivity == 2 and pMassive[j + 1].socialActivity == 1) swap(pMassive[j], pMassive[j + 1]);
			}
		}
	}

	for (int i = 0; i < MASSIVE_SIZE; i++) {
		for (int j = 0; j < MASSIVE_SIZE - i - 1; j++) {

			if (pMassive[j].income.flag == false and pMassive[j + 1].income.flag == true) swap(pMassive[j], pMassive[j + 1]);
		}
	}
}

// ������� ������
void searchStudentByName(student* pMassive) {
	
	vector<int>index;
	char nameOfStudent[30] = {'\0'};
	bool flag = false;

	cout << "������� ��� ��������: ";
	cin.ignore();
	cin.getline(nameOfStudent, 30);

	// ���� ��� ������ �������� �������
	for (int i = 0; i < MASSIVE_SIZE; i++) {
		short int countOfSameLetters = 0;
		for (int j = 0; j < 4; j++) {
			if (nameOfStudent[j] == pMassive[i].studentName[j]) countOfSameLetters++;
		}
		if (countOfSameLetters == 4) {
			index.push_back(i);
			flag = true;
		}
	}
	
	if (flag == false)  cout << "����� ��������� ��� � ������" << endl;
	else {
		cout << "+--------------------------------------------------------------------------+" << endl;
		cout << "| ����� | ��� �������� | ����� ������ | ��. ���� | ����� | C��. ���������� |" << endl;
		cout << "+--------------------------------------------------------------------------+" << endl;
		
		for (int i = 0; i < index.size(); i++) {
			string socialActivity = "";

			if (pMassive[index[i]].socialActivity == 1) socialActivity = "����������";
			else socialActivity = "�� ����������";

			cout << "|" << setw(7) << i + 1 << "|" << setw(14) << pMassive[index[i]].studentName << "|";
			cout << setw(14) << pMassive[index[i]].groupNumber << "|" << setw(10) << pMassive[index[i]].averageScore << "|";
			cout << setw(7) << pMassive[index[i]].income.netIncome << "|" << setw(17) << socialActivity << "|" << endl;
			cout << "+--------------------------------------------------------------------------+" << endl;
		}
	}

}
void searchStudentByGroup(student* pMassive) {

	vector<int>index;
	char groupNumber[30] = {'\0'};
	bool flag = false;

	cout << "������� ����� ������ . . ." << endl;
	cout << "����: ";
	cin.ignore();
	cin.getline(groupNumber, 30);

	for (int i = 0; i < MASSIVE_SIZE; i++) {
		if (strcmp(groupNumber, pMassive[i].groupNumber) == 0) {
			index.push_back(i);
			flag = true;
		}
	}

	if (flag == false)  cout << "����� ��������� ��� � ������" << endl;
	else {
		cout << "+--------------------------------------------------------------------------+" << endl;
		cout << "| ����� | ��� �������� | ����� ������ | ��. ���� | ����� | C��. ���������� |" << endl;
		cout << "+--------------------------------------------------------------------------+" << endl;

		for (int i = 0; i < index.size(); i++) {
			string socialActivity = "";

			if (pMassive[index[i]].socialActivity == 1) socialActivity = "����������";
			else socialActivity = "�� ����������";

			cout << "|" << setw(7) << i + 1 << "|" << setw(14) << pMassive[index[i]].studentName << "|";
			cout << setw(14) << pMassive[index[i]].groupNumber << "|" << setw(10) << pMassive[index[i]].averageScore << "|";
			cout << setw(7) << pMassive[index[i]].income.netIncome << "|" << setw(17) << socialActivity << "|" << endl;
			cout << "+--------------------------------------------------------------------------+" << endl;
		}
	}

}
void searchStudentByAverageScore(student* pMassive) {

	vector<int>index;
	unsigned short int averageMarkOfStudent = 0;
	bool flag = false;

	cout << "������� ������� ���� . . ." << endl;
	
	averageMarkOfStudent = inputNumber(isNumberRangeCorrectForMark); // �������� �� ������������ �������� ������

	for (int i = 0; i < MASSIVE_SIZE; i++) {
		if (averageMarkOfStudent == pMassive[i].averageScore) {
			index.push_back(i);
			flag = true;
		}
	}
	if (flag == false)  cout << "����� ��������� ��� � ������" << endl;
	else {
		cout << "+--------------------------------------------------------------------------+" << endl;
		cout << "| ����� | ��� �������� | ����� ������ | ��. ���� | ����� | C��. ���������� |" << endl;
		cout << "+--------------------------------------------------------------------------+" << endl;

		for (int i = 0; i < index.size(); i++) {
			string socialActivity = "";

			if (pMassive[index[i]].socialActivity == 1) socialActivity = "����������";
			else socialActivity = "�� ����������";

			cout << "|" << setw(7) << i + 1 << "|" << setw(14) << pMassive[index[i]].studentName << "|";
			cout << setw(14) << pMassive[index[i]].groupNumber << "|" << setw(10) << pMassive[index[i]].averageScore << "|";
			cout << setw(7) << pMassive[index[i]].income.netIncome << "|" << setw(17) << socialActivity << "|" << endl;
			cout << "+--------------------------------------------------------------------------+" << endl;
		}
	}
}

// ������� ���������� ��������� � ������
student inputInfoAboutStudent() {
	student info;

	cin.ignore();
	cout << "\n������� ��� ��������: ";
	cin.getline(info.studentName, 30);

	cout << "������� ����� ������ ��������: ";
	cin.getline(info.groupNumber, 20);

	cout << "��������� �� ������� ����������� ��������({1 - ��} ��� {2 - ���}): ";
	cin >> info.socialActivity;

	cout << "������� ������� ���� ��������: ";
	cin >> info.averageScore;

	cout << "������� ����� ������� ����� �����: ";
	cin >> info.income.firstIncome;
	cout << "������� ����� ������� ����� �����: ";
	cin >> info.income.secondIncome;
	info.income.netIncome = (info.income.firstIncome + info.income.secondIncome) / 2;
	if (info.income.netIncome < MINIMAL_SALARY) info.income.flag = true;

	return info;
}
// ������� ����������
void addStudentInList(student*& pMassive) {  // ���������� ���������

	if (MASSIVE_SIZE == 0) {
		cout << "\n��������� ������� ��������" << endl;
		MASSIVE_SIZE++;
		pMassive = new student[MASSIVE_SIZE];

		pMassive[MASSIVE_SIZE - 1] = inputInfoAboutStudent();
	}
	else {
		MASSIVE_SIZE++;
		student* newMassive = new student[MASSIVE_SIZE];

		for (int i = 0; i < MASSIVE_SIZE - 1; i++) newMassive[i] = pMassive[i];

		newMassive[MASSIVE_SIZE - 1] = inputInfoAboutStudent();

		delete[] pMassive;
		pMassive = newMassive;
	}

}

int getNumberOfStudent() {

	int choiseNumberOfStudent = 0;
	bool running = true;

	while (running) {
		cout << "\n�������� �������� . . ." << endl;
		choiseNumberOfStudent = inputNumber(trueFunction);
		
		if (choiseNumberOfStudent <= 0 or choiseNumberOfStudent > MASSIVE_SIZE) cout << "�������� ��� ����� ������� ��� � ������. ������� ����� �������� . . ." << endl;
		else running = false;
	}
	

	return (choiseNumberOfStudent - 1);
}

// ������� �������������� ������ 
void editStudentElement(student*& pMassive, int index) {

	bool running = true;  // ��� ��������� ����� while
	
	cout << "�������� �������� ��� �������������� . . ." << endl;

	while (running) {
		double income = 0;
		short int choice = 0;

		formOfEditMenu();
		cout << "\n�����: ";

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "���: ";
			cin >> pMassive[index].studentName;
			break;
		case 2:
			cout << "����� ������: ";
			cin >> pMassive[index].groupNumber;
			break;
		case 3:
			cout << "������� ����������� �������� ({1} - ��, {2} - ���): ";
			cin >> pMassive[index].socialActivity;
			break;
		case 4:
			cout << "������� ����: ";
			cin >> pMassive[index].averageScore;
			break;
		case 5:
			cout << "����� ������� ����� �����: ";
			cin >> pMassive[index].income.firstIncome;
			income = (pMassive[index].income.firstIncome + pMassive[index].income.secondIncome) / 2;
			pMassive[index].income.netIncome = income;
			break;
		case 6:
			cout << "����� ������� ����� �����: ";
			cin >> pMassive[index].income.secondIncome;
			income = (pMassive[index].income.firstIncome + pMassive[index].income.secondIncome) / 2;
			pMassive[index].income.netIncome = income;
			break;
		case 0:
			running = false;  // ����������� false, ����� ��������� ����������� ����
		}
		system("cls");
	}
}

void deleteStudentElement(student*& pMassive, int indexOfStudent) {

	MASSIVE_SIZE--;
	short int deleteAction = 0;
	student* newMassive = new student[MASSIVE_SIZE];

	cout << "�� ������������� ������ ������� �������? (1 - ��, 2 - ���)\n" << "�������: ";
	cin >> deleteAction;

	switch (deleteAction)
	{
	case confirmationOfTheExecution::confirm:

		for (int i = indexOfStudent; i < MASSIVE_SIZE; i++) swap(pMassive[i], pMassive[i + 1]);
		for (int i = 0; i < MASSIVE_SIZE; i++) newMassive[i] = pMassive[i]; //��������� ����� ������

		delete[] pMassive;
		pMassive = newMassive;
		break;

	case confirmationOfTheExecution::notConfirm:
		cout << "������� �������� � ������ �������" << endl;
		delete[] newMassive;
	}
}

void inputMinimalSalary() {
	cout << "����������� ���������� �����: ";
	cin >> MINIMAL_SALARY;
}

int inputNumber(bool(*pFuction)(int))
{
	int number;
	cout << "����: ";
	while (true)
	{
		cin >> number;

		if (isNumberNumeric() && pFuction(number)) return number;
		else cout << "������������ ����! ��������� �������: ";
	}
}
bool isNumberNumeric()
{
	if (cin.get() == '\n')
		return true;
	else
	{
		cin.clear();
		cin.ignore(256, '\n');
		return false;
	}
}
bool isNumberRangeCorrectForMenu(int number) {
	if (number < 0 or number > 2) return false;
	else return true;
}
bool isNumberRangeCorrectForEditMenu(int number) {
	if (number < 0 or number > 6) return false;
	else return true;
}
bool isNumberRangeCorrectForProccesingMenu(int number) {
	if (number < 0 or number > 3) return false;
	else return true;
}
bool isNumberRangeCorrectForMark(int number) {
	if (number < 0 or number > 10) return false;
	else return true;
}
bool trueFunction(int number) {
	return true;
}
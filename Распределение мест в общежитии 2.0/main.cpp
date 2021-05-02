#include<iostream>
#include<fstream>
#include<iomanip>

#include "userTypes.h"
#include "functions.h"
#include "menu.h"

using namespace std;

short int MASSIVE_SIZE = 0;
unsigned int MINIMAL_SALARY = 0;
bool CONDITION_OF_MASSIVE = false;

// ���� ���������
void editMenu(short int, student*&);
void processingMenu(short int, short int, short int, student *&);
void searchMenu(short int, student *&);
void sortMenu(short int, student *&);


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


int main() {
	
	setlocale(0, "");

	student* pMassive = NULL;

	while (true) {

		short int modeSelection = 0, choiceEditMode = 0, choiceProcessingMode = 0, choiceSearchMode = 0, choiceSortMode = 0;

		formOfMainMenu();
		cout << "�����: ";
		cin >> modeSelection;

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
				exit(0);
		}
	}
}

void editMenu(short int choice, student*& pMassive) {

	formOfEditMenu();
	cout << "�����: ";
	cin >> choice;

	switch (choice)
	{
		case modeOfEditing::add_student_info:
			break;
		case modeOfEditing::delete_student_structer:
			break;
		case modeOfEditing::edit_student_info:
			break;
		case modeOfEditing::get_data_from_file:
			getDataFromFile(pMassive);
			break;
		case modeOfEditing::record_data_in_file:
			break;
		case modeOfEditing::close_editing_menu:
			return;
	}
	system("pause");
	system("cls");
}
void processingMenu(short int choiceProcessingMode, short int choiceSearchMode, short int choiceSortMode, student*& pMassive) {

	formOfProcessingMenu();
	cout << "�����: ";
	cin >> choiceProcessingMode;

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
			break;
		case modeOfProcessing::close_processing_mode:
			return;
	}
}
void searchMenu(short int choice, student*& pMassive) {
	formOfSearchMenu();
	cout << "�����: ";
	cin >> choice;

	system("cls");

	switch (choice)
	{
		case modeOfSerching::search_by_name:
			break;
		case modeOfSerching::search_by_group:
			break;
		case modeOfSerching::search_by_average_number:
			break;
		case modeOfSerching::close_search_menu:
			return;
	}
}
void sortMenu(short int choice, student*& pMassive) {

	formOfSortingMenu();
	cout << "�����: ";
	cin >> choice;

	system("cls");
	switch (choice)
	{
		case modeOfSorting::sort_by_name:
			outputDataInTable(pMassive);
			break;
		case modeOfSorting::sort_by_average_mark:
			break;
		case modeOfSorting::sort_by_income:
			break;
		case modeOfSorting::close_sort_menu:
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

	if (CONDITION_OF_MASSIVE == true) cout << "������ ���������� ��� ��� ������ ��������" << endl;

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
	CONDITION_OF_MASSIVE = true;

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
	
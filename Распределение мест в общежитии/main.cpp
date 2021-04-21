#include<iostream>
#include<fstream>
#include<Windows.h>

using namespace std;

struct student {
	char studentName[30] = {'\0'};
	short int socialActivity = 0;
	char groupNumber[20] = {'\0'};
	double averageScore = 0;

	struct familyIncome {
		unsigned int firstIncome = 0;
		unsigned int secondIncome = 0;
		unsigned int netIncome = 0;
		bool flag = false;
	}income;
		
};

enum menu { setllement_of_students = 1, sharing_of_student, pop_element, edit_element, sort_element, output_element, search_info, input_data_in_file, output_data_from_file, close_program = 0};
enum deleteAction {deletee_element = 1, leave_element};  // �������� ��� ��������� 


void inputStudentList(bool * , int &, student *&, short int, unsigned int); //���������� ������ � ������ (�������)

void settlementOfStudent(student*& pMassive, bool* , int&, unsigned int);

void sharingOfStudent(student*& pMassive, bool*, int&, unsigned int);

void deleteStudentElement(int& , student*&, string); // �������� ��������� ������� (�������)

void editStudentElement(int, student*&); // �������������� ��������� ������� (�������)

void sortStudentList(int, student*&, unsigned int); //���������� ������� ������

void outputStudentList(student *, int, unsigned int); //�������� ������ (�������)

void searchStudentInfo(int, student *); // ����� ���������� � �������� (�������)

void inputDataInFile(student*, int);

void outputDataFromFile(student *&, int&, bool *);

int main() {
	setlocale(0, "");
	//system("chcp 1251");

	
	int amountOfStudent = 0;
	bool running = true;

	student* pMassive = NULL; // ������������� ���� ������������ ���-�� ��������� ��� ��������� � main 

	unsigned int minimumWage = 0;
	unsigned short int choiseOfAction = 0;

	bool conditionOfMassive = false;

	unsigned int minimalSalary = 0;

	cout << "������� ����������� ���������� �����\n����: ";
	cin >> minimalSalary;


	while (running) {
		string nameOfStudent = "";
		cout << "----------------------";
		cout << "\n���� ���������\n" << endl;
		cout << "{1} - ��������� ���������\n" << "{2} - ���������� ���������\n" << "{3} - �������� ����������\n" << "{4} - ��������������\n";
		cout << "{5} - ���������� ����������\n" << "{6} - ����� ����������\n" << "{7} - ����� ����������\n";
		cout<< "{8} - �������� ������ � ����\n"<<"{9} - �������� ������ �� �����\n" << "{0} - ������� ���������\n" << endl;
		cout << "��������: ";
		cin >> choiseOfAction;
		cout << "----------------------";

		switch (choiseOfAction)
		{
			case menu::setllement_of_students:
				settlementOfStudent(pMassive, &conditionOfMassive, amountOfStudent, minimalSalary);
				break;

			case menu::sharing_of_student:
				sharingOfStudent(pMassive, &conditionOfMassive, amountOfStudent, minimalSalary);
				break;

			case menu::pop_element:
				if (amountOfStudent == 0) {
					cout << "\n������ ��������� ����\n";
					break;
				}
				cout << "\n������� ��� �������� ��� ��������\n" << "���: ";
				cin >> nameOfStudent;

				deleteStudentElement(amountOfStudent, pMassive, nameOfStudent);
				break;

			case menu::edit_element:
				editStudentElement(amountOfStudent, pMassive);
				break;

			case menu::sort_element:
				sortStudentList(amountOfStudent, pMassive, minimalSalary);
				cout << endl;
				break;

			case menu::output_element:
				outputStudentList(pMassive, amountOfStudent, minimalSalary);
				break;
			case menu::search_info:
				searchStudentInfo(amountOfStudent, pMassive);
				break;

			case menu::input_data_in_file:
				inputDataInFile(pMassive, amountOfStudent);
				break;

			case menu::output_data_from_file:
				outputDataFromFile(pMassive, amountOfStudent, &conditionOfMassive);
				break;

			case menu::close_program:
				if (conditionOfMassive == true) delete[] pMassive;
				exit(0);
		}
	}
}

void settlementOfStudent(student*& pMassive, bool* pCondition, int& size, unsigned int minimalSalary) {
	int amountOfStudent = 0;

	if (*pCondition == true) {
		cout << "\n��������� ��� ������, �������� ������ ����������" << endl;
		return;
	}

	cout << "\n������� ��������� �� ������ ��������?\n" << "����������: ";
	cin >> amountOfStudent;
	size = amountOfStudent;

	pMassive = new student[size];  // ������� ������������ ������ �� ���-�� ���������, ������� ������ ������������

	for (int i = 0; i < size; i++) {
		cin.ignore();
		cout << "\n������� ��� ��������: ";
		cin.getline(pMassive[i].studentName, 30);

		cout << "������� ����� ������ ��������: ";
		cin.getline(pMassive[i].groupNumber, 20);

		cout << "��������� �� ������� ����������� ��������({1 - ��} ��� {2 - ���}): ";
		cin >> pMassive[i].socialActivity;

		cout << "������� ������� ���� ��������: ";
		cin >> pMassive[i].averageScore;

		cout << "������� ����� ������� ����� �����: ";
		cin >> pMassive[i].income.firstIncome;
		cout << "������� ����� ������� ����� �����: ";
		cin >> pMassive[i].income.secondIncome;
		pMassive[i].income.netIncome = (pMassive[i].income.firstIncome + pMassive[i].income.secondIncome) / 2;
		if (pMassive[i].income.netIncome < minimalSalary) pMassive[i].income.flag = true;
	}

	*pCondition = true;
}
void sharingOfStudent(student*& pMassive, bool* pCondition, int& size, unsigned int minimalSalary) {

	if (*pCondition == false) {
		cout << "\n���������� ����������, ��� ��� ��������� ��� �� ������" << endl;
		return;
	}

	size++;
	student info;
	student* newMassive = new student[size];

	for (int i = 0; i < size - 1; i++) newMassive[i] = pMassive[i]; // �������������� ������ �� ������� ������� � �����

	cin.ignore();
	cout << "������� ��� ��������: ";
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
	if (info.income.netIncome < minimalSalary) info.income.flag = true;

	newMassive[size - 1] = info;

	delete[] pMassive;

	pMassive = newMassive;

}
void deleteStudentElement(int& size, student*& pMassive, string nameOfStudent) {

	short int index = 0;
	unsigned short int action = 0;

	student* newMassive = new student[size]; 
	
	for (int i = 0; i < size; i++) {  // ����� ������� �������� � ������� (�������� ���������� �������������� ����������) 
		index++;
		if (nameOfStudent == pMassive[i].studentName) break;
	}

	if (index == size and pMassive[index - 1].studentName != nameOfStudent) { // �������� ���������� �������� �������
		cout << "������� � ��������� ����������� �����c�����" << endl;
		return;
	}

	cout << "�� ������������� ������ ������� �������? (1 - ��, 2 - ���)\n" << "�������: ";
	cin >> action;

	switch (action)
	{
	case deleteAction::deletee_element:
		swap(pMassive[index - 1], pMassive[size - 1]); // ������ ������� ��������� ������� � �������, ������� ����� �������

		size--; // �������� ������ ������� �� ���� ������� 

		for (int i = 0; i < size; i++) newMassive[i] = pMassive[i]; //��������� ����� ������

		delete[] pMassive;
		pMassive = newMassive;
		break;

	case deleteAction::leave_element:
		cout << "������� �������� � ������ �������" << endl;
		delete[] newMassive;
	}

}
void editStudentElement(int size, student *&pMassive) {

	short int choice = 0;
	string name = "";
	int count = 0;  // ������� ��� ���-�� �������� (����� ������� ���������, � ������ ���� �������� � ����� ������ �� ����� � ������)
	bool running = true;  // ��� ��������� ����� while

	cout << "\n������� ��� ��������, ������ �������� ������ ���������������" << endl;
	cout << "���: ";
	cin >> name;

	for (int i = 0; i < size; i++) {

		count++;

		if (name == pMassive[i].studentName) {  // ������� ��� �������� ������� �������� � �������

			cout << "������� ���� � ������. �������� �������� ��� ��������������:" << endl;

			while (running) {

				int income = 0;

				cout << "\n{1} - ���\n" << "{2} - ����� ������\n" << "{3} - ������� ����������� ��������\n";
				cout << "{4} - ������� ����\n" << "{5} - ����� ������� ����� �����\n" << "{6} - ����� ������� ����� �����\n" << "{7} - ��������� ��������������" << endl;
				cout << "\n�����: ";
				cin >> choice;

				switch (choice)
				{
				case 1:
					cout << "���: ";
					cin >> pMassive[i].studentName;
					break;
				case 2:
					cout << "����� ������: ";
					cin >> pMassive[i].groupNumber;
					break;
				case 3:
					cout << "������� ����������� �������� (�� ��� ���): ";
					cin >> pMassive[i].socialActivity;
					break;
				case 4:
					cout << "������� ����: ";
					cin >> pMassive[i].averageScore;
					break;
				case 5:
					cout << "����� ������� ����� �����: ";
					cin >> pMassive[i].income.firstIncome;
					income = (pMassive[i].income.firstIncome + pMassive[i].income.secondIncome) / 2;
					pMassive[i].income.netIncome = income;
					break;
				case 6:
					cout << "����� ������� ����� �����: ";
					cin >> pMassive[i].income.secondIncome;
					income = (pMassive[i].income.firstIncome + pMassive[i].income.secondIncome) / 2;
					pMassive[i].income.netIncome = income;
					break;
				case 7:
					running = false;  // ����������� false, ����� ��������� ����������� ����
				}
			}
			break; // break ��� ������ �� ����� for
		}
		else if (count == size) cout << "������ �������� ��� � ������" << endl;
	}
}
void sortStudentList(int size, student *&pMassive, unsigned int minimalSalary) {

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {

			if (pMassive[j].averageScore < pMassive[j + 1].averageScore) swap(pMassive[j], pMassive[j + 1]);
			else if (pMassive[j].averageScore == pMassive[j + 1].averageScore) {
				if (pMassive[j].socialActivity == 2 and pMassive[j + 1].socialActivity == 1) swap(pMassive[j], pMassive[j + 1]);
			}
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {

			if (pMassive[j].income.flag == false and pMassive[j + 1].income.flag == true) swap(pMassive[j], pMassive[j + 1]);
		}
	}

	cout << "\n���������� ������ ���������" << endl;
}
void outputStudentList(student * pMassive, int size, unsigned int minimalSalary){

	if (size == 0) cout << "\n������ ��������� ����" << endl;

	if (pMassive == NULL) {
		cout << "\n��������� ��������� ��� �� ������" << endl;
		return;
	}

	for (int i = 0; i < size; i++) {

		cout << "\n��� ��������: " << pMassive[i].studentName << endl;
		cout << "����� ������: " << pMassive[i].groupNumber << endl;
		cout << "������� ����: " << pMassive[i].averageScore << endl;
		cout << "�������� � ������������ ������������: " << pMassive[i].socialActivity << endl;
		cout << "����� �� ����� �����: " << pMassive[i].income.netIncome << endl;
		cout << "����������� ���������� �����: " << minimalSalary << "\n" << endl;
	}
}
void searchStudentInfo(int size, student *pMassive) {

	string name = "";

	cout << "\n������� ��� ��������" << endl;
	cout << "���: ";
	cin >> name;
	cout << "��������� ������: " << endl;

	if (size == 0) cout << "\n������ ��������� ����" << endl;

	for (int i = 0; i < size; i++)
	{
		if (name == pMassive[i].studentName) {
			cout << "\n��� ��������: " << pMassive[i].studentName << endl;
			cout << "����� ������: " << pMassive[i].groupNumber << endl;
			cout << "������� ����: " << pMassive[i].averageScore << endl;
			cout << "�������� � ������������ ������������: " << pMassive[i].socialActivity << endl;
			cout << "����� �� ����� �����: " << pMassive[i].income.netIncome << "\n" << endl;
		}
		else if (i == size - 1) cout << "��������(��) � ����� ������ ��� � ������" << endl;
	}
} 
void inputDataInFile(student *pMassive, int size){
	student info;

	const char* PATH = "D:\\C++\\Structers of student\\file.dat";

	ofstream binaryFile(PATH, ios::binary);

	if (binaryFile.is_open()) cout << "\n���� ������\n";
	else {
		cout << "������ ��� ������� �����" << endl;
		return;
	}

	for (int i = 0; i < size; i++) {
		info = pMassive[i];
		binaryFile.write((char*)&info, sizeof(info));
	}

	cout << "������ � ���� ������ �������" << endl;

	binaryFile.close();
}
void outputDataFromFile(student *&pMassive, int &size, bool *conditionalOfMassive) {

	const char* PATH = "D:\\C++\\Structers of student\\file.dat";

	if (*conditionalOfMassive == true) {
		cout << "\n������ ��������� ��� ��������. ������ �� ����� ����������" << endl;
		return;
	}
	else *conditionalOfMassive = true;

	ifstream file(PATH, ios::binary);

	if (file.is_open()) cout << "\n���� ������\n";
	else {
		cout << "������ ��� ������� �����" << endl;
		return;
	}

	size = 10;
	pMassive = new student[size];
	

	for (int i = 0; i < size; i++) {
		file.read((char*)&pMassive[i], sizeof(student));
	}

	cout << "������ �� ����� ������ �������" << endl;

	file.close();

}
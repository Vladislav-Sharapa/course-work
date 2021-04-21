#include<iostream>
#include<Windows.h>

using namespace std;

struct student {
	string studentName;
	string socialActivity;
	string groupNumber;
	double averageScore = 0;

	struct familyIncome {
		unsigned int firstIncome = 0;
		unsigned int secondIncome = 0;
		unsigned int netIncome = 0;
	}income;

};

enum menu { push_element = 1, pop_element, edit_element, sort_element, output_element, search_info, close_program };
enum inputAction { accommodation_of_student = 1, sharing_of_student, return_back };
enum deleteAction { deletee_element = 1, leave_element };  // �������� ��� ��������� 

void inputStudentList(bool*, int&, student*&, short int); //���������� ������ � ������ (�������)

void deleteStudentElement(int&, student*&, string); // �������� ��������� ������� (�������)

void editStudentElement(int, student*&); // �������������� ��������� ������� (�������)

void sortStudentList(int, student*&); //���������� ������� ������

void outputStudentList(student*, int); //�������� ������ (�������)

void searchStudentInfo(int, student*); // ����� ���������� � �������� (�������)

int main() {
	setlocale(0, "");
	//system("chcp 1251");


	int amountOfStudent = 0;
	bool running = true;

	student* pMassive = NULL; // ������������� ���� ������������ ���-�� ��������� ��� ��������� � main 

	unsigned int minimumWage = 0;
	unsigned short int choiseOfAction = 0;
	short int action = 0;

	bool conditionOfMassive = false;

	while (running) {
		string nameOfStudent = "";
		cout << "----------------------";
		cout << "\n���� ���������\n" << endl;
		cout << "{1} - ���� ����������\n" << "{2} - �������� ����������\n" << "{3} - ��������������\n";
		cout << "{4} - ���������� ����������\n" << "{5} - ����� ����������\n" << "{6} - ����� ����������\n" << "{7} - ������� ���������\n" << endl;
		cout << "��������: ";
		cin >> choiseOfAction;
		cout << "----------------------";

		switch (choiseOfAction)
		{
		case menu::push_element:

			cout << "\n�������� ��������: " << endl;;
			cout << "{1} - ��������� ���������\n" << "{2} - ���������� ���������\n" << "{3} - ������� ����\n" << endl;
			cout << "��������: ";
			cin >> action;

			inputStudentList(&conditionOfMassive, amountOfStudent, pMassive, action);
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
			sortStudentList(amountOfStudent, pMassive);
			cout << endl;
			break;

		case menu::output_element:
			outputStudentList(pMassive, amountOfStudent);
			break;
		case menu::search_info:
			searchStudentInfo(amountOfStudent, pMassive);
			break;

		case menu::close_program:
			exit(0);
		}
	}
}

void inputStudentList(bool* pCondition, int& size, student*& pMassive, short int action) {

	int amountOfStudent = 0;

	switch (action)
	{
	case inputAction::accommodation_of_student:  // ��������� ��������� 


		if (*pCondition == true) {
			cout << "��������� ��� ������, �������� ������ ����������" << endl;
			break;
		}

		cout << "������� ��������� �� ������ ��������?\n" << "����������: ";
		cin >> amountOfStudent;
		size = amountOfStudent;

		pMassive = new student[size];  // ������� ������������ ������ �� ���-�� ���������, ������� ������ ������������

		for (int i = 0; i < size; i++) {
			cout << "\n������� ��� ��������: ";
			cin >> pMassive[i].studentName;

			cout << "������� ����� ������ ��������: ";
			cin >> pMassive[i].groupNumber;

			cout << "��������� �� ������� ����������� ��������({��} ��� {���}): ";
			cin >> pMassive[i].socialActivity;

			cout << "������� ������� ���� ��������: ";
			cin >> pMassive[i].averageScore;

			cout << "������� ����� ������� ����� �����: ";
			cin >> pMassive[i].income.firstIncome;
			cout << "������� ����� ������� ����� �����: ";
			cin >> pMassive[i].income.secondIncome;
			pMassive[i].income.netIncome = (pMassive[i].income.firstIncome + pMassive[i].income.secondIncome) / 2;
		}

		*pCondition = true;
		break;

	case inputAction::return_back:  // ������� �����
		break;

	case inputAction::sharing_of_student:  // ���������� ��������� 

		if (*pCondition == false) {
			cout << "���������� ����������, ��� ��� ��������� ��� �� ������" << endl;
			break;
		}

		size++;
		student info;
		student* newMassive = new student[size];

		for (int i = 0; i < size - 1; i++) newMassive[i] = pMassive[i];


		cout << "������� ��� ��������: ";
		cin >> info.studentName;

		cout << "������� ����� ������ ��������: ";
		cin >> info.groupNumber;

		cout << "��������� �� ������� ����������� ��������({��} ��� {���}): ";
		cin >> info.socialActivity;

		cout << "������� ������� ���� ��������: ";
		cin >> info.averageScore;

		cout << "������� ����� ������� ����� �����: ";
		cin >> info.income.firstIncome;
		cout << "������� ����� ������� ����� �����: ";
		cin >> info.income.secondIncome;
		info.income.netIncome = (info.income.firstIncome + info.income.secondIncome) / 2;

		newMassive[size - 1] = info;

		delete[] pMassive;

		pMassive = newMassive;
	}
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
void editStudentElement(int size, student*& pMassive) {

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
void sortStudentList(int size, student*& pMassive) {

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {

			if (pMassive[j].averageScore < pMassive[j + 1].averageScore) swap(pMassive[j], pMassive[j + 1]);

		}
	}

}
void outputStudentList(student* pMassive, int size) {

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
		cout << "����� �� ����� �����: " << pMassive[i].income.netIncome << "\n" << endl;
	}
}
void searchStudentInfo(int size, student* pMassive) {

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

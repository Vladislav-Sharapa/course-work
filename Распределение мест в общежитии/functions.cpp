#include<iostream>
#include<fstream>

#include "userTypes.h"
#include "functions.h"

using namespace std;

void settlementOfStudent(student*& pMassive, bool* pCondition, int* size, unsigned int minimalSalary) {
	int amountOfStudent = 0;

	if (*pCondition == true) {
		cout << "\n��������� ��� ������, �������� ������ ����������" << endl;
		return;
	}

	cout << "\n������� ��������� �� ������ ��������?\n" << "����������: ";
	cin >> amountOfStudent;
	*size = amountOfStudent;

	pMassive = new student[*size];  // ������� ������������ ������ �� ���-�� ���������, ������� ������ ������������

	for (int i = 0; i < *size; i++) {
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
void sharingOfStudent(student*& pMassive, bool* pCondition, int* size, unsigned int minimalSalary) {

	if (*pCondition == false) {
		cout << "\n���������� ����������, ��� ��� ��������� ��� �� ������" << endl;
		return;
	}
	else (*size)++;

	student info;
	student* newMassive = new student[*size];

	for (int i = 0; i < *size - 1; i++) newMassive[i] = pMassive[i]; // �������������� ������ �� ������� ������� � �����

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
	if (info.income.netIncome < minimalSalary) info.income.flag = true;

	newMassive[*size - 1] = info;

	delete[] pMassive;  // ������� ������ ������������ ������

	pMassive = newMassive;

}
void deleteStudentElement(int& size, student*& pMassive, string nameOfStudent) {

	short int indexOfELement = 0;
	unsigned short int action = 0;

	student* newMassive = new student[size];

	for (int i = 0; i < size; i++) {  // ����� ������� �������� � ������� (�������� ���������� �������������� ����������) 
		indexOfELement++;
		if (nameOfStudent == pMassive[i].studentName) break;
	}

	if (indexOfELement == size and pMassive[indexOfELement - 1].studentName != nameOfStudent) { // �������� ���������� �������� �������
		cout << "������� � ��������� ����������� �����c�����" << endl;
		return;
	}

	cout << "�� ������������� ������ ������� �������? (1 - ��, 2 - ���)\n" << "�������: ";
	cin >> action;

	switch (action)
	{
	case deleteAction::deletee_element:
		swap(pMassive[indexOfELement - 1], pMassive[size - 1]); // ������ ������� ��������� ������� � �������, ������� ����� �������

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
	string nameOfStudent = "";  // ���������� ��� ������ �������� � ������� �� �����
	int countOfItereations = 0;  // ������� ��� ���-�� �������� (����� ������� ���������, � ������ ���� �������� � ����� ������ �� ����� � ������)
	bool running = true;  // ��� ��������� ����� while

	cout << "\n������� ��� ��������, ������ �������� ������ ���������������" << endl;
	cout << "���: ";
	cin >> nameOfStudent;

	for (int i = 0; i < size; i++) {

		countOfItereations++;

		if (nameOfStudent == pMassive[i].studentName) {  // ������� ��� �������� ������� �������� � �������

			cout << "������� ���� � ������. �������� �������� ��� ��������������:" << endl;

			while (running) {

				double income = 0;

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
					cout << "������� ����������� �������� ({1} - ��, {2} - ���): ";
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
		else if (countOfItereations == size) cout << "������ �������� ��� � ������" << endl;
	}
}
void sortStudentList(int size, student*& pMassive, unsigned int minimalSalary) {

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

	cout << "\n���������� ������ ���������";
}
void outputStudentList(student* pMassive, int size, unsigned int minimalSalary) {

	string socialActivity = "";

	if (size == 0) {
		cout << "\n������ ��������� ����" << endl;
		return;
	}

	for (int i = 0; i < size; i++) {
		if (pMassive[i].socialActivity == 1) socialActivity = "����������";
		else socialActivity = "�� ����������";

		cout << "\n��� ��������: " << pMassive[i].studentName << endl;
		cout << "����� ������: " << pMassive[i].groupNumber << endl;
		cout << "������� ����: " << pMassive[i].averageScore << endl;
		cout << "�������� � ������������ ������������: " << socialActivity << endl;
		cout << "����� �� ����� �����: " << pMassive[i].income.netIncome << endl;
		cout << "����������� ���������� �����: " << minimalSalary << endl;
	}
}
void searchStudentInfo(int size, student* pMassive) {

	string name = "";
	string socialActivity = "";
	unsigned short int countOfStudent = 0;

	cout << "\n������� ��� ��������" << endl;
	cout << "���: ";
	cin >> name;
	cout << "��������� ������: " << endl;

	if (size == 0) cout << "\n������ ��������� ����" << endl;

	for (int i = 0; i < size; i++)
	{
		if (name == pMassive[i].studentName) {

			if (pMassive[i].socialActivity == 1) socialActivity = "����������";
			else socialActivity = "�� ����������";

			cout << "\n��� ��������: " << pMassive[i].studentName << endl;
			cout << "����� ������: " << pMassive[i].groupNumber << endl;
			cout << "������� ����: " << pMassive[i].averageScore << endl;
			cout << "�������� � ������������ ������������: " << socialActivity << endl;
			cout << "����� �� ����� �����: " << pMassive[i].income.netIncome << endl;
			countOfStudent++;
		}
		else if (i == size - 1 and countOfStudent == 0) cout << "��������(��) � ����� ������ ��� � ������" << endl;
	}
}
void inputDataInFile(student* pMassive, int size) {
	student info;

	ofstream binaryFile("D:\\C++\\Structers of student\\file.dat", ios::binary);

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
void outputDataFromFile(student*& pMassive, int* size, bool* conditionalOfMassive) {

	if (*conditionalOfMassive == true) {
		cout << "\n������ ��������� ��� ��������. ������ �� ����� ����������" << endl;
		return;
	}
	else *conditionalOfMassive = true;

	ifstream file("D:\\C++\\Structers of student\\file.dat", ios::binary);

	if (file.is_open()) cout << "\n���� ������\n";
	else {
		cout << "������ ��� ������� �����" << endl;
		return;
	}

	*size = 10;
	pMassive = new student[*size];


	for (int i = 0; i < *size; i++) {
		file.read((char*)&pMassive[i], sizeof(student));
	}

	cout << "������ �� ����� ������ �������" << endl;

	file.close();
}


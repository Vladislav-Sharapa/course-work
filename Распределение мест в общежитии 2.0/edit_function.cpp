#include<iostream>
#include<iomanip>

#include"edit_function.h"
#include"security_function.h"
#include"form_of_menu.h"

using namespace std;

extern short int MASSIVE_SIZE;
extern unsigned int MINIMAL_SALARY;

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

// ������� ���������� ��������� � ������
student inputInfoAboutStudent() {
	student info;

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

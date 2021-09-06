#include<iostream>
#include<vector>
#include<iomanip>

#include"userTypes.h"
#include"search_function.h"
#include"security_function.h"

extern short int MASSIVE_SIZE;

using namespace std;

void searchStudentByName(student* pMassive) {

	vector<int>index;
	char nameOfStudent[30] = { '\0' };
	bool flag = false;

	cout << "������� ��� ��������: ";
	cin.getline(nameOfStudent, 30);

	// ���� ��� ������ �������� �������
	for (int i = 0; i < MASSIVE_SIZE; i++) {
		short int countOfSameLetters = 0; // ������� ���-�� ��������
		for (int j = 0; j < 4; j++) {
			if (nameOfStudent[j] == pMassive[i].studentName[j]) countOfSameLetters++;
		}
		if (countOfSameLetters == 4) { // ������� ���������� �����
			index.push_back(i);
			flag = true;
		}
	}
	cout << "��������� ������: \n" << endl;
	
	// ����� ����������� ������ � ��������� ����
	if (flag == false)  cout << "����� ��������� ��� � ������" << endl;
	else {
		cout << "+--------------------------------------------------------------------------+" << endl;
		cout << "|    ��� ��������    | ����� ������ | ��. ���� | ����� | C��. ������������ |" << endl;
		cout << "+--------------------------------------------------------------------------+" << endl;

		for (int i = 0; i < index.size(); i++) {
			string socialActivity = "";

			if (pMassive[index[i]].socialActivity == 1) socialActivity = "����������";
			else socialActivity = "�� ����������";

			cout << "|" << setw(20) << pMassive[index[i]].studentName << "|";
			cout << setw(14) << pMassive[index[i]].groupNumber << "|" << setw(10) << pMassive[index[i]].averageScore << "|";
			cout << setw(7) << pMassive[index[i]].income.netIncome << "|" << setw(19) << socialActivity << "|" << endl;
			cout << "+--------------------------------------------------------------------------+" << endl;
		}
	}
}
// ����� �������� �� ������ ������
void searchStudentByGroup(student* pMassive) {

	vector<int>index;
	char groupNumber[30] = { '\0' };
	bool flag = false;

	cout << "������� ����� ������ . . ." << endl;
	cout << "����: ";
	cin.getline(groupNumber, 30);

	for (int i = 0; i < MASSIVE_SIZE; i++) {
		if (strcmp(groupNumber, pMassive[i].groupNumber) == 0) {  // ���������� ������
			index.push_back(i); // ��������� ������ � ������
			flag = true;
		}
	}

	cout << "��������� ������: \n" << endl;
	// ������ ��������� ������ � ��������� ����
	if (flag == false)  cout << "����� ��������� ��� � ������" << endl;
	else {
		cout << "+--------------------------------------------------------------------------+" << endl;
		cout << "|    ��� ��������    | ����� ������ | ��. ���� | ����� | C��. ������������ |" << endl;
		cout << "+--------------------------------------------------------------------------+" << endl;

		for (int i = 0; i < index.size(); i++) {
			string socialActivity = "";

			if (pMassive[index[i]].socialActivity == 1) socialActivity = "����������";
			else socialActivity = "�� ����������";

			cout << "|" << setw(20) << pMassive[index[i]].studentName << "|";
			cout << setw(14) << pMassive[index[i]].groupNumber << "|" << setw(10) << pMassive[index[i]].averageScore << "|";
			cout << setw(7) << pMassive[index[i]].income.netIncome << "|" << setw(19) << socialActivity << "|" << endl;
			cout << "+--------------------------------------------------------------------------+" << endl;
		}
	}

}
// ����� �� �������� �����
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

	cout << "��������� ������: \n" << endl;
	if (flag == false)  cout << "����� ��������� ��� � ������" << endl;
	else {
		cout << "+--------------------------------------------------------------------------+" << endl;
		cout << "|    ��� ��������    | ����� ������ | ��. ���� | ����� | C��. ������������ |" << endl;
		cout << "+--------------------------------------------------------------------------+" << endl;

		for (int i = 0; i < index.size(); i++) {
			string socialActivity = "";

			if (pMassive[index[i]].socialActivity == 1) socialActivity = "����������";
			else socialActivity = "�� ����������";

			cout << "|" << setw(20) << pMassive[index[i]].studentName << "|";
			cout << setw(14) << pMassive[index[i]].groupNumber << "|" << setw(10) << pMassive[index[i]].averageScore << "|";
			cout << setw(7) << pMassive[index[i]].income.netIncome << "|" << setw(19) << socialActivity << "|" << endl;
			cout << "+--------------------------------------------------------------------------+" << endl;
		}
	}
}
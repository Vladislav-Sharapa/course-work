#include<iostream>
#include<fstream>
#include<iomanip>

#include"userTypes.h"

extern short int MASSIVE_SIZE;

using namespace std;

// ������� ��� ������ � �������
int getCountOfStructerInFile() {
	// ��������� ���� ��� ������ � �������� ������ � ���������� ��������� � ����� ����� (ios::ate)
	ifstream file("D:\\C++\\Structers of student\\file.dat", ios::ate | ios::binary);

	int numberOfStructer = file.tellg() / sizeof(student);  // ����������� ���-�� �������� � �����
	return numberOfStructer;
}
// ������� ��������� ������ �� �����
void getDataFromFile(student*& pMassive) {

	// �������� ������������� �������
	if (MASSIVE_SIZE > 0) {
		cout << "������ ���������� ��� ��� ������ �������� . . ." << endl;
		return;
	}

	ifstream file("D:\\C++\\Structers of student\\file2.dat", ios::binary); // �������� ����� � ������ ������

	if (file.is_open()) cout << "\n���� ������. . .\n";
	else {
		cout << "������ ��� ������� �����" << endl;
		return;
	}

	MASSIVE_SIZE = getCountOfStructerInFile(); // �������� ���-�� ��������, ���������� � �����
	pMassive = new student[MASSIVE_SIZE];

	// ��������� ��������� �� ����� � ������
	for (int i = 0; i < MASSIVE_SIZE; i++) {
		file.read((char*)&pMassive[i], sizeof(student));
	}

	cout << "������ �� ����� ������ �������. . ." << endl;

	file.close(); // ��������� ����
}
// ������� ������ ������ � ����
void recordDatainFile(student* pMassive) {
	
	// �������� ������������� �������
	if (MASSIVE_SIZE == 0) {
		cout << "������ ����������, ��� ��� ������ ���� . . ." << endl;
		return;
	}

	ofstream file("D:\\C++\\Structers of student\\file2.dat", ios::binary | ios::out); // �������� ��������� ����� � ������ ������

	if (!file.is_open()) {
		cout << "������ ��� ��������. ��������� ���� �� ����������" << endl;
		return;
	}
	else {
		for (int i = 0; i < MASSIVE_SIZE; i++) file.write((char*)&pMassive[i], sizeof(student)); // ������ ������ � ����
		cout << "������ ������ � ���� ������ ������� . . ." << endl;
	}

	file.close(); // ��������� �����

}

void inputInTextFile(student* pMassive) {

	ofstream file;

	// ��������� �������������� ��������
	try {
		file.open(("D:\\C++\\Structers of student\\student.txt")); // �������� ����� 

	}
	catch(const std::exception& ex){
		cout << "������ ��� �������� ����� . . ." << endl;
		return;
	}

	string socialActivity = "";
	
	// ������ ������ � ����
	file << "+----------------------------------------------------------------------------------+\n";
	file << "| ����� |    ��� ��������    | ����� ������ | ��. ���� | ����� | C��. ������������ |\n";
	file << "+----------------------------------------------------------------------------------+\n";

	for (int i = 0; i < MASSIVE_SIZE; i++) {
		if (pMassive[i].socialActivity == 1) socialActivity = "����������";
		else socialActivity = "�� ����������";

		file << "|" << setw(7) << i + 1 << "|" << setw(20) << pMassive[i].studentName << "|";
		file << setw(14) << pMassive[i].groupNumber << "|" << setw(10) << pMassive[i].averageScore << "|";
		file<< setw(7) << pMassive[i].income.netIncome << "|" << setw(19) << socialActivity << "|\n";
		file <<	"+----------------------------------------------------------------------------------+" << endl;
	}

	file.close();
}
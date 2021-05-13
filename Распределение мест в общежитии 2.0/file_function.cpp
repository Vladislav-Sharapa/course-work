#include<iostream>
#include<fstream>

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
void getDataFromFile(student*& pMassive) {

	if (MASSIVE_SIZE > 0) {
		cout << "������ ���������� ��� ��� ������ �������� . . ." << endl;
		return;
	}

	ifstream file("D:\\C++\\Structers of student\\file2.dat", ios::binary);

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

	if (MASSIVE_SIZE == 0) {
		cout << "������ ����������, ��� ��� ������ ���� . . ." << endl;
		return;
	}

	ofstream file("D:\\C++\\Structers of student\\file2.dat", ios::binary | ios::out);

	if (!file.is_open()) {
		cout << "������ ��� ��������. ��������� ���� �� ����������" << endl;
		return;
	}
	else {
		for (int i = 0; i < MASSIVE_SIZE; i++) file.write((char*)&pMassive[i], sizeof(student));
		cout << "������ ������ � ���� ������ ������� . . ." << endl;
	}

	file.close();

}
void recordDataInEndOfFile(student* pMassive) {

	ofstream file("D:\\C++\\Structers of student\\file.dat", ios::binary | ios::app);

	if (!file.is_open()) {
		cout << "������ ��� ��������. ��������� ���� �� ����������" << endl;
		return;
	}
	else file.write((char*)&pMassive[MASSIVE_SIZE - 1], sizeof(student));

	file.close();
}

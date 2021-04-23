#include<iostream>
#include<fstream>
#include<Windows.h>

#include "userTypes.h"
#include "functions.h"

using namespace std;

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
				settlementOfStudent(pMassive, &conditionOfMassive, &amountOfStudent, minimalSalary);
				break;

			case menu::sharing_of_student:
				sharingOfStudent(pMassive, &conditionOfMassive, &amountOfStudent, minimalSalary);
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
				outputDataFromFile(pMassive, &amountOfStudent, &conditionOfMassive);
				break;

			case menu::close_program:
				if (conditionOfMassive == true) delete[] pMassive;
				exit(0);
		}
	}
}
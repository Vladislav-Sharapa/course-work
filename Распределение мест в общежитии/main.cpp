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

	student* pMassive = NULL; // предусмотреть ввод изначального кол-во студентов для заселения в main 

	unsigned int minimumWage = 0;
	unsigned short int choiseOfAction = 0;

	bool conditionOfMassive = false;

	unsigned int minimalSalary = 0;

	cout << "Введите минимальную заработную плату\nВвод: ";
	cin >> minimalSalary;


	while (running) {
		string nameOfStudent = "";
		cout << "----------------------";
		cout << "\nМеню программы\n" << endl;
		cout << "{1} - Заселение студентов\n" << "{2} - Подселение студентов\n" << "{3} - Удаление информации\n" << "{4} - Редактирование\n";
		cout << "{5} - Сортировка информации\n" << "{6} - Вывод информации\n" << "{7} - Поиск ифнормации\n";
		cout<< "{8} - Записать данные в файл\n"<<"{9} - Записать данные из файла\n" << "{0} - Закрыть программу\n" << endl;
		cout << "Действие: ";
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
					cout << "\nСписок студентов пуст\n";
					break;
				}
				cout << "\nВведите имя студента для удаления\n" << "Имя: ";
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
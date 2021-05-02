#include<iostream>
#include<fstream>

#include "userTypes.h"
#include "functions.h"

using namespace std;

void settlementOfStudent(student*& pMassive, bool* pCondition, int* size, unsigned int minimalSalary) {
	int amountOfStudent = 0;

	if (*pCondition == true) {
		cout << "\nЗаселение уже прошло, возможно только подселение" << endl;
		return;
	}

	cout << "\nСколько студентов вы хотите заселить?\n" << "Количество: ";
	cin >> amountOfStudent;
	*size = amountOfStudent;

	pMassive = new student[*size];  // создаем динамический массив на кол-во элементов, которое укажет пользователь

	for (int i = 0; i < *size; i++) {
		cin.ignore();
		cout << "\nВведите имя студента: ";
		cin.getline(pMassive[i].studentName, 30);

		cout << "Введите номер группы студента: ";
		cin.getline(pMassive[i].groupNumber, 20);

		cout << "Занимался ли студент социальными работами({1 - Да} или {2 - Нет}): ";
		cin >> pMassive[i].socialActivity;

		cout << "Введите средний балл студента: ";
		cin >> pMassive[i].averageScore;

		cout << "Введите доход первого члена семьи: ";
		cin >> pMassive[i].income.firstIncome;
		cout << "Введите доход второго члена семьи: ";
		cin >> pMassive[i].income.secondIncome;
		pMassive[i].income.netIncome = (pMassive[i].income.firstIncome + pMassive[i].income.secondIncome) / 2;
		if (pMassive[i].income.netIncome < minimalSalary) pMassive[i].income.flag = true;
	}

	*pCondition = true;
}
void sharingOfStudent(student*& pMassive, bool* pCondition, int* size, unsigned int minimalSalary) {

	if (*pCondition == false) {
		cout << "\nПодселение невозможно, так как заселение еще не прошло" << endl;
		return;
	}
	else (*size)++;

	student info;
	student* newMassive = new student[*size];

	for (int i = 0; i < *size - 1; i++) newMassive[i] = pMassive[i]; // перезаписываем данные из старого массива в новый

	cin.ignore();
	cout << "\nВведите имя студента: ";
	cin.getline(info.studentName, 30);

	cout << "Введите номер группы студента: ";
	cin.getline(info.groupNumber, 20);

	cout << "Занимался ли студент социальными работами({1 - Да} или {2 - Нет}): ";
	cin >> info.socialActivity;

	cout << "Введите средний балл студента: ";
	cin >> info.averageScore;

	cout << "Введите доход первого члена семьи: ";
	cin >> info.income.firstIncome;
	cout << "Введите доход второго члена семьи: ";
	cin >> info.income.secondIncome;
	info.income.netIncome = (info.income.firstIncome + info.income.secondIncome) / 2;
	if (info.income.netIncome < minimalSalary) info.income.flag = true;

	newMassive[*size - 1] = info;

	delete[] pMassive;  // удаляем старый динамический массив

	pMassive = newMassive;

}
void deleteStudentElement(int& size, student*& pMassive, string nameOfStudent) {

	short int indexOfELement = 0;
	unsigned short int action = 0;

	student* newMassive = new student[size];

	for (int i = 0; i < size; i++) {  // поиск нужного элемента в массиве (возможно добавление дополнительных параметров) 
		indexOfELement++;
		if (nameOfStudent == pMassive[i].studentName) break;
	}

	if (indexOfELement == size and pMassive[indexOfELement - 1].studentName != nameOfStudent) { // проверка последнего элемента массива
		cout << "Студент с заданными параметрами отсутcтвует" << endl;
		return;
	}

	cout << "Вы действительно хотите удалить элемент? (1 - Да, 2 - Нет)\n" << "Решение: ";
	cin >> action;

	switch (action)
	{
	case deleteAction::deletee_element:
		swap(pMassive[indexOfELement - 1], pMassive[size - 1]); // меняем местами последний элемент и элемент, который хотим удалить

		size--; // уменшаем размер массива на одну единицу 

		for (int i = 0; i < size; i++) newMassive[i] = pMassive[i]; //заполняем новый массив

		delete[] pMassive;
		pMassive = newMassive;
		break;

	case deleteAction::leave_element:
		cout << "Элемент оставлен в ячейке массива" << endl;
		delete[] newMassive;
	}

}
void editStudentElement(int size, student*& pMassive) {

	short int choice = 0;
	string nameOfStudent = "";  // переменная для поиска студента в массиве по имени
	int countOfItereations = 0;  // счётчик для кол-во итераций (чтобы вывести сообщение, в случае если студента с таким именем не будет в списке)
	bool running = true;  // для остановки цикла while

	cout << "\nВведите имя студента, данные которого хотите отредактировать" << endl;
	cout << "Имя: ";
	cin >> nameOfStudent;

	for (int i = 0; i < size; i++) {

		countOfItereations++;

		if (nameOfStudent == pMassive[i].studentName) {  // условие для проверки наличия элемента в массиве

			cout << "Студент есть в списке. Выберите параметр для редактирования:" << endl;

			while (running) {

				double income = 0;

				cout << "\n{1} - Имя\n" << "{2} - Номер Группы\n" << "{3} - Занятие социальными работами\n";
				cout << "{4} - Средний балл\n" << "{5} - Доход первого члена семьи\n" << "{6} - Доход второго члена семьи\n" << "{7} - Закончить редактирование" << endl;
				cout << "\nВыбор: ";
				cin >> choice;

				switch (choice)
				{
				case 1:
					cout << "Имя: ";
					cin >> pMassive[i].studentName;
					break;
				case 2:
					cout << "Номер группы: ";
					cin >> pMassive[i].groupNumber;
					break;
				case 3:
					cout << "Занятие социальными работами ({1} - Да, {2} - Нет): ";
					cin >> pMassive[i].socialActivity;
					break;
				case 4:
					cout << "Средний балл: ";
					cin >> pMassive[i].averageScore;
					break;
				case 5:
					cout << "Доход первого члена семьи: ";
					cin >> pMassive[i].income.firstIncome;
					income = (pMassive[i].income.firstIncome + pMassive[i].income.secondIncome) / 2;
					pMassive[i].income.netIncome = income;
					break;
				case 6:
					cout << "Доход второго члена семьи: ";
					cin >> pMassive[i].income.secondIncome;
					income = (pMassive[i].income.firstIncome + pMassive[i].income.secondIncome) / 2;
					pMassive[i].income.netIncome = income;
					break;
				case 7:
					running = false;  // присваиваем false, чтобы закончить бесконечный цикл
				}
			}
			break; // break для выхода из цикла for
		}
		else if (countOfItereations == size) cout << "Такого студента нет в списке" << endl;
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

	cout << "\nСортировка данных завершена";
}
void outputStudentList(student* pMassive, int size, unsigned int minimalSalary) {

	string socialActivity = "";

	if (size == 0) {
		cout << "\nСписок студентов пуст" << endl;
		return;
	}

	for (int i = 0; i < size; i++) {
		if (pMassive[i].socialActivity == 1) socialActivity = "Участвовал";
		else socialActivity = "Не участвовал";

		cout << "\nИмя студента: " << pMassive[i].studentName << endl;
		cout << "Номер группы: " << pMassive[i].groupNumber << endl;
		cout << "Средний балл: " << pMassive[i].averageScore << endl;
		cout << "Участиве в общественной деятельности: " << socialActivity << endl;
		cout << "Доход на члена семьи: " << pMassive[i].income.netIncome << endl;
		cout << "Минимальная заработная плата: " << minimalSalary << endl;
	}
}
void searchStudentInfo(int size, student* pMassive) {

	string name = "";
	string socialActivity = "";
	unsigned short int countOfStudent = 0;

	cout << "\nВведите имя студента" << endl;
	cout << "Имя: ";
	cin >> name;
	cout << "Результат поиска: " << endl;

	if (size == 0) cout << "\nСписок студентов пуст" << endl;

	for (int i = 0; i < size; i++)
	{
		if (name == pMassive[i].studentName) {

			if (pMassive[i].socialActivity == 1) socialActivity = "Участвовал";
			else socialActivity = "Не участвовал";

			cout << "\nИмя студента: " << pMassive[i].studentName << endl;
			cout << "Номер группы: " << pMassive[i].groupNumber << endl;
			cout << "Средний балл: " << pMassive[i].averageScore << endl;
			cout << "Участиве в общественной деятельности: " << socialActivity << endl;
			cout << "Доход на члена семьи: " << pMassive[i].income.netIncome << endl;
			countOfStudent++;
		}
		else if (i == size - 1 and countOfStudent == 0) cout << "Студента(ов) с таким именем нет в списке" << endl;
	}
}
void inputDataInFile(student* pMassive, int size) {
	student info;

	ofstream binaryFile("D:\\C++\\Structers of student\\file.dat", ios::binary);

	if (binaryFile.is_open()) cout << "\nФайл открыт\n";
	else {
		cout << "Ошибка при открыти файла" << endl;
		return;
	}

	for (int i = 0; i < size; i++) {
		info = pMassive[i];
		binaryFile.write((char*)&info, sizeof(info));
	}

	cout << "Запись в файл прошла успешно" << endl;

	binaryFile.close();
}
void outputDataFromFile(student*& pMassive, int* size, bool* conditionalOfMassive) {

	if (*conditionalOfMassive == true) {
		cout << "\nМассив студентов уже заполнен. Запись из файла невозможна" << endl;
		return;
	}
	else *conditionalOfMassive = true;

	ifstream file("D:\\C++\\Structers of student\\file.dat", ios::binary);

	if (file.is_open()) cout << "\nФайл открыт\n";
	else {
		cout << "Ошибка при открыти файла" << endl;
		return;
	}

	*size = 10;
	pMassive = new student[*size];


	for (int i = 0; i < *size; i++) {
		file.read((char*)&pMassive[i], sizeof(student));
	}

	cout << "Чтение из файла прошло успешно" << endl;

	file.close();
}


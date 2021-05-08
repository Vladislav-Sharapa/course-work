#include<iostream>
#include<iomanip>

#include"edit_function.h"
#include"security_function.h"
#include"form_of_menu.h"

using namespace std;

extern short int MASSIVE_SIZE;
extern unsigned int MINIMAL_SALARY;

// функция для вывода
void outputDataInTable(student* pMassive) {

	if (MASSIVE_SIZE == 0) {
		cout << "Список студентов пуст . . ." << endl;
		return;
	}

	string socialActivity = "";

	cout << "+--------------------------------------------------------------------------+" << endl;
	cout << "| Номер | Имя студента | Номер группы | Ср. балл | Доход | Cоц. активность |" << endl;
	cout << "+--------------------------------------------------------------------------+" << endl;

	for (int i = 0; i < MASSIVE_SIZE; i++) {
		if (pMassive[i].socialActivity == 1) socialActivity = "Участвовал";
		else socialActivity = "Не участвовал";

		cout << "|" << setw(7) << i + 1 << "|" << setw(14) << pMassive[i].studentName << "|";
		cout << setw(14) << pMassive[i].groupNumber << "|" << setw(10) << pMassive[i].averageScore << "|";
		cout << setw(7) << pMassive[i].income.netIncome << "|" << setw(17) << socialActivity << "|" << endl;
		cout << "+--------------------------------------------------------------------------+" << endl;
	}
}

// функции добавления студентов в список
student inputInfoAboutStudent() {
	student info;

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
	if (info.income.netIncome < MINIMAL_SALARY) info.income.flag = true;

	return info;
}
// функция добавления
void addStudentInList(student*& pMassive) {  // подселение студентов

	if (MASSIVE_SIZE == 0) {
		cout << "\nЗаселение первого студента" << endl;
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
		cout << "\nВыберите студента . . ." << endl;
		choiseNumberOfStudent = inputNumber(trueFunction);

		if (choiseNumberOfStudent <= 0 or choiseNumberOfStudent > MASSIVE_SIZE) cout << "Студента под таким номером нет в списке. Введите данны повторно . . ." << endl;
		else running = false;
	}


	return (choiseNumberOfStudent - 1);
}

// функции редактирования записи 
void editStudentElement(student*& pMassive, int index) {

	bool running = true;  // для остановки цикла while

	cout << "Выберите параметр для редактирования . . ." << endl;

	while (running) {
		double income = 0;
		short int choice = 0;

		formOfEditMenu();
		cout << "\nВыбор: ";

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Имя: ";
			cin >> pMassive[index].studentName;
			break;
		case 2:
			cout << "Номер группы: ";
			cin >> pMassive[index].groupNumber;
			break;
		case 3:
			cout << "Занятие социальными работами ({1} - Да, {2} - Нет): ";
			cin >> pMassive[index].socialActivity;
			break;
		case 4:
			cout << "Средний балл: ";
			cin >> pMassive[index].averageScore;
			break;
		case 5:
			cout << "Доход первого члена семьи: ";
			cin >> pMassive[index].income.firstIncome;
			income = (pMassive[index].income.firstIncome + pMassive[index].income.secondIncome) / 2;
			pMassive[index].income.netIncome = income;
			break;
		case 6:
			cout << "Доход второго члена семьи: ";
			cin >> pMassive[index].income.secondIncome;
			income = (pMassive[index].income.firstIncome + pMassive[index].income.secondIncome) / 2;
			pMassive[index].income.netIncome = income;
			break;
		case 0:
			running = false;  // присваиваем false, чтобы закончить бесконечный цикл
		}
		system("cls");
	}
}

void deleteStudentElement(student*& pMassive, int indexOfStudent) {

	MASSIVE_SIZE--;
	short int deleteAction = 0;
	student* newMassive = new student[MASSIVE_SIZE];

	cout << "Вы действительно хотите удалить элемент? (1 - Да, 2 - Нет)\n" << "Решение: ";
	cin >> deleteAction;

	switch (deleteAction)
	{
	case confirmationOfTheExecution::confirm:

		for (int i = indexOfStudent; i < MASSIVE_SIZE; i++) swap(pMassive[i], pMassive[i + 1]);
		for (int i = 0; i < MASSIVE_SIZE; i++) newMassive[i] = pMassive[i]; //заполняем новый массив

		delete[] pMassive;
		pMassive = newMassive;
		break;

	case confirmationOfTheExecution::notConfirm:
		cout << "Элемент оставлен в ячейке массива" << endl;
		delete[] newMassive;
	}
}

void inputMinimalSalary() {
	cout << "Минимальная заработная плата: ";
	cin >> MINIMAL_SALARY;
}

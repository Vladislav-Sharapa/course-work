#include<iostream>
#include<iomanip>

#include"edit_function.h"
#include"security_function.h"
#include"form_of_menu.h"

using namespace std;

extern short int MASSIVE_SIZE;
extern unsigned int MINIMAL_SALARY;

// функция для вывода информации в консоль в виде таблицы
void outputDataInTable(student* pMassive) {

	if (MASSIVE_SIZE == 0) {
		cout << "Список студентов пуст . . ." << endl;
		return;
	}

	string socialActivity = "";  // переменная, которая выводит информацию о соц. активности студента 
	/*Если переменная short int socialActivity, хранящаяся в структуре student, будет равна 1, то
	переменной string socialActivity будет присвоена строка "Участвовал", иначе - "Не участвовал".
	Это сделано с целью отображения информации в таблице, которая будет понятна пользователю (вместо 1 или 2)*/

	cout << "+--------------------------------------------------------------------------------+" << endl;
	cout << "| Номер |    Имя студента    | Номер группы | Ср. балл | Доход | Cоц. активность |" << endl;
	cout << "+--------------------------------------------------------------------------------+" << endl;

	for (int i = 0; i < MASSIVE_SIZE; i++) {
		if (pMassive[i].socialActivity == 1) socialActivity = "Участвовал";
		else socialActivity = "Не участвовал";

		cout << "|" << setw(7) << i + 1 << "|" << setw(20) << pMassive[i].studentName << "|";
		cout << setw(14) << pMassive[i].groupNumber << "|" << setw(10) << pMassive[i].averageScore << "|";
		cout << setw(7) << pMassive[i].income.netIncome << "|" << setw(17) << socialActivity << "|" << endl;
		cout << "+--------------------------------------------------------------------------------+" << endl;
	}
}
void outputStudentWithSocialActicity(student* pMassive) {
	
	string socialActivity = "";
	int amountOfStudent = 0;

	for (int i = 0; i < MASSIVE_SIZE; i++) {
		if (pMassive[i].socialActivity == 1) {
			amountOfStudent++;

			if (amountOfStudent == 1) {
				cout << "+------------------------------------------------------------------------+" << endl;
				cout << "|    Имя студента    | Номер группы | Ср. балл | Доход | Cоц. активность |" << endl;
				cout << "+------------------------------------------------------------------------+" << endl;
			}

			if (pMassive[i].socialActivity == 1) socialActivity = "Участвовал";
			else socialActivity = "Не участвовал";

			cout << "|" << setw(20) << pMassive[i].studentName << "|";
			cout << setw(14) << pMassive[i].groupNumber << "|" << setw(10) << pMassive[i].averageScore << "|";
			cout << setw(7) << pMassive[i].income.netIncome << "|" << setw(17) << socialActivity << "|" << endl;
			cout << "+------------------------------------------------------------------------+" << endl;
		}
	}
	if (amountOfStudent == 0) cout << "Таких студентов нет в списке" << endl;
}
void outputStudentWithMinIncome(student* pMassive) {
	string socialActivity = "";
	int amountOfStudent = 0;
	int minimalWage = MINIMAL_SALARY * 2;


	if (MINIMAL_SALARY == 0) {
		cout << "Перед выводом списка введите значение минимальной зарплаты . . ." << endl;
		return;
	}

	for (int i = 0; i < MASSIVE_SIZE; i++) {
		if (pMassive[i].income.netIncome < minimalWage) {
			amountOfStudent++;

			if (amountOfStudent == 1) {
				cout << "+------------------------------------------------------------------------+" << endl;
				cout << "|    Имя студента    | Номер группы | Ср. балл | Доход | Cоц. активность |" << endl;
				cout << "+------------------------------------------------------------------------+" << endl;
			}

			if (pMassive[i].socialActivity == 1) socialActivity = "Участвовал";
			else socialActivity = "Не участвовал";

			cout << "|" << setw(20) << pMassive[i].studentName << "|";
			cout << setw(14) << pMassive[i].groupNumber << "|" << setw(10) << pMassive[i].averageScore << "|";
			cout << setw(7) << pMassive[i].income.netIncome << "|" << setw(17) << socialActivity << "|" << endl;
			cout << "+------------------------------------------------------------------------+" << endl;
		}
	}
	if (amountOfStudent == 0) cout << "Таких студентов нет в списке" << endl;
}
void outputStudentByIndex(int index, student* pMassive)
{
	string socialActivity = "";

	cout << "-------------------------------------------------------------------------+" << endl;
	cout << "|    Имя студента    | Номер группы | Ср. балл | Доход | Cоц. активность |" << endl;
	cout << "+------------------------------------------------------------------------+" << endl;


	if (pMassive[index].socialActivity == 1) socialActivity = "Участвовал";
	else socialActivity = "Не участвовал";

	cout <<  "|" << setw(20) << pMassive[index].studentName << "|";
	cout << setw(14) << pMassive[index].groupNumber << "|" << setw(10) << pMassive[index].averageScore << "|";
	cout << setw(7) << pMassive[index].income.netIncome << "|" << setw(17) << socialActivity << "|" << endl;
	cout << "+------------------------------------------------------------------------+" << endl;
}
// функции для ввода информации о студенте 
student inputInfoAboutStudent() {
	student info;
	int minimalWage = MINIMAL_SALARY * 2;

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
	if (info.income.netIncome < minimalWage) info.income.flag = true;

	return info;
}
// функция добавления студента в массив
void addStudentInList(student*& pMassive) { 
	
	if (MASSIVE_SIZE == 0) {
		cout << "\nЗаселение первого студента" << endl;
		MASSIVE_SIZE++;
		pMassive = new student[MASSIVE_SIZE]; // создание массива

		pMassive[MASSIVE_SIZE - 1] = inputInfoAboutStudent(); // добавления структуры в массив
	}
	else {
		MASSIVE_SIZE++;
		student* newMassive = new student[MASSIVE_SIZE]; // создание нового массива

		for (int i = 0; i < MASSIVE_SIZE - 1; i++) newMassive[i] = pMassive[i]; // перезапись элементов из старого массива в новый

		newMassive[MASSIVE_SIZE - 1] = inputInfoAboutStudent(); // добавление записи в конец массива

		delete[] pMassive; // удаление старого массива
		pMassive = newMassive; // ставим указатель на новый массив
	} 

}
// функция для получения индекса студента по запросу пользователя
int getNumberOfStudent() {

	int choiseNumberOfStudent = 0;
	bool running = true; // переменная для остановки цикла while

	while (running) {
		cout << "\nВыберите студента . . ." << endl;
		choiseNumberOfStudent = inputNumber(trueFunction);  // ввод данных и их проверка

		if (choiseNumberOfStudent <= 0 or choiseNumberOfStudent > MASSIVE_SIZE) cout << "Студента под таким номером нет в списке. Введите данныe повторно . . ." << endl;
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
		short int choice = 0;  // переменная для выбора параметра редактирования 

		formOfEditMenu();  // функция вывода меню редактирования (с возможными вариантами выбора)
		outputStudentByIndex(index, pMassive);
		cout << "\nВыбор: ";

		cin >> choice;

		switch (choice)
		{
		case 1:
			cin.ignore();
			cout << "Имя: ";
			cin.getline(pMassive[index].studentName, 30);
			cout << "Имя студента изменено . . ."<< endl;
			system("pause");
			break;
		case 2:
			cin.ignore();
			cout << "Номер группы: ";
			cin.getline(pMassive[index].groupNumber, 20);
			cout << "Номер группы студента изменен . . ." << endl;
			system("pause");
			break;
		case 3:
			cout << "Занятие социальными работами ({1} - Да, {2} - Нет): ";
			cin >> pMassive[index].socialActivity;
			break;
		case 4:
			cout << "Средний балл: ";
			cin >> pMassive[index].averageScore;
			cout << "Средний бал студента изменен . . ." << endl;
			system("pause");
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

// функция удаления 
void deleteStudentElement(student*& pMassive, int indexOfStudent) {

	MASSIVE_SIZE--;
	short int deleteAction = 0;  // переменная для подтверждения выполнения необратимых действий
	student* newMassive = new student[MASSIVE_SIZE];

	cout << "Вы действительно хотите удалить студента из списка? (1 - Да, 2 - Нет)\n" << "Решение: ";
	cin >> deleteAction;

	switch (deleteAction)
	{
	case confirmationOfTheExecution::confirm: // удаляем элемент

		for (int i = indexOfStudent; i < MASSIVE_SIZE; i++) swap(pMassive[i], pMassive[i + 1]);  // перемаещаем выбранный элемент в конец массива
		for (int i = 0; i < MASSIVE_SIZE; i++) newMassive[i] = pMassive[i]; // перезаписываем все элементы, кроме последнего, из старого массива в новый 

		delete[] pMassive; // удаляем старый массив
		pMassive = newMassive; // ставим указатель на новый массив
		break;

	case confirmationOfTheExecution::notConfirm:  // оставляем элемент в массиве
		cout << "Элемент оставлен в ячейке массива" << endl;
		MASSIVE_SIZE++;
		delete[] newMassive; // удаляем новый массив
	}
}

// функциия для ввода минимальной зарплаты
void inputMinimalSalary(student*& pMassive) {
	
	if (MASSIVE_SIZE == 0) {
		cout<<"Перед тем, как ввести минимальную заработную плату, добавьте студентов в список . . ."<<endl;
		return;
	}
	
	cout << "Минимальная заработная плата: ";
	cin >> MINIMAL_SALARY;

	int minimalWage = MINIMAL_SALARY * 2;

	for (int i = 0; i < MASSIVE_SIZE; i++) {
		if (pMassive[i].income.netIncome < minimalWage) pMassive[i].income.flag = true;
		else pMassive[i].income.flag = false;
	}
}

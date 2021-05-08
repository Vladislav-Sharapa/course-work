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

	cout << "Введите имя студента: ";
	cin.getline(nameOfStudent, 30);

	// цикл для поиска индексов массива
	for (int i = 0; i < MASSIVE_SIZE; i++) {
		short int countOfSameLetters = 0;
		for (int j = 0; j < 4; j++) {
			if (nameOfStudent[j] == pMassive[i].studentName[j]) countOfSameLetters++;
		}
		if (countOfSameLetters == 4) {
			index.push_back(i);
			flag = true;
		}
	}
	cout << "Результат поиска: \n" << endl;
	if (flag == false)  cout << "Таких студентов нет в списке" << endl;
	else {
		cout << "+--------------------------------------------------------------------------+" << endl;
		cout << "| Номер | Имя студента | Номер группы | Ср. былл | Доход | Cоц. активность |" << endl;
		cout << "+--------------------------------------------------------------------------+" << endl;

		for (int i = 0; i < index.size(); i++) {
			string socialActivity = "";

			if (pMassive[index[i]].socialActivity == 1) socialActivity = "Участвовал";
			else socialActivity = "Не участвовал";

			cout << "|" << setw(7) << i + 1 << "|" << setw(14) << pMassive[index[i]].studentName << "|";
			cout << setw(14) << pMassive[index[i]].groupNumber << "|" << setw(10) << pMassive[index[i]].averageScore << "|";
			cout << setw(7) << pMassive[index[i]].income.netIncome << "|" << setw(17) << socialActivity << "|" << endl;
			cout << "+--------------------------------------------------------------------------+" << endl;
		}
	}
}
void searchStudentByGroup(student* pMassive) {

	vector<int>index;
	char groupNumber[30] = { '\0' };
	bool flag = false;

	cout << "Введите номер группы . . ." << endl;
	cout << "Ввод: ";
	cin.getline(groupNumber, 30);

	for (int i = 0; i < MASSIVE_SIZE; i++) {
		if (strcmp(groupNumber, pMassive[i].groupNumber) == 0) {
			index.push_back(i);
			flag = true;
		}
	}

	if (flag == false)  cout << "Таких студентов нет в списке" << endl;
	else {
		cout << "+--------------------------------------------------------------------------+" << endl;
		cout << "| Номер | Имя студента | Номер группы | Ср. былл | Доход | Cоц. активность |" << endl;
		cout << "+--------------------------------------------------------------------------+" << endl;

		for (int i = 0; i < index.size(); i++) {
			string socialActivity = "";

			if (pMassive[index[i]].socialActivity == 1) socialActivity = "Участвовал";
			else socialActivity = "Не участвовал";

			cout << "|" << setw(7) << i + 1 << "|" << setw(14) << pMassive[index[i]].studentName << "|";
			cout << setw(14) << pMassive[index[i]].groupNumber << "|" << setw(10) << pMassive[index[i]].averageScore << "|";
			cout << setw(7) << pMassive[index[i]].income.netIncome << "|" << setw(17) << socialActivity << "|" << endl;
			cout << "+--------------------------------------------------------------------------+" << endl;
		}
	}

}
void searchStudentByAverageScore(student* pMassive) {

	vector<int>index;
	unsigned short int averageMarkOfStudent = 0;
	bool flag = false;

	cout << "Введите средний балл . . ." << endl;

	averageMarkOfStudent = inputNumber(isNumberRangeCorrectForMark); // проверка на правильность вводимых данных

	for (int i = 0; i < MASSIVE_SIZE; i++) {
		if (averageMarkOfStudent == pMassive[i].averageScore) {
			index.push_back(i);
			flag = true;
		}
	}
	if (flag == false)  cout << "Таких студентов нет в списке" << endl;
	else {
		cout << "+--------------------------------------------------------------------------+" << endl;
		cout << "| Номер | Имя студента | Номер группы | Ср. былл | Доход | Cоц. активность |" << endl;
		cout << "+--------------------------------------------------------------------------+" << endl;

		for (int i = 0; i < index.size(); i++) {
			string socialActivity = "";

			if (pMassive[index[i]].socialActivity == 1) socialActivity = "Участвовал";
			else socialActivity = "Не участвовал";

			cout << "|" << setw(7) << i + 1 << "|" << setw(14) << pMassive[index[i]].studentName << "|";
			cout << setw(14) << pMassive[index[i]].groupNumber << "|" << setw(10) << pMassive[index[i]].averageScore << "|";
			cout << setw(7) << pMassive[index[i]].income.netIncome << "|" << setw(17) << socialActivity << "|" << endl;
			cout << "+--------------------------------------------------------------------------+" << endl;
		}
	}
}
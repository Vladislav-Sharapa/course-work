#include<iostream>
#include<fstream>
#include<iomanip>

#include"userTypes.h"

extern short int MASSIVE_SIZE;

using namespace std;

// функции для работы с файлами
int getCountOfStructerInFile() {
	// открываем файл для чтения в бинарном режиме и перемещаем указатель в конец файла (ios::ate)
	ifstream file("D:\\C++\\Structers of student\\file.dat", ios::ate | ios::binary);

	int numberOfStructer = file.tellg() / sizeof(student);  // высчитываем кол-во структур в файле
	return numberOfStructer;
}
// функция получения данных из файла
void getDataFromFile(student*& pMassive) {

	// проверка заполненности масиива
	if (MASSIVE_SIZE > 0) {
		cout << "Чтение невозможно так как список заполнен . . ." << endl;
		return;
	}

	ifstream file("D:\\C++\\Structers of student\\file2.dat", ios::binary); // открытие файла в режиме чтения

	if (file.is_open()) cout << "\nФайл открыт. . .\n";
	else {
		cout << "Ошибка при открыти файла" << endl;
		return;
	}

	MASSIVE_SIZE = getCountOfStructerInFile(); // получаем кол-во структур, хранящихся в файле
	pMassive = new student[MASSIVE_SIZE];

	// считываем структуры из файла в масиив
	for (int i = 0; i < MASSIVE_SIZE; i++) {
		file.read((char*)&pMassive[i], sizeof(student));
	}

	cout << "Чтение из файла прошло успешно. . ." << endl;

	file.close(); // закрываем файл
}
// функция записи данных в файл
void recordDatainFile(student* pMassive) {
	
	// проверка заполненности массива
	if (MASSIVE_SIZE == 0) {
		cout << "Запись невозможна, так как список пуст . . ." << endl;
		return;
	}

	ofstream file("D:\\C++\\Structers of student\\file2.dat", ios::binary | ios::out); // открытие бинарного файла в режиме записи

	if (!file.is_open()) {
		cout << "Ошибка при открытии. Указанный файл не существует" << endl;
		return;
	}
	else {
		for (int i = 0; i < MASSIVE_SIZE; i++) file.write((char*)&pMassive[i], sizeof(student)); // запись данных в файл
		cout << "Запись данных в файл прошла успешно . . ." << endl;
	}

	file.close(); // закрытике файла

}

void inputInTextFile(student* pMassive) {

	ofstream file;

	// обработка исключительных ситуаций
	try {
		file.open(("D:\\C++\\Structers of student\\student.txt")); // открытие файла 

	}
	catch(const std::exception& ex){
		cout << "Ошибка при открытии файла . . ." << endl;
		return;
	}

	string socialActivity = "";
	
	// запись данных в файл
	file << "+----------------------------------------------------------------------------------+\n";
	file << "| Номер |    Имя студента    | Номер группы | Ср. балл | Доход | Cоц. деятельность |\n";
	file << "+----------------------------------------------------------------------------------+\n";

	for (int i = 0; i < MASSIVE_SIZE; i++) {
		if (pMassive[i].socialActivity == 1) socialActivity = "Участвовал";
		else socialActivity = "Не участвовал";

		file << "|" << setw(7) << i + 1 << "|" << setw(20) << pMassive[i].studentName << "|";
		file << setw(14) << pMassive[i].groupNumber << "|" << setw(10) << pMassive[i].averageScore << "|";
		file<< setw(7) << pMassive[i].income.netIncome << "|" << setw(19) << socialActivity << "|\n";
		file <<	"+----------------------------------------------------------------------------------+" << endl;
	}

	file.close();
}
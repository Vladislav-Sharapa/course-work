#include<iostream>
#include<fstream>

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
void getDataFromFile(student*& pMassive) {

	if (MASSIVE_SIZE > 0) {
		cout << "Чтение невозможно так как список заполнен . . ." << endl;
		return;
	}

	ifstream file("D:\\C++\\Structers of student\\file2.dat", ios::binary);

	if (file.is_open()) cout << "\nФайл открыт. . .\n";
	else {
		cout << "Ошибка при открыти файла" << endl;
		return;
	}

	MASSIVE_SIZE = getCountOfStructerInFile();
	pMassive = new student[MASSIVE_SIZE];


	for (int i = 0; i < MASSIVE_SIZE; i++) {
		file.read((char*)&pMassive[i], sizeof(student));
	}

	cout << "Чтение из файла прошло успешно. . ." << endl;

	file.close();
}
void recordDatainFile(student* pMassive) {

	if (MASSIVE_SIZE == 0) {
		cout << "Запись невозможна, так как список пуст . . ." << endl;
		return;
	}

	ofstream file("D:\\C++\\Structers of student\\file2.dat", ios::binary | ios::out);

	if (!file.is_open()) {
		cout << "Ошибка при открытии. Указанный файл не существует" << endl;
		return;
	}
	else {
		for (int i = 0; i < MASSIVE_SIZE; i++) file.write((char*)&pMassive[i], sizeof(student));
		cout << "Запись данных в файл прошла успешно . . ." << endl;
	}

	file.close();

}
void recordDataInEndOfFile(student* pMassive) {

	ofstream file("D:\\C++\\Structers of student\\file.dat", ios::binary | ios::app);

	if (!file.is_open()) {
		cout << "Ошибка при открытии. Указанный файл не существует" << endl;
		return;
	}
	else file.write((char*)&pMassive[MASSIVE_SIZE - 1], sizeof(student));

	file.close();
}

#include<iostream>
#include<fstream>
#include<Windows.h>

using namespace std;

struct student {
	char studentName[30] = {'\0'};
	short int socialActivity = 0;
	char groupNumber[20] = {'\0'};
	double averageScore = 0;

	struct familyIncome {
		unsigned int firstIncome = 0;
		unsigned int secondIncome = 0;
		unsigned int netIncome = 0;
		bool flag = false;
	}income;
		
};

enum menu { setllement_of_students = 1, sharing_of_student, pop_element, edit_element, sort_element, output_element, search_info, input_data_in_file, output_data_from_file, close_program = 0};
enum deleteAction {deletee_element = 1, leave_element};  // подумать над названием 


void inputStudentList(bool * , int &, student *&, short int, unsigned int); //добавление данных в массив (сделано)

void settlementOfStudent(student*& pMassive, bool* , int&, unsigned int);

void sharingOfStudent(student*& pMassive, bool*, int&, unsigned int);

void deleteStudentElement(int& , student*&, string); // удаление элементов массива (сделано)

void editStudentElement(int, student*&); // редактирование элементов массива (сделано)

void sortStudentList(int, student*&, unsigned int); //сортировка массива данных

void outputStudentList(student *, int, unsigned int); //просмотр списка (сделана)

void searchStudentInfo(int, student *); // поиск информации о студенте (сделано)

void inputDataInFile(student*, int);

void outputDataFromFile(student *&, int&, bool *);

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
				settlementOfStudent(pMassive, &conditionOfMassive, amountOfStudent, minimalSalary);
				break;

			case menu::sharing_of_student:
				sharingOfStudent(pMassive, &conditionOfMassive, amountOfStudent, minimalSalary);
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
				outputDataFromFile(pMassive, amountOfStudent, &conditionOfMassive);
				break;

			case menu::close_program:
				if (conditionOfMassive == true) delete[] pMassive;
				exit(0);
		}
	}
}

void settlementOfStudent(student*& pMassive, bool* pCondition, int& size, unsigned int minimalSalary) {
	int amountOfStudent = 0;

	if (*pCondition == true) {
		cout << "\nЗаселение уже прошло, возможно только подселение" << endl;
		return;
	}

	cout << "\nСколько студентов вы хотите заселить?\n" << "Количество: ";
	cin >> amountOfStudent;
	size = amountOfStudent;

	pMassive = new student[size];  // создаем динамический массив на кол-во элементов, которое укажет пользователь

	for (int i = 0; i < size; i++) {
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
void sharingOfStudent(student*& pMassive, bool* pCondition, int& size, unsigned int minimalSalary) {

	if (*pCondition == false) {
		cout << "\nПодселение невозможно, так как заселение еще не прошло" << endl;
		return;
	}

	size++;
	student info;
	student* newMassive = new student[size];

	for (int i = 0; i < size - 1; i++) newMassive[i] = pMassive[i]; // перезаписываем данные из старого массива в новый

	cin.ignore();
	cout << "Введите имя студента: ";
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

	newMassive[size - 1] = info;

	delete[] pMassive;

	pMassive = newMassive;

}
void deleteStudentElement(int& size, student*& pMassive, string nameOfStudent) {

	short int index = 0;
	unsigned short int action = 0;

	student* newMassive = new student[size]; 
	
	for (int i = 0; i < size; i++) {  // поиск нужного элемента в массиве (возможно добавление дополнительных параметров) 
		index++;
		if (nameOfStudent == pMassive[i].studentName) break;
	}

	if (index == size and pMassive[index - 1].studentName != nameOfStudent) { // проверка последнего элемента массива
		cout << "Студент с заданными параметрами отсутcтвует" << endl;
		return;
	}

	cout << "Вы действительно хотите удалить элемент? (1 - Да, 2 - Нет)\n" << "Решение: ";
	cin >> action;

	switch (action)
	{
	case deleteAction::deletee_element:
		swap(pMassive[index - 1], pMassive[size - 1]); // меняем местами последний элемент и элемент, который хотим удалить

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
void editStudentElement(int size, student *&pMassive) {

	short int choice = 0;
	string name = "";
	int count = 0;  // счётчик для кол-во итераций (чтобы вывести сообщение, в случае если студента с таким именем не будет в списке)
	bool running = true;  // для остановки цикла while

	cout << "\nВведите имя студента, данные которого хотите отредактировать" << endl;
	cout << "Имя: ";
	cin >> name;

	for (int i = 0; i < size; i++) {

		count++;

		if (name == pMassive[i].studentName) {  // условие для проверки наличия элемента в массиве

			cout << "Студент есть в списке. Выберите параметр для редактирования:" << endl;

			while (running) {

				int income = 0;

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
					cout << "Занятие социальными работами (Да или Нет): ";
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
		else if (count == size) cout << "Такого студента нет в списке" << endl;
	}
}
void sortStudentList(int size, student *&pMassive, unsigned int minimalSalary) {

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

	cout << "\nСортировка данных завершена" << endl;
}
void outputStudentList(student * pMassive, int size, unsigned int minimalSalary){

	if (size == 0) cout << "\nСписок студентов пуст" << endl;

	if (pMassive == NULL) {
		cout << "\nЗаселение студентов еще не прошло" << endl;
		return;
	}

	for (int i = 0; i < size; i++) {

		cout << "\nИмя студента: " << pMassive[i].studentName << endl;
		cout << "Номер группы: " << pMassive[i].groupNumber << endl;
		cout << "Средний балл: " << pMassive[i].averageScore << endl;
		cout << "Участиве в общественной деятельности: " << pMassive[i].socialActivity << endl;
		cout << "Доход на члена семьи: " << pMassive[i].income.netIncome << endl;
		cout << "Минимальная заработная плата: " << minimalSalary << "\n" << endl;
	}
}
void searchStudentInfo(int size, student *pMassive) {

	string name = "";

	cout << "\nВведите имя студента" << endl;
	cout << "Имя: ";
	cin >> name;
	cout << "Результат поиска: " << endl;

	if (size == 0) cout << "\nСписок студентов пуст" << endl;

	for (int i = 0; i < size; i++)
	{
		if (name == pMassive[i].studentName) {
			cout << "\nИмя студента: " << pMassive[i].studentName << endl;
			cout << "Номер группы: " << pMassive[i].groupNumber << endl;
			cout << "Средний балл: " << pMassive[i].averageScore << endl;
			cout << "Участиве в общественной деятельности: " << pMassive[i].socialActivity << endl;
			cout << "Доход на члена семьи: " << pMassive[i].income.netIncome << "\n" << endl;
		}
		else if (i == size - 1) cout << "Студента(ов) с таким именем нет в списке" << endl;
	}
} 
void inputDataInFile(student *pMassive, int size){
	student info;

	const char* PATH = "D:\\C++\\Structers of student\\file.dat";

	ofstream binaryFile(PATH, ios::binary);

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
void outputDataFromFile(student *&pMassive, int &size, bool *conditionalOfMassive) {

	const char* PATH = "D:\\C++\\Structers of student\\file.dat";

	if (*conditionalOfMassive == true) {
		cout << "\nМассив студентов уже заполнен. Запись из файла невозможна" << endl;
		return;
	}
	else *conditionalOfMassive = true;

	ifstream file(PATH, ios::binary);

	if (file.is_open()) cout << "\nФайл открыт\n";
	else {
		cout << "Ошибка при открыти файла" << endl;
		return;
	}

	size = 10;
	pMassive = new student[size];
	

	for (int i = 0; i < size; i++) {
		file.read((char*)&pMassive[i], sizeof(student));
	}

	cout << "Чтение из файла прошло успешно" << endl;

	file.close();

}
#pragma once
#include<iostream>
#include<fstream>

using namespace std;

struct student {
	char studentName[30] = { '\0' };
	short int socialActivity = 0;
	char groupNumber[20] = { '\0' };
	double averageScore = 0;

	struct familyIncome {
		unsigned int firstIncome = 0;
		unsigned int secondIncome = 0;
		unsigned int netIncome = 0;
		bool flag = false;
	}income;

};

enum menu { setllement_of_students = 1, sharing_of_student, pop_element, edit_element, sort_element, output_element, search_info, input_data_in_file, output_data_from_file, close_program = 0 };
enum deleteAction { deletee_element = 1, leave_element };  // подумать над названием 

void inputStudentList(bool*, int&, student*&, short int, unsigned int); //добавление данных в массив (сделано)

void settlementOfStudent(student*& pMassive, bool*, int&, unsigned int);

void sharingOfStudent(student*& pMassive, bool*, int&, unsigned int);

void deleteStudentElement(int&, student*&, string); // удаление элементов массива (сделано)

void editStudentElement(int, student*&); // редактирование элементов массива (сделано)

void sortStudentList(int, student*&, unsigned int); //сортировка массива данных

void outputStudentList(student*, int, unsigned int); //просмотр списка (сделана)

void searchStudentInfo(int, student*); // поиск информации о студенте (сделано)

void inputDataInFile(student*, int);

void outputDataFromFile(student*&, int&, bool*);


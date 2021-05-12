#include<iostream>
#include<fstream>
#include<iomanip>

#include "userTypes.h"
#include "form_of_menu.h"
#include"security_function.h"
#include"menu.h"

using namespace std;

short int MASSIVE_SIZE = 0;  // начальный размер массив
unsigned int MINIMAL_SALARY = 0; // начальное значение минимальной зарплаты
int main() {
	
	setlocale(0, "");

	student* pMassive = NULL;  // указатель на динамический массив
	bool running = true;

	while (running) {

		short int modeSelection = 0, choiceEditMode = 0, choiceProcessingMode = 0, choiceSearchMode = 0, choiceSortMode = 0;
		system("cls");

		formOfMainMenu();  // вывод таблицы главного меню (с возможными вариантами выбора)
		modeSelection = inputNumber(isNumberRangeCorrectForMenu);  // функция ввода для проверки правильности вводимых данных
		
		system("cls");

		switch (modeSelection) 
		{
			case modeOfProgram::edit_mode:
				editMenu(choiceEditMode, pMassive);  // вызов режима редактирования
				break;
			case modeOfProgram::processing_mode:
				processingMenu(choiceProcessingMode, choiceSearchMode, choiceSortMode, pMassive); // вызоз режима обработки данных
				break;
			case modeOfProgram::close_program:
				delete[]pMassive;  
				running = false; // изменяем running для выхода из бесконечного цикла
		}
	}
}

#include<iostream>

#include"userTypes.h"
#include"form_of_menu.h"
#include"security_function.h"
#include"edit_function.h"
#include"file_function.h"
#include"sort_function.h"
#include"search_function.h"


extern short int MASSIVE_SIZE;
extern unsigned int MINIMAL_SALARY;

using namespace std;

void searchMenu(short int choice, student*& pMassive) {
	bool running = true;

	if (MASSIVE_SIZE <= 0) {
		cout << "ѕоиск невозможен, так как список студентов пуст . . ." << endl;
		system("pause");
		return;
	}

	while (running) {
		formOfSearchMenu(); // вывод меню поиска

		choice = inputNumber(isNumberRangeCorrectForProccesingMenu);
		system("cls");

		switch (choice)
		{
		case modeOfSerching::search_by_name:
			searchStudentByName(pMassive);
			system("pause");
			break;
		case modeOfSerching::search_by_group:
			searchStudentByGroup(pMassive);
			system("pause");
			break;
		case modeOfSerching::search_by_average_number:
			searchStudentByAverageScore(pMassive);
			system("pause");
			break;
		case modeOfSerching::close_search_menu:
			return;
		}
		system("cls");
	}
}
void sortMenu(short int choice, student*& pMassive) {
	bool running = true;

	if (MASSIVE_SIZE <= 0) {
		cout << "—ортировка невозможна, так как список студентов пуст . . ." << endl;
		system("pause");
		return;
	}

	while (running) {

		formOfSortingMenu(); // вывод меню сортировки

		choice = inputNumber(isNumberRangeCorrectForProccesingMenu);
		system("cls");

		switch (choice)
		{
		case modeOfSorting::sort_by_name:
			sortStudentListByStudentName(pMassive);
			outputDataInTable(pMassive);
			system("pause");
			break;
		case modeOfSorting::sort_by_average_mark:
			sortStudentListByAverageMark(pMassive);
			outputDataInTable(pMassive);
			system("pause");
			break;
		case modeOfSorting::sort_by_income:
			sortStudentListByIncome(pMassive);
			outputDataInTable(pMassive);
			system("pause");
			break;
		case modeOfSorting::close_sort_menu:
			running = false;
		}
		system("cls");
	}
}
void individualTaskMenu(short int choice, student*& pMassive) {

	formOfMenuOfSettelment();

	choice = inputNumber(isNumberRangeCorrectForMenu);

	system("cls");

	switch (choice)
	{
	case modeOfIndividualTask::output_student_by_priority:
		if (MINIMAL_SALARY <= 0) {
			cout << "ѕеред тем, как вывести список, введите значение минимальной зарплаты . . .\n" << endl;
			break;
		}
		sortStudentListByPriority(pMassive);
		outputDataInTable(pMassive);
		break;
	case modeOfIndividualTask::input_minimal_salary:
		inputMinimalSalary();
		break;
	case modeOfIndividualTask::close_individual_task_menu:
		return;
	}
	system("pause");
	system("cls");
}

void editMenu(short int choice, student*& pMassive) {

	int index = 0;

	formOfEditMode();

	choice = inputNumber(isNumberRangeCorrectForEditMenu);

	system("cls");

	switch (choice)
	{
	case modeOfEditing::output_data:
		outputDataInTable(pMassive);
		break;
	case modeOfEditing::add_student_info:
		addStudentInList(pMassive);
		break;
	case modeOfEditing::delete_student_structer:
		outputDataInTable(pMassive);
		if (MASSIVE_SIZE == 0) break;
		index = getNumberOfStudent();
		deleteStudentElement(pMassive, index);
		break;
	case modeOfEditing::edit_student_info:
		outputDataInTable(pMassive);
		if (MASSIVE_SIZE == 0) break;
		index = getNumberOfStudent();
		system("cls");
		editStudentElement(pMassive, index);
		break;
	case modeOfEditing::get_data_from_file:
		getDataFromFile(pMassive);
		break;
	case modeOfEditing::record_data_in_file:
		recordDatainFile(pMassive);
		break;
	case modeOfEditing::close_editing_menu:
		system("cls");
		return;
	}
	system("pause");
	system("cls");
}
void processingMenu(short int choiceProcessingMode, short int choiceSearchMode, short int choiceSortMode, student*& pMassive) {

	short int choiseModeOfIndTask = 0;

	formOfProcessingMenu(); // вывод меню обработки

	choiceProcessingMode = inputNumber(isNumberRangeCorrectForProccesingMenu);

	system("cls");

	switch (choiceProcessingMode)
	{
	case modeOfProcessing::search_student_info:
		searchMenu(choiceSearchMode, pMassive);
		break;
	case modeOfProcessing::sort_menu:
		sortMenu(choiceSortMode, pMassive);
		break;
	case modeOfProcessing::individual_task:
		individualTaskMenu(choiseModeOfIndTask, pMassive);
		break;
	case modeOfProcessing::close_processing_mode:
		return;
	}
}


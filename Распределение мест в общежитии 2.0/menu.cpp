#include<iostream>
#include<iomanip>

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


// меню просмотра 
void outputMenu(student* pMassive) {
	short int choise = 0;
	int amount = 0;
	bool running = true;

	if (MASSIVE_SIZE <= 0) {
		cout << "Просмотр невозможен, так как список студентов пуст . . ." << endl;
		return;
	}

	while (running) {
		formOfOutputMenu();

		choise = inputNumber(isNumberRangeCorrectForProccesingMenu);
		system("cls");

		switch (choise)
		{
		case modeOfOutputMenu::output_all_elements:
			outputDataInTable(pMassive);
			system("pause");
			break;
		case modeOfOutputMenu::output_social_activity_student:
			outputStudentWithSocialActicity(pMassive);
			system("pause");
			break;
		case modeOfOutputMenu::output_student_with_min_income:
			outputStudentWithMinIncome(pMassive);
			system("pause");
			break;
		case modeOfOutputMenu::close_output_menu:
			return;
		}
		system("cls");
	}
	
}


// Меню поиска
void searchMenu(short int choice, student*& pMassive) {
	bool running = true;

	if (MASSIVE_SIZE <= 0) {
		cout << "Поиск невозможен, так как список студентов пуст . . ." << endl;
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
// Меню сортировки
void sortMenu(short int choice, student*& pMassive) {
	bool running = true;

	if (MASSIVE_SIZE <= 0) {
		cout << "Сортировка невозможна, так как список студентов пуст . . ." << endl;
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
// Меню распределения мест в общежитии 
void individualTaskMenu(short int choice, student*& pMassive) {

	bool running = true;

	while (running) {
		formOfMenuOfSettelment();

		choice = inputNumber(isNumberRangeCorrectForMenu);
		system("cls");

		switch (choice)
		{
		case modeOfIndividualTask::output_student_by_priority:
			if (MINIMAL_SALARY <= 0) {
				cout << "Перед тем, как вывести список, введите значение минимальной зарплаты . . .\n" << endl;
				system("pause");
				break;
			}

			sortStudentListByPriority(pMassive);
			outputDataInTable(pMassive);
			cout << "\n-----------------------+" << endl;
			cout << "| Минимальная зарплата |" << endl;
			cout << "+----------------------" << endl;
			cout << "|" << setw(12) << MINIMAL_SALARY << setw(11) << "|" << endl;
			cout << "+----------------------+\n" << endl;
			system("pause");
			break;
		case modeOfIndividualTask::input_minimal_salary:
			inputMinimalSalary(pMassive);
			system("pause");
			break;
		case modeOfIndividualTask::close_individual_task_menu:
			return;
		}
		system("cls");
	}
}

// Режим редактирования
void editMenu(short int choice, student*& pMassive) {

	int index = 0;

	formOfEditMode();

	choice = inputNumber(isNumberRangeCorrectForEditMenu);

	system("cls");

	switch (choice)
	{
	case modeOfEditing::output_data:
		outputMenu(pMassive);
		break;
	case modeOfEditing::add_student_info:
		addStudentInList(pMassive);
		system("pause");
		break;
	case modeOfEditing::delete_student_structer:
		outputDataInTable(pMassive);
		if (MASSIVE_SIZE == 0) break;
		index = getNumberOfStudent();
		deleteStudentElement(pMassive, index);
		system("pause");
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
		system("pause");
		break;
	case modeOfEditing::record_data_in_file:
		recordDatainFile(pMassive);
		system("pause");
		break;
	case modeOfEditing::close_editing_menu:
		system("cls");
		return;
	}
	system("cls");
}
// Режим обработки
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


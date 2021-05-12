#include<iostream>
#include<fstream>
#include<iomanip>

#include "userTypes.h"
#include "form_of_menu.h"
#include"security_function.h"
#include"menu.h"

using namespace std;

short int MASSIVE_SIZE = 0;  // ��������� ������ ������
unsigned int MINIMAL_SALARY = 0; // ��������� �������� ����������� ��������
int main() {
	
	setlocale(0, "");

	student* pMassive = NULL;  // ��������� �� ������������ ������
	bool running = true;

	while (running) {

		short int modeSelection = 0, choiceEditMode = 0, choiceProcessingMode = 0, choiceSearchMode = 0, choiceSortMode = 0;
		system("cls");

		formOfMainMenu();  // ����� ������� �������� ���� (� ���������� ���������� ������)
		modeSelection = inputNumber(isNumberRangeCorrectForMenu);  // ������� ����� ��� �������� ������������ �������� ������
		
		system("cls");

		switch (modeSelection) 
		{
			case modeOfProgram::edit_mode:
				editMenu(choiceEditMode, pMassive);  // ����� ������ ��������������
				break;
			case modeOfProgram::processing_mode:
				processingMenu(choiceProcessingMode, choiceSearchMode, choiceSortMode, pMassive); // ����� ������ ��������� ������
				break;
			case modeOfProgram::close_program:
				delete[]pMassive;  
				running = false; // �������� running ��� ������ �� ������������ �����
		}
	}
}

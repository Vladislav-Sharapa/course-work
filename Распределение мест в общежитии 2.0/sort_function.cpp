#include<iostream>
#include"userTypes.h"
#include"sort_function.h"

using namespace std;

extern short int MASSIVE_SIZE;

// сортировка списка по алфавиту
void sortStudentListByStudentName(student*& pMassive) {
	for (int i = 0; i < MASSIVE_SIZE; i++)
	{
		for (int j = 0; j < MASSIVE_SIZE - i - 1; j++)
		{
			if (strcmp(pMassive[j].studentName, pMassive[j + 1].studentName) > 0) swap(pMassive[j], pMassive[j + 1]);
		}
	}
}
// сортировка списка по доходу
void sortStudentListByIncome(student*& pMassive) {

	for (int i = 0; i < MASSIVE_SIZE; i++) {
		for (int j = 0; j < MASSIVE_SIZE - i - 1; j++) {

			if (pMassive[j].income.netIncome < pMassive[j + 1].income.netIncome) swap(pMassive[j], pMassive[j + 1]);
		}
	}
}
// сортировка списка по среднему баллу
void sortStudentListByAverageMark(student*& pMassive) {

	for (int i = 0; i < MASSIVE_SIZE; i++) {
		for (int j = 0; j < MASSIVE_SIZE - i - 1; j++) {

			if (pMassive[j].averageScore < pMassive[j + 1].averageScore) swap(pMassive[j], pMassive[j + 1]);
			else if (pMassive[j].averageScore == pMassive[j + 1].averageScore) {
				if (pMassive[j].socialActivity == 2 and pMassive[j + 1].socialActivity == 1) swap(pMassive[j], pMassive[j + 1]);
			}
		}
	}
}
// сортировка списка по приоритету получения мест в общежитии
void sortStudentListByPriority(student*& pMassive) {

	for (int i = 0; i < MASSIVE_SIZE; i++) {
		for (int j = 0; j < MASSIVE_SIZE - i - 1; j++) {

			if (pMassive[j].averageScore < pMassive[j + 1].averageScore) swap(pMassive[j], pMassive[j + 1]);
			else if (pMassive[j].averageScore == pMassive[j + 1].averageScore) {
				if (pMassive[j].socialActivity == 2 and pMassive[j + 1].socialActivity == 1) swap(pMassive[j], pMassive[j + 1]);
			}
		}
	}

	for (int i = 0; i < MASSIVE_SIZE; i++) {
		for (int j = 0; j < MASSIVE_SIZE - i - 1; j++) {

			if (pMassive[j].income.flag == false and pMassive[j + 1].income.flag == true) swap(pMassive[j], pMassive[j + 1]);	
			if (pMassive[j].income.flag == true and pMassive[j + 1].income.flag == true) {
				if (pMassive[j].income.netIncome > pMassive[j + 1].income.netIncome) swap(pMassive[j], pMassive[j + 1]);
			}
		}
	}
}
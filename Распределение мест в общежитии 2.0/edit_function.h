#pragma once

#include"userTypes.h"

// вывод данных в виде таблицы
void outputDataInTable(student*);
void outputStudentWithSocialActicity(student*);
void outputStudentWithMinIncome(student*);
void outputStudentByIndex(int, student*);
// добавление элемента в массив
student inputInfoAboutStudent();
void addStudentInList(student*&);
// функция для получения индекса структуры, которая находится в массиве
int getNumberOfStudent();
// функции редактирования
void editStudentElement(student*&, int);
// функция удаления
void deleteStudentElement(student*&, int);
//функция ввода минимальной зарплаты
void inputMinimalSalary(student *&);
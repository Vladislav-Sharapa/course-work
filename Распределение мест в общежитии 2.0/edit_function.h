#pragma once

#include"userTypes.h"

// вывод данных в виде таблицы
void outputDataInTable(student*);

// добавление элемента в массив
student inputInfoAboutStudent();
void addStudentInList(student*&);

// функция для нахождения студента по имени
int findIndexOfStudentByName(student*);
int getNumberOfStudent();

// функции редактирования
void editStudentElement(student*&, int);

// функция удаления
void deleteStudentElement(student*&, int);

void inputMinimalSalary();
#pragma once

#include"userTypes.h"

// ����� ������ � ���� �������
void outputDataInTable(student*);

// ���������� �������� � ������
student inputInfoAboutStudent();
void addStudentInList(student*&);

// ������� ��� ���������� �������� �� �����
int findIndexOfStudentByName(student*);
int getNumberOfStudent();

// ������� ��������������
void editStudentElement(student*&, int);

// ������� ��������
void deleteStudentElement(student*&, int);

void inputMinimalSalary();
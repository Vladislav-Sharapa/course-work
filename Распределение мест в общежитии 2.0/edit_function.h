#pragma once

#include"userTypes.h"

// ����� ������ � ���� �������
void outputDataInTable(student*);
void outputStudentWithSocialActicity(student*);
void outputStudentWithMinIncome(student*);

// ���������� �������� � ������
student inputInfoAboutStudent();
void addStudentInList(student*&);

// ������� ��� ��������� ������� ���������, ������� ��������� � �������
int getNumberOfStudent();

// ������� ��������������
void editStudentElement(student*&, int);

// ������� ��������
void deleteStudentElement(student*&, int);

//������� ����� ����������� ��������
void inputMinimalSalary(student *&);
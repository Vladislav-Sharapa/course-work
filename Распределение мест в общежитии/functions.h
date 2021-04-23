#pragma once
#include<iostream>

#include "userTypes.h"


using namespace std;

void inputStudentList(bool*, int&, student*&, short int, unsigned int); //���������� ������ � ������ (�������)

void settlementOfStudent(student*& pMassive, bool*, int*, unsigned int);

void sharingOfStudent(student*& pMassive, bool*, int*, unsigned int);

void deleteStudentElement(int&, student*&, string); // �������� ��������� ������� (�������)

void editStudentElement(int, student*&); // �������������� ��������� ������� (�������)

void sortStudentList(int, student*&, unsigned int); //���������� ������� ������

void outputStudentList(student*, int, unsigned int); //�������� ������ (�������)

void searchStudentInfo(int, student*); // ����� ���������� � �������� (�������)

void inputDataInFile(student*, int);  // ������ � ���� 

void outputDataFromFile(student*&, int*, bool*); // ������ �����


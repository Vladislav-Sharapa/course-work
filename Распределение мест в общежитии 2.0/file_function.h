#pragma once
#include"userTypes.h"

// ������� ��� ������ � ������� 
void getDataFromFile(student*&);
// �������� ���-�� ���� ��������, ���������� � �����
int getCountOfStructerInFile();
// ������ ���� �������� � ����
void recordDatainFile(student*);
// ������ ��������� � ����� �����
void recordDataInEndOfFile(student*);
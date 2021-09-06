#include<iostream>
#include"security_function.h"

using namespace std;

int inputNumber(bool(*pFuction)(int))
{
	int number;
	cout << "����: ";
	while (true)
	{
		cin >> number;

		if (isNumberNumeric() && pFuction(number)) return number;
		else cout << "������������ ����! ��������� �������: ";
	}
}
bool isNumberNumeric()
{
	// ���������� ��������� ������ �� ������. ���� ��� ������� ���� �������,
	// �� ��������� ������ ������ ����� ������� �� ����� ������
	if (cin.get() == '\n') 
		return true;
	else
	{
		// ����������� ����� ������
		cin.clear();
		// ������� �����
		cin.ignore(256, '\n');
		return false;
	}
}
bool isNumberRangeCorrectForMenu(int number) {
	if (number < 0 or number > 2) return false;
	else return true;
}
bool isNumberRangeCorrectForEditMenu(int number) {
	if (number < 0 or number > 6) return false;
	else return true;
}
bool isNumberRangeCorrectForProccesingMenu(int number) {
	if (number < 0 or number > 3) return false;
	else return true;
}
bool isNumberRangeCorrectForMark(int number) {
	if (number < 0 or number > 10) return false;
	else return true;
}
bool trueFunction(int number) {
	return true;
}
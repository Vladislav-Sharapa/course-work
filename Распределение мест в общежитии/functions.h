#pragma once
#include<iostream>

#include "userTypes.h"


using namespace std;

void inputStudentList(bool*, int&, student*&, short int, unsigned int); //добавление данных в массив (сделано)

void settlementOfStudent(student*& pMassive, bool*, int*, unsigned int);

void sharingOfStudent(student*& pMassive, bool*, int*, unsigned int);

void deleteStudentElement(int&, student*&, string); // удаление элементов массива (сделано)

void editStudentElement(int, student*&); // редактирование элементов массива (сделано)

void sortStudentList(int, student*&, unsigned int); //сортировка массива данных

void outputStudentList(student*, int, unsigned int); //просмотр списка (сделана)

void searchStudentInfo(int, student*); // поиск информации о студенте (сделано)

void inputDataInFile(student*, int);  // запись в файл 

void outputDataFromFile(student*&, int*, bool*); // чтение файла


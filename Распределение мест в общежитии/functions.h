#pragma once
#include<iostream>

#include "userTypes.h"


using namespace std;

void settlementOfStudent(student*& pMassive, bool*, int*, unsigned int); // добавление элементов через цикл (заселение)

void sharingOfStudent(student*& pMassive, bool*, int*, unsigned int); // добавление элементов по одному (подселение)

void deleteStudentElement(int&, student*&, string); // удаление элементов массива (сделано)

void editStudentElement(int, student*&); // редактирование элементов массива (сделано)

void sortStudentList(int, student*&, unsigned int); //сортировка массива данных

void outputStudentList(student*, int, unsigned int); //просмотр списка (сделана)

void searchStudentInfo(int, student*); // поиск информации о студенте (сделано)

void inputDataInFile(student*, int);  // запись в файл 

void outputDataFromFile(student*&, int*, bool*); // чтение из файла
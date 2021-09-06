#pragma once
#include"userTypes.h"

// функции для работы с файлами 
void getDataFromFile(student*&);
// получить кол-во всех структур, хранящихся в файле
int getCountOfStructerInFile();
// запись всех структур в файл
void recordDatainFile(student*);

void inputInTextFile(student*);

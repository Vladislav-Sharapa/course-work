#pragma once
#include"userTypes.h"

// функции для работы с файлами 
void getDataFromFile(student*&);
// получить кол-во всех структур, хранящихся в файле
int getCountOfStructerInFile();
// запись всех структур в файл
void recordDatainFile(student*);
// запись структуры в конец файла
void recordDataInEndOfFile(student*);
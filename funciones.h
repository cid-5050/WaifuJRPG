#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "mini/ini.h"
#include <iostream>
#include <iomanip>
#include <vector>

template<typename T> void prettyPrint(T t, int width, char separator);

void prettyPrintFila(std::vector<std::string> contenidos, std::vector<int> widths);

int getINI(std::string section, std::string key);


#endif // FUNCIONES_H

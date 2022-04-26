#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "mini/ini.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <random>


template<typename T> void prettyPrint(T t, int width, char separator);

void prettyPrintFila(const std::vector<std::string> & contenidos,
                     const std::vector<int> & widths);

int getINI(const std::string & section, const std::string & key);

std::string nombreAleatorio(const std::string & filepath);

int numLineas(std::stringstream & stream);

template<typename T> T personajeAleatorio();

int calcularHitChance(double ACC, double EVA);

std::vector<std::string> stringSplit(const std::string & cadena,
                                     const std::string & separador);

void stringStrip(std::string & cadena, const std::string & subcadena);

#endif // FUNCIONES_H

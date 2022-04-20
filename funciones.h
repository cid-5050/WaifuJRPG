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

template<typename T> T personajeAleatorio();

int calcularHitChance(double ACC, double EVA);

struct PrinterPareja {
    int wColumna {0};
    int wMargen {0};
    int wEspacio {0};

    void fila(const std::string & nombre,
              const std::string & contenidoA,
              const std::string & contenidoB) const;
    void linea(void) const;
    std::string margen(void) const;
};

#endif // FUNCIONES_H

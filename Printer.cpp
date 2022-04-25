#include "Printer.h"

Printer::
Printer() {
    wColumna = 0;
    wMargen = 0;
    wEspacio = 0;
}

Printer::
Printer(int wCol, int wMrg, int wSpc) {
    wColumna = wCol;
    wMargen = wMrg;
    wEspacio = wSpc;
}

std::stringstream & Printer::
getStream() {
    return stream;
}

void Printer::
clearStream() {
    std::stringstream().swap(stream);
}

void Printer::
print() const {
    std::cout << stream.str();
}

void Printer::
fila(const std::string & nombre,
     const std::string & contenidoA,
     const std::string & contenidoB) {

    stream << std::left
           << std::setw(wMargen) << ""
           << "||  "
           << std::setw(wColumna) << nombre
           << "||  "
           << std::setw(wColumna) << contenidoA
           << "||"
           << std::setw(wEspacio) << ""
           << "||  "
           << std::setw(wColumna) << nombre
           << "||  "
           << std::setw(wColumna) << contenidoB
           << "||"
           << std::endl;
}

void Printer::
linea() {
    stream << std::left
           << std::setw(wMargen) << ""
           << std::setfill('-')
           << std::setw((wColumna * 2) + 10) << ""
           << std::setfill(' ')
           << std::setw(wEspacio) << ""
           << std::setfill('-')
           << std::setw((wColumna * 2) + 10) << ""
           << std::setfill(' ')
           << std::endl;
}

void Printer::
margen() {
    stream << std::left
           << std::setw(wMargen) << "";
}


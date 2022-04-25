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
filaSingle(const std::string & nombre,
           const std::string & contenido) {

    stream << std::left
           << std::setw(10) << ""
           << "||  "
           << std::setw(wColumna) << nombre
           << "||  "
           << std::setw(wColumna) << contenido
           << "||"
           << std::endl;
}

void Printer::
lineaSingle() {
    stream << std::left
           << std::setw(10) << ""
           << std::setfill('-')
           << std::setw((wColumna * 2) + 10) << ""
           << std::setfill(' ')
           << std::endl;
}

void Printer::
fila1v1(const std::string & nombre,
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
linea1v1() {
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

void Printer::
sendLeft(void) {
    streamPair.first << stream.str();
    clearStream();
}

void Printer::
sendRight(void) {
    streamPair.second << stream.str();
    clearStream();
}

void Printer::
mergePair(void) {
    clearStream();
    std::string linea;

    while (std::getline(streamPair.first, linea)) {
        stream << std::left << std::setw(50) << linea;
        std::getline(streamPair.second, linea);
        stream << linea;
        stream << std::endl;
    }

    while (std::getline(streamPair.second, linea)) {
        stream << std::left << std::setw(50) << "";
        stream << linea;
        stream << std::endl;
    }

    std::stringstream().swap(streamPair.first);
    std::stringstream().swap(streamPair.second);
}

#include "Printer.h"

Printer::
Printer() {
    wColumna = 0;
    wMargen = 0;
    wEspacio = 0;

    colores.insert({"black", 224});
    colores.insert({"blue", 225});
    colores.insert({"green", 226});
    colores.insert({"aqua", 227});
    colores.insert({"red", 228});
    colores.insert({"purple", 229});
    colores.insert({"yellow", 230});
    colores.insert({"lightgray", 231});
    colores.insert({"gray", 232});
    colores.insert({"lightblue", 233});
    colores.insert({"lightgreen", 234});
    colores.insert({"lightaqua", 235});
    colores.insert({"lightred", 236});
    colores.insert({"lightpurple", 237});
    colores.insert({"lightyellow", 238});
    colores.insert({"white", 239});

    color = colores.at("black");

    streamMain = std::make_shared<std::stringstream>();
    streamAux.first = std::make_shared<std::stringstream>();
    streamAux.second = std::make_shared<std::stringstream>();

    stream = streamMain;
}

Printer::
Printer(int wCol, int wMrg, int wSpc) : Printer() {
    wColumna = wCol;
    wMargen = wMrg;
    wEspacio = wSpc;
}

std::stringstream & Printer::
getStream() {
    return *stream;
}

void Printer::
setStreamMain(void) {
    stream = streamMain;
}

void Printer::
setStreamAuxL(void) {
    stream = streamAux.first;
}

void Printer::
setStreamAuxR(void) {
    stream = streamAux.second;
}

void Printer::
clearStream() {
    std::stringstream().swap(*stream);
}

void Printer::
print() {
    std::string linea;

    while (std::getline(*stream, linea)) {
        linea.insert(0, margen());
        std::cout << linea << std::endl;
    }
}

void Printer::
getLinea(std::string & linea) {
    std::string strColor;

    resetColor();

    std::getline(*stream, linea);

    if (linea.find("#") != std::string::npos) {
        strColor = stringSplit(linea, "#").at(1);
        stringStrip(linea, "#" + strColor + "#");
        setColor(std::stoi(strColor));
    }

    linea.insert(0, margen());
}

void Printer::
injectColor(const std::string & color) {
    *stream << "#" << colores.at(color) << "#";
}

void Printer::
setColor(int color) {
    SetConsoleTextAttribute(winHandle, color);
    this->color = color;
}

void Printer::
resetColor(void) {
    if (color != colores.at("black"))
        setColor(colores.at("black"));
}

void Printer::
setMargen(int margen) {
    wMargen = margen;
}

void Printer::
setColumna(int width) {
    wColumna = width;
}

void Printer::
filaSingle(const std::string & nombre,
           const std::string & contenido) {

    *stream << std::left
            << "||  "
            << std::setw(wColumna) << nombre
            << "||  "
            << std::setw(wColumna) << contenido
            << "||"
            << std::endl;
}

void Printer::
lineaSingle(void) {
    *stream << std::left
            << std::setfill('-')
            << std::setw((wColumna * 2) + 10) << ""
            << std::setfill(' ')
            << std::endl;
}

void Printer::
fila1v1(const std::string & nombre,
     const std::string & contenidoA,
     const std::string & contenidoB) {

    *stream << std::left
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
linea1v1(void) {
    *stream << std::left
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
filaGlobal(const std::string & celdaA,
           const std::string & celdaB,
           const std::string & celdaC,
           const std::string & celdaD) {

    *stream << std::left
            << "|| "
            << std::setw(wColumna) << celdaA
            << "| "
            << std::setw(wColumna - 2) << celdaB
            << "|| "
            << std::setw(wColumna) << celdaC
            << "| "
            << std::setw(wColumna - 2) << celdaD
            << "||"
            << std::endl;
}

void Printer::
lineaGlobalA(void) {
    *stream << std::left
            << std::setfill('-')
            << "<"
            << std::setw((wColumna * 4) + 6) << ""
            << ">"
            << std::setfill(' ')
            << std::endl;
}

void Printer::
lineaGlobalB(char fill) {
    *stream << std::left
            << std::setfill(fill)
            << "||"
            << std::setw((wColumna * 2) + 1) << ""
            << "||"
            << std::setw((wColumna * 2) + 1) << ""
            << "||"
            << std::setfill(' ')
            << std::endl;
}

std::string Printer::
margen() const {
    return (std::stringstream() << std::left << std::setw(wMargen) << "").str();
}

void Printer::
mergeAux(void) {

    setStreamMain();

    std::string linea;

    while (std::getline(*(streamAux.first), linea)) {
        *streamMain << std::left << std::setw(45) << linea;
        std::getline(*(streamAux.second), linea);
        *streamMain << linea
                    << std::endl;
    }

    while (std::getline(*(streamAux.second), linea)) {
        *streamMain << std::left << std::setw(45) << ""
                    << linea
                    << std::endl;
    }

    std::stringstream().swap(*(streamAux.first));
    std::stringstream().swap(*(streamAux.second));
}

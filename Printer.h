#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <iomanip>
#include <funciones.h>
#include <windows.h>


class Printer {
 public:
    Printer();
    Printer(int wCol, int wMrg, int wSpc);

    std::stringstream & getStream(void);
    void clearStream(void);
    void print(void);
    void getLinea(std::string & linea);
    void injectColor(const std::string & color);
    void setColor(int color);
    void resetColor(void);

    void filaSingle(const std::string & nombre,
                    const std::string & contenido);
    void lineaSingle(void);

    void fila1v1(const std::string & nombre,
                 const std::string & contenidoA,
                 const std::string & contenidoB);
    void linea1v1(void);


    std::string margen(void) const;

    void sendLeft(void);
    void sendRight(void);
    void mergePair(void);

 private:
    std::stringstream stream;
    std::pair<std::stringstream, std::stringstream> streamPair;

    int wColumna;
    int wMargen;
    int wEspacio;

    int color;
    std::unordered_map<std::string, int> colores;
    HANDLE  winHandle {GetStdHandle(STD_OUTPUT_HANDLE)};
};


#endif // PRINTER_H

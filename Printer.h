#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <iomanip>
#include <funciones.h>

class Printer {
 public:
    Printer();
    Printer(int wCol, int wMrg, int wSpc);

    std::stringstream & getStream(void);
    void clearStream(void);
    void print(void) const;

    void filaSingle(const std::string & nombre,
                    const std::string & contenido);
    void lineaSingle(void);

    void fila1v1(const std::string & nombre,
                 const std::string & contenidoA,
                 const std::string & contenidoB);
    void linea1v1(void);


    void margen(void);

    void sendLeft(void);
    void sendRight(void);
    void mergePair(void);

 private:
    std::stringstream stream;
    std::pair<std::stringstream, std::stringstream> streamPair;

    int wColumna;
    int wMargen;
    int wEspacio;
};


#endif // PRINTER_H

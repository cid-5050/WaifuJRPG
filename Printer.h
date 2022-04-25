#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <iomanip>

class Printer {
 public:
    Printer();
    Printer(int wCol, int wMrg, int wSpc);

    std::stringstream & getStream(void);
    void clearStream(void);
    void print(void) const;

    void fila(const std::string & nombre,
              const std::string & contenidoA,
              const std::string & contenidoB);
    void linea(void);
    void margen(void);

 private:
    std::stringstream stream;

    int wColumna;
    int wMargen;
    int wEspacio;
};


#endif // PRINTER_H

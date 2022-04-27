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

    void setStreamMain(void);
    void setStreamAuxL(void);
    void setStreamAuxR(void);

    void clearStream(void);
    void print(void);
    void getLinea(std::string & linea);
    void injectColor(const std::string & color);
    void setColor(int color);
    void resetColor(void);
    void setMargen(int margen);
    void setColumna(int width);
    void resetWidths(void);

    void filaSingle(const std::string & nombre,
                    const std::string & contenido);
    void lineaSingle(void);

    void fila1v1(const std::string & nombre,
                 const std::string & contenidoA,
                 const std::string & contenidoB);
    void linea1v1(void);

    void filaGlobal(const std::string & celdaA,
                    const std::string & celdaB,
                    const std::string & celdaC,
                    const std::string & celdaD);
    void lineaGlobalA(void);
    void lineaGlobalB(char fill);


    std::string margen(void) const;
    void removeMargen(std::stringstream & stream);
    void insertMargen(std::stringstream & stream);
    void insertMargen(std::string & linea) const;

    void mergeAux(int anchuraIzq);

 private:
    std::shared_ptr<std::stringstream> streamMain;
    std::pair<std::shared_ptr<std::stringstream>,
              std::shared_ptr<std::stringstream>> streamAux;
    std::shared_ptr<std::stringstream> stream;

    int wColumna, wColumna_;
    int wMargen, wMargen_;
    int wEspacio, wEspacio_;

    int color;
    std::unordered_map<std::string, int> colores;
    HANDLE  winHandle {GetStdHandle(STD_OUTPUT_HANDLE)};
};


#endif // PRINTER_H

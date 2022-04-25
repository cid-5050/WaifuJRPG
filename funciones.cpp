#include "funciones.h"
#include <Mago.h>
#include <Barbaro.h>


template<typename T> void prettyPrint(T t, int width, char separator) {
    std::cout << std::left << std::setw(width) << std::setfill(separator) << t;
}

void prettyPrintFila(const std::vector<std::string> & contenidos,
                     const std::vector<int> & widths) {
    for (int i {0}; i < static_cast<int>(contenidos.size()); i++) {
        prettyPrint("||", 4, ' ');
        prettyPrint(contenidos.at(i), widths.at(i), ' ');
    }
    prettyPrint("||", 4, ' ');
    std::cout << std::endl;
}

int getINI(const std::string & section, const std::string & key) {
    mINI::INIFile file("config.ini");
    mINI::INIStructure ini;

    file.read(ini);
    return std::stoi(ini[section][key]);
}

std::string nombreAleatorio(const std::string & filepath) {
    std::ifstream file(filepath);
    std::string linea;
    int total {0};

    std::random_device rd;
    std::default_random_engine defEngine(rd());

    while (std::getline(file, linea))
        total++;

    std::uniform_int_distribution<int> intDistro(0, total);

    file.clear();
    file.seekg(0);

    for (int i {0}; i < intDistro(defEngine); i++) {
        std::getline(file, linea);
    }

    return linea;
}

template<typename T> T personajeAleatorio() {
    std::random_device rd;
    std::default_random_engine defEngine(rd());
    std::uniform_int_distribution<int> intDistro(0, 1);

    switch (intDistro(defEngine)) {
        case 0:
            return Mago(nombreAleatorio("nombres-a.txt"));
        case 1:
            return Barbaro(nombreAleatorio("nombres-a.txt"));
    }
}

int calcularHitChance(double ACC, double EVA) {
    if (ACC / EVA >= 1.0)
        return (50.0 + (50.0 - (50.0 / (ACC / EVA)))) + 10;
    else
        return (50.0 * ACC / EVA) + 10;
}

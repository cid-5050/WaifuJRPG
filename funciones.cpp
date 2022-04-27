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

int numLineas(std::stringstream & stream) {
    std::string linea;
    int total {0};

    while (std::getline(stream, linea))
        total++;

    stream.clear();
    stream.seekg(0);

    return total;
}

int calcularHitChance(double ACC, double EVA) {
    if (ACC / EVA >= 1.0)
        return (50.0 + (50.0 - (50.0 / (ACC / EVA)))) + 10;
    else
        return (50.0 * ACC / EVA) + 10;
}

std::vector<std::string> stringSplit(const std::string & cadena,
                                     const std::string & separador) {
    size_t pos {0};
    std::string copia {cadena};
    std::vector<std::string> substrings;

    while ((pos = copia.find(separador)) != std::string::npos) {
        substrings.push_back(copia.substr(0, pos));
        copia.erase(0, pos + separador.length());
    }
    substrings.push_back(copia);
    return substrings;
}

void stringStrip(std::string & cadena, const std::string & subcadena) {
    size_t pos {cadena.find(subcadena)};

    if (pos != std::string::npos)
        cadena.erase(pos, subcadena.length());
}

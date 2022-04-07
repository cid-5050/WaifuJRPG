#include "funciones.h"


template<typename T> void prettyPrint(T t, int width, char separator) {
    std::cout << std::left << std::setw(width) << std::setfill(separator) << t;
}

void prettyPrintFila(std::vector<std::string> contenidos, std::vector<int> widths) {
    for (int i {0}; i < static_cast<int>(contenidos.size()); i++) {
        prettyPrint("||", 4, ' ');
        prettyPrint(contenidos.at(i), widths.at(i), ' ');
    }
    prettyPrint("||", 4, ' ');
    std::cout << std::endl;
}

int getINI(std::string section, std::string key) {
    mINI::INIFile file("config.ini");
    mINI::INIStructure ini;

    file.read(ini);
    return std::stoi(ini[section][key]);
}

std::string nombreAleatorio(std::string filepath) {
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

#include "WaifuJRPG.h"
#include <funciones.h>


WaifuJRPG::
WaifuJRPG() {
    readNombres("nombres.txt");

    equipoA = formarEquipoAleatorio(10);
    equipoB = formarEquipoAleatorio(10);

    for (const auto & personaje : *equipoA) {
        personaje->initStats();
        for (const auto & adversario : *equipoB)
            personaje->addAdversario(adversario);
    }

    for (const auto & personaje : *equipoB) {
        personaje->initStats();
        for (const auto & adversario : *equipoA)
            personaje->addAdversario(adversario);
    }

    turno = 0;

    nombres.clear();
}

int WaifuJRPG::
getTurno(void) const {
    return turno;
}

void WaifuJRPG::
readNombres(const std::string & filepath) {
    std::ifstream file(filepath);
    std::string linea;

    while (std::getline(file, linea))
        nombres.push_back(linea);
}

std::string WaifuJRPG::
nombreAleatorio(void) {
    int index;
    std::string nombre;

    std::random_device rd;
    std::default_random_engine defEngine(rd());
    std::uniform_int_distribution<int> intDistro(0, nombres.size() - 1);

    index = intDistro(defEngine);
    nombre = nombres.at(index);

    nombres.erase(nombres.begin() + index);
    return nombre;
}

std::shared_ptr<CombatEvent> WaifuJRPG::
evento(void) const {
    return eventos.back();
}

std::shared_ptr<std::vector<std::shared_ptr<Personaje>>> WaifuJRPG::
formarEquipoAleatorio(int numIntegrantes) {

    std::shared_ptr<std::vector<std::shared_ptr<Personaje>>>
    equipo {std::make_shared<std::vector<std::shared_ptr<Personaje>>>()};

    std::random_device rd;
    std::default_random_engine defEngine(rd());
    std::uniform_int_distribution<int> intDistro(0, 1);

    for (int i = 0; i < numIntegrantes; i++) {
        switch (intDistro(defEngine)) {
        case 0:
            equipo->push_back(std::make_shared<Mago>(nombreAleatorio()));
            break;
        case 1:
            equipo->push_back(std::make_shared<Barbaro>(nombreAleatorio()));
            break;
        }
    }
    return equipo;
}

void WaifuJRPG::
next() {
    std::shared_ptr<std::vector<std::shared_ptr<Personaje>>> party;
    std::shared_ptr<Personaje> personaje;

    if (turno % 2 == 0)
        party = equipoA;
    else
        party = equipoB;

    personaje = miembroAleatorio(party);

    eventos.push_back(std::make_shared<CombatEvent>(++turno, personaje));

    personaje->actuar(this->evento());
}

std::shared_ptr<Personaje> WaifuJRPG::
miembroAleatorio(std::shared_ptr<std::vector<std::shared_ptr<Personaje>>> party) const {
    std::random_device rd;
    std::default_random_engine defEngine(rd());
    std::uniform_int_distribution<int> intDistro(0, party->size() - 1);
    return party->at(intDistro(defEngine));
}

std::stringstream & WaifuJRPG::printer(void) {
    return printer_.getStream();
}

void WaifuJRPG::
setPrinter(int wCol, int wMrg, int wSpc) {
    printer_ = Printer(wCol, wMrg, wSpc);
}

void WaifuJRPG::
printerColor(const std::string & color) {
    printer_.injectColor(color);
}

/*void WaifuJRPG::
printStats(void) const {
    printer.linea1v1();
    printer.fila1v1("Nombre", equipoA->at(0)->getNombre(), equipoB->at(0)->getNombre());
    printer.linea1v1();
    printer.fila1v1("HP", std::to_string(equipoA->at(0)->getHP()), std::to_string(equipoB->at(0)->getHP()));
    printer.fila1v1("Mana", std::to_string(equipoA->at(0)->getMana()), std::to_string(equipoB->at(0)->getMana()));
    printer.fila1v1("Stamina", std::to_string(equipoA->at(0)->getStamina()), std::to_string(equipoB->at(0)->getStamina()));
    printer.linea1v1();
    printer.fila1v1("VIT", std::to_string(equipoA->at(0)->getVIT()), std::to_string(equipoB->at(0)->getVIT()));
    printer.fila1v1("END", std::to_string(equipoA->at(0)->getEND()), std::to_string(equipoB->at(0)->getEND()));
    printer.fila1v1("ATK", std::to_string(equipoA->at(0)->getATK()), std::to_string(equipoB->at(0)->getATK()));
    printer.fila1v1("PDEX", std::to_string(equipoA->at(0)->getPDEX()), std::to_string(equipoB->at(0)->getPDEX()));
    printer.fila1v1("MDEX", std::to_string(equipoA->at(0)->getMDEX()), std::to_string(equipoB->at(0)->getMDEX()));
    printer.fila1v1("DEF", std::to_string(equipoA->at(0)->getDEF()), std::to_string(equipoB->at(0)->getDEF()));
    printer.fila1v1("PRES", std::to_string(equipoA->at(0)->getPRES()), std::to_string(equipoB->at(0)->getPRES()));
    printer.fila1v1("MRES", std::to_string(equipoA->at(0)->getMRES()), std::to_string(equipoB->at(0)->getMRES()));
    printer.fila1v1("ACC", std::to_string(equipoA->at(0)->getACC()), std::to_string(equipoB->at(0)->getACC()));
    printer.fila1v1("EVA", std::to_string(equipoA->at(0)->getEVA()), std::to_string(equipoB->at(0)->getEVA()));
    printer.fila1v1("LCK", std::to_string(equipoA->at(0)->getLCK()), std::to_string(equipoB->at(0)->getLCK()));
    printer.linea1v1();
    printer.fila1v1("Clase", equipoA->at(0)->getClase(), equipoB->at(0)->getClase());
    printer.linea1v1();
}*/

void WaifuJRPG::
fullStats1v1(void) {
    printer_.linea1v1();
    printer_.fila1v1("Nombre", equipoA->at(0)->getNombre(), equipoB->at(0)->getNombre());
    printer_.linea1v1();
    printer_.fila1v1("HP", std::to_string(equipoA->at(0)->getHP()), std::to_string(equipoB->at(0)->getHP()));
    printer_.fila1v1("Mana", std::to_string(equipoA->at(0)->getMana()), std::to_string(equipoB->at(0)->getMana()));
    printer_.fila1v1("Stamina", std::to_string(equipoA->at(0)->getStamina()), std::to_string(equipoB->at(0)->getStamina()));
    printer_.linea1v1();
    printer_.fila1v1("VIT", std::to_string(equipoA->at(0)->getVIT()), std::to_string(equipoB->at(0)->getVIT()));
    printer_.fila1v1("END", std::to_string(equipoA->at(0)->getEND()), std::to_string(equipoB->at(0)->getEND()));
    printer_.fila1v1("ATK", std::to_string(equipoA->at(0)->getATK()), std::to_string(equipoB->at(0)->getATK()));
    printer_.fila1v1("PDEX", std::to_string(equipoA->at(0)->getPDEX()), std::to_string(equipoB->at(0)->getPDEX()));
    printer_.fila1v1("MDEX", std::to_string(equipoA->at(0)->getMDEX()), std::to_string(equipoB->at(0)->getMDEX()));
    printer_.fila1v1("DEF", std::to_string(equipoA->at(0)->getDEF()), std::to_string(equipoB->at(0)->getDEF()));
    printer_.fila1v1("PRES", std::to_string(equipoA->at(0)->getPRES()), std::to_string(equipoB->at(0)->getPRES()));
    printer_.fila1v1("MRES", std::to_string(equipoA->at(0)->getMRES()), std::to_string(equipoB->at(0)->getMRES()));
    printer_.fila1v1("ACC", std::to_string(equipoA->at(0)->getACC()), std::to_string(equipoB->at(0)->getACC()));
    printer_.fila1v1("EVA", std::to_string(equipoA->at(0)->getEVA()), std::to_string(equipoB->at(0)->getEVA()));
    printer_.fila1v1("LCK", std::to_string(equipoA->at(0)->getLCK()), std::to_string(equipoB->at(0)->getLCK()));
    printer_.linea1v1();
    printer_.fila1v1("Clase", equipoA->at(0)->getClase(), equipoB->at(0)->getClase());
    printer_.linea1v1();
}

void WaifuJRPG::
miniStats1v1(void) {
    printer_.linea1v1();
    printer_.fila1v1("Nombre", equipoA->at(0)->getNombre(), equipoB->at(0)->getNombre());
    printer_.linea1v1();
    printer_.fila1v1("HP", std::to_string(equipoA->at(0)->getHP()), std::to_string(equipoB->at(0)->getHP()));
    printer_.fila1v1("Mana", std::to_string(equipoA->at(0)->getMana()), std::to_string(equipoB->at(0)->getMana()));
    printer_.fila1v1("Stamina", std::to_string(equipoA->at(0)->getStamina()), std::to_string(equipoB->at(0)->getStamina()));
    printer_.linea1v1();
    printer_.fila1v1("Clase", equipoA->at(0)->getClase(), equipoB->at(0)->getClase());
    printer_.linea1v1();
}


void WaifuJRPG::
titleScreen() const {
    std::ifstream file("titleScreen.txt");
    std::string linea1v1;

    while (std::getline(file, linea1v1))
        std::cout << linea1v1 << std::endl;
}


void WaifuJRPG::
updateScreen(std::stringstream & o) const {
    std::ifstream file("titleScreen.txt");
    std::string lineaTitle;
    std::string lineaMain;
    int numLinea {1};

    while (std::getline(file, lineaTitle)) {
        if ((numLinea <= 3) or (numLinea >= 25)) {
            std::cout << lineaTitle << std::endl;
        } else {
            std::getline(o, lineaMain);
            std::cout << lineaTitle.substr(0, 9);
            std::cout << std::left << std::setw(102) << lineaMain;
            std::cout << lineaTitle.substr(111, std::string::npos) << std::endl;
        }
        numLinea++;
    }
    std::cout << ">> ";
}

void WaifuJRPG::
print(void) {
    std::ifstream file("titleScreen.txt");
    std::string lineaTitle;
    std::string lineaMain;
    int numLinea {1};

    while (std::getline(file, lineaTitle)) {
        if ((numLinea <= 3) or (numLinea >= 25)) {
            std::cout << lineaTitle << std::endl;
        } else {
            std::cout << lineaTitle.substr(0, 9);

            printer_.getLinea(lineaMain);

            if (numLinea != 23) {
                std::cout << std::left << std::setw(101) << lineaMain;
                printer_.resetColor();
            } else {
                std::cout << std::left << std::setw(94) << lineaMain;
                printer_.resetColor();
                std::cout << std::left << std::setw(7)
                          << (std::stringstream() << "[" << turno << "]").str();
            }

            std::cout << lineaTitle.substr(110, std::string::npos) << std::endl;
            lineaMain.clear();
        }
        numLinea++;
    }
    std::cout << ">> ";

    printer_.clearStream();
}

bool WaifuJRPG::
existePersonaje(const std::string & nombre) const {
    for (const auto & personaje : *equipoA) {
        if (nombre == personaje->getNombre())
            return true;
    }
    for (const auto & personaje : *equipoB) {
        if (nombre == personaje->getNombre())
            return true;
    }
    return false;
}

std::shared_ptr<Personaje> WaifuJRPG::
getPersonaje(const std::string & nombre) const {
    for (const auto & personaje : *equipoA) {
        if (nombre == personaje->getNombre())
            return personaje;
    }
    for (const auto & personaje : *equipoB) {
        if (nombre == personaje->getNombre())
            return personaje;
    }
    return nullptr;
}

void WaifuJRPG::
statsPersonaje(std::shared_ptr<Personaje> personaje) {

    printer_.setStreamAuxL();

    printer() << std::endl;
    printer() << std::endl;
    printer() << std::endl;
    printer() << "Stats de " << personaje->getNombre() << ":" << std::endl;
    printer() << std::endl;
    printer() << personaje->getNombre() << " ha inflingido 100 puntos" << std::endl;
    printer() << "de DMG y ha recuperado 100 puntos" << std::endl;
    printer() << "de HP." << std::endl;

    printer_.setStreamAuxR();

    printer_.lineaSingle();
    printer_.filaSingle("Nombre", personaje->getNombre());
    printer_.lineaSingle();
    printer_.filaSingle("HP", std::to_string(personaje->getHP()));
    printer_.filaSingle("Mana", std::to_string(personaje->getMana()));
    printer_.filaSingle("Stamina", std::to_string(personaje->getStamina()));
    printer_.lineaSingle();
    printer_.filaSingle("VIT", std::to_string(personaje->getVIT()));
    printer_.filaSingle("END", std::to_string(personaje->getEND()));
    printer_.filaSingle("ATK", std::to_string(personaje->getATK()));
    printer_.filaSingle("PDEX", std::to_string(personaje->getPDEX()));
    printer_.filaSingle("MDEX", std::to_string(personaje->getMDEX()));
    printer_.filaSingle("DEF", std::to_string(personaje->getDEF()));
    printer_.filaSingle("PRES", std::to_string(personaje->getPRES()));
    printer_.filaSingle("MRES", std::to_string(personaje->getMRES()));
    printer_.filaSingle("ACC", std::to_string(personaje->getACC()));
    printer_.filaSingle("EVA", std::to_string(personaje->getEVA()));
    printer_.filaSingle("LCK", std::to_string(personaje->getLCK()));
    printer_.lineaSingle();
    printer_.filaSingle("Clase", personaje->getClase());
    printer_.lineaSingle();

    printer_.mergeAux(55);
}

void WaifuJRPG::
statsGlobales(void) {
    std::shared_ptr<Personaje>  persAnterior;

    printer_.setMargen(8);
    printer_.setColumna(8);

    printer_.setStreamAuxL();

    printer_.lineaGlobalA();
    printer_.filaGlobal("Nombre", "HP", "Nombre", "HP");
    printer_.lineaGlobalB('=');

    for (auto iPersonaje = (*equipoA).begin(); iPersonaje != (*equipoA).end(); ++iPersonaje) {
        // indice no es par
        if (std::distance((*equipoA).begin(), iPersonaje) % 2 == 0) {
            // iterador no es el ultimo
            if (iPersonaje != ((*equipoA).end() - 1)) {
                persAnterior = *iPersonaje;
            } else {
                printer_.filaGlobal((*iPersonaje)->getNombre(),
                                    std::to_string((*iPersonaje)->getHP()),
                                    "", "");
            }
        } else {
            printer_.filaGlobal(persAnterior->getNombre(),
                                std::to_string(persAnterior->getHP()),
                                (*iPersonaje)->getNombre(),
                                std::to_string((*iPersonaje)->getHP()));

            // iterador no es el ultimo
            if (iPersonaje != ((*equipoA).end() - 1))
                printer_.lineaGlobalB('-');
        }
    }
    printer_.lineaGlobalA();

    printer_.setStreamAuxR();

    printer_.lineaGlobalA();
    printer_.filaGlobal("Nombre", "HP", "Nombre", "HP");
    printer_.lineaGlobalB('=');

    for (auto iPersonaje = (*equipoB).begin(); iPersonaje != (*equipoB).end(); ++iPersonaje) {
        // indice no es par
        if (std::distance((*equipoB).begin(), iPersonaje) % 2 == 0) {
            // iterador no es el ultimo
            if (iPersonaje != ((*equipoB).end() - 1)) {
                persAnterior = *iPersonaje;
            } else {
                printer_.filaGlobal((*iPersonaje)->getNombre(),
                                    std::to_string((*iPersonaje)->getHP()),
                                    "", "");
            }
        } else {
            printer_.filaGlobal(persAnterior->getNombre(),
                                std::to_string(persAnterior->getHP()),
                                (*iPersonaje)->getNombre(),
                                std::to_string((*iPersonaje)->getHP()));

            // iterador no es el ultimo
            if (iPersonaje != ((*equipoB).end() - 1))
                printer_.lineaGlobalB('-');
        }
    }
    printer_.lineaGlobalA();

    printer_.mergeAux(52);
    printer_.resetWidths();
}

int WaifuJRPG::
command(const std::string & comando) {

    if (comando == "next" or comando == "")
        return 1;

    if(comando == "game")
        return 2;

    if (existePersonaje(comando))
        return 3;

    if (comando == "exit")
        return 4;

    if (comando != "help") {
        printer() << std::endl;
        printer() << std::endl;
        printer() << "Comando '" << comando << "' desconocido" << std::endl;
    }

    return 0;
}

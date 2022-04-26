#include "WaifuJRPG.h"
#include <funciones.h>


WaifuJRPG::
WaifuJRPG() {
    std::shared_ptr<Personaje> p1 {std::make_shared<Mago>(nombreAleatorio("nombres-a.txt"))};
    std::shared_ptr<Personaje> p2 = {std::make_shared<Barbaro>(nombreAleatorio("nombres-b.txt"))};

    p1->addAdversario(p2);
    p2->addAdversario(p1);

    p1->initStats();
    p2->initStats();

    partyA->push_back(p1);
    partyB->push_back(p2);

    turno = 0;
}

int WaifuJRPG::
getTurno(void) const {
    return turno;
}

std::shared_ptr<CombatEvent> WaifuJRPG::
evento(void) const {
    return eventos.back();
}

void WaifuJRPG::
next() {
    std::shared_ptr<std::vector<std::shared_ptr<Personaje>>> party;
    std::shared_ptr<Personaje> personaje;

    if (turno % 2 == 0)
        party = partyA;
    else
        party = partyB;

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

/*void WaifuJRPG::
printStats(void) const {
    printer.linea1v1();
    printer.fila1v1("Nombre", partyA->at(0)->getNombre(), partyB->at(0)->getNombre());
    printer.linea1v1();
    printer.fila1v1("HP", std::to_string(partyA->at(0)->getHP()), std::to_string(partyB->at(0)->getHP()));
    printer.fila1v1("Mana", std::to_string(partyA->at(0)->getMana()), std::to_string(partyB->at(0)->getMana()));
    printer.fila1v1("Stamina", std::to_string(partyA->at(0)->getStamina()), std::to_string(partyB->at(0)->getStamina()));
    printer.linea1v1();
    printer.fila1v1("VIT", std::to_string(partyA->at(0)->getVIT()), std::to_string(partyB->at(0)->getVIT()));
    printer.fila1v1("END", std::to_string(partyA->at(0)->getEND()), std::to_string(partyB->at(0)->getEND()));
    printer.fila1v1("ATK", std::to_string(partyA->at(0)->getATK()), std::to_string(partyB->at(0)->getATK()));
    printer.fila1v1("PDEX", std::to_string(partyA->at(0)->getPDEX()), std::to_string(partyB->at(0)->getPDEX()));
    printer.fila1v1("MDEX", std::to_string(partyA->at(0)->getMDEX()), std::to_string(partyB->at(0)->getMDEX()));
    printer.fila1v1("DEF", std::to_string(partyA->at(0)->getDEF()), std::to_string(partyB->at(0)->getDEF()));
    printer.fila1v1("PRES", std::to_string(partyA->at(0)->getPRES()), std::to_string(partyB->at(0)->getPRES()));
    printer.fila1v1("MRES", std::to_string(partyA->at(0)->getMRES()), std::to_string(partyB->at(0)->getMRES()));
    printer.fila1v1("ACC", std::to_string(partyA->at(0)->getACC()), std::to_string(partyB->at(0)->getACC()));
    printer.fila1v1("EVA", std::to_string(partyA->at(0)->getEVA()), std::to_string(partyB->at(0)->getEVA()));
    printer.fila1v1("LCK", std::to_string(partyA->at(0)->getLCK()), std::to_string(partyB->at(0)->getLCK()));
    printer.linea1v1();
    printer.fila1v1("Clase", partyA->at(0)->getClase(), partyB->at(0)->getClase());
    printer.linea1v1();
}*/

void WaifuJRPG::
fullStats1v1(void) {
    printer_.linea1v1();
    printer_.fila1v1("Nombre", partyA->at(0)->getNombre(), partyB->at(0)->getNombre());
    printer_.linea1v1();
    printer_.fila1v1("HP", std::to_string(partyA->at(0)->getHP()), std::to_string(partyB->at(0)->getHP()));
    printer_.fila1v1("Mana", std::to_string(partyA->at(0)->getMana()), std::to_string(partyB->at(0)->getMana()));
    printer_.fila1v1("Stamina", std::to_string(partyA->at(0)->getStamina()), std::to_string(partyB->at(0)->getStamina()));
    printer_.linea1v1();
    printer_.fila1v1("VIT", std::to_string(partyA->at(0)->getVIT()), std::to_string(partyB->at(0)->getVIT()));
    printer_.fila1v1("END", std::to_string(partyA->at(0)->getEND()), std::to_string(partyB->at(0)->getEND()));
    printer_.fila1v1("ATK", std::to_string(partyA->at(0)->getATK()), std::to_string(partyB->at(0)->getATK()));
    printer_.fila1v1("PDEX", std::to_string(partyA->at(0)->getPDEX()), std::to_string(partyB->at(0)->getPDEX()));
    printer_.fila1v1("MDEX", std::to_string(partyA->at(0)->getMDEX()), std::to_string(partyB->at(0)->getMDEX()));
    printer_.fila1v1("DEF", std::to_string(partyA->at(0)->getDEF()), std::to_string(partyB->at(0)->getDEF()));
    printer_.fila1v1("PRES", std::to_string(partyA->at(0)->getPRES()), std::to_string(partyB->at(0)->getPRES()));
    printer_.fila1v1("MRES", std::to_string(partyA->at(0)->getMRES()), std::to_string(partyB->at(0)->getMRES()));
    printer_.fila1v1("ACC", std::to_string(partyA->at(0)->getACC()), std::to_string(partyB->at(0)->getACC()));
    printer_.fila1v1("EVA", std::to_string(partyA->at(0)->getEVA()), std::to_string(partyB->at(0)->getEVA()));
    printer_.fila1v1("LCK", std::to_string(partyA->at(0)->getLCK()), std::to_string(partyB->at(0)->getLCK()));
    printer_.linea1v1();
    printer_.fila1v1("Clase", partyA->at(0)->getClase(), partyB->at(0)->getClase());
    printer_.linea1v1();
}

void WaifuJRPG::
miniStats1v1(void) {
    printer_.linea1v1();
    printer_.fila1v1("Nombre", partyA->at(0)->getNombre(), partyB->at(0)->getNombre());
    printer_.linea1v1();
    printer_.fila1v1("HP", std::to_string(partyA->at(0)->getHP()), std::to_string(partyB->at(0)->getHP()));
    printer_.fila1v1("Mana", std::to_string(partyA->at(0)->getMana()), std::to_string(partyB->at(0)->getMana()));
    printer_.fila1v1("Stamina", std::to_string(partyA->at(0)->getStamina()), std::to_string(partyB->at(0)->getStamina()));
    printer_.linea1v1();
    printer_.fila1v1("Clase", partyA->at(0)->getClase(), partyB->at(0)->getClase());
    printer_.linea1v1();
}

void WaifuJRPG::
margen() {
    printer_.margen();
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
            std::getline(this->printer(), lineaMain);
            std::cout << lineaTitle.substr(0, 9);

            if (numLinea != 23) {
                std::cout << std::left << std::setw(101) << lineaMain;
            } else {
                std::cout << std::left << std::setw(94) << lineaMain
                          << std::left << std::setw(7)
                          << (std::stringstream() << "[" << turno << "]").str();
            }
            std::cout << lineaTitle.substr(110, std::string::npos) << std::endl;

        }
        numLinea++;
    }
    std::cout << ">> ";

    printer_.clearStream();
}

bool WaifuJRPG::
existePersonaje(const std::string & nombre) const {
    for (const auto & personaje : *partyA) {
        if (nombre == personaje->getNombre())
            return true;
    }
    for (const auto & personaje : *partyB) {
        if (nombre == personaje->getNombre())
            return true;
    }
    return false;
}

std::shared_ptr<Personaje> WaifuJRPG::
getPersonaje(const std::string & nombre) const {
    for (const auto & personaje : *partyA) {
        if (nombre == personaje->getNombre())
            return personaje;
    }
    for (const auto & personaje : *partyB) {
        if (nombre == personaje->getNombre())
            return personaje;
    }
    return nullptr;
}

void WaifuJRPG::
statsPersonaje(std::shared_ptr<Personaje> personaje) {

    printer() << std::endl;
    printer() << std::endl;
    margen();
    printer() << "Stats de " << personaje->getNombre() << ":" << std::endl;
    printer() << std::endl;
    margen();
    printer() << personaje->getNombre() << "ha inflingido 100 puntos" << std::endl;
    margen();
    printer() << "de DMG y ha recuperado 100 puntos" << std::endl;
    margen();
    printer() << "de HP." << std::endl;

    printer_.sendLeft();

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

    printer_.sendRight();

    printer_.mergePair();
}

void WaifuJRPG::
statsGlobales(void) {
    // IMPRIME STATS GLOBALES
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
        margen();
        printer() << "Comando '" << comando << "' desconocido" << std::endl;
    }

    return 0;
}

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
    printer.linea();
    printer.fila("Nombre", partyA->at(0)->getNombre(), partyB->at(0)->getNombre());
    printer.linea();
    printer.fila("HP", std::to_string(partyA->at(0)->getHP()), std::to_string(partyB->at(0)->getHP()));
    printer.fila("Mana", std::to_string(partyA->at(0)->getMana()), std::to_string(partyB->at(0)->getMana()));
    printer.fila("Stamina", std::to_string(partyA->at(0)->getStamina()), std::to_string(partyB->at(0)->getStamina()));
    printer.linea();
    printer.fila("VIT", std::to_string(partyA->at(0)->getVIT()), std::to_string(partyB->at(0)->getVIT()));
    printer.fila("END", std::to_string(partyA->at(0)->getEND()), std::to_string(partyB->at(0)->getEND()));
    printer.fila("ATK", std::to_string(partyA->at(0)->getATK()), std::to_string(partyB->at(0)->getATK()));
    printer.fila("PDEX", std::to_string(partyA->at(0)->getPDEX()), std::to_string(partyB->at(0)->getPDEX()));
    printer.fila("MDEX", std::to_string(partyA->at(0)->getMDEX()), std::to_string(partyB->at(0)->getMDEX()));
    printer.fila("DEF", std::to_string(partyA->at(0)->getDEF()), std::to_string(partyB->at(0)->getDEF()));
    printer.fila("PRES", std::to_string(partyA->at(0)->getPRES()), std::to_string(partyB->at(0)->getPRES()));
    printer.fila("MRES", std::to_string(partyA->at(0)->getMRES()), std::to_string(partyB->at(0)->getMRES()));
    printer.fila("ACC", std::to_string(partyA->at(0)->getACC()), std::to_string(partyB->at(0)->getACC()));
    printer.fila("EVA", std::to_string(partyA->at(0)->getEVA()), std::to_string(partyB->at(0)->getEVA()));
    printer.fila("LCK", std::to_string(partyA->at(0)->getLCK()), std::to_string(partyB->at(0)->getLCK()));
    printer.linea();
    printer.fila("Clase", partyA->at(0)->getClase(), partyB->at(0)->getClase());
    printer.linea();
}*/

void WaifuJRPG::
fullStats1v1(void) {
    printer_.linea();
    printer_.fila("Nombre", partyA->at(0)->getNombre(), partyB->at(0)->getNombre());
    printer_.linea();
    printer_.fila("HP", std::to_string(partyA->at(0)->getHP()), std::to_string(partyB->at(0)->getHP()));
    printer_.fila("Mana", std::to_string(partyA->at(0)->getMana()), std::to_string(partyB->at(0)->getMana()));
    printer_.fila("Stamina", std::to_string(partyA->at(0)->getStamina()), std::to_string(partyB->at(0)->getStamina()));
    printer_.linea();
    printer_.fila("VIT", std::to_string(partyA->at(0)->getVIT()), std::to_string(partyB->at(0)->getVIT()));
    printer_.fila("END", std::to_string(partyA->at(0)->getEND()), std::to_string(partyB->at(0)->getEND()));
    printer_.fila("ATK", std::to_string(partyA->at(0)->getATK()), std::to_string(partyB->at(0)->getATK()));
    printer_.fila("PDEX", std::to_string(partyA->at(0)->getPDEX()), std::to_string(partyB->at(0)->getPDEX()));
    printer_.fila("MDEX", std::to_string(partyA->at(0)->getMDEX()), std::to_string(partyB->at(0)->getMDEX()));
    printer_.fila("DEF", std::to_string(partyA->at(0)->getDEF()), std::to_string(partyB->at(0)->getDEF()));
    printer_.fila("PRES", std::to_string(partyA->at(0)->getPRES()), std::to_string(partyB->at(0)->getPRES()));
    printer_.fila("MRES", std::to_string(partyA->at(0)->getMRES()), std::to_string(partyB->at(0)->getMRES()));
    printer_.fila("ACC", std::to_string(partyA->at(0)->getACC()), std::to_string(partyB->at(0)->getACC()));
    printer_.fila("EVA", std::to_string(partyA->at(0)->getEVA()), std::to_string(partyB->at(0)->getEVA()));
    printer_.fila("LCK", std::to_string(partyA->at(0)->getLCK()), std::to_string(partyB->at(0)->getLCK()));
    printer_.linea();
    printer_.fila("Clase", partyA->at(0)->getClase(), partyB->at(0)->getClase());
    printer_.linea();
}

void WaifuJRPG::
miniStats1v1(void) {
    printer_.linea();
    printer_.fila("Nombre", partyA->at(0)->getNombre(), partyB->at(0)->getNombre());
    printer_.linea();
    printer_.fila("HP", std::to_string(partyA->at(0)->getHP()), std::to_string(partyB->at(0)->getHP()));
    printer_.fila("Mana", std::to_string(partyA->at(0)->getMana()), std::to_string(partyB->at(0)->getMana()));
    printer_.fila("Stamina", std::to_string(partyA->at(0)->getStamina()), std::to_string(partyB->at(0)->getStamina()));
    printer_.linea();
    printer_.fila("Clase", partyA->at(0)->getClase(), partyB->at(0)->getClase());
    printer_.linea();
}

void WaifuJRPG::
margen() {
    printer_.margen();
}

void WaifuJRPG::
titleScreen() const {
    std::ifstream file("titleScreen.txt");
    std::string linea;

    while (std::getline(file, linea))
        std::cout << linea << std::endl;
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
            std::cout << std::left << std::setw(102) << lineaMain;
            std::cout << lineaTitle.substr(111, std::string::npos) << std::endl;
        }
        numLinea++;
    }
    std::cout << ">> ";

    printer_.clearStream();
}

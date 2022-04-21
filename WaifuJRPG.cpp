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

void WaifuJRPG::
setPrinter(int wCol, int wMrg, int wSpc) {
    printer.wColumna = wCol;
    printer.wMargen = wMrg;
    printer.wEspacio = wSpc;
}

void WaifuJRPG::
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
}

std::string WaifuJRPG::
margen() const {
    return printer.margen();
}

void WaifuJRPG::
titleScreen() const {
    std::ifstream file("titleScreen.txt");
    std::string linea;

    while (std::getline(file, linea))
        std::cout << linea << std::endl;
}

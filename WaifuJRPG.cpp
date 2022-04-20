#include "WaifuJRPG.h"
#include <funciones.h>


WaifuJRPG::
WaifuJRPG() {
    p1 = std::make_shared<Mago>(nombreAleatorio("nombres-a.txt"));
    p2 = std::make_shared<Barbaro>(nombreAleatorio("nombres-b.txt"));

    p1->addAdversario(p2);
    p2->addAdversario(p1);

    p1->initStats();
    p2->initStats();
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
    std::shared_ptr<Personaje> personaje;

    if (turno % 2 == 0)
        personaje = p1;
    else
        personaje = p2;

    eventos.push_back(std::make_shared<CombatEvent>(++turno, personaje));

    personaje->actuar(this->evento());
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
    printer.fila("Nombre", p1->getNombre(), p2->getNombre());
    printer.linea();
    printer.fila("HP", std::to_string(p1->getHP()), std::to_string(p2->getHP()));
    printer.fila("Mana", std::to_string(p1->getMana()), std::to_string(p2->getMana()));
    printer.fila("Stamina", std::to_string(p1->getStamina()), std::to_string(p2->getStamina()));
    printer.linea();
    printer.fila("VIT", std::to_string(p1->getVIT()), std::to_string(p2->getVIT()));
    printer.fila("END", std::to_string(p1->getEND()), std::to_string(p2->getEND()));
    printer.fila("ATK", std::to_string(p1->getATK()), std::to_string(p2->getATK()));
    printer.fila("PDEX", std::to_string(p1->getPDEX()), std::to_string(p2->getPDEX()));
    printer.fila("MDEX", std::to_string(p1->getMDEX()), std::to_string(p2->getMDEX()));
    printer.fila("DEF", std::to_string(p1->getDEF()), std::to_string(p2->getDEF()));
    printer.fila("PRES", std::to_string(p1->getPRES()), std::to_string(p2->getPRES()));
    printer.fila("MRES", std::to_string(p1->getMRES()), std::to_string(p2->getMRES()));
    printer.fila("ACC", std::to_string(p1->getACC()), std::to_string(p2->getACC()));
    printer.fila("EVA", std::to_string(p1->getEVA()), std::to_string(p2->getEVA()));
    printer.fila("LCK", std::to_string(p1->getLCK()), std::to_string(p2->getLCK()));
    printer.linea();
    printer.fila("Clase", p1->getClase(), p2->getClase());
    printer.linea();
}

std::string WaifuJRPG::
margen(void) const {
    return printer.margen();
}

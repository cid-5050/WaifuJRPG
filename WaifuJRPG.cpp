#include "WaifuJRPG.h"
#include <funciones.h>


WaifuJRPG::
WaifuJRPG() {
    p1 = std::make_shared<Mago>(nombreAleatorio("nombres-a.txt"));
    p2 = std::make_shared<Barbaro>(nombreAleatorio("nombres-b.txt"));

    p1->setAdversario(p2);
    p2->setAdversario(p1);

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
printPareja(void) const {
    // CONTINUAR AQUI
}

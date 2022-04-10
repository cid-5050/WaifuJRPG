#include "WaifuJRPG.h"
#include <funciones.h>


WaifuJRPG::
WaifuJRPG() {
    p1 = std::make_shared<Mago>(Mago(nombreAleatorio("nombres-a.txt")));
    p2 = std::make_shared<Barbaro>(Barbaro(nombreAleatorio("nombres-b.txt")));

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
    std::shared_ptr<Personaje> agresor;
    std::shared_ptr<Personaje> defensor;

    eventos.push_back(std::make_shared<CombatEvent>(CombatEvent(turno)));

    if (turno % 2 == 0) {
        agresor = p1;
        defensor = p2;
    } else {
        agresor = p2;
        defensor = p1;
    }

    agresor->recarga();
    agresor->ataque(defensor, this->evento());

    this->evento()->setAgresorDefensor(agresor, defensor);

    turno++;
}

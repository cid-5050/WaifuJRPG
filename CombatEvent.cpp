#include "CombatEvent.h"

CombatEvent::
CombatEvent(int turno, std::shared_ptr<Personaje> personaje) {
    this->turno = turno;
    this->personaje = personaje;
}

bool CombatEvent::
critico(void) const {
    return critico_;
}

bool CombatEvent::
miss(void) const {
    return miss_;
}

int CombatEvent::
getDMG(void) const {
    return DMG;
}

std::string CombatEvent::
getAtaque(void) const {
    return ataque;
}

std::shared_ptr<Personaje> CombatEvent::
getPersonaje(void) const {
    return personaje;
}

void CombatEvent::
saveDatosAtaque(std::string ataque, int DMG, bool miss, bool critico) {
    this->ataque = ataque;
    this->DMG = DMG;
    miss_ = miss;
    critico_ = critico;
}

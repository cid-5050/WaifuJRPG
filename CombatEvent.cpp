#include "CombatEvent.h"

CombatEvent::
CombatEvent(int turno) {
    this->turno = turno;
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

void CombatEvent::
saveDatosAtaque(std::string ataque, int DMG, bool miss, bool critico) {
    this->ataque = ataque;
    this->DMG = DMG;
    miss_ = miss;
    critico_ = critico;
}

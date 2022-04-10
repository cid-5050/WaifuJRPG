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

std::shared_ptr<Personaje> CombatEvent::
getAgresor(void) const {
    return agresor;
}

std::shared_ptr<Personaje> CombatEvent::
getDefensor(void) const {
    return defensor;
}

void CombatEvent::
setAgresorDefensor(std::shared_ptr<Personaje> agresor,
                   std::shared_ptr<Personaje> defensor) {
    this->agresor = agresor;
    this->defensor = defensor;
}

void CombatEvent::
saveDatosAtaque(std::string ataque, int DMG, bool miss, bool critico) {
    this->ataque = ataque;
    this->DMG = DMG;
    miss_ = miss;
    critico_ = critico;
}

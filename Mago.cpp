#include "Mago.h"

Mago::
Mago(const std::string & nombre) : Personaje(nombre) {
    bonusPATK = getINI("bonus", "mg_bonus_patk");
    bonusMATK = getINI("bonus", "mg_bonus_matk");
    bonusPDEF = getINI("bonus", "mg_bonus_pdef");
    bonusMDEF = getINI("bonus", "mg_bonus_mdef");
}

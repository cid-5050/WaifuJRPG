#include "Barbaro.h"

Barbaro::
Barbaro(const std::string & nombre) : Personaje(nombre){
    bonusPATK = getINI("bonus", "brb_bonus_patk");
    bonusMATK = getINI("bonus", "brb_bonus_matk");
    bonusPDEF = getINI("bonus", "brb_bonus_pdef");
    bonusMDEF = getINI("bonus", "brb_bonus_mdef");

    clase = "Barbaro";
}

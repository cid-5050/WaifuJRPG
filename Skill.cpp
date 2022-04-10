#include "Skill.h"

Skill::Skill(std::string nombre, int coste) {
    this->nombre = nombre;
    this->coste = coste;
}

std::string Skill::
getNombre() const {
    return nombre;
}

int Skill::
getCoste() const {
    return coste;
}

/*int Skill::
perform(std::shared_ptr<Personaje> defensor) {
    //int DMG {static_cast<int>((double(ATK) * 3) * (double(defensor->DEF) / 200.0))};
    int DMG = ATK;
    defensor->HP -= DMG;
    return DMG;
}*/

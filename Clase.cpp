#include "Clase.h"

Clase::
Clase() {
}

int Clase::
getBonusPATK(void) const {
    return bonusPATK;
}

void Clase::
setBonusPATK(int ataque) {
    bonusPATK = ataque;
}

int Clase::
getBonusMATK(void) const {
    return bonusMATK;
}

void Clase::
setBonusMATK(int ataque) {
    bonusMATK = ataque;
}

int Clase::
getBonusPDEF(void) const {
    return bonusPDEF;
}

void Clase::
setBonusPDEF(int defensa) {
    bonusPDEF = defensa;
}

int Clase::
getBonusMDEF(void) const {
    return bonusMDEF;
}

void Clase::
setBonusMDEF(int defensa) {
    bonusMDEF = defensa;
}

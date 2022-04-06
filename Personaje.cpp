#include "Personaje.h"
#include <random>


Personaje::
Personaje(const std::string & name) {
    nombre = name;
}

int Personaje::
getHP(void) const {
    return HP;
}

void Personaje::
setHP(int vida) {
    HP = vida;
}

int Personaje::
getATK(void) const {
    return ATK;
}

void Personaje::
setATK(int ataque) {
    ATK = ataque;
}

int Personaje::
getPATK(void) const {
    return PATK;
}

void Personaje::
setPATK(int ataque) {
    PATK = ataque;
}

int Personaje::
getMATK(void) const {
    return MATK;
}

void Personaje::
setMATK(int ataque) {
    MATK = ataque;
}

int Personaje::
getPDEF(void) const {
    return PDEF;
}

void Personaje::
setPDEF(int defensa) {
    PDEF = defensa;
}

int Personaje::
getMDEF(void) const {
    return MDEF;
}

void Personaje::
setMDEF(int defensa) {
    MDEF = defensa;
}

int Personaje::
getEVA(void) const {
    return EVA;
}

void Personaje::
setEVA(int evasion) {
    EVA = evasion;
}

int Personaje::
getLCK(void) const {
    return LCK;
}

void Personaje::
setLCK(int suerte) {
    LCK = suerte;
}

int Personaje::
getBonusPATK(void) const {
    return bonusPATK;
}

void Personaje::
setBonusPATK(int ataque) {
    bonusPATK = ataque;
}

int Personaje::
getBonusMATK(void) const {
    return bonusMATK;
}

void Personaje::
setBonusMATK(int ataque) {
    bonusMATK = ataque;
}

int Personaje::
getBonusPDEF(void) const {
    return bonusPDEF;
}

void Personaje::
setBonusPDEF(int defensa) {
    bonusPDEF = defensa;
}

int Personaje::
getBonusMDEF(void) const {
    return bonusMDEF;
}

void Personaje::
setBonusMDEF(int defensa) {
    bonusMDEF = defensa;
}

void Personaje::
randomizarStats() {
    std::random_device rd;
    std::default_random_engine defEngine(rd());
    std::uniform_int_distribution<int> intDistro;

    intDistro.param(std::uniform_int_distribution<int>::param_type(MIN_HP, MAX_HP));
    HP = intDistro(defEngine);
    intDistro.param(std::uniform_int_distribution<int>::param_type(MIN_ATK, MAX_ATK));
    ATK = intDistro(defEngine);
    intDistro.param(std::uniform_int_distribution<int>::param_type(MIN_PATK, MAX_PATK));
    PATK = intDistro(defEngine);
    PATK = ((PATK + bonusPATK) > 0) ? (PATK + bonusPATK) : 0;
    intDistro.param(std::uniform_int_distribution<int>::param_type(MIN_MATK, MAX_MATK));
    MATK = intDistro(defEngine);
    MATK = ((MATK + bonusMATK) > 0) ? (MATK + bonusMATK) : 0;
    intDistro.param(std::uniform_int_distribution<int>::param_type(MIN_PDEF, MAX_PDEF));
    PDEF = intDistro(defEngine);
    PDEF = ((PDEF + bonusPDEF) > 0) ? (PDEF + bonusPDEF) : 0;
    intDistro.param(std::uniform_int_distribution<int>::param_type(MIN_MDEF, MAX_MDEF));
    MDEF = intDistro(defEngine);
    MDEF = ((MDEF + bonusMDEF) > 0) ? (MDEF + bonusMDEF) : 0;
    intDistro.param(std::uniform_int_distribution<int>::param_type(MIN_EVA, MAX_EVA));
    EVA = intDistro(defEngine);
    intDistro.param(std::uniform_int_distribution<int>::param_type(MIN_LCK, MAX_LCK));
    LCK = intDistro(defEngine);

}

void Personaje::
printStats() {
    prettyPrint("-", 26, '-');
    std::cout << std::endl;
    prettyPrintFila({"Nombre", nombre}, {8, 8});
    prettyPrint("-", 26, '-');
    std::cout << std::endl;
    prettyPrintFila({"HP", std::to_string(HP)}, {8, 8});
    prettyPrintFila({"ATK", std::to_string(ATK)}, {8, 8});
    prettyPrintFila({"PATK", std::to_string(PATK)}, {8, 8});
    prettyPrintFila({"MATK", std::to_string(MATK)}, {8, 8});
    prettyPrintFila({"PDEF", std::to_string(PDEF)}, {8, 8});
    prettyPrintFila({"MDEF", std::to_string(MDEF)}, {8, 8});
    prettyPrintFila({"EVA", std::to_string(EVA)}, {8, 8});
    prettyPrintFila({"LCK", std::to_string(LCK)}, {8, 8});

    prettyPrint("-", 26, '-');
    std::cout << std::endl;
}

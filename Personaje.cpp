#include "Personaje.h"


Personaje::
Personaje(const std::string & nombre) {
    this->nombre = nombre;

    VIT = 5;
    END = 5;
    INT = 5;
    ATK = 5;
    PDEX = 5;
    MDEX = 5;
    DEF = 5;
    PRES = 5;
    MRES = 5;
    ACC = 5;
    EVA = 5;
    LCK = 5;

    // Total 0 / 240

    maxHP = VIT * 100;
    maxMana = INT * 10;
    maxStamina = END * 10;

    HP = maxHP;
    mana = maxMana;
    stamina = maxStamina;

    clase = "Personaje";
}

std::string Personaje::
getNombre() const {
    return nombre;
}

std::string Personaje::
getClase() const {
    return clase;
}

int Personaje::
getHP() const {
    return HP;
}

void Personaje::
setHP(int vida) {
    HP = vida;
}

int Personaje::
getMana() const {
    return mana;
}

void Personaje::
setMana(int mp) {
    mana = mp;
}

int Personaje::
getStamina() const {
    return stamina;
}

void Personaje::
setStamina(int aguante) {
    stamina = aguante;
}

int Personaje::
getMaxHP() const {
    return maxHP;
}

int Personaje::
getMaxMana() const {
    return maxMana;
}

int Personaje::
getMaxStamina() const {
    return maxStamina;
}


int Personaje::
getVIT() const {
    return VIT;
}

int Personaje::
getEND() const {
    return END;
}

int Personaje::
getINT() const {
    return INT;
}

int Personaje::
getATK() const {
    return ATK;
}

int Personaje::
getPDEX() const {
    return PDEX;
}

int Personaje::
getMDEX() const {
    return MDEX;
}

int Personaje::
getDEF() const {
    return DEF;
}

int Personaje::
getPRES() const {
    return PRES;
}

int Personaje::
getMRES() const {
    return MRES;
}

int Personaje::
getACC() const {
    return ACC;
}

int Personaje::
getEVA() const {
    return EVA;
}

int Personaje::
getLCK() const {
    return LCK;
}


void Personaje::
initStats() {
    std::random_device rd;
    std::default_random_engine defEngine(rd());

    int puntos {100};
    int statMax {100};
    std::uniform_int_distribution<int> intDistro(1, 12);

    while (puntos > 0) {
        switch (intDistro(defEngine)) {
            case 1:
                if (VIT < statMax) {
                    VIT += 5;
                    puntos--;
                }
                break;
            case 2:
                if (END < statMax) {
                    END += 5;
                    puntos--;
                }
                break;
            case 3:
                if (INT < statMax) {
                    INT += 5;
                    puntos--;
                }
                break;
            case 4:
                if (ATK < statMax) {
                    ATK += 5;
                    puntos--;
                }
                break;
            case 5:
                if (PDEX < statMax) {
                    PDEX += 5;
                    puntos--;
                }
                break;
            case 6:
                if (MDEX < statMax) {
                    MDEX += 5;
                    puntos--;
                }
                break;
            case 7:
                if (DEF < statMax) {
                    DEF += 5;
                    puntos--;
                }
                break;
            case 8:
                if (PRES < statMax) {
                    PRES += 5;
                    puntos--;
                }
                break;
            case 9:
                if (MRES < statMax) {
                    MRES += 5;
                    puntos--;
                }
                break;
            case 10:
                if (ACC < statMax) {
                    ACC += 5;
                    puntos--;
                }
                break;
            case 11:
                if (EVA < statMax) {
                    EVA += 5;
                    puntos--;
                }
                break;
            case 12:
                if (LCK < statMax) {
                    LCK += 5;
                    puntos--;
                }
                break;
        }
    }

    maxHP = VIT * 100;
    maxMana = INT * 10;
    maxStamina = END * 10;

    HP = maxHP;
    mana = maxMana;
    stamina = maxStamina;
}


void Personaje::
printStats() const {
    prettyPrint("-", 30, '-');
    std::cout << std::endl;

    prettyPrintFila({"Nombre", nombre}, {10, 10});

    prettyPrint("-", 30, '-');
    std::cout << std::endl;

    prettyPrintFila({"HP", std::to_string(HP)}, {10, 10});
    prettyPrintFila({"Mana", std::to_string(mana)}, {10, 10});
    prettyPrintFila({"Stamina", std::to_string(stamina)}, {10, 10});

    prettyPrint("-", 30, '-');
    std::cout << std::endl;

    prettyPrintFila({"VIT", std::to_string(VIT)}, {10, 10});
    prettyPrintFila({"END", std::to_string(END)}, {10, 10});
    prettyPrintFila({"INT", std::to_string(INT)}, {10, 10});
    prettyPrintFila({"ATK", std::to_string(ATK)}, {10, 10});
    prettyPrintFila({"PDEX", std::to_string(PDEX)}, {10, 10});
    prettyPrintFila({"MDEX", std::to_string(MDEX)}, {10, 10});
    prettyPrintFila({"DEF", std::to_string(DEF)}, {10, 10});
    prettyPrintFila({"PRES", std::to_string(PRES)}, {10, 10});
    prettyPrintFila({"MRES", std::to_string(MRES)}, {10, 10});
    prettyPrintFila({"ACC", std::to_string(ACC)}, {10, 10});
    prettyPrintFila({"EVA", std::to_string(EVA)}, {10, 10});
    prettyPrintFila({"LCK", std::to_string(LCK)}, {10, 10});

    prettyPrint("-", 30, '-');
    std::cout << std::endl;

    prettyPrintFila({"Clase", clase}, {10, 10});

    prettyPrint("-", 30, '-');
    std::cout << std::endl;
}

bool Personaje::
dead() const {
    return (HP <= 0);
}

void Personaje::
recarga() {
    int inc {50};
    if ((mana + inc) <= maxMana)
        mana += inc;
    if ((stamina + inc) <= maxStamina)
        stamina += inc;
}

int Personaje::
ataqueBasico(std::shared_ptr<Personaje> defensor) {
    int DMG {static_cast<int>((double(ATK) * 3) * (double(defensor->DEF) / 200.0))};
    defensor->HP -= DMG;
    return DMG;
}

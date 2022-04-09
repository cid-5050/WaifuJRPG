#include "Mago.h"

Mago::
Mago(const std::string & nombre) : Personaje(nombre) {
    VIT = 20;   // 4
    END = 5;    // 1
    INT = 40;   // 8
    ATK = 10;   // 2
    PDEX = 5;   // 1
    MDEX = 30;  // 6
    DEF = 15;   // 3
    PRES = 10;  // 2
    MRES = 20;  // 4
    ACC = 20;   // 4
    EVA = 20;   // 4
    LCK = 5;    // 1

    // Total 40 / 240

    maxHP = VIT * 100;
    maxMana = INT * 10;
    maxStamina = END * 10;

    HP = maxHP;
    mana = maxMana;
    stamina = maxStamina;

    clase = "Mago";
}

void Mago::
initStats() {
    std::random_device rd;
    std::default_random_engine defEngine(rd());

    int puntos {100};
    int statMax {100};
    std::uniform_int_distribution<int> intDistro(1, 10);

    while (puntos > 0) {
        switch (intDistro(defEngine)) {
            case 1:
                if (VIT < statMax) {
                    VIT += 5;
                    puntos--;
                }
                break;
            case 2:
                if (INT < statMax) {
                    INT += 5;
                    puntos--;
                }
                break;
            case 3:
                if (ATK < statMax) {
                    ATK += 5;
                    puntos--;
                }
                break;
            case 4:
                if (MDEX < statMax) {
                    MDEX += 5;
                    puntos--;
                }
                break;
            case 5:
                if (DEF < statMax) {
                    DEF += 5;
                    puntos--;
                }
                break;
            case 6:
                if (PRES < statMax) {
                    PRES += 5;
                    puntos--;
                }
                break;
            case 7:
                if (MRES < statMax) {
                    MRES += 5;
                    puntos--;
                }
                break;
            case 8:
                if (ACC < statMax) {
                    ACC += 5;
                    puntos--;
                }
                break;
            case 9:
                if (EVA < statMax) {
                    EVA += 5;
                    puntos--;
                }
                break;
            case 10:
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

int Mago::
fireblast(std::shared_ptr<Personaje> defensor) {
    std::random_device rd;
    std::default_random_engine defEngine(rd());
    std::uniform_int_distribution<int> intDistro(1, 100);

    int base {200};
    int coste {200};
    double coef {double(MDEX) / double(defensor->getMRES())};
    int hit_chance {calcularHitChance(ACC, defensor->getEVA())};
    int DMG;


    if (mana < coste)
        return this->ataqueBasico(defensor);
        //throw std::string("Mana insuficiente para realizar 'fireblast'");


    if (intDistro(defEngine) > hit_chance) {
        return 0;
    }

    DMG = (double(base) * coef) + ((double(ATK) * 3) * (double(defensor->getDEF()) / 200.0));

    if (intDistro(defEngine) <= LCK)
        DMG *= 2;

    defensor->setHP(defensor->getHP() - DMG);
    mana -= coste;
    return DMG;
}

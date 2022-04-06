#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include <string>
#include <funciones.h>


class Personaje {
 public:
    explicit Personaje(const std::string & nombre);

    int getHP(void) const;
    void setHP(int vida);
    int getATK(void) const;
    void setATK(int ataque);
    int getPATK(void) const;
    void setPATK(int ataque);
    int getMATK(void) const;
    void setMATK(int ataque);
    int getPDEF(void) const;
    void setPDEF(int defensa);
    int getMDEF(void) const;
    void setMDEF(int defensa);
    int getEVA(void) const;
    void setEVA(int evasion);
    int getLCK(void) const;
    void setLCK(int suerte);

    int getBonusPATK(void) const;
    void setBonusPATK(int ataque);
    int getBonusMATK(void) const;
    void setBonusMATK(int ataque);
    int getBonusPDEF(void) const;
    void setBonusPDEF(int defensa);
    int getBonusMDEF(void) const;
    void setBonusMDEF(int defensa);

    void randomizarStats(void);
    void printStats(void);

 protected:
    std::string nombre;

    int HP;
    int ATK;
    int PATK;
    int MATK;
    int PDEF;
    int MDEF;
    int EVA;
    int LCK;

    int bonusPATK;
    int bonusMATK;
    int bonusPDEF;
    int bonusMDEF;

    const int MAX_HP {getINI("stats", "max_hp")};
    const int MIN_HP {getINI("stats", "min_hp")};
    const int MAX_ATK {getINI("stats", "max_atk")};
    const int MIN_ATK {getINI("stats", "min_atk")};
    const int MAX_PATK {getINI("stats", "max_patk")};
    const int MIN_PATK {getINI("stats", "min_patk")};
    const int MAX_MATK {getINI("stats", "max_matk")};
    const int MIN_MATK {getINI("stats", "min_matk")};
    const int MAX_PDEF {getINI("stats", "max_pdef")};
    const int MIN_PDEF {getINI("stats", "min_pdef")};
    const int MAX_MDEF {getINI("stats", "max_mdef")};
    const int MIN_MDEF {getINI("stats", "min_mdef")};
    const int MAX_EVA {getINI("stats", "max_eva")};
    const int MIN_EVA {getINI("stats", "min_eva")};
    const int MAX_LCK {getINI("stats", "max_lck")};
    const int MIN_LCK {getINI("stats", "min_lck")};
};


#endif // PERSONAJE_H

#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include <string>
#include <random>
#include <funciones.h>


class Personaje {
 public:
    Personaje();
    explicit Personaje(const std::string & nombre);
    //Personaje(const Personaje &);


    std::string getNombre(void) const;
    void setNombre(std::string name);
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
    void printStats(void) const;

    int ataqueBasico(std::shared_ptr<Personaje> defensor);

 protected:
    std::string nombre;
    std::string clase;

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

    int MAX_HP {getINI("stats", "max_hp")};
    int MIN_HP {getINI("stats", "min_hp")};
    int MAX_ATK {getINI("stats", "max_atk")};
    int MIN_ATK {getINI("stats", "min_atk")};
    int MAX_PATK {getINI("stats", "max_patk")};
    int MIN_PATK {getINI("stats", "min_patk")};
    int MAX_MATK {getINI("stats", "max_matk")};
    int MIN_MATK {getINI("stats", "min_matk")};
    int MAX_PDEF {getINI("stats", "max_pdef")};
    int MIN_PDEF {getINI("stats", "min_pdef")};
    int MAX_MDEF {getINI("stats", "max_mdef")};
    int MIN_MDEF {getINI("stats", "min_mdef")};
    int MAX_EVA {getINI("stats", "max_eva")};
    int MIN_EVA {getINI("stats", "min_eva")};
    int MAX_LCK {getINI("stats", "max_lck")};
    int MIN_LCK {getINI("stats", "min_lck")};
};


#endif // PERSONAJE_H

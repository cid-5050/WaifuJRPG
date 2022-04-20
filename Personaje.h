#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include <string>
#include <random>
#include <funciones.h>
#include <Skill.h>
#include <CombatEvent.h>


class Skill;
class CombatEvent;

class Personaje {
 public:
    explicit Personaje(const std::string & nombre);


    std::string getNombre(void) const;
    std::string getClase(void) const;

    int getHP(void) const;
    void setHP(int vida);
    int getMana(void) const;
    void setMana(int mp);
    int getStamina(void) const;
    void setStamina(int aguante);

    int getMaxHP(void) const;
    int getMaxMana(void) const;
    int getMaxStamina(void) const;

    int getVIT(void) const;
    int getEND(void) const;
    int getINT(void) const;
    int getATK(void) const;
    int getPDEX(void) const;
    int getMDEX(void) const;
    int getDEF(void) const;
    int getPRES(void) const;
    int getMRES(void) const;
    int getACC(void) const;
    int getEVA(void) const;
    int getLCK(void) const;

    std::shared_ptr<Personaje> getAdversario(void) const;
    void setAdversario(std::shared_ptr<Personaje> adversario);


    virtual void initStats(void);
    void printStats(void) const;

    bool dead(void) const;

    void recarga(void);

    int ataqueBasico(void) const;

    std::shared_ptr<Skill> ataqueAleatorio(void) const;

    virtual void actuar(std::shared_ptr<CombatEvent> evento) = 0;


 protected:
    std::string nombre;
    std::string clase;

    int HP;
    int maxHP;
    int mana;
    int maxMana;
    int stamina;
    int maxStamina;

    int VIT;    // Afecta HP
    int END;    // Afecta stamina
    int INT;    // Afecta mana
    int ATK;    // Afecta todos los ataques
    int PDEX;   // Afecta ataques físicos
    int MDEX;   // Afecta ataques mágicos
    int DEF;    // Afecta todos los ataques
    int PRES;   // Afecta ataques físicos
    int MRES;   // Afecta ataques mágicos
    int ACC;    // Afecta probabilidad de acertar
    int EVA;    // Afecta probabilidad de evadir
    int LCK;    // Afecta probabilidad de críticos y RNG

    std::shared_ptr<Personaje> adversario;

    std::vector<std::shared_ptr<Skill>> ataques;

 private:
    /*
    std::function<int(std::shared_ptr<Personaje>)>
    ataqueBasico = [this] (std::shared_ptr<Personaje> defensor) {
        //int DMG = ATK;
        int DMG {static_cast<int>((double(ATK) * 3) * (double(defensor->DEF) / 200.0))};
        return DMG;
    };
    */
};


#endif // PERSONAJE_H

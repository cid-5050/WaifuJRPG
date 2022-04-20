#ifndef COMBATEVENT_H
#define COMBATEVENT_H

#include <Personaje.h>

class Personaje;

class CombatEvent {
 public:
    CombatEvent(int turno, std::shared_ptr<Personaje>);

    bool critico(void) const;
    bool miss(void) const;
    int getDMG(void) const;
    std::string getAtaque(void) const;
    std::shared_ptr<Personaje> getPersonaje(void) const;
    void saveDatosAtaque(std::string ataque, int DMG, bool miss, bool critico);

 protected:
    int turno;
    std::shared_ptr<Personaje> personaje;
    std::string ataque;
    int DMG;
    bool miss_;
    bool critico_;
};

#endif // COMBATEVENT_H

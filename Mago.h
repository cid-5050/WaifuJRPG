#ifndef MAGO_H
#define MAGO_H

#include <Personaje.h>


class Mago : public Personaje {

  public:
    using Personaje::Personaje;
    explicit Mago(const std::string & nombre);

    void initStats(void);

    int ataque(std::shared_ptr<Personaje> defensor, std::shared_ptr<CombatEvent> evento);
    int fireblast(std::shared_ptr<Personaje> defensor, std::shared_ptr<CombatEvent> evento);

};

#endif // MAGO_H

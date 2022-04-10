#ifndef BARBARO_H
#define BARBARO_H

#include <Personaje.h>


class Barbaro : public Personaje {

  public:
    using Personaje::Personaje;
    explicit Barbaro(const std::string & nombre);

    void initStats(void);

    int ataque(std::shared_ptr<Personaje> defensor, std::shared_ptr<CombatEvent> evento);
    int slash(std::shared_ptr<Personaje> defensor, std::shared_ptr<CombatEvent> evento);

};

#endif // BARBARO_H

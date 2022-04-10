#ifndef WAIFUJRPG_H
#define WAIFUJRPG_H

#include <Mago.h>
#include <Barbaro.h>
#include <memory>


class WaifuJRPG {
  public:
    WaifuJRPG();

    std::shared_ptr<Personaje> p1;
    std::shared_ptr<Personaje> p2;

    int getTurno(void) const;

    std::shared_ptr<CombatEvent> evento(void) const;
    void next(void);

  private:
    int turno {0};
    std::vector<std::shared_ptr<CombatEvent>> eventos;


};

#endif // WAIFUJRPG_H

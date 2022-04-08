#ifndef WAIFUJRPG_H
#define WAIFUJRPG_H

#include <Mago.h>
#include <Barbaro.h>
#include <memory>


class WaifuJRPG {
  public:
    WaifuJRPG();

    void next(void);

    std::shared_ptr<Personaje> p1;
    std::shared_ptr<Personaje> p2;

  private:
    int turno {1};


};

#endif // WAIFUJRPG_H

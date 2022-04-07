#ifndef WAIFUJRPG_H
#define WAIFUJRPG_H

#include <Mago.h>
#include <Barbaro.h>

class WaifuJRPG {
  public:
    WaifuJRPG();

    void next(void);

    Personaje p1;
    Personaje p2;

  private:
    int turno {1};


};

#endif // WAIFUJRPG_H

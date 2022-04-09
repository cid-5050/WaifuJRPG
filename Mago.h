#ifndef MAGO_H
#define MAGO_H

#include <Personaje.h>


class Mago : public Personaje {

  public:
    using Personaje::Personaje;
    explicit Mago(const std::string & nombre);

    void initStats(void);

    int ataqueMagico(std::shared_ptr<Personaje> defensor);

};

#endif // MAGO_H

#ifndef MAGO_H
#define MAGO_H

#include <Personaje.h>


class Mago : public Personaje {

  public:
    using Personaje::Personaje;
    explicit Mago(const std::string & nombre);

};

#endif // MAGO_H

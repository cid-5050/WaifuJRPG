#ifndef BARBARO_H
#define BARBARO_H

#include <Personaje.h>


class Barbaro : public Personaje {

  public:
    using Personaje::Personaje;
    explicit Barbaro(const std::string & nombre);

    void initStats(void);

};

#endif // BARBARO_H

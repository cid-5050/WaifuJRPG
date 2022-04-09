#ifndef BARBARO_H
#define BARBARO_H

#include <Personaje.h>


class Barbaro : public Personaje {

  public:
    using Personaje::Personaje;
    explicit Barbaro(const std::string & nombre);

    void initStats(void);

    int slash(std::shared_ptr<Personaje> defensor);

};

#endif // BARBARO_H

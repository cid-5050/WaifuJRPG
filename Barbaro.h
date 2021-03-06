#ifndef BARBARO_H
#define BARBARO_H

#include <Personaje.h>


class Barbaro : public Personaje {

 public:
    using Personaje::Personaje;
    explicit Barbaro(const std::string & nombre);

    void initStats(void);

    //int slash(std::shared_ptr<Personaje> defensor);

    void actuar(std::shared_ptr<CombatEvent> evento);


 private:
    std::shared_ptr<std::function<int(void)>>
    slash = std::make_shared<std::function<int(void)>>(
        [this] (void) {
            int DMG;
            int base {200};
            double coef {double(PDEX) / double(adversario->getPRES())};

            DMG = (double(base) * coef) + ((double(ATK) * 3) * (double(adversario->getDEF()) / 200.0));
            return DMG;
        }
    );
};

#endif // BARBARO_H

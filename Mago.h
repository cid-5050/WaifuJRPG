#ifndef MAGO_H
#define MAGO_H

#include <Personaje.h>


class Mago : public Personaje {

 public:
    using Personaje::Personaje;
    explicit Mago(const std::string & nombre);

    void initStats(void);

    //int fireblast(std::shared_ptr<Personaje> defensor);

    void actuar(std::shared_ptr<CombatEvent> evento);


 private:
    std::shared_ptr<std::function<int(void)>>
    fireblast = std::make_shared<std::function<int(void)>>(
        [this] (void) {
            int DMG;
            int base {200};
            double coef {double(MDEX) / double(adversario->getMRES())};

            DMG = (double(base) * coef) + ((double(ATK) * 3) * (double(adversario->getDEF()) / 200.0));
            return DMG;
        }
    );
};

#endif // MAGO_H

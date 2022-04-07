#include "WaifuJRPG.h"
#include <funciones.h>
#include <memory>


WaifuJRPG::
WaifuJRPG() {
    p1 = Mago(nombreAleatorio("nombres-a.txt"));
    p2 = Barbaro(nombreAleatorio("nombres-b.txt"));

    p1.randomizarStats();
    p2.randomizarStats();
}

void WaifuJRPG::
next() {
    std::shared_ptr<Personaje> agresor;
    std::shared_ptr<Personaje> defensor;

    if (turno % 2 == 0) {
        agresor = std::make_shared<Personaje>(p1);
        defensor = std::make_shared<Personaje>(p2);
    } else {
        agresor = std::make_shared<Personaje>(p2);
        defensor = std::make_shared<Personaje>(p1);
    }

    std::cout << "Turno: " << turno << std::endl;
    std::cout << agresor->getNombre() << " realiza Ataque Basico contra "
              << defensor->getNombre() << std::endl;
    std::cout << defensor->getNombre() << " recibe "
              << agresor->ataqueBasico(defensor) << " puntos de DMG." << std::endl;

    turno++;
}

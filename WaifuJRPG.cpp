#include "WaifuJRPG.h"
#include <funciones.h>


WaifuJRPG::
WaifuJRPG() {
    p1 = std::make_shared<Personaje>(Mago(nombreAleatorio("nombres-a.txt")));
    p2 = std::make_shared<Personaje>(Barbaro(nombreAleatorio("nombres-b.txt")));

    p1->initStats();
    p2->initStats();
}

void WaifuJRPG::
next() {
    std::shared_ptr<Personaje> agresor;
    std::shared_ptr<Personaje> defensor;

    if (turno % 2 == 0) {
        agresor = p1;
        defensor = p2;
    } else {
        agresor = p2;
        defensor = p1;
    }

    std::cout << "Turno: " << turno << std::endl;
    std::cout << agresor->getNombre() << " realiza Ataque Basico contra "
              << defensor->getNombre() << std::endl;
    std::cout << defensor->getNombre() << " recibe "
              << "agresor->ataqueBasico(defensor)" << " puntos de DMG." << std::endl;

    if (defensor->dead()) {
        std::cout << defensor->getNombre() << " ha muerto!" << std::endl;
    }

    turno++;
}

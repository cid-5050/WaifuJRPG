#include <iostream>
// #include <Mago.h>
// #include <Barbaro.h>
#include <WaifuJRPG.h>
#include <CombatEvent.h>
#include <funciones.h>
#include <memory>


int main() {

    std::shared_ptr<Personaje> mago = std::make_shared<Mago>(Mago(nombreAleatorio("nombres-a.txt")));
    std::shared_ptr<Personaje> barbaro = std::make_shared<Barbaro>(Barbaro(nombreAleatorio("nombres-b.txt")));

    std::vector<std::shared_ptr<CombatEvent>> eventos;

    mago->initStats();
    barbaro->initStats();

    mago->printStats();
    std::cout << std::endl;
    barbaro->printStats();
    std::cout << std::endl;


    int turno {0};
    std::shared_ptr<Personaje> agresor;
    std::shared_ptr<Personaje> defensor;
    std::shared_ptr<CombatEvent> evento {std::make_shared<CombatEvent>(CombatEvent(turno))};

    while (true) {
        if (turno % 2 == 0) {
            agresor = mago;
            defensor = barbaro;
        } else {
            agresor = barbaro;
            defensor = mago;
        }

        agresor->recarga();
        agresor->ataque(defensor, evento);

        std::cout << "Turno: " << turno << std::endl;

        std::cout << agresor->getNombre() << " utiliza '" << evento->getAtaque()
                  << "' contra " << defensor->getNombre() << "...";

        if (evento->miss()) {
            std::cout << " pero ha fallado." << std::endl;
        } else {
            std::cout << std::endl;
            if (evento->critico())
                std::cout << "Es critico!" << std::endl;

            std::cout << defensor->getNombre() << " recibe "
                      << evento->getDMG() << " puntos de DMG." << std::endl;
        }

        std::cout << std::endl;

        if (defensor->dead()) {
            std::cout << defensor->getNombre() << " ha muerto!" << std::endl;
            break;
        }

        turno++;
    }

    std::cout << agresor->getNombre() << " es la vencedora!" << std::endl;
    std::cout << std::endl;

    return 0;
}

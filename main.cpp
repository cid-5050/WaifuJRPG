#include <iostream>
// #include <Mago.h>
// #include <Barbaro.h>
#include <WaifuJRPG.h>
#include <funciones.h>
#include <memory>


int main() {

    std::shared_ptr<Mago> mago = std::make_shared<Mago>(Mago(nombreAleatorio("nombres-a.txt")));
    std::shared_ptr<Barbaro> barbaro = std::make_shared<Barbaro>(Barbaro(nombreAleatorio("nombres-b.txt")));

    std::shared_ptr<Mago> mago2 = std::make_shared<Mago>(Mago(nombreAleatorio("nombres-a.txt")));


    mago->initStats();
    mago2->initStats();

    mago->printStats();
    std::cout << std::endl;
    mago2->printStats();
    std::cout << std::endl;


    int turno {0};
    std::shared_ptr<Mago> agresor;
    std::shared_ptr<Mago> defensor;

    while (true) {
        if (turno % 2 == 0) {
            agresor = mago;
            defensor = mago2;
        } else {
            agresor = mago2;
            defensor = mago;
        }

        agresor->recarga();

        std::cout << "Turno: " << turno << std::endl;
        std::cout << agresor->getNombre() << " utiliza Fireblast contra "
                  << defensor->getNombre() << std::endl;
        std::cout << defensor->getNombre() << " recibe "
                  << agresor->fireblast(defensor) << " puntos de DMG." << std::endl;

        std::cout << std::endl;

        if (defensor->dead()) {
            std::cout << defensor->getNombre() << " ha muerto!" << std::endl;
            break;
        }

        turno++;
    }

    std::cout << agresor->getNombre() << " es la vencedora!" << std::endl;

    return 0;
}

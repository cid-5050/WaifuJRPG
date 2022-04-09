#include <iostream>
// #include <Mago.h>
// #include <Barbaro.h>
#include <WaifuJRPG.h>
#include <funciones.h>
#include <memory>


int main() {

    std::shared_ptr<Mago> mago = std::make_shared<Mago>(Mago(nombreAleatorio("nombres-a.txt")));
    std::shared_ptr<Barbaro> barbaro = std::make_shared<Barbaro>(Barbaro(nombreAleatorio("nombres-b.txt")));

    mago->initStats();
    barbaro->initStats();

    mago->printStats();
    std::cout << std::endl;
    barbaro->printStats();
    std::cout << std::endl;


    int turno {0};
    std::shared_ptr<Personaje> agresor;
    std::shared_ptr<Personaje> defensor;

    while (true) {
        if (turno % 2 == 0) {
            agresor = mago;
            defensor = barbaro;
        } else {
            agresor = barbaro;
            defensor = mago;
        }

        std::cout << "Turno: " << turno << std::endl;
        std::cout << agresor->getNombre() << " realiza Ataque Basico contra "
                  << defensor->getNombre() << std::endl;
        std::cout << defensor->getNombre() << " recibe "
                  << agresor->ataqueBasico(defensor) << " puntos de DMG." << std::endl;

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

#include <iostream>
// #include <Mago.h>
// #include <Barbaro.h>
#include <WaifuJRPG.h>
#include <CombatEvent.h>
#include <funciones.h>
#include <memory>


int main() {

    /*std::shared_ptr<Personaje> mago = std::make_shared<Mago>(Mago(nombreAleatorio("nombres-a.txt")));
    std::shared_ptr<Personaje> barbaro = std::make_shared<Barbaro>(Barbaro(nombreAleatorio("nombres-b.txt")));

    mago->initStats();
    barbaro->initStats();

    mago->printStats();
    std::cout << std::endl;
    barbaro->printStats();
    std::cout << std::endl;
    */

    WaifuJRPG game;

    game.p1->printStats();
    std::cout << std::endl;
    game.p2->printStats();
    std::cout << std::endl;

    while (true) {
        game.next();

        std::cout << "Turno: " << game.getTurno() << std::endl;

        std::cout << game.evento()->getAgresor()->getNombre()
                  << " utiliza '" << game.evento()->getAtaque()
                  << "' contra " << game.evento()->getDefensor()->getNombre() << "...";

        if (game.evento()->miss()) {
            std::cout << " pero ha fallado." << std::endl;
        } else {
            std::cout << std::endl;
            if (game.evento()->critico())
                std::cout << "Es critico!" << std::endl;

            std::cout << game.evento()->getDefensor()->getNombre() << " recibe "
                      << game.evento()->getDMG() << " puntos de DMG." << std::endl;
        }

        std::cout << std::endl;

        if (game.evento()->getDefensor()->dead()) {
            std::cout << game.evento()->getDefensor()->getNombre()
                      << " ha muerto!" << std::endl;
            break;
        }
    }

    std::cout << game.evento()->getAgresor()->getNombre()
              << " es la vencedora!" << std::endl;
    std::cout << std::endl;

    return 0;
}

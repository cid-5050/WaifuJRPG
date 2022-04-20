#include <iostream>
#include <WaifuJRPG.h>
#include <CombatEvent.h>
#include <funciones.h>


int main() {

    WaifuJRPG game;

    game.setPrinter(10, 20, 15);

    std::cout << game.margen() << "Contrincantes:" << std::endl;
    std::cout << std::endl;

    game.printStats();

    std::cin.get();
    std::system("cls");


    while (true) {
        game.next();

        std::cout << game.margen();
        std::cout << "TURNO " << game.getTurno() << std::endl;
        std::cout << std::endl;

        game.printStats();
        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << game.margen();
        std::cout << game.evento()->getPersonaje()->getNombre()
                  << " utiliza '" << game.evento()->getAtaque() << "' contra "
                  << game.evento()->getPersonaje()->getAdversario()->getNombre() << "...";

        if (game.evento()->miss()) {
            std::cout << " pero ha fallado." << std::endl;
        } else {
            std::cout << std::endl;
            if (game.evento()->critico()) {
                std::cout << game.margen();
                std::cout << "Es critico!" << std::endl;
            }

            std::cout << game.margen();
            std::cout << game.evento()->getPersonaje()->getAdversario()->getNombre()
                      << " recibe " << game.evento()->getDMG()
                      << " puntos de DMG." << std::endl;
        }

        std::cout << std::endl;

        std::cout << game.margen();
        if (game.evento()->getPersonaje()->getAdversario()->dead()) {
            std::cout << game.evento()->getPersonaje()->getAdversario()->getNombre()
                      << " ha muerto!" << std::endl;
            break;

        } else {
            // system() se considera "sucio" e inseguro, pero...
            std::cin.get();
            std::system("cls");
        }
    }

    std::cout << game.margen();
    std::cout << game.evento()->getPersonaje()->getNombre()
              << " es la vencedora!" << std::endl;
    std::cout << std::endl;

    return 0;
}

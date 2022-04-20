#include <iostream>
#include <WaifuJRPG.h>
#include <CombatEvent.h>
#include <funciones.h>
#include <memory>


int main() {

    WaifuJRPG game;

    std::cout << "Contrincantes: " << std::endl;
    std::cout << std::endl;

    game.p1->printStats();
    std::cout << std::endl;
    game.p2->printStats();
    std::cout << std::endl;

    std::cin.get();
    std::system("cls");


    while (true) {
        game.next();

        std::cout << "Turno: " << game.getTurno() << std::endl;
        std::cout << std::endl;

        game.p1->printStats();
        std::cout << std::endl;
        game.p2->printStats();
        std::cout << std::endl;

        std::cout << game.evento()->getPersonaje()->getNombre()
                  << " utiliza '" << game.evento()->getAtaque() << "' contra "
                  << game.evento()->getPersonaje()->getAdversario()->getNombre() << "...";

        if (game.evento()->miss()) {
            std::cout << " pero ha fallado." << std::endl;
        } else {
            std::cout << std::endl;
            if (game.evento()->critico())
                std::cout << "Es critico!" << std::endl;

            std::cout << game.evento()->getPersonaje()->getAdversario()->getNombre()
                      << " recibe " << game.evento()->getDMG()
                      << " puntos de DMG." << std::endl;
        }

        std::cout << std::endl;

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

    std::cout << game.evento()->getPersonaje()->getNombre()
              << " es la vencedora!" << std::endl;
    std::cout << std::endl;

    return 0;
}

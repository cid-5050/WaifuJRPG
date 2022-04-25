#include <iostream>
#include <WaifuJRPG.h>
#include <CombatEvent.h>
#include <funciones.h>


int main() {

    WaifuJRPG game;

    game.titleScreen();
    std::cout << ">> ";
    std::cin.get();
    std::system("cls");

    game.setPrinter(10, 15, 15);

    game.fullStats1v1();
    game.print();


    do {
        // system() se considera "sucio" e inseguro, pero...
        std::cin.get();
        std::system("cls");

        game.next();

        game.printer() << std::endl;
        game.margen();
        game.printer() << "TURNO " << game.getTurno() << std::endl;
        game.printer() << std::endl;

        game.miniStats1v1();
        game.printer() << std::endl;
        game.printer() << std::endl;

        game.margen();
        game.printer() << game.evento()->getPersonaje()->getNombre()
                       << " utiliza '" << game.evento()->getAtaque() << "' contra "
                       << game.evento()->getPersonaje()->getAdversario()->getNombre() << "...";

        if (game.evento()->miss()) {
            game.printer() << " pero ha fallado." << std::endl;
        } else {
            game.printer() << std::endl;
            if (game.evento()->critico()) {
                game.margen();
                game.printer() << "Es critico!" << std::endl;
            }

            game.margen();
            game.printer() << game.evento()->getPersonaje()->getAdversario()->getNombre()
                           << " recibe " << game.evento()->getDMG()
                           << " puntos de DMG." << std::endl;
        }

        game.printer() << std::endl;

        game.print();

    } while (not game.evento()->getPersonaje()->getAdversario()->dead());

    std::system("cls");

    game.printer() << std::endl;
    game.margen();
    game.printer() << "TURNO " << game.getTurno() << std::endl;
    game.printer() << std::endl;

    game.miniStats1v1();
    game.printer() << std::endl;
    game.printer() << std::endl;

    game.margen();
    game.printer() << game.evento()->getPersonaje()->getAdversario()->getNombre()
                   << " ha muerto!" << std::endl;
    game.printer() << std::endl;

    game.margen();
    game.printer() << game.evento()->getPersonaje()->getNombre()
                   << " es la vencedora!" << std::endl;
    game.printer() << std::endl;

    game.print();

    return 0;
}

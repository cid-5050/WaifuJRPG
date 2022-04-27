#include <iostream>
#include <WaifuJRPG.h>
#include <CombatEvent.h>
#include <funciones.h>


int main() {
    system("Color E0");

    WaifuJRPG game;
    std::string comando;

    game.titleScreen();
    std::cout << ">> ";
    getline(std::cin, comando);
    std::system("cls");

    game.setPrinter(10, 15, 15);

    game.fullStats1v1();
    game.print();


    do {
        getline(std::cin, comando);

        std::system("cls");


        switch (game.command(comando)) {
        case 1:
            game.next();

            game.printer() << std::endl;
            game.printer() << std::endl;

            game.miniStats1v1();
            game.printer() << std::endl;
            game.printer() << std::endl;

            game.printer() << game.evento()->getPersonaje()->getNombre()
                           << " utiliza '" << game.evento()->getAtaque() << "' contra "
                           << game.evento()->getPersonaje()->getAdversario()->getNombre() << "...";

            if (game.evento()->miss()) {
                game.printer() << " pero ha fallado." << std::endl;
            } else {
                game.printer() << std::endl;
                if (game.evento()->critico()) {
                    game.printer() << "Es critico!" << std::endl;
                }

                game.printer() << game.evento()->getPersonaje()->getAdversario()->getNombre()
                               << " recibe " << game.evento()->getDMG()
                               << " puntos de DMG." << std::endl;
            }

            game.printer() << std::endl;

            break;

        case 2:
            game.printer() << std::endl;
            game.printer() << std::endl;
            game.printer() << std::endl;
            game.statsGlobales();

            break;
        case 3:
            game.statsPersonaje(game.getPersonaje(comando));

            break;

        case 4:
            game.printer() << std::endl << std::endl << std::endl << std::endl;
            game.printerColor("purple");
            game.printer() << "Adios!" << std::endl;

            break;

        default:
            game.printer() << std::endl;
            game.printer() << std::endl;
            game.printer() << std::endl;
            game.printer() << "Comandos disponsibles:" << std::endl;
            game.printer() << std::endl;
            game.printer() << std::left << std::setw(20) << "next";
            game.printer() << "Avanza al siguiente turno" << std::endl;
            game.printer() << std::left << std::setw(20) << "[nombre]";
            game.printer() << "Muestra los stats del personaje" << std::endl;
            game.printer() << std::left << std::setw(20) << "game";
            game.printer() << "Muestra todos los personajes" << std::endl;
            game.printer() << std::left << std::setw(20) << "help";
            game.printer() << "Muestra los comandos disponibles" << std::endl;
            game.printer() << std::left << std::setw(20) << "exit";
            game.printer() << "Sale del juego" << std::endl;

            break;
        }

        game.print();

    } while (not game.evento()->getPersonaje()->getAdversario()->dead());

    std::system("cls");

    game.printer() << std::endl;
    game.printer() << std::endl;

    game.miniStats1v1();
    game.printer() << std::endl;
    game.printer() << std::endl;

    game.printer() << game.evento()->getPersonaje()->getAdversario()->getNombre()
                   << " ha muerto!" << std::endl;
    game.printer() << std::endl;

    game.printer() << game.evento()->getPersonaje()->getNombre()
                   << " es la vencedora!" << std::endl;
    game.printer() << std::endl;

    game.print();

    return 0;
}

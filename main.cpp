#include <iostream>
#include <Mago.h>
#include <Barbaro.h>
#include <funciones.h>


int main() {

    Mago mago(nombreAleatorio("nombres-a.txt"));
    Barbaro barbaro(nombreAleatorio("nombres-b.txt"));
    Mago mago2(nombreAleatorio("nombres-a.txt"));
    Barbaro barbaro2(nombreAleatorio("nombres-b.txt"));

    mago.randomizarStats();
    barbaro.randomizarStats();
    mago2.randomizarStats();
    barbaro2.randomizarStats();

    mago.printStats();
    std::cout << std::endl;
    barbaro.printStats();
    std::cout << std::endl;
    mago2.printStats();
    std::cout << std::endl;
    barbaro2.printStats();
    std::cout << std::endl;


    return 0;
}

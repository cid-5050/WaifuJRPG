#include <iostream>
#include <Mago.h>
#include <Barbaro.h>


int main() {

    Mago mago("Megumin");
    Barbaro barbaro("Conan");
    Mago mago2("Roxy");
    Barbaro barbaro2("Rudeus");

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

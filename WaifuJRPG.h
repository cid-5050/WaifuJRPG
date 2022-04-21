#ifndef WAIFUJRPG_H
#define WAIFUJRPG_H

#include <Mago.h>
#include <Barbaro.h>
#include <memory>
//#include <sstream>


class WaifuJRPG {
  public:
    WaifuJRPG();

    int getTurno(void) const;

    std::shared_ptr<CombatEvent> evento(void) const;
    std::shared_ptr<Personaje> miembroAleatorio(
            std::shared_ptr<std::vector<std::shared_ptr<Personaje>>>) const;
    void next(void);

    void setPrinter(int wCol, int wMrg, int wSpc);

    void printStats(void) const;
    std::string margen(void) const;
    void titleScreen(void) const;

  private:
    int turno {0};
    std::shared_ptr<std::vector<std::shared_ptr<Personaje>>> partyA
    {std::make_shared<std::vector<std::shared_ptr<Personaje>>>()};
    std::shared_ptr<std::vector<std::shared_ptr<Personaje>>> partyB
    {std::make_shared<std::vector<std::shared_ptr<Personaje>>>()};
    std::vector<std::shared_ptr<CombatEvent>> eventos;
    PrinterPareja printer;


};

#endif // WAIFUJRPG_H

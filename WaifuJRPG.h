#ifndef WAIFUJRPG_H
#define WAIFUJRPG_H

#include <Mago.h>
#include <Barbaro.h>
#include <Printer.h>
#include <memory>


class WaifuJRPG {
  public:
    WaifuJRPG();

    int getTurno(void) const;

    std::shared_ptr<CombatEvent> evento(void) const;
    std::shared_ptr<Personaje> miembroAleatorio(
            std::shared_ptr<std::vector<std::shared_ptr<Personaje>>>) const;
    void next(void);

    std::stringstream & printer(void);
    void setPrinter(int wCol, int wMrg, int wSpc);

    //void printStats(void) const;
    void fullStats1v1(void);
    void miniStats1v1(void);
    void margen(void);
    void titleScreen(void) const;
    void updateScreen(std::stringstream & o) const;
    void print(void);
    int command(const std::string & comando);

    bool existePersonaje(const std::string & nombre) const;
    std::shared_ptr<Personaje> getPersonaje(const std::string & nombre) const;
    void statsPersonaje(std::shared_ptr<Personaje>);
    void statsGlobales(void);

  private:
    int turno;
    std::shared_ptr<std::vector<std::shared_ptr<Personaje>>> partyA
    {std::make_shared<std::vector<std::shared_ptr<Personaje>>>()};
    std::shared_ptr<std::vector<std::shared_ptr<Personaje>>> partyB
    {std::make_shared<std::vector<std::shared_ptr<Personaje>>>()};
    std::vector<std::shared_ptr<CombatEvent>> eventos;
    Printer printer_;
};

#endif // WAIFUJRPG_H

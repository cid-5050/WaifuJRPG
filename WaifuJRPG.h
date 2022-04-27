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

    void readNombres(const std::string & filepath);
    std::string nombreAleatorio(void);

    std::shared_ptr<CombatEvent> evento(void) const;

    std::shared_ptr<std::vector<std::shared_ptr<Personaje>>>
    formarEquipoAleatorio(int numIntegrantes);

    std::shared_ptr<Personaje> miembroAleatorio(
            std::shared_ptr<std::vector<std::shared_ptr<Personaje>>>) const;
    void next(void);

    std::stringstream & printer(void);
    void setPrinter(int wCol, int wMrg, int wSpc);
    void printerColor(const std::string & color);

    //void printStats(void) const;
    void fullStats1v1(void);
    void miniStats1v1(void);
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
    std::vector<std::string> nombres;
    std::shared_ptr<std::vector<std::shared_ptr<Personaje>>> equipoA;
    std::shared_ptr<std::vector<std::shared_ptr<Personaje>>> equipoB;
    std::vector<std::shared_ptr<CombatEvent>> eventos;
    Printer printer_;
};

#endif // WAIFUJRPG_H

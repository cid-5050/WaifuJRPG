#include "Skill.h"

Skill::
Skill(std::string nombre,
      int coste,
      std::shared_ptr<std::function<int(std::shared_ptr<Personaje>)>> func)
{
    this->nombre = nombre;
    this->coste = coste;
    this->func = func;
    tipo = "Skill";
}

MagicSkill::
MagicSkill(std::string nombre,
           int coste,
           std::shared_ptr<std::function<int(std::shared_ptr<Personaje>)>> func
           ) : Skill(nombre, coste, func)
{
    tipo = "Magico";
}

PhysSkill::
PhysSkill(std::string nombre,
           int coste,
           std::shared_ptr<std::function<int(std::shared_ptr<Personaje>)>> func
           ) : Skill(nombre, coste, func)
{
    tipo = "Fisico";
}

std::string Skill::
getNombre() const {
    return nombre;
}

int Skill::
getCoste() const {
    return coste;
}

std::string Skill::
getTipo(void) const {
    return tipo;
}

int Skill::
perform(std::shared_ptr<Personaje> defensor) {
    return (*func)(defensor);
}

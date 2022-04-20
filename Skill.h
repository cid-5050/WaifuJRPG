#ifndef SKILL_H
#define SKILL_H

#include <string>
#include <functional>
#include <Personaje.h>

class Personaje;


class Skill {

 public:
    Skill(std::string nombre,
          int coste,
          std::shared_ptr<std::function<int(std::shared_ptr<Personaje>)>> func);

    std::string getNombre(void) const;
    int getCoste(void) const;
    std::string getTipo(void) const;


    int perform(std::shared_ptr<Personaje> defensor);


 protected:
    std::string nombre;
    int coste;
    std::shared_ptr<std::function<int(std::shared_ptr<Personaje>)>> func;
    std::string tipo;
};


class MagicSkill : public Skill {

 public:
    using Skill::Skill;
    MagicSkill(std::string nombre,
               int coste,
               std::shared_ptr<std::function<int(std::shared_ptr<Personaje>)>> func);
};


class PhysSkill : public Skill {

 public:
    using Skill::Skill;
    PhysSkill(std::string nombre,
               int coste,
               std::shared_ptr<std::function<int(std::shared_ptr<Personaje>)>> func);
};


#endif // SKILL_H

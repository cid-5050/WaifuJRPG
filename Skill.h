#ifndef SKILL_H
#define SKILL_H

#include <string>
//#include <Personaje.h>

class Skill {

 public:
    Skill(std::string nombre, int coste);

    std::string getNombre(void) const;
    int getCoste(void) const;

    //virtual int perform(std::shared_ptr<Personaje> defensor);


 protected:
    std::string nombre;
    int coste;
};

class MagicSkill : public Skill {

 public:



 protected:
    std::string tipo;
};

#endif // SKILL_H

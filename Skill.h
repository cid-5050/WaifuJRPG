#ifndef SKILL_H
#define SKILL_H

#include <string>

class Skill {

 public:
    Skill(std::string nombre, int coste);


 protected:
    std::string nombre;
    int coste;
};

class SkillMagica : public Skill {

 public:



 protected:
    std::string tipo;
};

#endif // SKILL_H

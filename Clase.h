#ifndef CLASE_H
#define CLASE_H


class Clase {
  public:
    Clase();

    int getBonusPATK(void) const;
    void setBonusPATK(int ataque);
    int getBonusMATK(void) const;
    void setBonusMATK(int ataque);
    int getBonusPDEF(void) const;
    void setBonusPDEF(int defensa);
    int getBonusMDEF(void) const;
    void setBonusMDEF(int defensa);

  protected:
    int bonusPATK;
    int bonusMATK;
    int bonusPDEF;
    int bonusMDEF;
};

#endif // CLASE_H

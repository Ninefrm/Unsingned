#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Obj.h"

struct Enemy{
  public:
    Enemy();
    int coordX() const;
    int coordY() const;
    int MaxW() const;
    int MaxH() const;
  private:
    Obj E;
    int maxwidth; //Ancho maximo
    int maxheight; //Alto maximo
    char e=64;
};
#endif

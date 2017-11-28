#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Obj.h"

struct Enemy{
  public:
    Enemy();
    int MaxW() const;
    int MaxH() const;
    Obj E;
  private:
    int maxwidth; //Ancho maximo
    int maxheight; //Alto maximo
    char e=64;
};
#endif

#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "Obj.h"
#include "Enemy.h"

struct Character{
  public:
    Character();
    ~Character();
    void MoveCharacter();
    char Empty();
    bool Q();
    bool Collision();
    Enemy E;
  private:
    Obj P;
    int maxwidth; //Ancho maximo
    int maxheight; //Alto maximo
    char c='0';
    char empty=(char)129;
    int life=3;
    int plus=0;
    int minus=0;
    bool quit=false;
    bool get;
};

#endif

#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "obj.h"

class Character{
    int points, del; //Add/Delete points
    bool get;
    char direction; //Direccion del personaje

    int maxwidth;
    int maxheight;
    char partchar;
    char oldalchar;
    char etel;
    int m_life;
    Obj Up;
    Obj Bala;
    Obj P; //El personaje

    void putObj();
    bool collision();
    void moveCharacter();
  public:
    Character();
    ~Character();
    void start();

};
#endif

#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <iostream>
#include <vector>
#include <curses.h>
#include <cstdlib>
#include <unistd.h>

struct Obj{
  int x,y;
  Obj(int col, int row);
  Obj();
};

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

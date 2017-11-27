#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Obj.h"
#include "Game.h"
#include "Character.h"

struct Enemy{
  public:
    Enemy();
    Enemy Enemy_R();
    ~Enemy();
  private:
    Obj id_E;
    char e;
};
#endif

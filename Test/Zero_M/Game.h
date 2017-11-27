#ifndef _GAME_H_
#define _GAME_H_

#include "Obj.h"
#include "Character.h"
#include "Enemy.h"
#include "Mapa.h"

class Game{
  public:
    Game();
    ~Game();
    int MaxW() const;
    int MaxH() const;
  private:
    int maxwidth; //Ancho maximo
    int maxheight; //Alto maximo

    int delay; //Delay de tecla
    bool quit;
};
#endif

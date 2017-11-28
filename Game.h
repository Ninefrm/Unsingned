#ifndef _GAME_H_
#define _GAME_H_

#include "Obj.h"
#include "Character.h"


class Game{
  public:
    Game();
    ~Game();
    int MaxW() const;
    int MaxH() const;
    void Start(Character &P);
    void Border();
  private:
    int maxwidth; //Ancho maximo
    int maxheight; //Alto maximo

    int delay; //Delay de tecla
};
#endif

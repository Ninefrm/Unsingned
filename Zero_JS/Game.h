#ifndef _GAME_H_
#define _GAME_H_

#include "Obj.h"
#include "Character.h"
#include "Wall.h"
#include "Player.h"
#include "Mapa.h"
#include <vector>
#include <curses.h>

class Game{
public:
   Game();
   ~Game();
   void start();
   void loop();
private:
   void move_player(int);
   int delay; //Delay de tecla
   Player player;
   const int max_w = 79;
   const int max_h = 23;
   bool end;
   std::vector<Mapa> maps;
};
#endif

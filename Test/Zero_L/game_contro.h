#ifndef GAME_CONTROL_H_
#define GAME_CONTROL_H_

#include <curses.h>
#include <unistd.h>

#include "Character.h"
#include "object.h"

class Game {
public:
  Game();
  ~Game();


private:
  int maxwidth;// hancho de la pantalla
  int maxheight; // alto de la pantalla

  int delay; //control delay
  bool quit;

};

#endif

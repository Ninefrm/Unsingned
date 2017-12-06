#ifndef _GAME_H_
#define _GAME_H_

#include "Obj.h"
#include "Character.h"
#include "Wall.h"
#include "Player.h"
#include "Mapa.h"
#include "Sword.h"
#include <cctype>
#include <exception>
#include <vector>
#include <curses.h>
#include <random>
#include <ctime>

class Game{
public:
   Game();
   ~Game();
   void start();
   void loop();
private:
   void move_player(int);
   void atack(int);
   void change_map(Mapa*&);
   int delay; //Delay de tecla
   Player player;
   const int max_w = 79;
   const int max_h = 23;
   bool end, colision;
   std::vector<Mapa> maps;
   std::mt19937 motor;
   std::bernoulli_distribution coin;
};
#endif

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
   //constructor
   Game();
   //destructor
   ~Game();

   void start();
   void loop();
private:
   void move_player(int);
   void atack(int);
   //transicion de pantallas
   void change_map(Mapa*&);

   bool end;// colision;

   //int delay; //Delay de tecla

   //const int max_w = 79;
   //const int max_h = 23;

   Player player;
   std::vector<Mapa> maps;
   std::mt19937 motor;
   std::bernoulli_distribution coin;
};
#endif

//Realizado por:
//Maximiliano Fonseca Romero
//Hrista Arantxa Martinez Martinez
//Jorge Salazar Ramirez
//Wendy Vanessa Bravo Guevara
//Vicente Ramirez Gonzales
//Luis David Lopez Zavala
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
   void change_map(Mapa*&);

   bool end;// colision;

   Player player;
   std::vector<Mapa> maps;
   std::mt19937 motor;
   std::bernoulli_distribution coin;
};
#endif

/*
Define el comportamiento del jugador
Jorge Salazar Ramirez
*/
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <vector>
#include "figther.h"
#include "point.h"
#include "pacific.h"


class Player:public Figther{
public:
  Player();
  ~Player(){};

  int get_level() const;//Regresa el nivel del jugador
  int get_karma() const;//Regresa el karma del jugador
  int get_xp() const;//Regresa los puntos de expereiencia del jugador

  void level_up();//Aumenta el nivel del jugador
  void boost_xp( unsigned int );//Aumenta la expereiencia del jugador
  void add_karma( int );//Suma el entero al karma del jugador
private:
  int xp;
  int level;
  int karma;
  const int max_level = 100; //Define el nivel maximo a alcanzar
};

#endif

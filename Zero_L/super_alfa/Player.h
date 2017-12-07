#ifndef _PLAYER_H_
#define _PLAYER_H_

//librerias
#include "Obj.h"
#include "Character.h"
#include "Sword.h"
#include <curses.h>
#include <ctime>

class Player : public Character { //Jugador es herencia de la clase derivada de Obj, Character
public:
  //constructores
   Player(); //constructor por defecto
   Player(int, int);
   //destructores
   ~Player() { };
   //accesors
   int get_plus() const;
   int get_minus() const;
   //modificadores
   Sword sword() const;
   void add_plus(int);
   void add_minus(int);
   void take(const Sword&);
   Sword atack(int key);
private:
   int plus;
   int minus;
   Sword armament;
   bool armed;
};

#endif

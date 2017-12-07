#ifndef _ENEMY_H_
#define _ENEMY_H_

//librerias
#include "Obj.h"
#include "Character.h"
#include <curses.h>


class Enemy : public Character{ //Enemigo, al igual que Player, es una herencia de Character
public:
  //constructores
   Enemy(); //constructor por defecto
   Enemy(int, int, char, int, int);
   //destructores
   ~Enemy() {};

   bool in_range(const Character&) const;//Verifica si un personaje esta en su rango de ataque
   void stalk(const Character&);//Se mueve hacia las coordenadas del personaje
   //accesor
   int damage() const;//Consulta el daño que hace
private:
   int range_x;
   int range_y;
   int _damage;//Guarda el daño que hace al atacar
};

#endif

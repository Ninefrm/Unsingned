#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Obj.h"
#include "Character.h"
#include <curses.h>


class Enemy : public Character{
public:
   Enemy();
   Enemy(int, int, char, int, int);
   ~Enemy() {};
   bool in_range(const Character&) const;//Verifica si un personaje esta en su rango de ataque
   void stalk(const Character&);//Se mueve hacia las coordenadas del personaje
   int damage() const;//Consulta el daño que hace
private:
   int range_x;
   int range_y;
   int _damage;//Guarda el daño que hace al atacar
};

#endif

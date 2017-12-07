#include "Enemy.h"

Enemy::Enemy() : Character(1, 1, '@', 10){ //constructor de Enemigo
   _damage = 1;
   range_x = 1;
   range_y = 2;
}

Enemy::Enemy(int w, int z, char t, int ml, int d) : Character(w, z, t, ml){
   _damage = d;
   range_x = 3;
   range_y = 3;
}

bool Enemy::in_range(const Character& p) const{ //para verificar si el jugador esta en rango recibe un apuntador a Character
   int xp = p.x_pos(),
       yp = p.y_pos();
   if(xp < x - range_x) return false;//evalua si la posicion que recive de Character esta en su rango de agro
   if(xp > x + range_x) return false;
   if(yp < y - range_y) return false;
   if(yp > y + range_y) return false;

   return true;//cuando el jugador esta dentro del rango, el metodo regresa verdadero
}

void Enemy::stalk(const Character& p){ //recibe un apuntador a Character para verificar la posicion del jugador
   int xp = p.x_pos(),
       yp = p.y_pos();
   if(yp != y){ // Compara la posicion en y del jugador con la de enemigo
      if(yp > y) y++; // si la posicion en y del jugador es mayor a la de enemigo, la posicion en y de enemigo aumenta
      if(yp < y) y--; // si la posicion en y del jugador es menor a la de enemigo, la posicion en y de enemigo decrementa
   }
   if(xp != x){// Compara la posicion en x del jugador con la de enemigo
      if(xp > x) x++;// si la posicion en x del jugador es mayor a la de enemigo, la posicion en x de enemigo aumenta
      if(xp < x) x--;// si la posicion en x del jugador es menor a la de enemigo, la posicion en x de enemigo decrementa
   }
}
//accesor
int Enemy::damage() const{
   return _damage; //regresa la cantidad de daño que provoca el enemigo 
}

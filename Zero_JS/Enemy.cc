#include "Enemy.h"

Enemy::Enemy() : Character(1, 1, '@', 10){
   _damage = 1;
}

Enemy::Enemy(int w, int z, char t, int ml, int d) : Character(w, z, t, ml){
   _damage = d;
}

bool Enemy::in_range(const Character& p) const{
   int xp = p.x_pos(),
       yp = p.y_pos();
   if(xp < x - range_x) return false;
   if(xp > x + range_x) return false;
   if(yp < y - range_y) return false;
   if(yp > y + range_y) return false;

   return true;
}

void Enemy::stalk(const Character& p){
   int xp = p.x_pos(),
       yp = p.y_pos();
   if(yp > y) y++;
   if(yp < y) y--;
   if(xp > x) x++;
   if(xp < x) y--;
}

int Enemy::damage() const{
   return _damage;
}

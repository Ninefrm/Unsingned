#include "Sword.h"

Sword::Sword() : Obj(-1, -1, '/') {
   _damage = 0;
   user = nullptr;
   dir = 0;
}

Sword::Sword(int d, Character* u) {
   x = u->x_pos();
   y = u->y_pos();
   _damage = d;
   texture = '/';
   dir = 0;
}

int Sword::damage() const{
   return _damage;
}

void Sword::use(int key){
   x = user->x_pos();
   y = user->y_pos();
   switch (key) {
      case 'w':
         --y;
         return;
      case 's':
         ++y;
         return;
      case 'a':
         --x;
         return;
      case 'd':
         ++x;
         return;
   }
}

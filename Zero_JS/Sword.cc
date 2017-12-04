#include "Sword.h"

Sword::Sword() : Obj(-1, -1, '/') { };

Sword::Sword(int d, const Obj& p) {//p se utiliza para saber donde se mostrara el arma
   x = p.x_pos();
   y = p.y_pos();
   _damage = d;
}

Obj Sword::use(int key){
   int px = x_pos(),
       py = y_pos();
   switch (key) {
      case 'w':
         py--;
         break;
      case 's':
         py++;
         break;
      case 'a':
         px--;
         break;
      case 'd':
         px++;
         break;
   }
   return Obj(px, py, texture);
}

int Sword::damage() const{
   return _damage;
}

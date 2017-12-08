//Realizado por:
//Maximiliano Fonseca Romero
//Hrista Arantxa Martinez Martinez
//Jorge Salazar Ramirez
//Wendy Vanessa Bravo Guevara
//Vicente Ramirez Gonzales
//Luis David Lopez Zavala
#include "Sword.h"

Sword::Sword() : Obj(-1, -1, '/') {
   _damage = 0;
   user = nullptr;
   //dir = 0;
}

Sword::Sword(int d, Character* u) {
   x = u->x_pos();
   y = u->y_pos();
   user = u;
   _damage = d;
   texture = '/';
   //dir = 0;
}

int Sword::damage() const{
   return _damage;
}

/*void Sword::use(int key){
   x = user->x_pos();
   y = user->y_pos();
   switch (key) {
      case 'w':
         --y;
         mvprintw(y, x, "/");
         refresh();
         while(getch()<0);
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
*/

void Sword::set_pos(int key){
  x_prev = x;
  y_prev = y;

  int xP, yP;

  switch (key) {
    case 'w':
    xP = user->x_pos();
    yP = user->y_pos()-1;
    break;

    case 's':
    xP = user->x_pos();
    yP = user->y_pos()+1;
    break;

    case 'a':
    xP = user->x_pos()-1;
    yP = user->y_pos();
    break;

    case 'd':
    xP = user->x_pos()+1;
    yP = user->y_pos();
    break;

    default:
    xP=user->x_pos();
    yP=user->y_pos();
  }

  x = xP;
  y = yP;

}

int Sword::get_x_prev() const{
  return x_prev;
}
int Sword::get_y_prev() const{
  return y_prev;
}

void Sword::setdamage(int d){
  _damage = d;
}

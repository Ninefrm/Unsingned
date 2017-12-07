#include "Long_Sword.h"

LSword::LSword() : Sword() { };

LSword::LSword(int d, Character* u) : Sword(d, u){
  setdamage(d);
}

void LSword::set_pos(int key){
  x_prev = x;
  y_prev = y;

  int xP, yP;

  switch (key) {
    case 'w':
    xP = user->x_pos();
    yP = user->y_pos()-2;
    break;

    case 's':
    xP = user->x_pos();
    yP = user->y_pos()+2;
    break;

    case 'a':
    xP = user->x_pos()-2;
    yP = user->y_pos();
    break;

    case 'd':
    xP = user->x_pos()+2;
    yP = user->y_pos();
    break;

    default:
    xP=user->x_pos();
    yP=user->y_pos();
  }

  x = xP;
  y = yP;

}

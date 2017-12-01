#include "Obj.h"

Obj::Obj(){
   x = 1;
   y = 1;
   texture = '0';
}

Obj::Obj(int r, int c, char t){
   x = c;
   y = r;
   texture = t;
}

int Obj::y_pos() const{
   return y;
}

int Obj::x_pos() const{
   return x;
}

void Obj::draw() const{
   mvaddch(y, x, texture);
}

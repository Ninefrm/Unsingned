#include "Character.h"

Character::Character() : Obj(1, 1, '?'){  //se construye character y objeto por defecto
   _max_life = 3;
   _life = 3;
}

Character::Character(int w, int z, char t, int ml) : Obj(w, z, t){ //se especifican valores para construir Obj y Character
   _max_life = ml;
   _life = ml;
}

//accesors
int Character::max_life() const{
   return _max_life;
}

int Character::life() const{
   return _life;
}

//modificadores
void Character::kill(){
   _life = 0;
}

void Character::heal(){
   _life = _max_life;
}

void Character::add_life(const int h){
   _life += h;
}

void Character::add_max_life(const int h){
   _max_life += h;
}

void Character::move_x(int h){
   mvaddch(y, x, ' ');
   x += h;
}

void Character::move_y(int h){
   mvaddch(y, x, ' ');
   y += h;
}

void Character::move(int r, int c){
   mvaddch(y, x, ' ');
   x = c;
   y = r;
}

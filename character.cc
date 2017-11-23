#include "character.h"

Character::Character(){
   m_pos = Point(0,0);
   m_life = 1;
   m_curr_life = 1;
   m_id = "PERSONAJE NO DEFINIDO";
}

Character::Character(Point pos, int life, std::string id){
   m_pos = pos;
   m_life = life;
   m_curr_life = life;
   m_id = id;
}

int Character::get_curr_life() const{
   return m_curr_life;
}

int Character::get_life() const{
   return m_life;
}

std::string Character::id() const{
   return m_id;
}

Point Character::get_pos() const{
   return m_pos;
}

void Character::set_curr_life(int h){
   m_curr_life = (h < 0)? 0 : h;
}

void Character::add_curr_life(int add){
   if(add < 0 && (add >= m_curr_life || add >= m_life))
      m_curr_life = 0;
   m_curr_life += add;
}

void Character::set_life(int h){
   m_life = h;
}

void Character::add_life(int add){
   if(add < 0 && add >= m_life)
      m_life = 1;
   m_life += add;
}

void Character::set_pos(Point pos){
   m_pos = pos;
}

void Character::set_pos(double x, double y){
   m_pos.x = x;
   m_pos.y = y;
}

void Character::move_x(double x){
   m_pos.x += x;
}

void Character::move_y(double y){
   m_pos.y += y;
}

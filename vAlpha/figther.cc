#include "figther.h"

Figther::Figther():Pacific(Point(0,0),100,"figther" ){
}


Figther::Figther(Point pos, int life, std::string id, Stats s, Element e):Pacific(pos, life , id){
  m_stats = s;
  m_element = e;
}

Figther::Figther(Point pos, int life, std::string id):Pacific(pos, life,id){
}

bool Figther::atack(Figther& other){
  other.add_life(-m_stats.damage);
  if(other.Character::get_curr_life() == 0)return true;
    return false;
}

void Figther::atack(Pacific& other){
    other.Character::set_life(0);
}

Stats Figther::stats(){
  return m_stats;
}

Element Figther::elements(){
  return m_element;
}

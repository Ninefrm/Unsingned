#include "weapon.h"

Weapon::Weapon() : Item(false, 1, Point(0,0), "ARAMA NO DEFINIDA"){
   m_damage = 1;
   m_durability_max = 100;
   m_speed = 50;
   m_critic_hit = 0.5;
   m_special_damage = 0.5;
}

Weapon::Weapon(bool inside, int size, Point pos, std::string id, int damage,
 int durmax, int speed, double critic, double special) : Item(inside, size, pos, id){
   m_damage = damage;
   m_durability_max = durmax;
   m_speed = speed;
   m_critic_hit = critic;
   m_special_damage = special;
}

int Weapon::get_damage() const{
   return m_damage;
}

int Weapon::get_speed() const{
   return m_speed;
}

int Weapon::get_durability_max() const{
   return m_durability_max;
}

int Weapon::get_durability_current() const{
   return m_durability_current;
}

double Weapon::critic_hit() const{
   return m_critic_hit;
}

double Weapon::special_damage() const{
   return m_special_damage;
}

void Weapon::boost_damage(int boost){
   m_damage += boost;
}

int Weapon::use(){
   int damage = m_damage;
   if(m_durability_current == 0){
      return 1;
   }
   m_durability_current--;
   if(m_durability_current == m_durability_max){
      return m_damage;
   }
   return int(m_durability_current * m_damage / m_durability_max );
}

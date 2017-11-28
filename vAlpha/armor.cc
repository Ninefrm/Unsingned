#include "armor.h"

Armor::Armor() : Item(false, 1, Point(0,0), "ARMADURA GENERICA"){
   m_def = 1;
   m_magic_def = 1;
   m_durability_current = 100;
   m_durability_max = 100;
   m_weigth = 1;
}

Armor::Armor(bool inside, int size, Point pos, std::string id, int def, int mdef, Element elm, int dur, int w) :
 Item(inside, size, pos, id){
    m_def = def;
    m_magic_def = mdef;
    m_element = elm;
    m_durability_current = dur;
    m_durability_max = dur;
    m_weigth = w;
}

int Armor::get_def() const{
   return m_def;
}

int Armor::get_magic_def() const{
   return m_magic_def;
}

int Armor::get_durability_max() const{
   return m_durability_max;
}

int Armor::get_durability_current() const{
   return m_durability_current;
}

Element Armor::get_element() const{
   return m_element;
}

int Armor::get_weigth() const{
   return m_weigth;
}

int Armor::use(){
   if(m_durability_current == 0)
      return 0;
   m_durability_current--;
   if(m_durability_current + 1 == m_durability_max)
      return m_def;
   return m_def * (m_durability_current + 1)/m_durability_max;
}

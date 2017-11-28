#include "item.h"

Item::Item(){
   int m_size = 1;
   bool m_inside = false;
   std::string m_id = "OBJETO NO DEFINIDO";
   Point m_pos = Point(0, 0);
}

Item::Item(bool inside, int size, Point pos, const std::string id){
   int m_size = size;
   bool m_inside = inside;
   std::string m_id = id;
   Point m_pos = pos;
}

Item::Item(bool inside, int size, Point pos, const char* id){
   int m_size = size;
   bool m_inside = inside;
   std::string m_id = id;
   Point m_pos = pos;
}

int Item::size() const{
   return m_size;
}

bool Item::inside() const{
   return m_inside;
}

Point Item::pos() const{
   return m_pos;
}

std::string Item::get_id() const{
   return m_id;
}

void Item::inside(bool inside){
   m_inside = inside;
}

void Item::pos(Point pos){
   m_pos = pos;
}

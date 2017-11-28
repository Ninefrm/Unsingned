#include "inventory.h"

Inventory::Inventory(){
  m_size = 1;
  m_curr_size = 0;
  m_container.resize(1);
}

Inventory::Inventory(int size){
  m_size = size;
  m_curr_size = 0;
  m_container.resize(size);
}

bool Inventory::full() const{

  if(m_curr_size == m_size) return true;
    return false;

}

bool Inventory::empty() const{
  if(m_curr_size > 0 )return true;
    return false;
}

int Inventory::curr_size() const{
  return m_curr_size;
}

int Inventory::size() const{
  return m_size;
}

void Inventory::growth(unsigned int size){

  m_container.resize(m_size + size);
}

void Inventory::erase(std::string id){
  for(int i=0; i<m_curr_size; i++){
    if(m_container[i].get_id() == id){
      m_container.erase(m_container.begin() + i);
      return;
    }
  }
}

Item& Inventory::operator [] (int index){
   return m_container[index];
}

const Item& Inventory::operator [] (int index) const{
   return m_container[index];
}

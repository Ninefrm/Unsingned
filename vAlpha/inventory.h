/*
VICENTE RAMIREZ GONZALEZ
Define el comportamiento del inventario
El inventario se almancena en una lista enlazada por que se necesitaran agregar
y eliminar objetos constantemente, ademas de hacer intercambos de posicion
*/
#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#include "item.h"
#include <vector>

class Inventory{
public:
   Inventory();
   Inventory(int);//Crea un inventario del tamaño especificado
   ~Inventory();

   bool full() const;//Verifica si el inventario esta lleno
   bool empty() const;//Verifica si el inventario esta vacio
   int size() const;//Regresa el tamaño maximo de objetos que puede almacenar el inventario
   int curr_size() const;//Regresa el numero de objetos que se encuentran en el inventario

   void growth(unsigned int);//Aumenta el tamaño maximo del inventario
   void erase(std::string);//Borra del objeto con el identificador especificado
   void erase(int);//Borra el objeto seleccionado del inventrio
   void swap(int, int);//Intercambia dos objetos de posicion
   bool put(Item);//Guarda un nuevo objeto en el inventario
   bool is_in(const Item&);//Verifica si el el objeto esta en el inventario
   Item discard(std::string);//Elimina el objeto y regresa una copia
   Item discard(int);//Elimina el objeto y regresa una copia

   Item& operator [] (int);//Regresa un objeto del inventaio
   const Item& operator [] (int) const;

private:
   std::vector<Item> m_container;//Contiene los objetos almacenados
   int m_size;//Guarda el tamaño maximo del inventario
   int m_curr_size;
};

#endif

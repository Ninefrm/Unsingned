/*
Jorge Salazar Ramirez
Define a  un personaje generico
*/
#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "point.h"
#include "item.h"
#include "inventory.h"
#include <string>

class Character{
public:
   Character();
   Character(Point, int, std::string);//Constructor para un punto inicial, vida e identificador
   virtual ~Character(){}//De la clase caracter derivaran otros personajes

   int get_curr_life() const;//Regresa la vida actual
   int get_life() const;//Regresa la vida maxima
   std::string id() const;//Regresa el identificador
   Point get_pos() const;//Regresa la posicion actual

   void set_curr_life(int);//Establece la vida del jugador
   void add_curr_life(int);//Suma el argumento a la bida actual
   void set_life(int);//Establece la vida maxima del jugador
   void add_life(int);//Suma el argumento a la vida maxima
   void set_pos(Point);//Establece la posicion, regresa la posicion anterior
   void set_pos(double, double);//Establece la posicion, regresa la posicion anterior
   void move_x(double);//aumenta el componente en x de la posicion actual
   void move_y(double);//aumenta el componente en y de la posicion actual
   Inventory bag;//Guarda todos los objetos que puede almacenar el personaje-------------------------------------------------------------------------------------
private:
   std::string m_id;//Identificador del personaje, no debe ser modificado
protected:
   int m_life;//Guarda la vida maxima del jugador
   int m_curr_life;//Guarda la vida del objeto, no es la vida maxima
   Point m_pos;//Guarda la posicion actual del objeto
};

#endif

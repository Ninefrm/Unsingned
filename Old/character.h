/*
Define a  un personaje generico
*/
#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "point.h"
#include "object.h"
#include <cstring>
#include <vector>

class Character{
public:
   Character();
   Character(Point, int, std::string);//Constructor para un punto inicial, vida e identificador
   virtual ~Character();

   Point getPos() const;//Regresa la posicion actual
   int getCurrLife() const;//Regresa la vida actual
   int getLife() const;//Regresa la vida maxima
   std::string id() const;//Regresa el identificador

   Point setPos(Point);//Establece la posicion
   Point setPos(double, double);//Establece la posicion
   void setCurrLife(int);//Establece la vida del jugador
   void addCurrLife(int);//Suma el argumento a la bida actual
   void setLife(int);//Establece la vida maxima del jugador
   void addLife(int);//Suma el argumento a la vida maxima
private:
   int m_life;//Guarda la vida maxima del jugador, privado por seguridad
   std::string m_id;//Identificador del personaje, no debe ser modificado
protected:
   Point m_pos;//Guarda la posicion actual del objeto
   int m_curr_life;//Guarda la vida del objeto, no es la vida maxima
   std::vector <Object> m_inv;
};

#endif

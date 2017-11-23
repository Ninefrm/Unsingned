/*
VICENTE RAMIREZ GONZALEZ
Define a un personaje incapaz de atacar
La clase "Item" puede cambiar de nombre
*/
#ifndef _PACIFIC_H_
#define _PACIFIC_H_

#include "character.h"
#include "item.h"//El archivo que contiene la definicion de objeto
#include "point.h"
#include <cstring>
#include <vector>

class Pacific : public Character{
public:
   Pacific();
   Pacific(Point, int, std::string);
   ~Pacific(){};

   std::string talk();//Regresa un dialgo

   std::string talk(std::string);//Regresa un dialogo distinto segun la respuesta
   std::string talk(unsigned int);//Se usa para obtener un dialogo segun la opcion seleccionada
   Item trade(Item);//Funcion utilizada para realizar intercambios, por ejemplo reparar una arma
   Item look(const Item&);//Funcion utilizada para consultar infornacion de un objeto

private:
   unsigned int m_talk_counter;//Cuenta las veces que se ha hablado con el jugador
   std::vector<std::string> m_dialog;//Guarda todos los dialogos del personaje
protected:
   int m_empaty;//Segun los dialogos seleccionados aumentara o reducira, lo que cambiara el comportamiento del objeto
   bool m_quest;//Es verdadera si el jugador completo la mision asignada
};

#endif

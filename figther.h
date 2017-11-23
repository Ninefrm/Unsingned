/*
VICENTE RAMIREZ GONZALEZ
Define un personaje que puede entrar en batalla
ESTA CLASE NECESITA DE LAS HABILIDADES QUE PODRA USAR AL ATACAR
*/
#ifndef _FIGTHER_H_
#define _FIGTHER_H_

#include "character.h"
#include "pacific.h"
#include "point.h"
#include "item.h"//El nombre puede cambiar
#include "structs.h"
#include "inventory.h"
#include <string>
#include <vector>

class Figther : public Pacific{
public:
  Figther();
  Figther(Point, int, std::string, Stats, Element);//Constructor para un peleador con estadisticas y elementos definidos
  Figther(Point, int, std::string);//Constructor para un peleador con estadisticas y elementos por defeco
   ~Figther(){};
  bool atack(Figther&); //La funcion regresara true si gano la batalla
  void atack(Pacific&); //Al atacar un personaje pacifico este morira automaticamente, pues no puede pelear
  Stats stats();//Regresa las estadisticas del peleador
  Element elements();//Regresa los elementos a los que pertenece el peleador
private:
protected:
   Stats m_stats;//Contiene las estadisticas del peleador
   Element m_element;//Contiene los elementos actuales
};

#endif

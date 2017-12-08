//Realizado por:
//Maximiliano Fonseca Romero
//Hrista Arantxa Martinez Martinez
//Jorge Salazar Ramirez
//Wendy Vanessa Bravo Guevara
//Vicente Ramirez Gonzales
//Luis David Lopez Zavala
#ifndef _LONG_SWORD_H_
#define _LONG_SWORD_H_

//librerias
#include "Sword.h"

class LSword : public Sword{
public:
  LSword();
  LSword(int d, Character* u);

  void set_pos(int key);

  ~LSword() { };
};

#endif

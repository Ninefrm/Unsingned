/*
Define a un personaje incapaz de atacar
La clase "Object" puede cambiar de nombre
*/
#ifndef _PACIFIC_H_
#define _PACIFIC_H_

#include "character.h"
#include "object.h"//El archivo que contiene la definicion de objeto
#include "point.h"
#include <cstring>
#include <vector>

class Pacific : public Character{
public:
   Pacific();
   Pacific(Point, int, std::string);
   ~Pacific();

   std::string talk() const;

   std::string talk(std::string);
   std:::string talk(int);

   Object give();
   Object give(Object&);
   Object give(const Object&);

private:
   int m_empaty;
   unsigned int m_talk_counter;

protected:
   bool m_quest;
};

#endif

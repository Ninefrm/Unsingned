#ifndef _FIGTHER_H_
#define _FIGTHER_H_

#include "character.h"
#include "point.h"
#include "object.h"

typedef struct Stats{
  int luck;
  int speed;
  int armor;
  int magic_armor;
  int damage;
  int magic_damage;
}
typedef struct element{
  bool water;
  bool earth;
  bool fire;
  bool abstract;
  bool electric;
}


class Figther : public Pacific{
public:
  bool atack(Figther&);
  void atack(Pacific&);
private:
protected:
   Stats m_stats;
   element m_element;
};

#endif

//Skills

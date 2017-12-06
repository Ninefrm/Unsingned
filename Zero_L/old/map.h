#ifndef MAP_H_
#define MAP_H_

#include "object.h"

class Map{
public:
  void draw();
  bool collision(Object P);

private:
  char wall;
  char tree;

};

#endif

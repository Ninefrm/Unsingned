#ifndef _WALL_H_
#define _WALL_H_

#include "Obj.h"

class Wall{
public:
  Wall();
  Wall(int x, int y, int r, int c);
  ~Wall() { };
  Obj getWall();
  int getRows() const;
  int getCols() const;

private:
  int rows;
  int cols;
  char brick;
  Obj wall;
};


#endif

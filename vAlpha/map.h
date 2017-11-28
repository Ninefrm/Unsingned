#ifndef _MAP_H_
#define _MAP_H_

#include <vector>
#include <curses.h>

struct map{
  int x,y;
  map(int col, int row);
  map();
};

#endif

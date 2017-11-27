#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <curses.h>
#include <unistd.h>

struct Object{
public:
  Object();
  Object(int col, int row);
  ~Object() { };

  int x,y;
};

#endif

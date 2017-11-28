#ifndef _OBJ_H_
#define _OBJ_H_

#include <iostream>
#include <vector>
#include <curses.h>
#include <cstdlib>
#include <unistd.h>

struct Obj{
  int x,y;
  Obj(int col, int row){
    x=col;
    y=row;
  }
  Obj(){
    x=0;
    y=0;
  }
};

#endif

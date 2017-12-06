#ifndef _WALL_H_
#define _WALL_H_

#include "Obj.h"
#include "Character.h"
#include <curses.h>

class Wall : public Obj{
public:
  Wall();
  Wall(int, int, char, int, int);
  ~Wall() { };
  void draw() const;
  bool collision(int, int) const;
  bool collision( const Character& p) const;
  int get_rows() const;
  int get_cols() const;
private:
  int rows;
  int cols;
};


#endif

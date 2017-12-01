#include "Wall.h"

Wall::Wall() : Obj(1, 1, '#'){
   rows = 2;
   cols = 2;
}

Wall::Wall(int w, int z, char brick, int r, int c) : Obj(w, z, brick){
   rows = r;
   cols = c;
}

void Wall::draw() const{
   for(size_t i = 0; i < rows; i++){
      for(size_t j = 0; j < cols; j++){
         mvaddch(y + i, x + j, texture);
      }
   }
}

bool Wall::collision(int xp, int yp) const{
   if(xp < x || xp > x + cols) return false;
   if(yp < y || yp > y + rows) return false;
   return true;
}

bool Wall::collision(const Character& p) const{
   return collision(p.x_pos(), p.y_pos());
}

int Wall::get_rows() const{
   return rows;
}

int Wall::get_cols() const{
   return cols;
}

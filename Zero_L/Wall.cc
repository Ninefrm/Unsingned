#include "Wall.h"

Wall::Wall(){
  wall.x = 0;
  wall.y = 0;
  rows = 1;
  cols = 1;
  brick = '#';

  move(wall.x, wall.y);
  addch(brick);
  refresh();
}

Wall::Wall(int x, int y, int r, int c){
  wall.x = x;
  wall.y = y;
  rows = r;
  cols = c;
  brick = '#';

  for (int i = 0; i < cols; i++) {
    for(int j = 0; j < rows; j++){
      move(wall.x + j, wall.y + i);
      addch(brick);
    }
  }
  refresh();
}

Obj Wall::getWall(){
  return wall;
}

int Wall::getRows() const{
  return rows;
}

int Wall::getCols() const{
  return cols;
}

#include "Enemy.h"

Enemy::Enemy(){
  getmaxyx(stdscr, maxheight, maxwidth);
  while(1){
    int random_x=rand()%maxwidth+1;
    int random_y=rand()%maxheight+1;
    if(random_x>=maxwidth-2 || random_y>=maxheight-3)
      continue;
      E.x=random_x;
      E.y=random_y;
    break;
  }
  move(E.y,E.x);
  addch(e);
  refresh();
}

#include "Enemy.h"

Enemy::Enemy(){
  id_E.x=0;
  id_E.y=0;
  e=64;
}
Enemy Enemy::Enemy_R(){
  Enemy();
  while(1){
    int random_x=rand()%MaxW()+1;
    int random_y=rand()%MaxH()+1;
    if(random_x>=MaxW()-2 || random_y>=MaxH()-3)
      continue;
        id_E.x=random_x;
        id_E.y=random_y;
    break;
  }
  move(id_E.y,id_E.x);
  addch(e);
  refresh();
}
Enemy::~Enemy(){
  if(P.x==Up.x && P.y==Up.y){
    Enemy_R();
    move(MaxH()-1,0);
    return true;
  }else
    get=false;
    return false;
}

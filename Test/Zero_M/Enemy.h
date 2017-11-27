#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Obj.h"

struct Enemy{
  public:
    Enemy(){
      id_E.x=0;
      id_E.y=0;
      id_E.e=64;
    }
    Enemy_R():Enemy(){
      while(1){
    		int random_x=rand()%maxwidth+1;
    		int random_y=rand()%maxheight+1;
    		if(random_x>=maxwidth-2 || random_y>=maxheight-3)
    			continue;
    		    id_E.x=random_x;
    		    id_E.y=random_y;
    		break;
    	}
    	move(id_E.y,id_E.x);
    	addch(id_E.e);
    	refresh();
    }
    ~Enemy(){
      if(P.x==Up.x && P.y==Up.y){
      	Enemy_R();
    		move(maxheight-1,0);
        return true;
      }else
      	get=false;
      	return false;
    }
  private:
    Obj id_E;
    char e;
};

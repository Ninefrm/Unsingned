#include "Character.h"

Character::Character(){
  getmaxyx(stdscr, maxheight, maxwidth);
  P.x=maxwidth/2;
  P.y=maxheight/2;
  plus=0;
  minus=0;
  life=3;

}
Character::~Character(){
  nodelay(stdscr,false); //Cerramos
  getch(); //Espera tecla para cerrar
  endwin(); //Cerrar ventana
}
void Character::MoveCharacter(){
  int Key=getch(); //Key Será nuestra tecla oprimida.
  move(P.y,P.x);
  printw(" ");

  switch(Key){
    case KEY_LEFT:
        P.x--;
        break;
    case KEY_UP:
        P.y--;
        break;
    case KEY_DOWN:
        P.y++;
        break;
    case KEY_RIGHT:
        P.x++;
        break;
    case 27: //Barra para salir
        quit=true;
        break;
  }
  if(!get){
    move(P.y, P.x);
    printw(" ");
    refresh();
  }
    move(P.y,P.x);
    addch(c);
    refresh();
}
char Character::Empty(){
  return empty;
}
bool Character::Q(){
    return quit;
}
bool Character::Collision(){
  if(P.x==0 || P.x==maxwidth-1 || P.y==0 || P.y==maxheight-2){
  		return true;
    }
  	/*collision con los 1
  if(P.x==Up.x && P.y==Up.y){
  	//get=true;
  	putObj();
		//points+=10;
		move(maxheight-1,0);
  	printw("%d",points);
		/*if((points%100)==0)
			del-=10000;
    return true;
  }else
  	else{
  	  return false;
    }
}*/
return false;
}

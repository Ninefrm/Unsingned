#include "Character.h"

Character::Character(){
  getmaxyx(stdscr, maxheight, maxwidth);
  P.x=maxwidth/2;
  P.y=maxheight/2;
  plus=0;
  minus=0;
  life=3;
  srand(time(NULL));
}
Character::~Character(){
  nodelay(stdscr,false); //Cerramos
  getch(); //Espera tecla para cerrar
  endwin(); //Cerrar ventana
}
void Character::MoveCharacter(){
  move(P.y,P.x);
  addch(c);
  move(maxheight-1,0);
  printw("Plus: %d, Minus: %d, Life: %d",plus, minus,life);
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
    move(maxheight-1,0);
    printw("Plus: %d, Minus: %d, Life: %d",plus, minus,life);
    refresh();
}
char Character::Empty(){
  return empty;
}
bool Character::Q(){
    return quit;
}
bool Character::Collision(){
  //Colision con el muro
  if(P.x==0 || P.x==maxwidth-1 || P.y==0 || P.y==maxheight-2){
    clear();
    move(maxheight/2-2,maxwidth/2-11);
    printw("WALL COLLISION");
    return true;
  }
  //Enemy Collision
  if(P.x==E.E.x && P.y==E.E.y){
    life--;
    if(life==0){ //Si vida llega a 0, termina el juego
      clear();
      move(maxheight/2-2,maxwidth/2-7);
      printw("WASTED");
      return true;
    }
    else{ //Si no llegó a cero, entonces cambiar de posición al enemigo
      while(1){
        int random_x=rand()%maxwidth+1;
        int random_y=rand()%maxheight+1;
        if(random_x>=maxwidth-2 || random_y>=maxheight-3)
          continue;
          E.E.x=random_x;
          E.E.y=random_y;
        break;
      }
      move(E.E.y,E.E.x);
      addch(64);
      refresh();
      return false;
    }
    }
    return false;
}

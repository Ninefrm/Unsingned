#include "Character.h"

Character::Character(){
  P.x=40;
  P.y=10;
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
    case KEY_BACKSPACE: //Barra para salir
        quit=true;
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

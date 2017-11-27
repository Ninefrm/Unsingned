#include "Game.h"

Game::Game(){
    initscr(); //inicializar pantalla
    nodelay(stdscr,false); //Espera tecla para moverse
    keypad(stdscr,true); //Habilita el teclado
    noecho(); //No sale lo que escribes
    curs_set(0); //Cursor no visible
    getmaxyx(stdscr, maxheight, maxwidth); //Obtiene el Max (Width/Height), de la pantalla.
    delay=100000;

    Character P;
    while(1){
      P.MoveCharacter();
      if(P.Q()) break;
      usleep(delay);
    }
}
Game::~Game(){
  nodelay(stdscr,false); //cerrar
  endwin();
}
int Game::MaxW() const{
  return maxwidth;
}
int Game::MaxH() const{
  return maxheight;
}

#include "game_control.h"

Game::Game(){
  //incializando pantalla
  initscr();
  nodelay(stdscr,false); //No espera key
  keypad(stdscr,true); //habilita teclado
  noecho(); //no escribe
  curs_set(0); //cursor invisible

  //incializando variables
  getmaxyx(stdscr, maxheight, maxwidth); //obtener medidas de la pantalla
  delay=100000; //delay de rspuesta de control
  //quit = false;

  //incializando personaje
  Player P(maxheight, maxwidth);

  while(1){
    P.playermovement();
    if(P.quit) break;
    usleep(delay);
  }
}

Game::~Game(){
  nodelay(stdscr,false); //Cerramos
  endwin();
}

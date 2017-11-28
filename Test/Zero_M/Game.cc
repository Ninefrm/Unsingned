#include "Game.h"

Game::Game(){
    initscr(); //inicializar pantalla
    nodelay(stdscr,false); //Espera tecla para moverse
    keypad(stdscr,true); //Habilita el teclado
    noecho(); //No sale lo que escribes
    curs_set(0); //Cursor no visible
    getmaxyx(stdscr, maxheight, maxwidth); //Obtiene el Max (Width/Height), de la pantalla.
    move(maxheight/2-2,maxwidth/2-17);
    printw("READY PLAYER ONE?, press a key");
    getch();
    clear();
    Character P;
    //MARGEN
    for(int i=0;i<MaxW()-1;i++){
      move(0,i);
      addch(P.Empty());
    }//Izquierda-Horizontal
    for(int i=0;i<MaxH()-1;i++){
      move(i,0);
      addch(P.Empty());
    }//Abajo-Vertical
    for(int i=0;i<MaxW()-1;i++){
      move(MaxH()-2,i);
      addch(P.Empty());
    }//Derecha Horizontal
    for(int i=0;i<MaxH()-1;i++){
      move(i,MaxW()-2);
      addch(P.Empty());
    }
    //MARGEN

    delay=100000;

    Start(P);
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
void Game::Start(Character &P){
  while(1){
    getmaxyx(stdscr, maxheight, maxwidth);
    if(P.Collision()){
      move(maxheight/2-1,maxwidth/2-9);
      printw("GAME OVER");
      break;
    }
    P.MoveCharacter();
    usleep(110000);
  }
}

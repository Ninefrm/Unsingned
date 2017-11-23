#include <iostream>
#include <vector>
#include <string>
#include <curses.h>
#include "window.h"

using namespace std;

int main(){
  WINDOW *screen;
  int width, height, startx, starty; //anchura,altura,inicio X, inicio Y;
  int key; //inicializamos track de teclado.
  initscr(); //iniciar curses.
  clear();
  noecho();
  cbreak(); //Desactiva el buffer de lineas y elimina/mata character-proccesing

  height=260;
  width=320;
  starty=(LINES - height)/2; //Calcula el centro.
  startx=(COLS - width)/2;
  refresh();

  printw("UNSINGNED");
  printw("FUCK U");
  refresh();
  screen=new_win(height,width,startx,starty);
  keypad(screen,TRUE);
  delwin(screen);
  do{
    key=wgetch(screen);
    switch(key){
      case KEY_LEFT:
  				destroy_win(screen);
  				screen = new_win(height, width, starty,--startx);
          printw("PRESIONASTE IZQUIERDA");
  			break;
  		case KEY_RIGHT:
  				destroy_win(screen);
  				screen = new_win(height, width, starty,++startx);
          printw("DERECHA");
  			break;
  		case KEY_UP:
  				destroy_win(screen);
  				screen = new_win(height, width, --starty,startx);
          printw("ARRIBA");
  			break;
  		case KEY_DOWN:
  				destroy_win(screen);
  				screen = new_win(height, width, ++starty,startx);
          printw("ABAJO");
  			break;
  		}
    }while((key=getch())!=KEY_BREAK);
  endwin();
  return 0;
}

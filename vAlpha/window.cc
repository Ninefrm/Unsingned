#include "window.h"

WINDOW *new_win(int height, int width, int startx, int starty){
  WINDOW *local_win;
  local_win = newwin(height,width,startx, starty);
    box(local_win,0,0); //Iguala valores por defecto para la vertical y horizontal
    wrefresh(local_win);
    
    return local_win;
}

void destroy_win(WINDOW *local_win){
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(local_win);
	delwin(local_win);
}

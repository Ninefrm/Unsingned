#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <curses.h>

WINDOW *new_win(int height, int width, int startx, int starty);
void destroy_win(WINDOW *local_win);

#endif

//Realizado por:
//Maximiliano Fonseca Romero
//Hrista Arantxa Martinez Martinez
//Jorge Salazar Ramirez
//Wendy Vanessa Bravo Guevara
//Vicente Ramirez Gonzales
//Luis David Lopez Zavala
/*
Colores de curses
COLOR_BLACK   0
COLOR_RED     1
COLOR_GREEN   2
COLOR_YELLOW  3
COLOR_BLUE    4
COLOR_MAGENTA 5
COLOR_CYAN    6
COLOR_WHITE   7
*/

#include "Game.h"
#include <vector>
#include <curses.h>
#include <iostream>

using namespace std;

int main(){
   Game control;
   control.start();
   control.loop();
   return 0;
}

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

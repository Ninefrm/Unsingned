#include <curses.h>
#include <ctime>
#include <cctype>
#include "basics.h"
using namespace std;

int main(){
   int key;
   bool end = false;
   initscr();
   noecho();
   keypad(stdscr, TRUE);
   timeout(300);
   delay_output(100);
   Basics control(100, 40);
   do{
      key = getch();
      mvprintw(0, 0, "Input: %3d\tBullets: %3d", key, control.bullets());
      if(key == ERR){
         control.upgrade();
         refresh();
         continue;
      }
      if(key == '@'){
         printw("ADIOS");
         wclear(stdscr);
         refresh();
         end = true;
         continue;
      }
      if(isalpha(key)){
         control.shoot(key);
         control.upgrade();
         refresh();
         continue;
      }
      else{
         control.move(key);
         control.upgrade();
         refresh();
         continue;
      }
      if(time(nullptr) % 4 == 0){
         control.shoot(2, 4);
         control.upgrade();
         refresh();
         continue;
      }
      control.upgrade();
      refresh();
   }while(!end);
   wclear(stdscr);
   endwin();
   return 0;
}

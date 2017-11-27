#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "Obj.h"

struct Character{
  public:
    Character(){
      P.x=40;
      P.y=10;
      plus=0;
      minus=0;
      life=3;
    }
    ~Character(){
      nodelay(stdscr,false); //Cerramos
      getch(); //Espera tecla para cerrar
      endwin(); //Cerrar ventana
    }
    void MoveCharacter(){
      int Key=getch(); //Key Será nuestra tecla oprimida.
      switch(Key){
        case KEY_LEFT:
      			direction='l';
            break;
      	case KEY_UP:
      			direction='u';
      			break;
      	case KEY_DOWN:
      			direction='d';
      			break;
    		case KEY_RIGHT:
      			direction='r';
            break;
      	case KEY_BACKSPACE: //Barra para salir
      		  direction='q';
            break;
      }
      if(!get){
        move(P.y, P.x);
        printw(" ");
        refresh();
      }
      if(direction=='l'){   //Cuando es Izquierda
        P.x--;
      }else if(direction=='r'){ //Derecha
      	P.x++;
      }else if(direction=='u'){ //Arriba
      	P.y--;
      }else if(direction=='d'){ //Abajo
      	P.y++;
      }
      	move(P.y,P.x);
      	addch(c);
      	refresh();
    }
    void Start();
  private:
    Obj P;
    char c='0';
    char empty=(char)129;
    int life=0;
    int plus=0;
    int minus=0;
};

#endif

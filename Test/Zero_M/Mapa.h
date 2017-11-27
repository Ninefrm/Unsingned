#ifndef _MAPA_H_
#define _MAPA_H_

#include "Obj.h"

struct Mapa{
  public:
    Mapa(){
      initscr(); //inicializar pantalla
      nodelay(stdscr,false); //Espera tecla para moverse
      keypad(stdscr,true); //Habilita el teclado
      noecho(); //No sale lo que escribes
      curs_set(0); //Cursor no visible
      getmaxyx(stdscr, maxheight, maxwidth); //Obtiene el Max (Width/Height), de la pantalla.
      //CREAR EL MARGEN->
      //Vertical-Arriba
      for(int i=0;i<maxwidth-1;i++){
        move(0,i);
        addch(oldalchar);
      }//Izquierda-Horizontal
      for(int i=0;i<maxheight-1;i++){
        move(i,0);
        addch(oldalchar);
      }//Abajo-Vertical
      for(int i=0;i<maxwidth-1;i++){
        move(maxheight-2,i);
    	  addch(oldalchar);
      }//Derecha Horizontal
      for(int i=0;i<maxheight-1;i++){
    	  move(i,maxwidth-2);
        addch(oldalchar);
      }//Se creó el margen<-
    }
    ~Mapa(){

    }
  private:

};

#endif

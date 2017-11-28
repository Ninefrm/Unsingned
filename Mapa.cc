#include "Mapa.h"

Mapa::Mapa(Game &G){
  //CREAR EL MARGEN->
  //Vertical-Arriba
  int MaxW=G.MaxW();
  for(int i=0;i<MaxW-1;i++){
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
}
Mapa::~Mapa(){

}

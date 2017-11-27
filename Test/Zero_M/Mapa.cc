#include "Mapa.h"

Mapa::Mapa(){
  //CREAR EL MARGEN->
  //Vertical-Arriba
  for(int i=0;i<MaxW()-1;i++){
    move(0,i);
    addch(Empty());
  }//Izquierda-Horizontal
  for(int i=0;i<MaxH()-1;i++){
    move(i,0);
    addch(Empty());
  }//Abajo-Vertical
  for(int i=0;i<MaxW()-1;i++){
    move(MaxH()-2,i);
    addch(oldalchar);
  }//Derecha Horizontal
  for(int i=0;i<MaxH()-1;i++){
    move(i,MaxW()-2);
    addch(Empty());
  }//Se creó el margen<-
}
Mapa::~Mapa(){

}

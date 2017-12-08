//Realizado por:
//Maximiliano Fonseca Romero
//Hrista Arantxa Martinez Martinez
//Jorge Salazar Ramirez
//Wendy Vanessa Bravo Guevara
//Vicente Ramirez Gonzales
//Luis David Lopez Zavala
#include "Obj.h"

Obj::Obj(){ //constructor por defecto
   x = 1; //se asignan las coordendas del objeto por defecto
   y = 1;
   texture = '0'; // el caracter por defecto que va a dibujar en la textura
}

Obj::Obj(int r, int c, char t){ //constructor con especificaciones
   x = c; //asignando las coordenadas y textura
   y = r;
   texture = t;
}

int Obj::y_pos() const{ // regresa la posicion en y de Objeto
   return y;
}

int Obj::x_pos() const{ // regresa la posicion en x de Objeto
   return x;
}

void Obj::draw() const{ //dibuja la textura en la posicon actual
   mvaddch(y, x, texture); //mvaddch: funcion de curses que imprime en pantalla un caracter en las coordenadas especificas
}

char Obj::txt() const{ // regresa la textura del objeto
   return texture;
}

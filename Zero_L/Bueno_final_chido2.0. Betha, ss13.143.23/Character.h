#ifndef _CHARACTER_H_
#define _CHARACTER_H_
//librerias
#include "Obj.h"
#include <ctime>
#include <curses.h>

class Character : public Obj{ //Character hereda los miembros de Obj
public:

  //constructores
   Character(); // constructor por defecto
   Character(int, int, char, int);

   //destructores
   ~Character() {};

   //accesors
   int max_life() const; //Consulta la vida maxima
   int life() const;//Consulta la vida actual

   //modificadores
   void kill();//Establece en cero la vida
   void heal();//Restaura la vida
   void add_life(const int);//Suma a la vida actual del personaje
   void add_max_life(const int);//Suma a la vida maxima del personaje
   void move_x(int);//Suma a la posicion en x del personaje
   void move_y(int); //Suma a la posicion en y del personaje
   void move(int, int);//Mueve al personaje a la posicion especificada

private:
   int _life; // vida del personaje
   int _max_life;
};

#endif

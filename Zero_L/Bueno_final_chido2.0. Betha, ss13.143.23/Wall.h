//Realizado por:
//Maximiliano Fonseca Romero
//Hrista Arantxa Martinez Martinez
//Jorge Salazar Ramirez
//Wendy Vanessa Bravo Guevara
//Vicente Ramirez Gonzales
//Luis David Lopez Zavala
#ifndef _WALL_H_
#define _WALL_H_
//librerias
#include "Obj.h"
#include "Character.h"
#include <curses.h>

class Wall : public Obj{ //Wall hereda de Obj sus miembros
public:
  //constructores
  Wall();
  Wall(int, int, char, int, int);
  //destructor
  ~Wall() { };

  void draw() const; //metodo que dibuja en pantalla un character
  bool collision(int, int) const; //verifica las colisiones con otros objetos o derivados
  bool collision( const Character& p) const;//verifica las colisiones con otros objetos o derivados
  //accesors
  int get_rows() const;
  int get_cols() const;
private:
  int rows;
  int cols;
};


#endif

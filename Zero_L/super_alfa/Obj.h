#ifndef _OBJ_H_
#define _OBJ_H_

#include <curses.h>

class Obj{
public:
   Obj();
   Obj(int, int, char);//Objeto se construye con fila columna y textura
   virtual ~Obj() {};

   int x_pos() const;//Consulta la fila/y
   int y_pos() const;//Consulta la columna/x
   char txt() const;//Consulta la textura
   void draw() const;//Dibuja al objeto en el mapa

protected:
   int x; //columnas
   int y; //filas
   char texture; //Caracter que se va a dibujar
};

#endif

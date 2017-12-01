#ifndef _OBJ_H_
#define _OBJ_H_

#include <curses.h>

class Obj{
public:
   Obj();
   Obj(int, int, char);
   virtual ~Obj() {};

   int x_pos() const;//Consulta la fila/y
   int y_pos() const;//Consulta la columna/x
   void draw() const;//Dibuja al objeto en el mapa

protected:
   int x;
   int y;
   char texture;
};

#endif

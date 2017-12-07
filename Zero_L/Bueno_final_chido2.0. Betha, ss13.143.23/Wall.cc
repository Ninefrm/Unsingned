#include "Wall.h"

Wall::Wall() : Obj(1, 1, '#'){ //constructor por defecto de Wall
   rows = 2; //pone una matriz 2*2 de # en la posicion 1,1 sin imprimirla en pantalla
   cols = 2;
}

Wall::Wall(int w, int z, char brick, int r, int c) : Obj(w, z, brick){
   rows = r;
   cols = c;
}

void Wall::draw() const{ // metodo que imprime en pantalla la pared completa
   for(size_t i = 0; i <= rows; i++){//barre filas y columnas
      for(size_t j = 0; j <= cols; j++){
         mvaddch(y + i, x + j, texture);//muestra en pantalla la textura de la pared
      }
   }
}

bool Wall::collision(int xp, int yp) const{ //metodo recibe 2 enteros que indican la posicion de un objeto para verificar colisiones con la pared
   if(x <= xp && xp <= x + cols && y <= yp && yp <= y + rows){
      mvaddch(yp, xp, texture);//dibuja la pared sobre la posicion de la colision para que no pueda ser "destruida" al sobreponer otro character
      return true;
   }
   return false;
}

bool Wall::collision(const Character& p) const{//sobrecarga para una colision que recibe una posicion mediante un apuntador a Character
   return collision(p.x_pos(), p.y_pos());
}
//accesors
int Wall::get_rows() const{
   return rows;
}

int Wall::get_cols() const{
   return cols;
}

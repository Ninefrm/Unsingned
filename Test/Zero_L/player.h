#ifndef _PLAYER_H_
#define _PLAYER_H_

 #include "object.h"

 class Player{
 public:
   Player();
   Player(int maxheight, int maxwidth);
   ~Player() { };
   void playermovement();
   //void start();
   bool quit;

 private:
   Object P; //El personaje
   bool get; //interacciones
   char playerchar; //caracter que representa el personaje



 };
#endif

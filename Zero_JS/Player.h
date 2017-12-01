#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Obj.h"
#include "Character.h"
#include <curses.h>

class Player : public Character {
public:
   Player();
   Player(int, int);
   ~Player() { };
   int get_plus() const;
   int get_minus() const;
   void add_plus(int);
   void add_minus(int);
private:
   int plus;
   int minus;
};

#endif

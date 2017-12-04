#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Obj.h"
#include "Character.h"
#include "Sword.h"
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
   Obj atack(int);
   void take(Sword&);
private:
   int plus;
   int minus;
   Sword armament;
   bool armed;
};

#endif

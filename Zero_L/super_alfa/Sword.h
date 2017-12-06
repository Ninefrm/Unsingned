#ifndef SWORD_H
#define SWORD_H

#include "Obj.h"
#include "Character.h"

class Sword : public Obj{
public:
   Sword();
   Sword(int, Character*);
   ~Sword(){ };
   int damage() const;
   void set_pos(int key);
   int get_x_prev() const;
   int get_y_prev() const;
   //void use(int);
private:
   int _damage;
   Character* user;
   char dir;
   int x_prev;
   int y_prev;
};

#endif

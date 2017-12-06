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
   //void use(int);
private:
   int _damage;
   Character* user;
   char dir;
};

#endif

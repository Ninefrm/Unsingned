#ifndef SWORD_H
#define SWORD_H

#include "Obj.h"

class Sword : public Obj{
public:
   Sword();
   Sword(int, const Obj&);
   ~Sword(){ };
   Obj use(int);
   int damage() const;
private:
   int _damage;
};

#endif

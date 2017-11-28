//VICENTE RAMIREZ GONZALEZ
#ifndef _POTION_H_
#define _POTION_H_

#include "item.h"
#include "structs.h"

class Potion : public Item{
public:
  Potion();
  Potion( int, int, int, int, int, int );
  ~Potion();
  Stats drink();
  bool is_empty() const;
private:
protected:
  bool empty;
  Stats effect;
};

#endif

#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "Obj.h"

struct Character{
  public:
    Character();
    ~Character();
    void MoveCharacter();
    char Empty();
    bool Q();
  private:
    Obj P;
    char c='0';
    char empty=(char)129;
    int life=0;
    int plus=0;
    int minus=0;
    bool quit;
    bool get;
};

#endif

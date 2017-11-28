#include "potion.h"
#include "structs.h"

Potion::Potion(){

  empty = true;

}

Potion::Potion(int l,int s, int a, int ma, int d, int md){

  effect.luck = 0;
  effect.speed = 0;
  effect.armor = 0;
  effect.magic_armor = 0;
  effect.damage = 0;
  effect.magic_damage = 0;

  empty = true;

}

Stats Potion::drink(){

  if( empty ) return Stats ();

  return effect;

}

bool Potion::is_empty()const{

  return empty;

}

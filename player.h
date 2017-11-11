#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Figther"
#include "Point"
#include <vector>
#include "Pacific"

class Player:public Figther{

public:
  Player();
  ~Player();
  void level_up();
  int get_level();
  int get_xp();
  void boost_xp( int );
  int get_karma();
  void add_karma( int );


private:
  int xp;
  int level;
  int karma;

protected:


};


#endif

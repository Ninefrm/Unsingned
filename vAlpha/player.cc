#include "player.h"

Player::Player() : Figther(Point(0, 0), 50, "Cero"){
}

int Player::get_level() const{
   return level;
}
int Player::get_karma() const{
   return karma;
}
int Player::get_xp() const{
   return xp;
}

void Player::level_up(){
   if(level == max_level)
      return;
   level++;
}

void Player::boost_xp( unsigned int gained){
   xp += gained;
}

void Player::add_karma( int action){
   karma += action;
}

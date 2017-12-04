#include "Player.h"

Player::Player() : Character(50, 50, '0', 100){
   plus = 0;
   minus = 0;
   armament = Sword();
   armed = false;
}

Player::Player(int w, int z) : Character(w, z, '0', 100){
   plus = 0;
   minus = 0;
   armament = Sword();
   armed = false;
}

int Player::get_plus() const{
   return plus;
}

int Player::get_minus() const{
   return minus;
}

void Player::add_plus(int h){
   plus += h;
}

void Player::add_minus(int h){
   minus += h;
}

Obj Player::atack(int key){
   if(armed){
      return armament.use(key);
   }
   return Obj(-1, -1, '?');
}

void Player::take(Sword& s){
   armament = s;
   armed = true;
}

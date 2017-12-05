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

void Player::take(const Sword& s){
   armament = s;
   armed = true;
}

Sword Player::sword() const{
   if(!armed){
      return Sword();
   }
   return armament;
}

void Player::atack(int key){
   if(!armed){
      mvprintw(35, 0, "Desarmado");
      return;
   }
   mvprintw(35, 0, "Armado   ");
   armament.use(key);
}

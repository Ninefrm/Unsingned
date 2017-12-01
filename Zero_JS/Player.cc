#include "Player.h"

Player::Player() : Character(50, 50, '0', 100){
   plus = 0;
   minus = 0;
}

Player::Player(int w, int z) : Character(w, z, '0', 100){
   plus = 0;
   minus = 0;
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

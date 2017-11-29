#ifndef BASICS_H
#define BASICS_H

#include <curses.h>
#include <list>
#include <random>

class Bullet{
public:
   Bullet();
   Bullet(int, int, int, int, char, bool e = false);
   void upgrade();
   int xpos() const;
   int ypos() const;
   char bform() const;
   bool is_enemy() const;
private:
   int x, y, xspeed, yspeed, damage;
   char form;
   bool enemy;
};

class Basics{
public:
   Basics(int, int);
   ~Basics();
   void move(int);
   void shoot(int, int, int);
   void shoot(int, int);
   void shoot(int);
   void upgrade();
   int bullets();
private:
   int Xmax, Ymax, playerX, playerY;
   std::list <Bullet> bullets_displayed;
   std::mt19937 gen;
   std::uniform_int_distribution <int> rand_x;
   std::uniform_int_distribution <int> rand_y;
   std::uniform_int_distribution <int> rand_speed;
};

#endif

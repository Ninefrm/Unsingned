#include "basics.h"

Basics::Basics(int xm, int ym){
   static bool called = false;
   if(!called){
      Xmax = xm;
      Ymax = ym;
      playerX = 1;
      playerY = 1;
      called = true;
      gen.seed(-3123);
      rand_x = std::uniform_int_distribution <int> (1, xm);
      rand_y = std::uniform_int_distribution <int> (1, ym);
      rand_speed = std::uniform_int_distribution <int> (-3, 3);
   }
}

Basics::~Basics(){
   bullets_displayed.clear();
}

void Basics::move(int key){
   static int prevx, prevy;
   prevx = playerX;
   prevy = playerY;
   switch(key){
      case KEY_UP:
         if(playerY == 1){
            playerY = 1;
            prevy = 2;
         }
         else
            playerY--;
         mvaddch(playerY,playerX,'^');
         break;
      case KEY_DOWN:
         if(playerY == Ymax){
            playerY = Ymax;
            prevy = Ymax - 1;
         }
         else
            playerY++;
         mvaddch(playerY,playerX,'V');
         break;
      case KEY_LEFT:
         if(playerX == 1){
            playerX = 1;
            prevx = 2;
         }
         else
            playerX--;
         mvaddch(playerY,playerX,'<');
         break;
      case KEY_RIGHT:
         if(playerX == Xmax){
            playerX = Xmax;
            prevx = Xmax - 1;
         }
         else
           playerX++;
         mvaddch(playerY,playerX,'>');
         break;
   }
   mvaddch(prevy, prevx,' ');
}

void Basics::shoot(int key, int x0, int y0){
   int xs  = 0, ys = 0;
   switch(key){
      case 'w':
         ys --;
         break;
      case 'a':
         xs --;
         break;
      case 's':
         ys ++;
         break;
      case 'd':
         xs++;
         break;
      default:
         return;
   }
   bullets_displayed.push_back(Bullet(x0, y0, xs, ys, '.'));
}

void Basics::shoot(int key){
   int xs  = 0, ys = 0, h = 0, k = 0;
   switch(key){
      case 'w':
         ys -= 2;
         k --;
         break;
      case 'a':
         xs -= 2;
         h --;
         break;
      case 's':
         ys += 2;
         k ++;
         break;
      case 'd':
         xs += 2;
         h++;
         break;
      default:
         return;
   }
   bullets_displayed.push_back(Bullet(playerX + h, playerY + k, xs, ys, '*'));
}

void Basics::shoot(int x0, int y0){
   bullets_displayed.push_back(Bullet(x0, y0, rand_speed(gen), rand_speed(gen), 'x'));
}

void Basics::upgrade(){
   using namespace std;
   if(bullets_displayed.empty()){
      return;
   }
   list<Bullet>::iterator it = bullets_displayed.begin();
   for(int i = 0; i < bullets_displayed.size(); i++){
      mvaddch(it->ypos(), it->xpos(), ' ');
      it->upgrade();
      if(it->xpos() <= 0 || it->xpos() >= Xmax || it->ypos() <= 0 || it->ypos() >= Ymax){
         bullets_displayed.erase(it);
         continue;
      }
      mvaddch(it->ypos(), it->xpos(), it->bform());
      it++;
   }
}

int Basics::bullets(){
   return bullets_displayed.size();
}

Bullet::Bullet(){
   x = 0;
   y = 0;
   xspeed = 1;
   yspeed = 0;
   form = '.';
   enemy = true;
}

Bullet::Bullet(int x0, int y0, int xs, int ys, char d, bool e){
   x = x0;
   y = y0;
   xspeed = xs;
   yspeed = ys;
   form = d;
   enemy = e;
}

int Bullet::xpos() const{
   return x;
}

int Bullet::ypos() const{
   return y;
}

char Bullet::bform() const{
   return form;
}

void Bullet::upgrade(){
   x += xspeed;
   y += yspeed;
}

bool Bullet::is_enemy() const{
   return enemy;
}

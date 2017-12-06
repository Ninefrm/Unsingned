#include "Mapa.h"

Mapa::Mapa(){
   player = nullptr;
   rows = 60;
   cols = 30;
}

Mapa::Mapa(Character* p, std::vector<Wall> w, int r, int c){
   player = p;
   walls = w;
   rows = r;
   cols = c;
   int x = p->x_pos(), y = p->y_pos();
   inside = (0 < x && x < cols && 0 < y && y < rows);
   motor.seed(time(nullptr));
   rand_x = std::uniform_int_distribution<int> (2, cols - 2);
   rand_y = std::uniform_int_distribution<int> (2, rows - 2);
   rand_mov = std::uniform_int_distribution<int> (-1, 1);
}

void Mapa::draw_walls(){
   for(size_t i = 0; i < walls.size(); i++){
      walls[i].draw();
   }
}

bool Mapa::wall_colision() const{
   for(size_t i = 0; i < walls.size(); i++){
      if(walls[i].collision(*player)){
         return true;
      }
   }
   return false;
}

bool Mapa::wall_colision(int xp, int yp) const{
   for(size_t i = 0; i < walls.size(); i++){
      if(walls[i].collision(xp, yp)){
         return true;
      }
   }
   return false;
}

bool Mapa::outside() const{
   int xp = player->x_pos(), yp = player->y_pos();
   return !(0 < xp && xp < cols && 0 < yp && yp < rows);
}

void Mapa::generate_enemy(){
   int x = rand_x(motor),
       y = rand_y(motor);
   for(int i = 0; i < walls.size(); i++){
      if(walls[i].collision(x, y)){
         x = walls[i].x_pos() - 1;
         y = walls[i].y_pos() + walls[i].get_rows() + 1;
         break;
      }
   }
   enemys = Enemy(y, x, '@', 100, 8);
   enemys.draw();
}

void Mapa::move_enemys(){
   if(enemys.life() <= 0){
      return;
   }
   int x = enemys.x_pos(),
           y = enemys.y_pos(),
           mx = rand_mov(motor),
           my = rand_mov(motor);

   if(!wall_colision(x + mx, y + my)){
       mvaddch(enemys.y_pos(), enemys.x_pos(), ' ');
       enemys.move_x(mx);
       enemys.move_y(my);
    }
    else if(!wall_colision(x - mx, y + my)){
       mvaddch(enemys.y_pos(), enemys.x_pos(), ' ');
       enemys.move_x(-mx);
       enemys.move_y(my);
    }
    else if(!wall_colision(x + mx, y - my)){
      mvaddch(enemys.y_pos(), enemys.x_pos(), ' ');
      enemys.move_x(mx);
      enemys.move_y(-my);
    }
    else if(!wall_colision(x - mx, y - my)){
      mvaddch(enemys.y_pos(), enemys.x_pos(), ' ');
      enemys.move_x(-mx);
      enemys.move_y(-my);
    }
}

void Mapa::move_agresive(){
   if(enemys.life() <= 0){
      return;
   }
   if(enemys.in_range(*player)){
      mvaddch(enemys.y_pos(), enemys.x_pos(), ' ');
      enemys.stalk(*player);
   }
   return;
}

bool Mapa::enemys_colision(){
   if(enemys.life() <= 0){
      return false;
   }
   bool c = (player->x_pos() == enemys.x_pos() && player->y_pos() == enemys.y_pos());
   if(c){
      player->add_life(-enemys.damage());
   }
   return c;
}

bool Mapa::enemys_colision(const Obj& w, int dmg){
   if(enemys.life() <= 0){
      return false;
   }
   bool c = (w.x_pos() == enemys.x_pos() && w.y_pos() == enemys.y_pos());
   if(c){
      enemys.add_life(-dmg);
   }
   return c;
}

void Mapa::draw_enemys(){
   if(enemys.life() <= 0){
      return;
   }
   enemys.draw();
}

bool Mapa::enemys_colision(const Sword espada){
  
}

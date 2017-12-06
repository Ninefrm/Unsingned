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

bool Mapa::wall_colision() const {
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
   if(enemys.size() == max_n_enemys){
      return;
   }
   int x = rand_x(motor),
       y = rand_y(motor);
   for(int i = 0; i < walls.size(); i++){
      if(walls[i].collision(x, y)){
         x = walls[i].x_pos() - 1;
         y = walls[i].y_pos() + walls[i].get_rows() + 1;
         break;
      }
   }
   enemys.push_back(Enemy(y, x, '@', 1, 8));
   draw_enemys();
}

void Mapa::move_enemy(Enemy& enemy){
   int x = enemy.x_pos(),
           y = enemy.y_pos(),
           mx = rand_mov(motor),
           my = rand_mov(motor);

   if(!wall_colision(x + mx, y + my)){
       mvaddch(enemy.y_pos(), enemy.x_pos(), ' ');
       enemy.move_x(mx);
       enemy.move_y(my);
    }
    else if(!wall_colision(x - mx, y + my)){
       mvaddch(enemy.y_pos(), enemy.x_pos(), ' ');
       enemy.move_x(-mx);
       enemy.move_y(my);
    }
    else if(!wall_colision(x + mx, y - my)){
      mvaddch(enemy.y_pos(), enemy.x_pos(), ' ');
      enemy.move_x(mx);
      enemy.move_y(-my);
    }
    else if(!wall_colision(x - mx, y - my)){
      mvaddch(enemy.y_pos(), enemy.x_pos(), ' ');
      enemy.move_x(-mx);
      enemy.move_y(-my);
    }
}

void Mapa::move_enemys(){
   if(enemys.empty()){
      return;
   }
   for(auto it = enemys.begin(); it != enemys.end(); ++it){
      if(it->life() == 0){
         continue;
      }
      move_enemy(*it);
   }
}

void Mapa::move_agresive(){
   if(enemys.empty()){
      return;
   }
   for(auto it = enemys.begin(); it != enemys.end(); ++it){
      if(it->in_range(*player)){
         mvaddch(it->y_pos(), it->x_pos(), ' ');
         it->stalk(*player);
         return;
      }
   }
}

bool Mapa::enemys_colision(){
   if(enemys.empty()){
      return false;
   }
   bool c = false;
   int xp = player->x_pos(),
       yp = player->y_pos();
   for(auto it = enemys.begin(); it != enemys.end(); ++it){
      if(xp == it->x_pos() && yp == it->y_pos() && it->life() > 0){
        c = true;
        player->add_life(-it->damage());
        break;
      }
   }
   return c;
}

bool Mapa::enemys_colision(const Obj& w, int dmg){
   if(enemys.empty()){
      return false;
   }
   bool c = false;
   int xp = w.x_pos(),
       yp = w.y_pos();
   for(auto it = enemys.begin(); it != enemys.end(); ++it){
      if(xp == it->x_pos() && yp == it->y_pos() && it->life() > 0){
         c = true;
         it->add_life(-dmg);
         break;
      }
   }
   return c;
}

void Mapa::draw_enemys(){
   remove_dead();
   if(enemys.empty()){
      return;
   }
   for(auto it = enemys.begin(); it != enemys.end(); ++it){
      it->draw();
   }
}

void Mapa::remove_dead(){
   if(enemys.empty()){
      return;
   }
   for(auto it = enemys.begin(); it != enemys.end(); ++it){
      if(it->life() <= 0){
         mvaddch(it->y_pos(), it->x_pos(), ' ');
         enemys.erase(it);
         continue;
      }
   }
}

void Mapa::remove_enemys(){
   if(enemys.empty()){
      return;
   }
   for(auto it = enemys.begin(); it != enemys.end(); ++it){
      mvaddch(it->y_pos(), it->x_pos(), ' ');
   }
   enemys.clear();
}

bool Mapa::enemys_colision(const Sword espada){
  if(enemys.empty()) return false;

  bool c = false;
  int xp = espada.x_pos();
  int yp = espada.y_pos();

  //mvprintw(37, 0, "pos en x sword: %3d", xp);
  //mvprintw(38, 0, "pos en y sword: %3d", yp);

  for(auto it = enemys.begin(); it != enemys.end(); ++it){
    if(xp == it->x_pos() && yp == it->y_pos() && it->life() > 0){
       c = true;
       //mvprintw(36, 0, "enemy life: %d", it->life());
       it->add_life(-espada.damage() );
       //mvprintw(36, 0, "enemy life: %d", it->life());
       break;
  }
}
return c;
}

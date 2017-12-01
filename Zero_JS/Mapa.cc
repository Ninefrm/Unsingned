#include "Mapa.h"

Mapa::Mapa(){
   player = Character();
   rows = 80;
   cols = 40;
}

Mapa::Mapa(Character& p, std::vector<Wall> w){
   player = p;
   walls = w;
   rows = 80;
   cols = 40;
   int x = p.x_pos(), y = p.y_pos();
   inside = (0 < x && x < cols && 0 < y && y < rows);
   motor.seed(time(nullptr));
   rand_x = std::uniform_int_distribution<int> (1, cols - 1);
   rand_y = std::uniform_int_distribution<int> (1, rows - 1);
   rand_mov = std::uniform_int_distribution<int> (-1, 1);
}

void Mapa::start(){
   for(size_t i = 0; i < walls.size(); i++){
      walls[i].draw();
   }
}

bool Mapa::wall_colision() const{
   for(int i = 0; i < walls.size(); i++){
      if(walls[i].collision(player)){
         return true;
      }
   }
   return false;
}

bool Mapa::wall_colision(int xp, int yp) const{
   for(int i = 0; i < walls.size(); i++){
      if(walls[i].collision(xp, yp)){
         return true;
      }
   }
   return false;
}

bool Mapa::outside() const{
   int xp = player.x_pos(), yp = player.y_pos();
   return (0 < xp && xp < cols && 0 < yp && yp < rows);
}

void Mapa::generate_enemy(){
   enemys = Enemy(10, 10, '@', 100, 2);
   enemys.draw();
   return;
   int x = rand_x(motor),
       y = rand_y(motor);
   for(int i = 0; i < walls.size(); i++){
      if(!walls[i].collision(x, y)){
         x = walls[i].x_pos() - 1;
         y = walls[i].y_pos() + walls[i].get_rows() + 1;
         break;
      }
   }
   enemys = Enemy(x, y, '@', 100, 2);
   enemys.draw();
}

void Mapa::move_enemys(){
    int x = enemys.x_pos(),
           y = enemys.y_pos(),
           mx = rand_mov(motor),
           my = rand_mov(motor);
    if(!wall_colision(x + mx, y + my)){
       enemys.move_x(mx);
       enemys.move_y(my);
    }
    else if(!wall_colision(x - mx, y + my)){
       enemys.move_x(-mx);
       enemys.move_y(my);
    }
    else if(!wall_colision(x + mx, y - my)){
      enemys.move_x(mx);
      enemys.move_y(-my);
    }
    else if(!wall_colision(x - mx, y - my)){
      enemys.move_x(-mx);
      enemys.move_y(-my);
    }
    enemys.draw();
}

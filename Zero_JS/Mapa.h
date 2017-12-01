#ifndef _MAPA_H_
#define _MAPA_H_

#include <vector>
#include <random>
#include <ctime>
#include "Obj.h"
#include "Wall.h"
#include "Character.h"
#include "Enemy.h"

class Mapa{
  public:
    Mapa();
    Mapa(Character&, std::vector<Wall>);
    bool wall_colision() const;//Verifica si el jugador colisiona con alguo de los muros
    bool wall_colision(int, int) const;//Verifica si la posicion (x, y) colisiona con alguno de los muros
    bool outside() const;
    void generate_enemy();
    void move_enemys();
    void start();//Dibuja los muros

  private:
    int rows;
    int cols;
    std::mt19937 motor;
    std::uniform_int_distribution<int> rand_x;
    std::uniform_int_distribution<int> rand_y;
    std::uniform_int_distribution<int> rand_mov;
    std::vector<Wall> walls;
    Character player;
    Enemy enemys;
    bool inside;
};

#endif

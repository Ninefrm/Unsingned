#ifndef _MAPA_H_
#define _MAPA_H_

//librerias
#include <vector>
#include <list>
#include <random>
#include <curses.h>
#include <ctime>
#include "Obj.h"
#include "Wall.h"
#include "Character.h"
#include "Enemy.h"
#include "Sword.h"
#include <exception>

class Mapa{
  public:
    //constructores
    Mapa();
    Mapa(Character* , std::vector<Wall>, int, int);
    //destructor
    ~Mapa(){ };
    //colisiones
    bool wall_colision() const;//Verifica si el jugador colisiona con alguo de los muros
    bool wall_colision(int, int) const;//Verifica si la posicion (x, y) colisiona con alguno de los muros
    bool enemys_colision();
    bool enemys_colision(const Obj&, int);
    bool enemys_colision(const Sword espada);
    //control de enemigos
    void generate_enemy();
    void move_enemys();
    void move_enemy(Enemy&);
    void move_agresive();
    void draw_enemys();
    void remove_enemys();

    void draw_walls();//Dibuja los muros
    bool outside() const;

  private:
    void remove_dead();//Elimina de la lista los enemigos muertos
    int rows;
    int cols;
    std::mt19937 motor;
    std::uniform_int_distribution<int> rand_x;
    std::uniform_int_distribution<int> rand_y;
    std::uniform_int_distribution<int> rand_mov;
    std::vector<Wall> walls;
    Character* player;
    std::list<Enemy> enemys;
    static const size_t max_n_enemys = 5;
    bool inside;
};

#endif

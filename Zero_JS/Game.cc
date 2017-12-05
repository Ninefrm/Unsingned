#include "Game.h"

Game::Game(){
   initscr(); //inicializar pantalla
   nodelay(stdscr,false); //Espera tecla para moverse
   keypad(stdscr,true); //Habilita el teclado
   timeout(166);//Tiempo de espera de getch antes de regresar error
   noecho(); //No sale lo que escribes
   curs_set(0); //Cursor no visible
   player = Player(12, 12);
   player.take(Sword(10, &player));
   motor.seed(time(nullptr));
   coin = std::bernoulli_distribution(0.5);
   end = false;
   std::vector<Wall> w;
   w.push_back(Wall(0, 0, char(129), 0, 61));
   w.push_back(Wall(1, 0, char(129), 31, 0));
   w.push_back(Wall(1, 61, char(129), 29, 0));
   w.push_back(Wall(33, 0, char(129), 0, 61));
   w.push_back(Wall(15, 1, '#', 5, 10));
   w.push_back(Wall(5, 20, ':', 20, 0));
   w.push_back(Wall(3, 1, ':', 0, 35));
   w.push_back(Wall(31, 4, ':', 0, 20));
   maps.push_back(Mapa(&player, w, 32, 61));
   w.resize(5);
   w[0] = Wall(0, 0, char(129), 0, 61);
   w[1] = Wall(1, 0, char(129), 29, 0);
   w[2] = Wall(1, 61, char(129), 32, 0);
   w[3] = Wall(33, 0, char(129), 0, 61);
   w[5] = Wall(20, 3, '&', 4, 4);
   maps.push_back(Mapa(&player, w, 30, 61));
}

Game::~Game(){
   curs_set(1);
   nodelay(stdscr,false); //cerrar
   endwin();
}

void Game::start(){
   mvprintw(20, 20,"READY PLAYER ONE?, press a key");
   refresh();
   while(getch() < 0);
   flash();
   clear();
}

void Game::loop(){
   int key = 0, prev_x, prev_y;
   Mapa *curr_map = &maps[0];
   maps[0].draw_walls();
   maps[0].generate_enemy();
   do{
      prev_x = player.x_pos();
      prev_y = player.y_pos();
      mvprintw(35, 0, "(-): %3d (+): %3d (<3): %3d <Input: %3d> <x: %3d> <y: %3d>",
               player.get_minus(), player.get_plus(), player.life(), key, player.x_pos(), player.y_pos());
      if(player.x_pos() < 0 || player.y_pos() < 0){
         break;
      }
      if(curr_map->outside()){
         mvprintw(34, 0, "Fuera del mapa ");
         player.move(12, 12);
         curr_map = &maps[1];
         clear();
         curr_map->draw_walls();
      }
      else{
         mvprintw(34, 0, "Dentro del mapa");
      }
      player.draw();
      key = getch();
      move_player(key);
      if(curr_map->wall_colision()){
         player.move(prev_y, prev_x);
         player.add_life(-1);
         curr_map->draw_walls();
      }

      if(curr_map->enemys_colision()){
         player.move(prev_y, prev_x);
      }
      end = (player.life() <= 0);
      if(coin(motor)){
         curr_map->move_agresive();
      }
      else{
         curr_map->move_enemys();
      }
      curr_map->draw_enemys();
      refresh();
   }while(!end);
   clear();
   flash();
   mvprintw(20, 20,"WASTED!");
   while(getch() < 0);
}

void Game::move_player(int key){
   switch (key) {
      case KEY_UP:
         player.move_y(-1);
         return;
      case KEY_DOWN:
         player.move_y(1);
         return;
      case KEY_LEFT:
         player.move_x(-1);
         return;
      case KEY_RIGHT:
         player.move_x(1);
         return;
   }
}

void Game::atack(int key){
   if(key != 'w' && key != 's' && key != 'a' && key != 'd'){
      return;
   }
   /*
   static Sword w;
   player.atack(key);
   w = player.sword();
   mvprintw(34, 0, "Sword <x:%3d> <y:%3d>", w.x_pos(), w.y_pos());
   if(maps[0].wall_colision(w.x_pos(), w.y_pos())){
      return;
   }
   if(maps[0].enemys_colision(w, w.damage())){
      return;
   }
   w.draw();
   */
}

/*
Game::Game(){
    initscr(); //inicializar pantalla
    nodelay(stdscr,false); //Espera tecla para moverse
    keypad(stdscr,true); //Habilita el teclado
    noecho(); //No sale lo que escribes
    curs_set(0); //Cursor no visible
    getmaxyx(stdscr, maxheight, maxwidth); //Obtiene el Max (Width/Height), de la pantalla.
    move(maxheight/2-2,maxwidth/2-17);
    printw("READY PLAYER ONE?, press a key");
    getch();
    clear();
    Character P;
    Border();

    delay=1000000;

    Start(P);
}
Game::~Game(){
  nodelay(stdscr,false); //cerrar
  endwin();
}
int Game::MaxW() const{
  return maxwidth;
}
int Game::MaxH() const{
  return maxheight;
}
void Game::Start(Character &P){
  while(1){
    getmaxyx(stdscr, maxheight, maxwidth);
    if(P.Collision()){
      move(maxheight/2-1,maxwidth/2-9);
      printw("GAME OVER");
      break;
    }
    P.MoveCharacter();
  }
}
void Game::Border(){
  //MARGEN
  for(int i=0;i<78;i++){
    move(0,i);
    addch((char)129);
  }//Izquierda-Horizontal
  for(int i=0;i<22;i++){
    move(i,0);
    addch((char)129);
  }//Abajo-Vertical
  for(int i=0;i<79;i++){
    move(23,i);
    addch((char)129);
  }//Derecha Horizontal
  for(int i=0;i<22;i++){
    move(i,78);
    addch((char)129);
  }
  //MARGEN
}
*/

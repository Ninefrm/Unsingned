#include "Game.h"

Game::Game(){
   initscr(); //inicializar pantalla
   nodelay(stdscr,false); //Espera tecla para moverse
   keypad(stdscr,true); //Habilita el teclado
   timeout(166);//Tiempo de espera de getch antes de regresar error
   noecho(); //No sale lo que escribes
   curs_set(0); //Cursor no visible
   player = Player(12, 12);
   motor.seed(time(nullptr));
   coin = std::bernoulli_distribution(0.5);
   end = false;
   std::vector<Wall> w;
   w.push_back(Wall(1, 0, char(129), 0, 61));
   w.push_back(Wall(2, 0, char(129), 40, 0));
   w.push_back(Wall(2, 61, char(129), 40, 0));
   w.push_back(Wall(43, 0, char(129), 0, 61));
   w.push_back(Wall(15, 1, '#', 5, 10));
   w.push_back(Wall(5, 20, ':', 20, 0));
   w.push_back(Wall(3, 1, ':', 0, 45));
   w.push_back(Wall(41, 4, ':', 0, 20));
   maps.resize(1);
   maps[0] = Mapa(&player, w);
}

Game::~Game(){
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
   maps[0].draw_walls();
   maps[0].generate_enemy();
   do{
      prev_x = player.x_pos();
      prev_y = player.y_pos();
      mvprintw(0, 0, "(-): %3d (+): %3d (<3): %3d <Input: %3d> <x: %3d> <y: %3d>",
               player.get_minus(), player.get_plus(), player.life(), key, player.x_pos(), player.y_pos());
      if(player.x_pos() < 0 || player.y_pos() < 0){
         break;
      }
      player.draw();
      key = getch();
      move_player(key);
      if(maps[0].wall_colision()){
         player.move(prev_y, prev_x);
         player.add_life(-1);
         maps[0].draw_walls();
      }
      if(maps[0].enemys_colision()){
         player.move(prev_y, prev_x);
      }
      end = (player.life() <= 0);
      if(coin(motor)){
         maps[0].move_agresive();
      }
      else{
         maps[0].move_enemys();
      }
      maps[0].draw_enemys();
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

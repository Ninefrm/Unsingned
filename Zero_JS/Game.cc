#include "Game.h"

Game::Game(){
   initscr(); //inicializar pantalla
   nodelay(stdscr,false); //Espera tecla para moverse
   keypad(stdscr,true); //Habilita el teclado
   timeout(100);//Tiempo de espera de getch antes de regresar error
   noecho(); //No sale lo que escribes
   curs_set(0); //Cursor no visible
   player = Player(2, 2);
   end = false;
   std::vector<Wall> w;
   w.push_back(Wall(0, 1, '-', 1, 10));
   w.push_back(Wall(0, 2, '|', 10, 1));
   maps.resize(1);
   maps[0] = Mapa(player, w);
}

Game::~Game(){
   nodelay(stdscr,false); //cerrar
   endwin();
}

void Game::start(){
   mvprintw(50, 50,"READY PLAYER ONE?, press a key");
   refresh();
   while(getch() < 0);
   flash();
   clear();
}

void Game::loop(){
   int key = 0;
   maps[0].start();
   maps[0].generate_enemy();
   do{
      mvprintw(0, 0, "(-): %3d (+): %3d <3: %d input: %3d", player.get_minus(), player.get_plus(), player.life(), key);
      player.draw();
      key = getch();
      move_player(key);
      end = maps[0].wall_colision();
      maps[0].move_enemys();
      refresh();
   }while(end);
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

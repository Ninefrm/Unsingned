 #include "Game.h"

Game::Game(){

  //iniciando curses
   initscr(); //inicializar pantalla
   nodelay(stdscr,false); //Espera tecla para moverse
   keypad(stdscr,true); //Habilita el teclado
   timeout(166);//Tiempo de espera de getch antes de regresar error
   noecho(); //No sale lo que escribes
   curs_set(0); //Cursor no visible

   //inicializando al jugador
   player = Player(12, 12); //Inicializa al jugador en las coordenadas 12, 12
   player.take(Sword(100, &player)); //el jugador obtiene la espada

   //inciando numeros aleatorios
   motor.seed(time(nullptr)); // semilla para pseudogeneracionde numeros aleatorios
   coin = std::bernoulli_distribution(0.3); //distribucion de los numeros aleatorio

   end = false;

   //creando mapas
   maps.resize(3);
   std::vector<Wall> w(6);
   w[0] = Wall(0, 0, char(129), 0, 61);
   w[1] = Wall(2, 0, char(129), 29, 0);
   w[2] = Wall(31, 0, char(129), 0, 61);
   w[3] = Wall(0, 61, char(129), 31, 0);
   w[4] = Wall(5, 5, 'd', 4,4);
   w[5] = Wall(12, 1, 'c', 5, 0);
   maps[0] = Mapa(&player, w, 32, 62);
   w[0] = Wall(0, 0, char(129), 0, 3);
   w[1] = Wall(0, 5, char(129), 0, 56);
   w[2] = Wall(2, 61, char(129), 29, 0);
   w[3] = Wall(0, 0, char(129), 31, 0);
   w[4] = Wall(31, 0, char(129), 0, 61);
   w[5] = Wall(10, 10, 'b', 5, 2);
   maps[1] = Mapa(&player, w, 32, 62);
   w[0] = Wall(0, 0, char(129), 0, 61);
   w[1] = Wall(1, 0, char(129), 30, 0);
   w[2] = Wall(1, 61, char(129), 30, 0);
   w[3] = Wall(31, 0, char(129), 0, 3);
   w[4] = Wall(31, 5, char(129), 0, 56);
   w[5] = Wall(10, 21, 'a', 5, 2);
   maps[2] = Mapa(&player, w, 32, 62);
}

Game::~Game(){ //destructor del juego cierra ncurses
   curs_set(1); //el puntero se vuele visible de nuevo
   nodelay(stdscr,false); //cerrar ncurses
   endwin(); //cierra la ventana de curses
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
   do{
      prev_x = player.x_pos();
      prev_y = player.y_pos();
      mvprintw(35, 0, "(-): %3d (+): %3d (<3): %3d <Input: %3d> <x: %3d> <y: %3d>",
               player.get_minus(), player.get_plus(), player.life(), key, player.x_pos(), player.y_pos());
      if(player.x_pos() < 0 || player.y_pos() < 0){
         break;
      }
      if(curr_map->outside()){
         change_map(curr_map);
         continue;
      }
      else{
         mvprintw(34, 0, "Dentro del mapa");
      }

      // el jugador se imprime en pantalla
      player.draw();
      //key rcomienza a recibir las entradas del teclado
      key = getch();
      //la funcion de Game mueve al jugador con las flechas direccionales
      move_player(key);

      //uso de la espada, se restringe solo a las teclas w, a, s, d.
      if(key == 'w' || key == 'a' || key == 's' || key == 'd')
      {
        Sword espada = player.atack(key);
        curr_map->wall_colision(espada.x_pos(), espada.y_pos());

        curr_map->enemys_colision(espada);
      }

      //se checa la colision del jugador con muros para cada movimiento
      if(curr_map->wall_colision()){
         player.move(prev_y, prev_x);
         player.add_life(-1);
         curr_map->draw_walls();
      }
      //se checa la colision de enemuigos con muros para cada movimiento
      if(curr_map->enemys_colision()){
         player.move(prev_y, prev_x);
      }

      //un generador de numeros aleatorio determina la probabilidad de que el enemigo ataque directamente al jugador o siga moviendose aleatoriamente
      if(coin(motor)){
         curr_map->move_agresive();
      }
      else{
         curr_map->move_enemys();
      }

      //exception
      if(coin(motor)){
         try{
            curr_map->generate_enemy();
         }
         catch(std::bad_alloc& ex){
            mvprintw(36, 0, "No se pudo generar un enemigo");
         }
      }

      if(key == 'q'){
         curr_map->remove_enemys();
      }
      curr_map->draw_enemys();
      refresh();
      end = (player.life() <= 0);
   }while(!end); //termina el loop

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
}

void Game::change_map(Mapa*& curr){
   if(curr == &maps[0]){
      player.move(1, 60);
      curr = &maps[1];
   }
   else if(curr == &maps[1]){
      if(player.x_pos() == 62 && player.y_pos() == 1){
         player.move(1, 1);
         curr = &maps[0];
      }
      else{
         player.move(30, 4);
         curr = &maps[2];
      }
   }
   else if(curr == &maps[2]){
      player.move(1, 4);
      curr = &maps[1];
   }
   clear();
   curr->draw_walls();
   refresh();
}

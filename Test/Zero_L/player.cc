#include "player.h"

Player::Player() {
  playerchar='0'; // char que representa al jugador
  get=false;
  P.x=0; //asignando la posicion en x de player
  P.y=0; //asignando la posicion en y de player
  move(P.y,P.x); //moviendo el cursos a donde se dibujara player
  addch(playerchar); // dibujando player
  refresh();
}

Player::Player(int maxheight, int maxwidth){
  playerchar='0'; // char que representa al jugador
  get=false;
  P.x=maxwidth/2; //asignando la posicion en x de player
  P.y=maxheight/2; //asignando la posicion en y de player
  move(P.y,P.x); //moviendo el cursos a donde se dibujara player
  addch(playerchar); // dibujando player
  refresh();
}

void Player::playermovement(){
  int key = getch();
  move(P.y, P.x);
  printw(" ");

  switch (key) {
    case KEY_LEFT:
    P.x--;
    break;
    case KEY_RIGHT:
    P.x++;
    break;
    case KEY_UP:
    P.y--;
    break;
    case KEY_DOWN:
    P.y++;
    break;
    case 27:
    quit=true;
  }
  move(P.y, P.x);
  addch(playerchar);
  refresh();
}

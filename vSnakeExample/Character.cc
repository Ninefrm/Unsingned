#include "Character.h"

using namespace std;

void Character::putObj(){
    while(1){
  		int tmpx=rand()%maxwidth+1;
  		int tmpy=rand()%maxheight+1;
  		if(tmpx>=maxwidth-2 || tmpy>=maxheight-3)
  			continue;
  		    Up.x=tmpx;
  		    Up.y=tmpy;
  		break;
  	}
  	move(Up.y,Up.x);
  	addch(etel);
  	refresh();
}
bool Character::collision(){
  if(P.x==0 || P.x==maxwidth-1 || P.y==0 || P.y==maxheight-2)
  		return true;
  	//collision con los 1
  if(P.x==Up.x && P.y==Up.y){
  	//get=true;
  	putObj();
		//points+=10;
		move(maxheight-1,0);
  	printw("%d",points);
		/*if((points%100)==0)
			del-=10000;*/
    //return true;
  }else
  	get=false;
  	return false;
}
void Character::moveCharacter(){
  int tmp=getch(); //TMP Será nuestra tecla oprimida.
  switch(tmp){
    case KEY_LEFT:
  	 //if(direction!='r')
  			direction='l';
        break;
  	case KEY_UP:
  		//if(direction!='d')
  			direction='u';
  			break;
  	case KEY_DOWN:
  		//if(direction!='u')
  			direction='d';
  			break;
		case KEY_RIGHT:
  		//if(direction!='l')
  			direction='r';
  		    break;
  	case KEY_BACKSPACE: //Barra para salir
  		direction='q';
      addch(partchar);
    	refresh();
  		break;
  }

  if(!get){
    move(P.y, P.x);
    printw(" ");
    refresh();
  }
  if(direction=='l'){ //Cuando es Izquierda
    P.x--;
  }else if(direction=='r'){ //Derecha
  	P.x++;
  }else if(direction=='u'){ //Arriba
  	P.y--;
  }else if(direction=='d'){ //Abajo
  	P.y++;
  }
  	move(P.y,P.x);
  	addch(partchar);
  	refresh();
}
Character::Character(){
  initscr(); //inicializar pantalla
  nodelay(stdscr,false); //No espera key
  keypad(stdscr,true); //habilita teclado
  noecho(); //no escribe
  curs_set(0); //cursor invisible
  getmaxyx(stdscr, maxheight, maxwidth);
  partchar='0';
  oldalchar=(char)129;
  etel='1';
  Up.x=0;
  Up.y=0;
  //for(int i=0;i<5;i++)
  P.x=40;
  P.y=10;
  points=0;
  del=110000;
  get=0;
  direction='l';
  srand(time(NULL));
  putObj();
    //CREAR EL MARGEN->
    //Vertical-Arriba
  for(int i=0;i<maxwidth-1;i++){
    move(0,i);
    addch(oldalchar);
  }
    //Izquierda-Horizontal
  for(int i=0;i<maxheight-1;i++){
    move(i,0);
    addch(oldalchar);
  }
    //Abajo-Vertical
  for(int i=0;i<maxwidth-1;i++){
  	move(maxheight-2,i);
  	addch(oldalchar);
  }
    //Derecha Horizontal
  for(int i=0;i<maxheight-1;i++){
  	move(i,maxwidth-2);
  	addch(oldalchar);
  }
    //Se creó el margen<-
    //Dibujar personaje ->
    move(P.y,P.x);
    addch(partchar);
  move(maxheight-1,0);
  printw("%d",points);
  move(Up.y,Up.x);
  addch(etel);
  refresh();
}
Character::~Character(){
  nodelay(stdscr,false); //Cerramos
  getch(); //Esperamos una tecla para cerrar
  endwin();
}
void Character::start(){
  while(1){
    if(collision()){
      move(10,30);
      printw("GAME OVER");
      break;
    }
    moveCharacter();
    if(direction=='q') //break
      break;
      usleep(del);
  }
}

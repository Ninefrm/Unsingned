#include "Character.h"

using namespace std;

Obj::Obj(int col, int row){
  x=col;
  y=row;
}
Obj::Obj(){
  x=0;
  y=0;
}
void Character::putObj(){
    while(1){
  		int tmpx=rand()%maxwidth+1;
  		int tmpy=rand()%maxheight+1;
  		for(int i=0;i<P.size();i++)
  			if(P[i].x==tmpx && P[i].y==tmpy)
  				continue;
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
  if(P[0].x==0 || P[0].x==maxwidth-1 || P[0].y==0 || P[0].y==maxheight-2)
  		return true;
	for(int i=2;i<P.size();i++){
  	if(P[0].x==P[i].x && P[0].y==P[i].y)
  		return true;
  }
  	//collision con los 1
  if(P[0].x==Up.x && P[0].y==Up.y){
  	get=true;
  	putObj();
		points+=10;
		move(maxheight-1,0);
  	printw("%d",points);
		if((points%100)==0)
			del-=10000;
  }else
  	get=false;
  	return false;
}
void Character::moveCharacter(){
  int tmp=getch(); //TMP Será nuestra tecla oprimida.
  switch(tmp){
    case KEY_LEFT:
  	 if(direction!='r')
  			direction='l';
        break;
  	case KEY_UP:
  		if(direction!='d')
  			direction='u';
  			break;
  	case KEY_DOWN:
  		if(direction!='u')
  			direction='d';
  			break;
		case KEY_RIGHT:
  		if(direction!='l')
  			direction='r';
  		    break;
  	case KEY_BACKSPACE: //Barra para salir
  		direction='q';
  		break;
  }
  if(!get){
    //move(P[P.size()-1].y, P[P.size()-1].x);
    printw(" ");
    refresh();
    P.pop_back();
  }

  if(direction=='l'){ //Cuando es Izquierda
    P.insert(P.begin(),Obj(P[0].x-1,P[0].y));
  }else if(direction=='r'){ //Derecha
  	P.insert(P.begin(),Obj(P[0].x+1,P[0].y));
  }else if(direction=='u'){ //Arriba
  	P.insert(P.begin(),Obj(P[0].x,P[0].y-1));
  }else if(direction=='d'){ //Abajo
  	P.insert(P.begin(),Obj(P[0].x,P[0].y+1));
  }
  	move(P[0].y,P[0].x);
  	addch(partchar);
  	refresh();
}
Character::Character(){
  initscr(); //inicializar pantalla
  nodelay(stdscr,true); //No espera key
  keypad(stdscr,true); //habilita teclado
  noecho(); //no escribe
  curs_set(0); //cursor invisible
  getmaxyx(stdscr, maxheight, maxwidth);
  partchar='0';
  oldalchar=(char)129;
  etel='1';
  Up.x=0;
  Up.y=0;
  for(int i=0;i<5;i++)
    P.push_back(Obj(40+i,10));
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
    move(P[0].y,P[0].x);
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

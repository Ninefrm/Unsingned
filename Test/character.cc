#include "character.h"


/*map::map(int col, int row){
  x=col;
  y=row;
}
map::map(){
  x=0;
  y=0;
}
*/
Character::Character(){
  initscr();
  nodelay(stdscr,true);
  keypad(stdscr,true);
  noecho();
  curs_set(0); //cursor invisible
  getmaxyx(stdscr,maxheight,maxwidth);
  //init variables
  partchar='0';
  oldalchar=(char)219;
  get=false;
  direction='l';
  for(int i=0;i<maxwidth-1;i++){
    move(maxheight-2,i);
    addch(oldalchar);
  }
  for(int i=0;i<maxheight-1;i++){
    move(i,maxwidth-2);
    addch(oldalchar);
  }
  move(maxheight-1,0);

  m_pos = Point(0,0);
  m_life = 1;
  m_curr_life = 1;
  m_id = "PERSONAJE NO DEFINIDO";
  refresh();
}

Character::~Character(){
  nodelay(stdscr,false);
  getch();
  endwin();
}

bool Character::collision(){
	if(m_pos.x==0 || m_pos.x==maxwidth-1 || m_pos.y==0 || m_pos.y==maxheight-2)
	   return true;
	   get=false;
	 return false;
}
void Character::moveCharacter(){
	//detect key
	int tmp=getch();
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
		case KEY_BACKSPACE:
			direction='q';
			break;
	}
	if(direction=='l'){
		move_x(-1);
	}else if(direction=='r'){
		move_x(1);
	}else if(direction=='u'){
		move_y(-1);
	}else if(direction=='d'){
		move_y(1);
	}

		addch(partchar);
	refresh();
}

Character::Character(Point pos, int life, std::string id){

   m_pos = pos;
   m_life = life;
   m_curr_life = life;
   m_id = id;
}

int Character::get_curr_life() const{
   return m_curr_life;
}

int Character::get_life() const{
   return m_life;
}

std::string Character::id() const{
   return m_id;
}

Point Character::get_pos() const{
   return m_pos;
}

void Character::set_curr_life(int h){
   m_curr_life = (h < 0)? 0 : h;
}

void Character::add_curr_life(int add){
   if(add < 0 && (add >= m_curr_life || add >= m_life))
      m_curr_life = 0;
   m_curr_life += add;
}

void Character::set_life(int h){
   m_life = h;
}

void Character::add_life(int add){
   if(add < 0 && add >= m_life)
      m_life = 1;
   m_life += add;
}

void Character::set_pos(Point pos){
   m_pos = pos;
}

void Character::set_pos(double x, double y){
   m_pos.x = x;
   m_pos.y = y;
}

void Character::move_x(double x){
   m_pos.x += x;
}

void Character::move_y(double y){
   m_pos.y += y;
}

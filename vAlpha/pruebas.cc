#include <iostream>
#include <vector>
#include "point.h"
#include "character.h"
#include "pacific.h"
#include "figther.h"
#include "player.h"
#include "inventory.h"
#include "weapon.h"
#include "item.h"
#include "structs.h"
#include "potion.h"
#include <string>

using namespace std;

void print(const Character A){
   cout<< "Vida Maxima: " << A.get_life() << endl;
   cout<< "Posición actual: ("<< A.get_pos().x << ", "<< A.get_pos().y << ")\n";
   cout<< "Vida actual: " << A.get_curr_life() << endl;
   cout<< "Name: " << A.id() << endl;
}


int main(){
   Character Personaje1(Point(0,0), 300, "Vicente");
   print(Personaje1);
   return 0;
}

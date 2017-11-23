#ifndef _STRUCTS_H_
#define _STRUCTS_H_

typedef struct Stats{ //Contiene todas las estadisticas del peleador
  Stats(){
    luck = 0;
    speed = 0;
    armor = 0;
    magic_armor = 0;
    damage = 0;
    magic_damage = 0;
  }
  Stats(const int v[6]){
    luck = v[0];
    speed = v[1];
    armor = v[2];
    magic_armor = v[3];
    damage = v[4];
    magic_damage = v[5];
  }
  Stats(int x0, int x1, int x2, int x3, int x4, int x5){
    luck = x0;
    speed = x1;
    armor = x2;
    magic_armor = x3;
    damage = x4;
    magic_damage = x5;
  }
  int luck;
  int speed;
  int armor;
  int magic_armor;
  int damage;
  int magic_damage;
} Stats;

typedef struct Element{
/*
Guarda los elementos a los que pertenece el jugador, segun estos
algunos ataques seran mas o menos efectivos
*/
  Element(){
    water = false;
    earth = false;
    fire = false;
    electric = false;
    abstract = false;
  }
  Element(bool x0, bool x1, bool x2, bool x3, bool x4){
    water = x0;
    earth = x1;
    fire = x2;
    electric = x3;
    abstract = x4;
  }
  Element(const bool v[5]){
    water = v[0];
    earth = v[1];
    fire = v[2];
    electric = v[3];
    abstract = v[4];
  }
  bool water;
  bool earth;
  bool fire;
  bool electric;
  bool abstract;
} Element;

#endif

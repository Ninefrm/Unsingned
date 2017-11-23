#ifndef _Weapon_H_
#define _Weapon_H_

#include "item.h"
#include "point.h"
#include <string>

class Weapon : public Item{
public:
  Weapon();
  Weapon(bool, int, Point, std::string, int, int, int, double, double);
  ~Weapon();
  int get_damage() const;
  int get_speed() const;
  int get_durability_max() const;
  int get_durability_current() const;
  double critic_hit() const;//Regresa la probabilidad de que el objeto pueda hacer un golpe critico
  double special_damage() const;//Regresa la probabilidad de que el objeto pueda hacer un golpe especial
  void boost_damage(int);
  int use();//Similar a get_damage, regresa el daño actual y disminuye la durabilidad
private:

protected:
  int m_durability_current;
  int m_damage;
  int m_durability_max;
  int m_speed;//Velcoidad dependiendo el tipo de espada
  double m_critic_hit;
  double m_special_damage;
};

#endif

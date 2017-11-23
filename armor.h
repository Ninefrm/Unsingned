#ifndef _AROMR_H_
#define _AROMR_H_

#include "item.h"
#include "structs.h"
#include "point.h"

class Armor : public Item{
public:
  Armor();
  Armor(bool,int,Point,std::string,int,int,Element, int, int);
  ~Armor();
  int get_def() const;
  int get_magic_def() const;
  int get_durability_max() const;
  int get_durability_current() const;
  Element get_element() const;
  int get_weigth() const;
  int use();
private:
protected:
  int m_def;
  int m_magic_def;
  Element m_element;
  int m_durability_current;
  int m_durability_max;
  int m_weigth;
};

#endif

#ifndef _ITEM_H_
#define _ITEM_H_

#include "point.h"
#include <string>

class Item{

public:
  Item();
  Item(bool,int,Point, const std::string);
  Item(bool,int,Point, const char*);
  virtual ~Item() {};

  int size()const;
  bool inside()const;
  Point pos()const;
  std::string get_id()const;

  void inside(bool);
  void pos(Point);

private:
  std::string m_id;
protected:
  int m_size;
  bool m_inside;//Para saber si esta dentro o fuera de nuestro inventario
  Point m_pos;//Posiciòn de nuestro item
};

#endif

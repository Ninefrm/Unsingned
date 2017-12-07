#ifndef Mapas_h_
#define Mapas_h_

#include "Wall.h"
#include <vector>

std::vector<Wall> m_1(4);
m_1[0]=Wall(0, 0, char(129), 0, 61);
m_1[1]=Wall(1, 0, char(129), 31, 0);
m_1[2]=Wall(1, 61, char(129), 29, 0);
m_1[3]=Wall(33, 0, char(129), 0, 61);

std::vector<Wall> m_2(6);
m_2[0]=Wall(0, 0, char(129), 0, 61);
m_2[1]=Wall(1, 0, char(129), 28, 0);
m_2[2]=Wall(1, 61, char(129), 5, 0);
m_2[3]=Wall(8, 61, char(129), 23, 0);
m_2[4]=Wall(31, 0, char(129), 0, 30);
m_2[5]=Wall(31, 32, char(129), 0, 30);

std::vector<Wall> m_3(4);
m_2[0]=Wall(0, 0, char(129), 0, 30);
m_2[1]=Wall(0, 32, char(129), 0, 30);
m_2[2]=Wall(1, 0, char(129), 31, 0);
m_2[3]=Wall(33, 0, char(129), 0, 61);
m_2[4]=Wall(1, 62, char(129), 32, 0);

std::vector<Wall> m_4(5);
m_2[0]=Wall(0, 0, char(129), 0, 62);
m_2[1]=Wall(33, 0, char(129), 0, 61);
m_2[2]=Wall(1, 0, char(129), 5, 0);
m_2[3]=Wall(8, 0, char(129), 28, 0);
m_2[4]=Wall(1, 62, char(129), 32, 0);

#endif

#include "pacific.h"

Pacific::Pacific():Character(Point(0,0), -1, "pacific"){

  m_empaty = 0;
  m_quest = false;
  m_talk_counter = 0;

}

Pacific::Pacific(Point pos, int life, std::string id):Character(pos, life, id){

  m_empaty = 0;
  m_quest = false;
  m_talk_counter = 0;
  m_dialog.resize(4);
  m_dialog.at(0) = "Bienvenido";
  m_dialog.at(1) = "Hola";
  m_dialog.at(2) = "Viajero";
  m_dialog.at(3) = "Quieres aceptar un desafio\?";

}

std::string Pacific::talk(){

  if(m_dialog.size() == 0 ) return "Este dialogo no debio ser leìdo";
  if(m_talk_counter >= m_dialog.size()) m_talk_counter = 0;
    return m_dialog.at(m_talk_counter);

}

std::string Pacific::talk(unsigned int op ){

  if( op == 0 ) return "Tal vez luego";
  return "Gracias";
}

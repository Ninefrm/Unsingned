#include "Player.h"

  Player::Player(){
    std::string m_name("Unsingned");
    m_Damage=5;
    m_AttackSpeed=1;
    m_Life=100;
    m_Armor=3;
    m_MagicResist=3;
  }
  Player::~Player(){
    std::cout<<"\n \n \t \t GAME OVER"<<std::endl;
  }
  const std::string Player::Name() const{
    return m_name;
  }
  const double Player::Damage() const{
    return m_Damage;
  }
  const double Player::AttackSpeed() const{
    return m_AttackSpeed;
  }
  const double Player::Life() const{
    return m_Life;
  }
  const double Player::Armor() const{
    return m_Armor;
  }
  const double Player::MagicResist() const{
    return m_MagicResist;
  }
  std::string Player::Name(std::string Name){
    return m_name=Name;
  }
  double Player::Damage(double value){
    return m_Damage=value;
  }
  double Player::AttackSpeed(double value){
    return m_AttackSpeed=value;
  }
  double Player::Life(double value){
    return m_Life=value;
  }
  double Player::Armor(double value){
    return m_Armor=value;
  }
  double Player::MagicResist(double value){
    return m_MagicResist=value;
  }

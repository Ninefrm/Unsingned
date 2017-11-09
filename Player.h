#ifndef _PLAYER_H_
#define _PLAYER_H_

//librerias
#include <string>
#include <vector>
#include <iostream>
//

struct Player{
  public:
    Player();
    Player(std::string name);

    ~Player();

    const double Damage() const;
    const double AttackSpeed() const;
    const double Life() const;
    const double Armor() const;
    const double MagicResist() const;
    const std::string Name() const;

    double Damage(double value);
    double AttackSpeed(double value);
    double Life(double value);
    double Armor(double value);
    double MagicResist(double value);
    std::string Name(std::string Name);

  private:
    std::string m_name;

    double m_Damage;
    double m_AttackSpeed;

    double m_Life;
    double m_Armor;
    double m_MagicResist;

    //std::vector<Guns*> m_array; virtuales
};

#endif

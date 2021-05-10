#ifndef POWERUP_HPP
#define POWERUP_HPP

#include "Element.hpp"

class PowerUp : public Element{
  public :
  //constructeur
    PowerUp();
    ~PowerUp(){}

  //méthodes
    void affichage();
    int getType() const;
    //void setType(int type);

  protected :
    int _type;
    bool _updown;
};
#endif

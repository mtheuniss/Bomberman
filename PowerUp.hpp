#ifndef POWERUP_HPP
#define POWERUP_HPP

#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

class PowerUp{
  public :
  //constructeur
    PowerUp();

  //méthodes
    void affichage();
    int getType() const;
    void setType(int type);

  protected :
    int _type;
    bool _updown;
};
#endif

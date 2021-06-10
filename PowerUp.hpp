#ifndef POWERUP_HPP
#define POWERUP_HPP

#include "Element.hpp"
#include "Joueur.hpp"
//PowerUP, c'est une interface

class PowerUp : public Element{
  public :
  //constructeur
    //PowerUp();
    //~PowerUp(){}

  //méthodes
    virtual void affichage() = 0;
    virtual int powerUpAttrape(Joueur* j) = 0;


};
#endif

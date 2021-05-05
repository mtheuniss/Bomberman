#ifndef MURVOID_HPP
#define MURVOID_HPP

#include "Element.hpp"

class MurVoid : public Element {
  public :
    //Constructeur, destructeur
    MurVoid();
    MurVoid(int x, int y);
    //virtual ~MurCassable();

    //Accesseurs
    //PowerUp getPowerUp ();

    void affichage();
  protected :
    //PowerUp _powerup;

};
#endif

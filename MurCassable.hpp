#ifndef MURCASSABLE_HPP
#define MURCASSABLE_HPP

#include "Element.hpp"

class MurCassable : public Element {
  public :
    //Constructeur, destructeur
    MurCassable();
    MurCassable(int x, int y);
    //virtual ~MurCassable();

    //Accesseurs
    //PowerUp getPowerUp ();

    void affichage();
  protected :
    //PowerUp _powerup;

};
#endif

#ifndef MURVOID_HPP
#define MURVOID_HPP

#include "Element.hpp"
#include "Mur.hpp"

class MurVoid : public Mur {
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

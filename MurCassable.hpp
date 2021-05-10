#ifndef MURCASSABLE_HPP
#define MURCASSABLE_HPP

#include "Mur.hpp"
#include "PowerUp.hpp"

class MurCassable : public Mur {
  public :
    //Constructeur, destructeur
    MurCassable();
    MurCassable(int x, int y);
    //virtual ~MurCassable();

    //Accesseurs
    //PowerUp getPowerUp ();

    void affichage();
  protected :
    PowerUp _powerup;
    bool casse;
};
#endif

#ifndef MURDUR_HPP
#define MURDUR_HPP

#include "Element.hpp"
#include "Mur.hpp"

class MurDur : public Mur {
  public :
    //Constructeur, destructeur
    MurDur();
    MurDur(int x, int y);
    //virtual ~MurCassable();

    //Accesseurs
    //PowerUp getPowerUp ();

    void affichage();
  protected :

};
#endif

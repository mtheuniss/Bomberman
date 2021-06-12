#ifndef MURCASSABLE_HPP
#define MURCASSABLE_HPP

#include "Mur.hpp"
#include "PowerUp.hpp"

class MurCassable : public Mur {
  public :
    //Constructeur, destructeur
    MurCassable();
    MurCassable(int x, int y);

    void affichage();
};
#endif

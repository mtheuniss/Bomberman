#ifndef MURVOID_HPP
#define MURVOID_HPP

#include "Element.hpp"
#include "Mur.hpp"

class MurVoid : public Mur {
  public :
    //Constructeur, destructeur
    MurVoid();
    MurVoid(int x, int y);
    virtual ~MurVoid(){}

    void affichage();
  protected :


};
#endif

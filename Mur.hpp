#ifndef MUR_HPP
#define MUR_HPP

#include "Element.hpp"

class Mur : public Element {
  public :
    //Constructeur, destructeur
    virtual ~Mur(){}

    //Accesseurs
    bool getCassable(){return this->cassable;}
    bool getFranchissable(){return this->franchissable;}

    virtual void affichage()=0; //redéfinition dans les murs dérivés
  protected :
    bool franchissable;
    bool cassable;

};
#endif

#ifndef MUR_HPP
#define MUR_HPP

#include "Element.hpp"

//Classe virtuelle dont les 3 types de murs dérivent

class Mur : public Element {
  public :
    //Constructeur, destructeur
    virtual ~Mur(){
      delete this->_esthetique;
    }

    //Accesseurs const : en lecture seule
    const bool& getCassable() const {return this->cassable;}
    const bool& getFranchissable()const {return this->franchissable;}

    virtual void affichage()=0; //redéfinition dans les murs dérivés
  protected :
  //attribut permettant de différentier les types de murs
    bool franchissable;
    bool cassable;

};
#endif

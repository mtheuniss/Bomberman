#ifndef BOMBE_HPP
#define BOMBE_HPP

#include "Element.hpp"

class Bombe : public Element{
  public :
  //Constructeur et destructeur
    Bombe();
    //Bombe(int x, int y);
    ~Bombe(){}

  //Accesseurs
    const int& getRayon() const{return _rayon;}
    const int& getExplose() const{return _explose;}
    void setRayon(int r){_rayon = r;}
    void setExplose(){_explose = 1;}

  //Autres fonctions
    void affichage();
    //void explose();


  protected :
    int _rayon;
    int _explose; //0 pas explosé, 1 explose (pour l'affichage)
};


#endif

#ifndef BOMBE_HPP
#define BOMBE_HPP

#include "Element.hpp"

class Bombe : public Element{
  public :
  //Constructeur et destructeur
    Bombe();
    //Bombe(int x, int y);
    ~Bombe(){}
    //constructeur par copie
    Bombe(const Bombe& b){*this = b;}

    //opérateur d'assignement =
    Bombe& operator=(const Bombe& b){
      _rayon = b._rayon;
      _explose = b._explose;
      _pos = b._pos;
      _esthetique = b._esthetique;
      _texture = b._texture;
      return *this;
    }

  //Accesseurs const et non const
    const int& rayon() const{return _rayon;}
    const int& explose() const{return _explose;}
    int& rayon() {return _rayon;}
    int& explose() {return _explose;}
    //void setRayon(int r){_rayon = r;}
    //void setExplose(){_explose = 1;}

  //Autres fonctions
    void affichage();
    //void explose();
    //Gestion du temps de vie de la bombe
    bool imBoum();

  protected :
    int _rayon;
    int _explose; //0 pas explosé, 1 explose (pour l'affichage)

    sf::Clock _clock;
};


#endif

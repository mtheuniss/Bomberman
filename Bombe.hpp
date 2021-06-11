#ifndef BOMBE_HPP
#define BOMBE_HPP

#include "Element.hpp"
#include <list>

class Bombe : public Element{
  public :
  //Constructeur et destructeur
    Bombe();
    //Bombe(int x, int y);
    ~Bombe(){}
    //constructeur par copie
    Bombe(const Bombe& b){
      *this = b;
    }

    //opérateur d'assignement =
    Bombe& operator=(const Bombe& b){
      _rayon = b._rayon;
      _explose = b._explose;
      _type = b._type;
      this->affichage();
      this->setPosX(b.getPosX());
      this->setPosY(b.getPosY());
      return *this;
    }

  //Accesseurs const et non const
    const int& rayon() const{return _rayon;}
    const int& explose() const{return _explose;}
    const int& type() const{return _type;}
    int& rayon() {return _rayon;}
    int& explose() {return _explose;}
    int& type() {return _type;}

    //void setRayon(int r){_rayon = r;}
    //void setExplose(){_explose = 1;}

  //Autres fonctions
    void affichage();
    //void explose();
    //Gestion du temps de vie de la bombe
    bool imBoum();
    void degatsBombe(std::list<sf::Vector2i>& listeDegats);

  protected :
    int _rayon;
    int _explose; //0 pas explosé, 1 explose (pour l'affichage)
    int _type;

    sf::Clock _clock;
};


#endif

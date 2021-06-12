#ifndef BOMBE_HPP
#define BOMBE_HPP

#include "Element.hpp"
#include <list>

class Bombe : public Element{
  public :
  //Constructeur et destructeur
    Bombe();
    virtual ~Bombe(){
      std::cout << "destructeur bombe" << '\n';
      delete this->_animation;
    }
    //constructeur par copie
    Bombe(const Bombe& b){
      *this = b;
    }

    //opérateur d'assignement =
    Bombe& operator=(const Bombe& b){
      _rayon = b._rayon;
      _type = b._type;
      this->affichage();
      this->setPosX(b.getPosX());
      this->setPosY(b.getPosY());
      return *this;
    }

  //Accesseurs const et non const
    const int& rayon() const{return _rayon;}
    const int& type() const{return _type;}
    int& rayon() {return _rayon;}
    int& type() {return _type;}

  //Autres fonctions
  /**
	 * fonction redéfinie par toutes les methodes dérivées d'Element
	 */
    void affichage();

    /**
	 * Gestion de l'explosion de la bombe : elle explose au bout de 3 secondes
	 */
    bool imBoum();

    /**
	 * A partir de la position de la bombe (attribut _pos), la fonction remplie la liste passée par référence
   * en inscrivant les coordonnées de toutes les cases POTENTIELLEMENT touchées par l'explosion
	 */
    void degatsBombe(std::list<sf::Vector2i>& listeDegats);

    void setAnimation(sf::Texture* texture, sf::Vector2u nbImages, float tmp){
      this->_animation = new Animation(texture,nbImages,tmp);
    }
    Animation* getAnimation(){return this->_animation;}

  protected :
    //les attributs
    int _rayon; //le rayon d'explosion de la bombe (variable selon les powerup)
    int _type;

    Animation* _animation;
    sf::Clock _clock;
};


#endif

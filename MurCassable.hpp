#ifndef MURCASSABLE_HPP
#define MURCASSABLE_HPP

#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

class MurCassable : public Element {
  public :
    //Constructeur, destructeur
    MurCassable();
    virtual ~MurCassable();

    //Accesseurs
    PowerUp getPowerUp ();

    void affichage();
  protected :
    PowerUp _powerup;

};
#endif

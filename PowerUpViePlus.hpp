#ifndef POWERUPVIEPLUS_HPP
#define POWERUPVIEPLUS_HPP

#include "Element.hpp"
#include "PowerUp.hpp"

//Ce powerUp ajoute une vie au joueur que le récupère

class PowerUpViePlus : public PowerUp {
  public :
    //Constructeurs
    PowerUpViePlus();
    PowerUpViePlus(sf::Vector2i position);
    //Desctructeur
    virtual ~ PowerUpViePlus(){}
    //méthodes à redefinir
    void affichage();
    int powerUpAttrape(Joueur* j);
};

#endif

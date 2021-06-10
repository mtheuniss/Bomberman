#ifndef POWERUPBOMBEPLUS_HPP
#define POWERUPBOMEPLUS_HPP

#include "Element.hpp"
#include "PowerUp.hpp"

//Ce powerUp ajoute une vie au joueur que le récupère

class PowerUpBombePlus : public PowerUp {
  public :
    //Constructeurs
    PowerUpBombePlus();
    PowerUpBombePlus(sf::Vector2i position);
    //Desctructeur
    virtual ~ PowerUpBombePlus(){}
    //méthodes à redefinir
    void affichage();
    int powerUpAttrape(Joueur* j);
};

#endif

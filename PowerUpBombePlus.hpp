#ifndef POWERUPBOMBEPLUS_HPP
#define POWERUPBOMEPLUS_HPP

#include "Element.hpp"
#include "PowerUp.hpp"

//Ce powerUp ajoute une bombe au joueur que le récupère

class PowerUpBombePlus : public PowerUp {
  public :
    //Constructeurs
    PowerUpBombePlus();
    PowerUpBombePlus(sf::Vector2i position);

    //méthodes à redefinir
    void affichage();
    bool powerUpAttrape(Joueur* j);
};

#endif

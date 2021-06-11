#ifndef PowerUpVitessePlus_HPP
#define POWERUPBOMEPLUS_HPP

#include "Element.hpp"
#include "PowerUp.hpp"

//Ce powerUp ajoute une vie au joueur que le récupère

class PowerUpVitessePlus : public PowerUp {
  public :
    //Constructeurs
    PowerUpVitessePlus();
    PowerUpVitessePlus(sf::Vector2i position);
    //Desctructeur
    virtual ~ PowerUpVitessePlus(){}
    //méthodes à redefinir
    void affichage();
    int powerUpAttrape(Joueur* j);
};

#endif

#ifndef PowerUpFirePlus_HPP
#define POWERUPBOMEPLUS_HPP

#include "Element.hpp"
#include "PowerUp.hpp"

//Ce powerUp ajoute une vie au joueur que le récupère

class PowerUpFirePlus : public PowerUp {
  public :
    //Constructeurs
    PowerUpFirePlus();
    PowerUpFirePlus(sf::Vector2i position);
    //Desctructeur
    virtual ~ PowerUpFirePlus(){}
    //méthodes à redefinir
    void affichage();
    int powerUpAttrape(Joueur* j);
};

#endif

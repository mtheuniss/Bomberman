#ifndef PowerUpFirePlus_HPP
#define POWERUPBOMEPLUS_HPP

#include "Element.hpp"
#include "PowerUp.hpp"

//Ce powerUp augmente de 1 le rayon de l'explosion de la bombe

class PowerUpFirePlus : public PowerUp {
  public :
    //Constructeurs
    PowerUpFirePlus();
    PowerUpFirePlus(sf::Vector2i position);

    //méthodes à redefinir
    void affichage();
    bool powerUpAttrape(Joueur* j);
};

#endif

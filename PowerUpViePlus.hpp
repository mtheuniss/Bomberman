#ifndef POWERUPVIEPLUS_HPP
#define POWERUPVIEPLUS_HPP

#include "Element.hpp"
#include "PowerUp.hpp"

//Ce powerUp ajoute une vie au joueur que le récupère

class PowerUpViePlus : public PowerUp {
  //Constructeurs
  PowerUpViePlus();
  PowerUpViePlus(int x, int y);
  //Desctructeur
  virtual ~ PowerUpViePlus(){}
  //méthodes à redefinir
  void affichage();
  void powerUpAttrape(Joueur* j);
};

#endif

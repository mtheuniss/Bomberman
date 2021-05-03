# include <iostream>

#include "Element.hpp"

//Constructeur
MurCassable::MurCassable(){
  this->_powerup = PowerUp();
}

MurCassable::PowerUp getPowerUp (){
  return this->_powerup;
}

MurCassable::affichage(){
  this->_esthetique.setSize(sf::Vector2f(72.f,72.f)); //.f -> float sans être float (carrés 72*72)
  this->_esthetique.setFillColor(sf::Color::color(205, 133, 63));); //On peut direct mettre la couleur c'est pas mal
}

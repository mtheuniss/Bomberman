#include "Bombe.hpp"

Bombe::Bombe(){
  _pos.x = 0; _pos.y = 0;
  _rayon = 2;
  _explose = 0;
  this->affichage();
}

void Bombe::affichage(){
  this->_esthetique.setSize(sf::Vector2f(30.f,30.f)); //.f -> float sans être float (carrés 72*72)
  this->_esthetique.setFillColor(sf::Color(255, 0, 0,255)); //On peut direct mettre la couleur c'est pas mal
  this->_esthetique.setOutlineThickness(1);
  this->_esthetique.setOutlineColor(sf::Color(0, 0, 0));
}

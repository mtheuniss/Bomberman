#include "PowerUpViePlus.hpp"

// Constructeurs

PowerUpViePlus::PowerUpViePlus(){
  this->affichage();
}

PowerUpViePlus::PowerUpViePlus(int x, int y){
  this->affichage();
  this->setPosX(x);
  this->setPosY(y);
}


//redéfinition des méthodes :

void PowerUpViePlus::affichage(){
  this->_esthetique = new sf::RectangleShape();
  this->_esthetique->setSize(sf::Vector2f(72.f,72.f)); //.f -> float sans être float (carrés 72*72)
  this->_esthetique->setFillColor(sf::Color(205, 133, 63,255)); //On peut direct mettre la couleur c'est pas mal
  this->_esthetique->setOutlineThickness(1);
  this->_esthetique->setOutlineColor(sf::Color(170, 68, 0));
}

void PowerUpViePlus::powerUpAttrape(Joueur* j){
  //on incrémente de 1 le nombre de vie du joueur passé en argument
  j->nbVies()++;
}

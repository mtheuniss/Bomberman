#include "PowerUpViePlus.hpp"

// Constructeurs

PowerUpViePlus::PowerUpViePlus(){
  this->affichage();
}

PowerUpViePlus::PowerUpViePlus(sf::Vector2i position){
  this->affichage();
  this->setPosX(position.x);
  this->setPosY(position.y);
}


//redéfinition des méthodes :

void PowerUpViePlus::affichage(){
  this->_esthetique = new sf::RectangleShape();
  this->_esthetique->setSize(sf::Vector2f(72.f,72.f)); //.f -> float sans être float (carrés 72*72)
  this->_esthetique->setFillColor(sf::Color(0, 0, 0,255)); //On peut direct mettre la couleur c'est pas mal
}

void PowerUpViePlus::powerUpAttrape(Joueur* j){
  //on incrémente de 1 le nombre de vie du joueur passé en argument
  j->nbVies()++;
}

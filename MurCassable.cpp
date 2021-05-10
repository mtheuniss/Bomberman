#include "MurCassable.hpp"

//Constructeur
MurCassable::MurCassable(){
  this->_powerup = PowerUp();
  this->cassable = 1;
  this->franchissable = 0;
  this->casse = 0; //pas cassé lors de sa construction
}
MurCassable::MurCassable(int x , int y){
  this->affichage();
  this->setPosX(x);
  this->setPosY(y);
  this->cassable = 1;
  this->franchissable = 0;
  this->casse = 0;
}
/*
MurCassable::PowerUp getPowerUp (){
  return this->_powerup;
}
*/
void MurCassable::affichage(){
  this->_esthetique.setSize(sf::Vector2f(72.f,72.f)); //.f -> float sans être float (carrés 72*72)
  this->_esthetique.setFillColor(sf::Color(205, 133, 63,255)); //On peut direct mettre la couleur c'est pas mal
  this->_esthetique.setOutlineThickness(1);
  this->_esthetique.setOutlineColor(sf::Color(170, 68, 0));
}

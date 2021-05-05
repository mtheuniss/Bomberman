#include "MurVoid.hpp"

//Constructeur
MurVoid::MurVoid(){
  //this->_powerup = PowerUp();
}
MurVoid::MurVoid(int x , int y){
  this->affichage();
  this->setPosX(x);
  this->setPosY(y);
}
/*
MurCassable::PowerUp getPowerUp (){
  return this->_powerup;
}
*/
void MurVoid::affichage(){
  this->_esthetique.setSize(sf::Vector2f(72.f,72.f)); //.f -> float sans être float (carrés 72*72)
  this->_esthetique.setFillColor(sf::Color(0, 0, 0, 0)); //On peut direct mettre la couleur c'est pas mal
}

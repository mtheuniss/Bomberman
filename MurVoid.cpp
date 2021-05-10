#include "MurVoid.hpp"

//Constructeur
MurVoid::MurVoid(){
  this->cassable = 0;//pas cassable par une bombe
  this->franchissable = 1;//un personnage peut aller dessus
}
MurVoid::MurVoid(int x , int y){
  this->affichage();
  this->setPosX(x);
  this->setPosY(y);
  this->cassable = 0;
  this->franchissable = 1;
}
/*
MurCassable::PowerUp getPowerUp (){
  return this->_powerup;
}
*/
void MurVoid::affichage(){
  this->_esthetique.setSize(sf::Vector2f(72.f,72.f)); //.f -> float sans être float (carrés 72*72)
  this->_esthetique.setFillColor(sf::Color(85, 212, 0, 255)); //On peut direct mettre la couleur c'est pas mal
  this->_esthetique.setOutlineThickness(1);
  this->_esthetique.setOutlineColor(sf::Color(0, 128, 0));
}

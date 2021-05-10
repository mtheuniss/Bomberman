#include "MurDur.hpp"

//Constructeur
MurDur::MurDur(){
  this->affichage();
  this->setPosX(0);
  this->setPosY(0);
  this->cassable = 0;
  this->franchissable = 0;
}
MurDur::MurDur(int x , int y){
  this->affichage();
  this->setPosX(x);
  this->setPosY(y);
  this->cassable = 0;
  this->franchissable = 0;
  if (!this->_texture.loadFromFile("mur_brique.png"))
  {
    std::cout<<"erreur lors de l'ouverture de l'image"<<std::endl;
  }
  this->_texture.setSmooth(true);//lissage de l'image
}
/*
MurCassable::PowerUp getPowerUp (){
  return this->_powerup;
}
*/
void MurDur::affichage(){
  this->_esthetique.setSize(sf::Vector2f(72.f,72.f)); //.f -> float sans être float (carrés 72*72)
  this->_esthetique.setFillColor(sf::Color(200, 190, 183,255)); //On peut direct mettre la couleur c'est pas mal
  this->_esthetique.setOutlineThickness(1);
  this->_esthetique.setOutlineColor(sf::Color(145, 124, 111));
  this->_esthetique.setTexture(&this->_texture);
  this->_esthetique.setTextureRect(sf::IntRect(0, 0, 200, 150));
}

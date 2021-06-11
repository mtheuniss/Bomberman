#include "MurCassable.hpp"

//Constructeur
MurCassable::MurCassable(){
  this->affichage();
  //this->_powerup = PowerUp();
  this->cassable = 1;
  this->franchissable = 0;
  //this->casse = 0; //pas cassé lors de sa construction
}
MurCassable::MurCassable(int x , int y){
  this->affichage();
  //this->_powerup = PowerUp();
  this->cassable = 1;
  this->franchissable = 0;
  //this->casse = 0; //pas cassé lors de sa construction
  this->setPosX(x);
  this->setPosY(y);
}
/*
MurCassable::PowerUp getPowerUp (){
  return this->_powerup;
}
*/
void MurCassable::affichage(){
  this->_esthetique = new sf::RectangleShape();
  this->_esthetique->setSize(sf::Vector2f(72.f,72.f)); //.f -> float sans être float (carrés 72*72)
  this->_esthetique->setOutlineThickness(1);
  this->_esthetique->setOutlineColor(sf::Color(0, 128, 0));
  if (!this->_texture.loadFromFile("Images/mur_cassable.png"))
  {
    std::cout<<"erreur lors de l'ouverture de l'image"<<std::endl;
  }
  this->_texture.setSmooth(true);//lissage de l'image
  this->_esthetique->setTexture(&this->_texture);
  this->_esthetique->setTextureRect(sf::IntRect(0, 0, 256, 256));
}

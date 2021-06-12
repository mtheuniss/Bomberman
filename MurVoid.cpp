#include "MurVoid.hpp"

//Constructeur

MurVoid::MurVoid(){
  this->affichage();
}
MurVoid::MurVoid(int x , int y){
  this->affichage();
  this->cassable = 0;//pas cassable par une bombe
  this->franchissable = 1;//un personnage peut aller dessus
  this->setPosX(x);
  this->setPosY(y);
}

void MurVoid::affichage(){
  this->_esthetique = new sf::RectangleShape();
  this->_esthetique->setSize(sf::Vector2f(72.f,72.f)); //.f -> float sans être float (carrés 72*72)
  this->_esthetique->setOutlineThickness(1);
  this->_esthetique->setOutlineColor(sf::Color(0, 128, 0));
  if (!this->_texture.loadFromFile("Images/plaque_verte.png"))
  {
    std::cout<<"erreur lors de l'ouverture de l'image"<<std::endl;
  }
  this->_texture.setSmooth(true);//lissage de l'image
  this->_esthetique->setTexture(&this->_texture);
  this->_esthetique->setTextureRect(sf::IntRect(0, 0, 95, 95));
}

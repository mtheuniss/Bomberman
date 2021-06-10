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
  this->_esthetique->setTextureRect(sf::IntRect(96,0,32,32));
  this->_texture.loadFromFile("Images/sprite_powerup.png");
  this->_esthetique->setOrigin(1,0);
  this->_esthetique->setTexture(&(this->_texture));

}

int PowerUpViePlus::powerUpAttrape(Joueur* j){
  //on incrémente de 1 le nombre de vie du joueur passé en argument
  if(j->getPosOnGridX()==this->getPosX() && j->getPosOnGridY() == this->getPosY() ){
    j->nbVies()++;
    return 1;
  }
  return 0;
}

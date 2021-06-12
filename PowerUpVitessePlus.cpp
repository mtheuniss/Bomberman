#include "PowerUpVitessePlus.hpp"

// Constructeurs

PowerUpVitessePlus::PowerUpVitessePlus(){
  this->affichage();
}

PowerUpVitessePlus::PowerUpVitessePlus(sf::Vector2i position){
  this->affichage();
  this->setPosX(position.x);
  this->setPosY(position.y);
}


//redéfinition des méthodes :

void PowerUpVitessePlus::affichage(){
  this->_esthetique = new sf::RectangleShape();
  this->_esthetique->setSize(sf::Vector2f(72.f,72.f)); //.f -> float sans être float (carrés 72*72)
  this->_esthetique->setTextureRect(sf::IntRect(64,0,32,32));
  this->_texture.loadFromFile("Images/sprite_powerup.png");
  this->_esthetique->setOrigin(1,0);
  this->_esthetique->setTexture(&(this->_texture));

}

bool PowerUpVitessePlus::powerUpAttrape(Joueur* j){
  //on augmente la vitesse du joueur passé en argument si les 2 sont sur la même case
  if(j->getPosOnGridX()==this->getPosX() && j->getPosOnGridY() == this->getPosY() ){
    j->setVitesse(j->getVitesse()+1);
    return true;
  }
  return false;
}

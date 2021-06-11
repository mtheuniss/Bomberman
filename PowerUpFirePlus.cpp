#include "PowerUpFirePlus.hpp"

// Constructeurs

PowerUpFirePlus::PowerUpFirePlus(){
  this->affichage();
}

PowerUpFirePlus::PowerUpFirePlus(sf::Vector2i position){
  this->affichage();
  this->setPosX(position.x);
  this->setPosY(position.y);
}


//redéfinition des méthodes :

void PowerUpFirePlus::affichage(){
  this->_esthetique = new sf::RectangleShape();
  this->_esthetique->setSize(sf::Vector2f(68.f,68.f)); //.f -> float sans être float (carrés 72*72)
  this->_esthetique->setTextureRect(sf::IntRect(32,0,32,32));
  this->_texture.loadFromFile("Images/sprite_powerup.png");
  this->_esthetique->setOrigin(1,0);
  this->_esthetique->setTexture(&(this->_texture));

}

int PowerUpFirePlus::powerUpAttrape(Joueur* j){
  //on incrémente de 1 le nombre de vie du joueur passé en argument
  if(j->getPosOnGridX()==this->getPosX() && j->getPosOnGridY() == this->getPosY() ){
    j->getBombe()->rayon()++;
    return 1;
  }
  return 0;
}

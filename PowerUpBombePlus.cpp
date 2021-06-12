#include "PowerUpBombePlus.hpp"

// Constructeurs

PowerUpBombePlus::PowerUpBombePlus(){
  this->affichage();
}

PowerUpBombePlus::PowerUpBombePlus(sf::Vector2i position){
  this->affichage();
  this->setPosX(position.x);
  this->setPosY(position.y);
}


//redéfinition des méthodes :

void PowerUpBombePlus::affichage(){
  this->_esthetique = new sf::RectangleShape();
  this->_esthetique->setSize(sf::Vector2f(72.f,72.f)); //.f -> float sans être float (carrés 72*72)
  this->_esthetique->setTextureRect(sf::IntRect(0,0,32,32));
  this->_texture.loadFromFile("Images/sprite_powerup.png");
  this->_esthetique->setOrigin(1,0);
  this->_esthetique->setTexture(&(this->_texture));

}

bool PowerUpBombePlus::powerUpAttrape(Joueur* j){
  //on incrémente de 1 le nombre de bombes du joueur passé en argument
  if(j->getPosOnGridX()==this->getPosX() && j->getPosOnGridY() == this->getPosY() ){
    j->setNbBombes(j->getNbBombes()+1); //ajout d'une bombe
    return true;
  }
  return false;
}

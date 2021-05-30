#include "PowerUp.hpp"

PowerUp::PowerUp(){
  this->_esthetique = new sf::RectangleShape();
  /*le type du powerup est choisit de façon aléatoire lors de la construction
  Il faut faire en sorte qu'il y ait plus de chance d'avoir un bon PowerUp qu'un
  mauvais PowerUP
   _type :  1= rapidité de déplacement
            2= rayon de la bombe
            3= nombre de vies
            4= changement de type de bombe
            5= nombre de bombes
  _updown : 1=amélioration
            0=régression
  */
  this->_type = ((int) rand()/(5)) + 1;
  int ud = ((int) rand()/(10)) + 1;//entre 1 et 10
  if (ud>3) //plus de chance d'avoir un bon powerup
    this->_updown = true;
  else
    this->_updown = false;
}

int PowerUp::getType() const{
  if (this->_updown)
    return this->_type;
  else
    return (- this->_type);
}

void PowerUp::affichage(){
  this->_esthetique->setSize(sf::Vector2f(72.f,72.f)); //.f -> float sans être float (carrés 72*72)
  this->_esthetique->setFillColor(sf::Color(205, 133, 63,255)); //On peut direct mettre la couleur c'est pas mal
  this->_esthetique->setOutlineThickness(1);
  this->_esthetique->setOutlineColor(sf::Color(170, 68, 0));
}

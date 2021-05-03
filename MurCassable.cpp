# include <iostream>

#include "Element.hpp"

//Constructeur
MurCassable::MurCassable(){
  this->_powerup = PowerUp();
}

MurCassable::PowerUp getPowerUp (){
  return this->_powerup;
}

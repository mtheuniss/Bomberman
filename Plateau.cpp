# include <iostream>
#include "Plateau.hpp"

//Constructeur
Plateau::Plateau(){
  _MAP = 0;
  _MAX_X = 1080; //HD = 1280 taille cube = 72*72 -> 10*15 -> 200 pixels pour l'affichage des scores
  _MAX_Y = 720;

  initPlateau();

}

//Accesseurs
int Plateau::getMaxX() const{
  return this->_MAX_X;
}
int Plateau::getMaxY() const{
  return this->_MAX_Y;
}
int Plateau::getMap() const{
  return this->_MAP;
}

void Plateau::setMaxX(int mx){ this->_MAX_X = mx;}
void Plateau::setMaxY(int my){ this->_MAX_Y = my;}
void Plateau::setMapType(int mt){this-> _MAP = mt;}


//Fonction private

void Plateau::initPlateau(){


}

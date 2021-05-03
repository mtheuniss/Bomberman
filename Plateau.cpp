# include <iostream>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

#include "Plateau.hpp"

//Constructeur
Plateau::Plateau(){
  _MAX_X = 1080; //HD = 1280 taille cube = 72*72 -> 10*15 -> 200 pixels pour l'affichage des scores
  _MAX_Y = 720;
  _TailleElementStandard = 72;

  _grid = sf::RectangleShape[10];
  for (int i = 0 ; i < 10 ; i++){
    _grid[i] = sf::RectangleShape();
  }

}

//Accesseurs
const int Plateau::getMaxX() const{
  return this->_MAX_X;
}
const int Plateau::getMaxY() const{
  return this->_MAX_Y;
}
const int Plateau::getMaxX() const{
  return this->_grid;
}

void setMaxX(int mx){ this->_MAX_X = mx;}
void setMaxY(int my){ this->_MAX_Y = my;}
void setMaxX(sf::RectangleShape**){ this->_grid = g;}



//Fonction private

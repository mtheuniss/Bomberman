
#include "Plateau.hpp"

//Constructeur
Plateau::Plateau(){
  _MAP = 0;
  _MAX_X = 1080; //HD = 1280 taille cube = 72*72 -> 10*15 -> 200 pixels pour l'affichage des scores
  _MAX_Y = 720;

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

void Plateau::setElement(Element* ent){
  this->_grid[ent->getPosX()][ent->getPosY()] = ent;
}
Element* Plateau::getElement(int x, int y){
  return this->_grid[x][y];
}


void Plateau::initPlateau(){
  switch (this->_MAP) {
    case 0:
      std::cout<<"Testing void map"<<std::endl;
      break;
    case 1:
      std::cout<<"Testing simple map 1"<<std::endl;

      for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 15; j++) {
          this->setElement( new MurVoid(i,j));
        }
      }


      break;

    default:
      throw std::runtime_error("_MAP mal définie :(");
  }

std::cout<<"sortie initPlateau ? "<<std::endl;
}


void Plateau::renderPlateau(sf::RenderWindow* w ){
  for (size_t i = 0; i < 10; i++) {
    for (size_t j = 0; j < 15; j++) {
        w->draw(this->getElement(i,j)->getEsthetique()); // On place l'element sur le plateau
      }
    }
  }

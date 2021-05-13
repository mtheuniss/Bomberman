
#include "Plateau.hpp"

//Constructeur
Plateau::Plateau(){
  _MAP = 0;
  _MAX_X = 1080; //HD = 1280 taille cube = 72*72 -> 10*15 -> 200 pixels pour l'affichage des scores
  _MAX_Y = 720;
}

//Destructeur
Plateau::~Plateau(){
  std::cout<<"suppression des l'elements de la grille"<<std::endl;

 for (int i =0; i<15; i++){
    for (int j =0; j<10; j++){
      std::cout << "i ="<<i<<"  j =" << j << '\n';
      delete this->_grid[i][j];
    }
  }



  std::cout<<"sortie du destructeur"<<std::endl;
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

      //On ajoute les murs dans le Plateau
      //  ATTENTION REPÈRE DE LA GRILLE COMME POUR LES IMAGES (en haut à gauche, ylignes)
      //les MurCassables sont partout sauf dans les coins
      for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 10; j++) {
          if ((i==0 || i==14) && (j==0 || j==1 || j== 8 ||j==9)){
            this->setElement( new MurVoid(i,j));}
          else if ((i==1 || i==13)&&(j==0 || j==9))
            this->setElement( new MurVoid(i,j));
          else if ((i==1 || i==13) && (j!=4 && j!=5)){
            this->setElement( new MurDur(i,j));}
          else if ((j==1 || j==8) && (i!=4 && i!=6 && i!=8 && i!=10))
            this->setElement( new MurDur(i,j));
          else if (i%2==1 && (j==3 || j==6))
            this->setElement( new MurDur(i,j));
          else
            this->setElement( new MurCassable(i,j));
        }
      }

      break;
    case 2:
        std::cout << "void map" << '\n';
        for (int i = 0; i < 15; i++) {
          for (int j = 0; j < 10; j++) {
              this->setElement(new MurVoid(i,j));
            }
          }

      break;

    default:
      throw std::runtime_error("_MAP mal définie :(");
  }
std::cout<<"sortie initPlateau ? "<<std::endl;
}


void Plateau::renderPlateau(sf::RenderWindow* w ){
  for (size_t i = 0; i < 15; i++) {
    for (size_t j = 0; j < 10; j++) {
        w->draw(this->getElement(i,j)->getEsthetique()); // On place l'element sur le plateau
      }
    }
  }

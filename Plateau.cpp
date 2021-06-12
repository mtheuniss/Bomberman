
#include "Plateau.hpp"

//Constructeur
Plateau::Plateau(){
  _MAP = 1;
  _MAX_X = 1080; //HD = 1280 taille cube = 72*72 -> 10*15 -> 200 pixels pour l'affichage des scores
  _MAX_Y = 720;
  initPlateau();
  std::cout << "taille tableau" <<  _grid.size()<< '\n';
  std::cout << "taille tableau" <<  _grid[0].size()<< '\n';
}

//Destructeur
Plateau::~Plateau(){
  std::cout<<"suppression des l'elements de la grille"<<std::endl;
  for (int i =0; i<10; i++){
    for (int j =0; j<15; j++){
      delete this->_grid[j][i];
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

void Plateau::setElement(Mur* ent){
  this->_grid[ent->getPosX()][ent->getPosY()] = ent;
}

Mur* Plateau::getElement(int x, int y) const{
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
          else if ((j==1 || j==8) && (i!=4 && i!=6 && i!=8 && i!=10)){
            this->setElement( new MurDur(i,j));}
          else if (i%2==1 && (j==3 || j==6)){
            this->setElement( new MurDur(i,j));}
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
        w->draw(* this->getElement(i,j)->getEsthetique()); // On place l'element sur le plateau
      }
    }
  }

  void Plateau::updateGrille(std::list<sf::Vector2i>& liste){
    //on parcours la liste.
    //pour chaque coordonnées, si le mur est cassable alors on le casse
    //casser = supprimer le pointeur de mur et nouveau pointeur MurVoid
    //premier élément de la liste = point d'impact : ne nous interresse pas
    sf::Vector2i pt_impact = liste.front();
    liste.erase(liste.begin());
    std::cout << "liste des coordonnées" << '\n';
    for (std::list<sf::Vector2i>::iterator coord = liste.begin(); coord!=liste.end(); ++coord){
      std::cout << "coord = ["<<(*coord).x<<" ; "<<(*coord).y<<"]"<< '\n';
    }
    bool stop_gauche = false, stop_droite = false, stop_haut = false, stop_bas = false;
    for (std::list<sf::Vector2i>::iterator coord = liste.begin(); coord!=liste.end(); ++coord){
      std::cout << "coord = ["<<(*coord).x<<" ; "<<(*coord).y<<"]"<< '\n';
      if(_grid[(*coord).x][(*coord).y]->getCassable() == 0 && _grid[(*coord).x][(*coord).y]->getFranchissable() == 1){ //cas pas de mur
        //on le supprime de la liste, il ne nous interresse pas
        std::cout << "murVoid" << '\n';
        liste.erase(coord);
        coord--;
      }
      //si c'est un mur dur : on ne supprime pas les murs cassables qui suivent, mise à jour des variables stop
      else if (_grid[(*coord).x][(*coord).y]->getCassable() == 0 && _grid[(*coord).x][(*coord).y]->getFranchissable() == 0){
        std::cout << "murDur" << '\n';
        if (pt_impact.y == (*coord).y){//droite ou gauche
          if (pt_impact.x < (*coord).x)//droite
            stop_droite = true;
          else //gauche
            stop_gauche = true;
        }
        else {//haut ou bas
          if (pt_impact.y > (*coord).y)//haut
            stop_haut = true;
          else //bas
            stop_bas = true;
        }
        //on le supprime de la liste, il ne nous interresse pas
        liste.erase(coord);
        coord--;
      }
      //si c'est un mur cassable, on verifie qu'il n'est pas protégé par un mur dur
      else {
        std::cout << "murCassable" << '\n';
        if ((pt_impact.x>(*coord).x &&stop_gauche)||(pt_impact.y>(*coord).y&&stop_haut)||(pt_impact.x<(*coord).x &&stop_droite)||(pt_impact.y<(*coord).y&&stop_bas)){
          //le mur est protégé
          std::cout << "mais protégé" << '\n';
          liste.erase(coord);
          coord--;
        }
        else{
          delete this->_grid[(*coord).x][(*coord).y];
          this->setElement(new MurVoid((*coord).x,(*coord).y));
        }
      }
    }
    /*
    for (std::list<sf::Vector2i>::iterator coord = liste.begin(); coord!=liste.end(); ++coord){
      if (_grid[(*coord).x][(*coord).y]->getCassable() == 1){//on peut casser le mur
        delete this->_grid[(*coord).x][(*coord).y];
        this->setElement(new MurVoid((*coord).x,(*coord).y));
      }
      else{ //la case ne nous interresse pas : on supprime la case de la liste qui a la fin de la fonction
        //ne contient plus que les cases où un mur a été cassé
        liste.erase(coord);
        coord--;
      }
    }*/
  }

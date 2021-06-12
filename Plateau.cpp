
#include "Plateau.hpp"

//Constructeur
Plateau::Plateau(){
  initPlateau();
}

//Destructeur
Plateau::~Plateau(){
  for (int i =0; i<10; i++){
    for (int j =0; j<15; j++){
      delete this->_grid[j][i];
    }
  }
}

//Accesseurs
void Plateau::setElement(Mur* ent){
  this->_grid[ent->getPosX()][ent->getPosY()] = ent;
}
Mur* Plateau::getElement(int x, int y) const{
  return this->_grid[x][y];
}

//fonction private car on ne l'utilise qu'à l'interieur de la classe
void Plateau::initPlateau(){
  //On ajoute les murs dans le Plateau
  //  ATTENTION REPÈRE DE LA GRILLE COMME POUR LES IMAGES (en haut à gauche, ylignes)
  //les MurCassables sont partout sauf dans les coins
  //Note : nous ne sommes pas obligé d'utiliser setElement() car on est dans la classe. choix utilisation pour simplifier la lecture
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
}


void Plateau::renderPlateau(sf::RenderWindow* w ){
  //parcours de la grille 2D
  for (size_t i = 0; i < 15; i++) {
    for (size_t j = 0; j < 10; j++) {
        w->draw(* this->getElement(i,j)->getEsthetique()); // On place l'element sur le plateau
      }
    }
  }

  void Plateau::updateGrille(std::list<sf::Vector2i>& liste){
    //on parcours la liste.
    //pour chaque coordonnées, si le mur est cassable ET non protégé par un mur dur ALORS on le casse
    //casser = supprimer le pointeur de mur et nouveau pointeur MurVoid
    sf::Vector2i pt_impact = liste.front();
    //premier élément de la liste = point d'impact : ne nous interresse pas pour le parcours de la liste : forcément murVoid
    liste.erase(liste.begin());
    // variables stop : pour stopper la propagation d'une explosion dans une direction lorsque qu'il y a un murDur qui s'interpose
    bool stop_gauche = false, stop_droite = false, stop_haut = false, stop_bas = false;
    //parcours de la liste
    for (std::list<sf::Vector2i>::iterator coord = liste.begin(); coord!=liste.end(); ++coord){

      //CAS : PAS DE MUR (murVoid)
      if(_grid[(*coord).x][(*coord).y]->getCassable() == 0 && _grid[(*coord).x][(*coord).y]->getFranchissable() == 1){
        //on le supprime de la liste, il ne nous interresse pas
        liste.erase(coord);
        coord--;
      }
      //CAS : MUR DUR
      //si c'est un mur dur : on ne supprime pas les murs cassables qui suivent -> mise à jour des variables stop
      else if (_grid[(*coord).x][(*coord).y]->getCassable() == 0 && _grid[(*coord).x][(*coord).y]->getFranchissable() == 0){
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
      //CAS : MUR CASSABLE
      //si c'est un mur cassable, on verifie qu'il n'est pas protégé par un mur dur
      else {
        if ((pt_impact.x>(*coord).x &&stop_gauche)||(pt_impact.y>(*coord).y&&stop_haut)||(pt_impact.x<(*coord).x &&stop_droite)||(pt_impact.y<(*coord).y&&stop_bas)){
          //le mur est protégé
          liste.erase(coord);
          coord--;
        }
        else{
          //Le mur n'est pas protégé : destruction -> il devient un murVoid
          delete this->_grid[(*coord).x][(*coord).y];
          this->setElement(new MurVoid((*coord).x,(*coord).y));
        }
      }
    }
  }

#include "Joueur.hpp"

//Constructeur
Joueur::Joueur(){
  this->_numplayer = 0;
  this->_couleur =0 ;
}
Joueur::Joueur(int x , int y , int num, int color){

  this->_numplayer = num; //Numero du jouer ( si deux jouers 1 ou 2 )
  this->_couleur = color; // Couleur du jouer

  this->_pos.x = 72*x;
  this->_pos.y = 72*y;

  this->affichage();

}

//------------------------------------------------------------------------------
int Joueur::getPosOnGridX(){
  return round(this->getEsthetique().getPosition().x/72);
}

int Joueur::getPosOnGridY(){
  return round(this->getEsthetique().getPosition().y/72);
}
//------------------------------------------------------------------------------

void Joueur::setPosOnGridX(int x){
  this->_pos.x = round(x/72);
}
void Joueur::setPosOnGridY(int y){
  this->_pos.y = round(y/72);
}

void Joueur::setPosX(int x){
  this->getEsthetique().setPosition(x,sf::Vector2f(this->getEsthetique().getPosition().y));
}

void Joueur::setPosinPixY(int y){
  this->setPosX(round(y));
}


void Joueur::affichage(){
  switch (this->_couleur) {
    case 0:
      this->_esthetique.setSize(sf::Vector2f(60.f,60.f)); //.f -> float sans être float (carrés 72*72)
      this->_esthetique.setFillColor(sf::Color(0, 0, 0,255)); //On peut direct mettre la couleur c'est pas mal
      break;
}
}

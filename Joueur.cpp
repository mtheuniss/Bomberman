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

int Joueur::getPosX(){
  return this->getEsthetique().getPosition().x;
}
int Joueur::getPosY(){
  return this->getEsthetique().getPosition().y;
}

//------------------------------------------------------------------------------
int Joueur::getPosOnGridX(){
  return this->_pos.x;
}

int Joueur::getPosOnGridY(){
  return this->_pos.y;
}
//------------------------------------------------------------------------------

void Joueur::setPosOnGridX(int x){
  this->_pos.x = round(x/72);
}
void Joueur::setPosOnGridY(int y){
  this->_pos.y = round(y/72);
}

void Joueur::setPosX(int x){
  this->getEsthetique().setPosition(sf::Vector2f(x,this->getPosY()));
  this->setPosOnGridX(x);
}

void Joueur::setPosY(int y){
  this->getEsthetique().setPosition(sf::Vector2f(this->getPosX(),y));
  this->setPosOnGridX(y);
}

void Joueur::affichage(){
  switch (this->_couleur) {
    case 0:
      this->_esthetique.setSize(sf::Vector2f(60.f,60.f)); //.f -> float sans être float (carrés 72*72)
      this->_esthetique.setFillColor(sf::Color(0, 0, 0,255)); //On peut direct mettre la couleur c'est pas mal
      break;
}
}

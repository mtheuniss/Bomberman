#include "Joueur.hpp"

//Constructeur
Joueur::Joueur(){
  this->_numplayer = 0;
  this->_couleur = 0;
  this->_vitesse = 5;
}
Joueur::Joueur(int x , int y , int num, int color){

  this->_numplayer = num; //Numero du jouer ( si deux joueur 1 ou 2 )
  this->_couleur = color; // Couleur du joueur
  this->_vitesse = 5;

  this->setPosX(x*72); //On init avec une postion dans la grille
  this->setPosY(y*72); // Mais on set les position en pixels

  this->affichage();

}
//------------------------------------------------------------------------------
//Position dans la grille
int Joueur::getPosX() const{
  return this->getEsthetique().getPosition().x;
}
int Joueur::getPosY()const{
  return this->getEsthetique().getPosition().y;
}

//------------------------------------------------------------------------------
//Position dans la fenetre
int Joueur::getPosOnGridX()const{
  return this->_pos.x;
}
int Joueur::getPosOnGridY()const{
  return this->_pos.y;
}
//------------------------------------------------------------------------------
int Joueur::getVit()const{
  return this->_vitesse;
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
  this->setPosOnGridX(x); // division et arondi fait dans la fonction
}

void Joueur::setPosY(int y){
  this->getEsthetique().setPosition(sf::Vector2f(this->getPosX(),y));
  this->setPosOnGridX(y);// division et arondi fait dans la fonction
}

void Joueur::affichage(){
  switch (this->_couleur) {
    case 0:
      this->_esthetique.setSize(sf::Vector2f(60.f,60.f)); //.f -> float sans être float (carrés 72*72)
      this->_esthetique.setFillColor(sf::Color(0, 0, 0,255)); //On peut direct mettre la couleur c'est pas mal
      break;
}
}

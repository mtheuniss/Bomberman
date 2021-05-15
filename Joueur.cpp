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

  this->setPosX(x); //On init avec une position dans la grille
  this->setPosY(y); // Mais on set les position en pixels

  //gestion des bombes
  _nbBombes = 5;
  _typeBombe = Bombe();

  this->affichage();

}
//------------------------------------------------------------------------------
//Position dans la grille
int Joueur::getPosX() const{
  return _esthetique.getPosition().x;
}
int Joueur::getPosY()const{
  return _esthetique.getPosition().y;
}

//------------------------------------------------------------------------------
//Position dans la fenetre
int Joueur::getPosOnGridX()const{
  return this->_pos.x;
}
int Joueur::getPosOnGridY()const{
  //on vérifie que c'est dans la GRILLE
  return this->_pos.y;
}
//------------------------------------------------------------------------------
const int& Joueur::getVit()const{
  return this->_vitesse;
}

//------------------------------------------------------------------------------

void Joueur::setPosOnGridX(int x){
  if (round(x/72)<15){
    std::cout<<"setPosOnGridX"<<std::endl;
    this->_pos.x = round(x/72);
    std::cout<<"sortie setPosOnGridX"<<std::endl;
  }
}
void Joueur::setPosOnGridY(int y){
  if (round(y/72)){
    std::cout<<"setPosOnGridY"<<std::endl;
    this->_pos.y = round(y/72);
    std::cout<<"sortie setPosOnGridY"<<std::endl;
  }
}

void Joueur::setPosX(int x){
  //on fait en sorte que le joueur reste dans le plateau
  if(x>=0 && x<=(1080-30)){
    _esthetique.setPosition(sf::Vector2f(x,this->getPosY()));
    this->setPosOnGridX(x); // division et arrondi fait dans la fonction
  }
}

void Joueur::setPosY(int y){
  //on fait en sorte que le joueur reste dans le plateau
  std::cout<<"y= "<<y<<std::endl;
  if (y>=0 && y<(720-30)){
    std::cout<<"y compatible"<<std::endl;
    _esthetique.setPosition(sf::Vector2f(this->getPosX(),y));
    this->setPosOnGridY(y);// division et arondi fait dans la fonction
    std::cout<<"ICI"<<std::endl;
  }
}

void Joueur::affichage(){
  switch (this->_couleur) {
    case 0:
      this->_esthetique.setSize(sf::Vector2f(30.f,30.f)); //.f -> float sans être float (carrés 72*72)
      this->_esthetique.setFillColor(sf::Color(0, 0, 0,255)); //On peut direct mettre la couleur c'est pas mal
      break;
}
}

#include "Joueur.hpp"

//Constructeur
Joueur::Joueur(){
  this->_numplayer = 0;
  this->_couleur =0 ;
}
Joueur::Joueur(int x , int y , int num, int color){
  this->_numplayer = num; //Numero du jouer ( si deux jouers 1 ou 2 )
  this->_couleur = color; // Couleur du jouer

  this->affichage();
  this->setPosX(x);
  this->setPosY(y);
  if (!this->_texture.loadFromFile("mur_brique.png"))
  {
    std::cout<<"erreur lors de l'ouverture de l'image"<<std::endl;
  }
  this->_texture.setSmooth(true);//lissage de l'image
}

int Joueur::getPosOnGridX(){
  int posgridx = round(this->getEsthetique().getPosition().x);
  return posgridx;
}

int Joueur::getPosOnGridY(){
  int posgridy = round(this->getEsthetique().getPosition().y);
  return posgridy;
}

void Joueur::setPosinPixX(int x){
  this->getEsthetique().setPosition(sf::Vector2f(x,this->getEsthetique().getPosition().y));
  this->setPosX(round(x));
}
void Joueur::setPosinPixY(int y){
  this->getEsthetique().setPosition(sf::Vector2f(this->getEsthetique().getPosition().x, y));
  this->setPosX(round(y));
}


void Joueur::affichage(){


  switch (this->_couleur) {
    case 0:
      this->_esthetique.setSize(sf::Vector2f(72.f,72.f)); //.f -> float sans être float (carrés 72*72)
      this->_esthetique.setFillColor(sf::Color(255, 0, 0,255)); //On peut direct mettre la couleur c'est pas mal
      break;
}
}

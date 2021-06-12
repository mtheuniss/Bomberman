#include "Joueur.hpp"

//Constructeur
Joueur::Joueur(){
  this->_numplayer = 0;
  this->_couleur = 0;
  this->_vitesse = 5;
  this->_sensMarche =0;
  this->_nbVies = 3; //chaque joueur commence la partie avec 3 vies
}
Joueur::Joueur(int x , int y , int num, int color){
  this->_numplayer = num; //Numero du jouer ( si deux joueur 1 ou 2 )
  this->_couleur = color; // Couleur du joueur
  this->_vitesse = 5;

  this->_esthetique = new sf::RectangleShape();
  this->setPosX(x); //On init avec une position dans la grille
  this->setPosY(y); // Mais on set les position en pixels

  //gestion des bombes
  _nbBombes = 5;
  _typeBombe = Bombe();

  this->_nbVies = 3; //chaque joueur commence la partie avec 3 vies

  this->affichage();
}
//------------------------------------------------------------------------------
//Position en pixels
int Joueur::getPosX() const{
  return _esthetique->getPosition().x;
}
int Joueur::getPosY()const{
  return _esthetique->getPosition().y;
}

//------------------------------------------------------------------------------
//Position dans la grille
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
    this->_pos.x = round(x/72);
  }
}
void Joueur::setPosOnGridY(int y){
  if (round(y/72)<10){
    this->_pos.y = round(y/72);
  }
}

void Joueur::setPosX(int x){
  //on fait en sorte que le joueur reste dans le plateau
  if(x>=0 && x<=(1080-30)){
    _esthetique->setPosition(sf::Vector2f(x,this->getPosY()));
    this->setPosOnGridX(x); // division et arrondi fait dans la fonction
  }
}

void Joueur::setPosY(int y){
  //on fait en sorte que le joueur reste dans le plateau
  if (y>=0 && y<(720-30)){
    _esthetique->setPosition(sf::Vector2f(this->getPosX(),y));
    this->setPosOnGridY(y);// division et arondi fait dans la fonction
  }
}


void Joueur::estTouche(std::list<sf::Vector2i> liste){
  //on parcours la liste : si une des cases détruite par la bombe est celle du joueur, il perd une vie
  for (sf::Vector2i coord : liste){
    if (coord.x == _pos.x && coord.y == _pos.y){
      _nbVies --;
      std::cout<<"nbVies = "<< _nbVies<<std::endl;
      break; //on sort car le joueur n'est que dans une seule case
    }
  }
}



void Joueur::affichage(){

  //-----------------------------------------------------------------

  this->_esthetique->setSize(sf::Vector2f(72.f,72.f));
  this->_esthetique->setTextureRect(sf::IntRect(0,0,64,64));
  switch (  this->_couleur ) {
    case 1 :
    this->_texture.loadFromFile("Images/Joueur/sprite_pokemon_rose.png");
    break;
    case 2 :
    this->_texture.loadFromFile("Images/Joueur/sprite_pokemon_jaune.png");
    break;
    case 3 :
    this->_texture.loadFromFile("Images/Joueur/sprite_pokemon_vert.png");
    break;
    case 4 :
    this->_texture.loadFromFile("Images/Joueur/sprite_pokemon_blanc.png");
    break;
    default :
    this->_texture.loadFromFile("Images/Joueur/sprite_pokemon.png");
    break;


  }
  this->_esthetique->setOrigin(32,32);
  this->_esthetique->setTexture(&(this->_texture));

  this->_animation = new Animation(&(this->_texture), sf::Vector2u(4,4),0.3f);



//-----------------------------------------------------------------


}

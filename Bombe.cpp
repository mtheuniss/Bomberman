#include "Bombe.hpp"

Bombe::Bombe(){
  _pos.x = 0; _pos.y = 0;
  _rayon = 2;
  _explose = 0;
  this->affichage();

}
bool Bombe::imBoum(){
  if (_clock.getElapsedTime() > sf::seconds(3)){
    return 1;
  } else
    return 0;
}

//Cette fonction renvoit la liste des éléments de la grille qui seront détruits
void Bombe::degatsBombe(std::list<sf::Vector2i>& listeDegats){
  //on récupère la position de la bombe dans la grille et le rayon
  //on en déduit les positions qui sont supprimées
  //en notant les positions successives
  sf::Vector2i coordDegats;
  for (int i = (this->_pos.x-_rayon+1); i<=this->_pos.x+_rayon-1; i++){
    coordDegats.x=i; coordDegats.y=this->_pos.y;
    //on vérifie que les coordonées sont valides
    if(coordDegats.x>=0 && coordDegats.x<15)
      listeDegats.push_back(coordDegats);
  }
  for (int j = (this->_pos.y-_rayon+1); j<=this->_pos.y+_rayon-1; j++){
    coordDegats.x=this->_pos.x; coordDegats.y=j;
    //on vérfie que les coordonnées sont valides
    if(coordDegats.y>=0 && coordDegats.y<10){
      //on vérifie qu'il ne s'agit pas du pt d'application (sinon il apparaît 2 fois)
      if(!(coordDegats.x==_pos.x && coordDegats.y==_pos.y))
        listeDegats.push_back(coordDegats);
    }
  }
}

void Bombe::affichage(){
  this->_esthetique = new sf::RectangleShape();
  this->_esthetique->setSize(sf::Vector2f(72.f,72.f));
  this->_esthetique->setTextureRect(sf::IntRect(0,0,18,18));
  this->_texture.loadFromFile("Images/sprite_bombes.png");
  this->_esthetique->setTexture(&(this->_texture));
  this->_esthetique->setOrigin(6,6);
  this->_animation = new Animation(&(this->_texture), sf::Vector2u(3,5),0.3f);

}

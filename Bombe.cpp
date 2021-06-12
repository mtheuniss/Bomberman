#include "Bombe.hpp"

/*
Ce constructeur n'est appelé que lorsque les joueurs sont créés : les bombes lancées au cours du jeu sont des copies de celle ci
Ainsi lors de l'appel de ce constructeur, la bombe n'est pas posée d'où sa position à 0.
*/
Bombe::Bombe(){
  _pos.x = 0; _pos.y = 0;
  _rayon = 2;
  _type = 0;
  this->affichage();
}

bool Bombe::imBoum(){
  if (_clock.getElapsedTime() > sf::seconds(3)){
    return 1;
  } else
    return 0;
}

//Cette fonction renvoit grâce au passage par référence la liste des éléments de la grille qui seront détruits
void Bombe::degatsBombe(std::list<sf::Vector2i>& listeDegats){
  //on récupère la position de la bombe dans la grille et le rayon
  //on en déduit les positions qui sont supprimées
  //en notant les positions successives
  sf::Vector2i coordDegats;
  //premiere case de dégats, le point de l'impact
  coordDegats.x=this->_pos.x; coordDegats.y=this->_pos.y;
  listeDegats.push_back(coordDegats);
  //façon d'entrer les cases dans la grille : en s'éloignant de la case de l'explosion
  for (int i=1; i<_rayon; i++){
    for (int j=0;j<4;j++){
      //j=0 ->gauche, j=1 ->haut, j=2 ->droite, j=3 ->bas
      //coordonnées de la case
      switch (j) {
        case 0:
          coordDegats.x=this->_pos.x-i; coordDegats.y=this->_pos.y;
          break;
        case 1:
          coordDegats.x=this->_pos.x; coordDegats.y=this->_pos.y-i;
          break;
        case 2:
          coordDegats.x=this->_pos.x+i; coordDegats.y=this->_pos.y;
          break;
        case 3:
          coordDegats.x=this->_pos.x; coordDegats.y=this->_pos.y+i;
          break;
      }
      //on vérifie que les coordonnées sont valides
      //si oui, on ajoute les coordonnées dans la liste de dégats
      if ((coordDegats.x>=0 && coordDegats.x<15)&&(coordDegats.y>=0 && coordDegats.y<10))
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

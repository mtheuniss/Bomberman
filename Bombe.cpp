#include "Bombe.hpp"

Bombe::Bombe(){
  _pos.x = 0; _pos.y = 0;
  _rayon = 2;
  std::cout << "test ?" << '\n';
  if (!this->_texture.loadFromFile("Images/plaque_verte.png"))
  {
    std::cout<<"erreur lors de l'ouverture de l'image"<<std::endl;
  }
  this->_texture.setSmooth(true);//lissage de l'image
  _explose = 0;
  this->affichage();

}
bool Bombe::imBoum(){
  if (_clock.getElapsedTime() > sf::seconds(5)){
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
  this->_esthetique.setSize(sf::Vector2f(72.f,72.f)); //.f -> float sans être float (carrés 72*72)
  //this->_esthetique.setFillColor(sf::Color(255, 0, 0, 255)); //On peut direct mettre la couleur c'est pas mal
  //this->_esthetique.setOutlineThickness(1);
  //this->_esthetique.setOutlineColor(sf::Color(0, 128, 0));
  //insertion de l'image
 std::cout << "test dans affichagE ?" << '\n';
  this->_esthetique.setTextureRect(sf::IntRect(0, 0, 311, 207));
  this->_esthetique.setTexture(&(this->_texture));
}

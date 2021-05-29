#include "Animation.hpp"

Animation::Animation(sf::Texture* texAAnime, sf::Vector2u nbImages, sf::Time tmpPAmage){

  this->_nombreImages = nbImages; //le nombre d'image est donne
  this->_tmpInter = tmpPAmage; //Le temps de changement est donne
  this->_tmpTotal = sf::seconds(0.0f); // Le temps total peut etre calculer
  this->_imageActuelle.x = 0; // On commence par default a la premiere image

  this->_RectSelect.width = texAAnime->getSize().x / float(nbImages.x); //On determine la taille de chaque image d'animation en fonction de la taille de la texture et le nombre d'image
  this->_RectSelect.height = texAAnime->getSize().y / float(nbImages.y);
}

Animation::~Animation(){

}
void Animation::update(int startImage, sf::Time tmpIncrement){

  this->_imageActuelle.x = startImage; // On place l'animation sur une position specifique
  this->_tmpTotal += tmpIncrement; // On souhaite inclementer plus ou moins fort l'animation

  if(this->_tmpTotal >= this-> _tmpInter ){
    this->_tmpTotal -= this->_tmpInter; // on utile des sf::Time qui sont precis, icic on reset mais pas avec 0 mais avec une soustraction pour eviter la disparition des virgules
    this->_imageActuelle.x++; // les image d'animation vont de gauche a droite on incremente donc vers la droite
    if(this->_imageActuelle.x >= this-> _nombreImages.x ){ //si on depasse le nombre d'image dans l'animation
      this->_imageActuelle.x = 0; // On renvoie l'animation au debut c'est bien cyclique
    }
  }

  this->_RectSelect.left = this->_imageActuelle.x * this->_RectSelect.width; //Pour savoir la taille du rectangle par rapport a la texture
  this->_RectSelect.top = this->_imageActuelle.y * this->_RectSelect.height;




}

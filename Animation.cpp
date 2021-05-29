#include "Animation.hpp"

Animation::Animation(){}


Animation::Animation(sf::Texture* texAAnime, sf::Vector2u nbImages, float tmpPImage){

  this->_nombreImages = nbImages; //le nombre d'image est donne
  this->_tmpInter = tmpPImage; //Le temps de changement est donne
  this->_tmpTotal = 0.0f; // Le temps total peut etre calculer
  this->_imageActuelle.x = 0; // On commence par default a la premiere image

  this->_RectSelect.width = texAAnime->getSize().x / float(nbImages.x); //On determine la taille de chaque image d'animation en fonction de la taille de la texture et le nombre d'image
  this->_RectSelect.height = texAAnime->getSize().y / float(nbImages.y);
}

Animation::~Animation(){

}
void Animation::update(int startImage, float tmpIncrement){

  this->_imageActuelle.y = startImage; // On place l'animation sur une position specifique
  this->_tmpTotal += tmpIncrement; // On souhaite inclementer plus ou moins fort l'animation

  if(this->_tmpTotal >= this-> _tmpInter ){
    this->_tmpTotal -= this->_tmpInter; // on utile des float qui sont precis, icic on reset mais pas avec 0 mais avec une soustraction pour eviter la disparition des virgules
    this->_imageActuelle.x += 1; // les image d'animation vont de gauche a droite on incremente donc vers la droite

    if(this->_imageActuelle.x >= this-> _nombreImages.x ){ //si on depasse le nombre d'image dans l'animation
      this->_imageActuelle.x = 0; // On renvoie l'animation au debut c'est bien cyclique
    }
  }
  this->_RectSelect.left = this->_imageActuelle.x * this->_RectSelect.width; //Pour savoir la taille du rectangle par rapport a la texture
  this->_RectSelect.top = this->_imageActuelle.y * this->_RectSelect.height;



}

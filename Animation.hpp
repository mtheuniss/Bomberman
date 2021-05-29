#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include<SFML/Graphics.hpp>

class Animation {

private:
  sf::Vector2u _nombreImages; //aka cb d'image au total ex : 3 types 5 image par type
  sf::Vector2u _imageActuelle; // ou on ce trouve dans notre cycle d'animation

  sf::Time _tmpTotal; //Le temps du cycle donc le nombre de temps par animation fois le nombre d'image dans chaque Animation
  sf::Time _tmpInter; // Le temps avant de passer a l'autre image

public:
  Animation (sf::Texture* texAAnime, sf::Vector2u nbImages, sf::Time tmpPAmage);
  virtual ~Animation ();

  sf::IntRect _RectSelect; // ou on ce trouve dans la texture global avec toute les images d'animation
  void update(int row, sf::Time deltaTime);




};









#endif

#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include<SFML/Graphics.hpp>
# include <iostream>
class Animation {

private:
  sf::Vector2u _nombreImages; //aka cb d'image au total ex : 3 types 5 image par type
  sf::Vector2u _imageActuelle; // ou on ce trouve dans notre cycle d'animation

  int _bouclage;
  float _tmpTotal; //Le temps du cycle donc le nombre de temps par animation fois le nombre d'image dans chaque Animation
  float _tmpInter; // Le temps avant de passer a l'autre image

public:
  Animation();
  Animation (sf::Texture* texAAnime, sf::Vector2u nbImages, float tmpPAmage);
  ~Animation (){std::cout << "destructeur animation" << '\n';};

  sf::IntRect _RectSelect; // ou on ce trouve dans la texture global avec toute les images d'animation
  void update(int startImage, float tmpIncrement);

};

#endif

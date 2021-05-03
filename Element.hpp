#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

class Element{
  public :
    virtual void affichage ()=0;
    virtual ~Element()=0;
    sf::RectangleShape getEsthetique(){return this->_esthetique;}
  protected:
    sf::Vector2i _pos;
    sf::RectangleShape _esthetique;


};
#endif

#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

class Element{
  public :
    virtual void affichage ();
  protected:
    sf::Vector2i _pos;
    sf::RectangleShape _esthetique;

};
#endif

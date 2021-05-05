#ifndef ELEMENT_HPP
#define ELEMENT_HPP

# include <iostream>

#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

class Element{
  public :
    virtual void affichage ()=0;
    virtual ~Element(){}

    //Accesseurs
    int getPosX (){return this->_pos.x;}
    int getPosY (){return this->_pos.y;}

    void setPosX(int x){
      this->_pos.x = x;
      this->_esthetique.setPosition(sf::Vector2f(72.0*x,this->_esthetique.getPosition().y));
    }
    void setPosY(int y){
      this->_pos.y = y;
      this->_esthetique.setPosition(sf::Vector2f(this->_esthetique.getPosition().x,72.0*y));
    }

    sf::RectangleShape getEsthetique(){return this->_esthetique;}
  protected:
    sf::Vector2i _pos; //Position dans la grille != position du RectangleShape
    sf::RectangleShape _esthetique;
};
#endif

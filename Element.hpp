#ifndef ELEMENT_HPP
#define ELEMENT_HPP

# include <iostream>
#include "Animation.hpp"
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

class Element{
  public :
    virtual void affichage ()=0;
    virtual ~Element(){
      delete this->_esthetique;
    }

    //Accesseurs
    const int& getPosX() const{return this->_pos.x;}
    const int& getPosY() const{return this->_pos.y;}

    void setPosX(const int& x){
      this->_pos.x = x;
      this->_esthetique->setPosition(sf::Vector2f(x*72,this->getEsthetique()->getPosition().y));
    }

    void setPosY(const int& y){
      this->_pos.y = y;
      this->_esthetique->setPosition(sf::Vector2f(this->getEsthetique()->getPosition().x, y*72 ));
    }

    sf::RectangleShape* getEsthetique(){return this->_esthetique;}
  protected:
    sf::Vector2i _pos; //Position dans la grille != position du RectangleShape
    sf::RectangleShape* _esthetique;
    sf::Texture _texture;
};
#endif

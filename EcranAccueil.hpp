#ifndef ECRANACCUEIL_HPP
#define ECRANACCUEIL_HPP

# include <iostream>
#include "Animation.hpp"
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
/*
EcranAccueil : interface graphique destinée à choisir les joueurs avant la partie
*/
class EcranAccueil{
  public :
    EcranAccueil();
    ~ EcranAccueil(){delete this->_window;}
    bool getIsRunning() const{return this->_window->isOpen();}

    //accesseurs const
    const int& getNperso1() const{return _nperso1;}
    const int& getNperso2() const{return _nperso2;}

    void initbouton();
    void update();
    void render();

  protected :
    sf::RenderWindow* _window;
    sf::VideoMode _videoMode;
    sf::Event _ev;
//les 2 perosonnages à choisir
    int _nperso1;
    int _nperso2;
//les boutons à afficher
    sf::RectangleShape _boutonperson1;
    sf::Texture _textureB1;
    sf::RectangleShape _boutonperson2;
    sf::Texture _textureB2;
    sf::RectangleShape _boutonperson3;
    sf::Texture _textureB3;
    sf::RectangleShape _boutonperson4;
    sf::Texture _textureB4;
    sf::RectangleShape _jouer;
    sf::Texture _textureJouer;
};

#endif

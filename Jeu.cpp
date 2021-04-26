# include <iostream>

#include "Jeu.hpp"

//Constructeur
Jeu::Jeu(){
  this->initVariables();
  this->initFenetre();
}

//Accesseurs
const bool Jeu::getIsRunning() const{
  return this->_window->isOpen();
}

// Fonctions private
void Jeu::initVariables(){
  this-> _window = nullptr;
  this->_videoMode.height = 600;
  this->_videoMode.width = 800;
}
void Jeu::initFenetre(){
  this-> _window = new sf::RenderWindow(this->_videoMode, "Bomberman", sf::Style::Close | sf::Style::Titlebar);
}
//Fonctions Public
//mise à jour du jeu (logique du jeu)
void Jeu::updateEvents(){
  while(this->_window->pollEvent(this->_ev))
  {
    switch (this->_ev.type) {
      case sf::Event::Closed:
        this->_window->close();
        break;
      case sf::Event::KeyPressed:
        if(_ev.key.code == sf::Keyboard::Escape)
          this->_window->close();
        break;
    }
  }
}
void Jeu::update(){
  this->updateEvents();
}
//visualisation du jeu (interface)
void Jeu::render(){
  this->_window->clear(sf::Color(255,255,255,255));//RGB+transparence
  //dessin des objets

  //affichage de la fenetre
  this->_window->display();
}

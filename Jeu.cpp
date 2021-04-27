# include <iostream>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

#include "Jeu.hpp"

//Constructeur
Jeu::Jeu(){
  this->initVariables();
  this->initFenetre();
  this->initEntity();
}

//Accesseurs
const bool Jeu::getIsRunning() const{
  return this->_window->isOpen();
}

//Fonction private

void Jeu::initEntity(){

  this->ent1.setSize(sf::Vector2f(100.f,100.f)); //.f -> float sans être float 
  this->ent1.setFillColor(sf::Color::Cyan); //On peut direct mettre la couleur c'est pas mal

}
// Fonctions private
void Jeu::initVariables(){
  this-> _window = nullptr;
  this->_videoMode.height = 600;
  this->_videoMode.width = 800;


  this->_spaceuse = 0;
  this->_couleurFond = sf::Color::White; //blanc

  this->_posEnt = sf::Vector2f(0,0); // On init en haut a gauche
  this-> _vitEnt = 5; // Vitesse

}
void Jeu::initFenetre(){
  this-> _window = new sf::RenderWindow(this->_videoMode, "Bomberman", sf::Style::Close | sf::Style::Titlebar);
  this->_window->setFramerateLimit(144);


}
//Fonctions Public
//mise à jour du jeu (logique du jeu)
void Jeu::updateEvents(){

  while(this->_window->pollEvent(this->_ev)) {
    switch (this->_ev.type) { //On regarde l'envent en cours



      case sf::Event::Closed: // Si c'est l fermeture on ferme
        this->_window->close();
        break;


      case sf::Event::KeyPressed: //Si c'est une pression clavier, on regarde la quelle 
        switch (_ev.key.code){//On verif le code /!\ qu'un touche à la fois pas ouf mais ok pour jeux 2d

          case sf::Keyboard::Space: // Si espace :
          this->_spaceuse = (this->_spaceuse+1)%3; // On tourne parmis les 3 couleurs
          switch(this->_spaceuse){ 
            case 0:
              this->_couleurFond = sf::Color::Blue;
              break;
            case 1:
              this->_couleurFond = sf::Color::Green;
              break;
            case 2:
              this->_couleurFond = sf::Color::Red;
             break;
          } 
          break;


          // On init les fleches pour déplacer 
         case sf::Keyboard::Left: 
            this->ent1.setPosition(this->ent1.getPosition()+sf::Vector2f(- this->_vitEnt,0));  // Le repère image est déplacer on fait attention à mettre les vitesse dans le bon sens
             break;
         case sf::Keyboard::Right:
            this->ent1.setPosition(this->ent1.getPosition()+sf::Vector2f(this->_vitEnt,0));
             break;
         case sf::Keyboard::Up:
            this->ent1.setPosition(this->ent1.getPosition()+sf::Vector2f(0,- this->_vitEnt));
             break;
          case sf::Keyboard::Down:
            this->ent1.setPosition(this->ent1.getPosition()+sf::Vector2f(0, this->_vitEnt));
             break;


          break;
        }
      break;

      
    }
  }
}
void Jeu::update(){
  this->updateEvents();
}
//visualisation du jeu (interface)
void Jeu::render(){
  this->_window->clear(this->_couleurFond);//RGB+transparence
  //dessin des objets
  this->_window->draw(this->ent1); // On place l'element sur le plateau



  //affichage de la fenetre
  this->_window->display();
}
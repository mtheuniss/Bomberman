#ifndef JEU_HPP
#define JEU_HPP

#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

#include "Element.hpp"
#include "MurCassable.hpp"
#include "Plateau.hpp"

class Jeu{
  private :
    //Variables (pas besoin protected car pas classe dérivée)
    sf::RenderWindow* _window;
    sf::VideoMode _videoMode;
    sf::Event _ev;

    //sf::RectangleShape ent1;
    MurCassable ent1;
    Plateau _grille;


    // Variable pour gestion d'event
    int _spaceuse;  //incrément pour changer de couleur avec la barre d'espace
    sf::Color _couleurFond; //Stockage de la couleur de fond du jeu

    sf::Vector2f _posEnt; //Position de la seul entité
    float _vitEnt; // vitesse de déplacement de l'entité /!\ si on augmemente trop ca ne sera plus continue


    // Fonctions privées (que pour l'initialisation)
    void initVariables();
    void initFenetre();
    void initEntity(); // Pour séparer l'init des entitées et des fenêtres qui stock les entitées

  public :
    //Constructeur, Destructeur
    Jeu();
    virtual ~Jeu(){delete this->_window;}

    //Accesseurs
    const bool getIsRunning() const;

    //Fonctions
    void updateEvents();
    void update();
    void render();
};

#endif

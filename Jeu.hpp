#ifndef JEU_HPP
#define JEU_HPP

#include "Plateau.hpp"

class Jeu{
  private :
    //Variables (pas besoin protected car pas classe dérivée)
    sf::RenderWindow* _window;
    sf::VideoMode _videoMode;
    sf::Event _ev;

    Plateau _grille;

    Joueur* _j1;
    Joueur* _j2;

    // Variable pour gestion d'event

    // sf::Vector2f _posEnt; //Position de la seul entité


    // Fonctions privées (que pour l'initialisation)
    void initVariables();
    void initFenetre();
    void initEntity(); // Pour séparer l'init des entitées et des fenêtres qui stock les entitées
      void initJoueur();

  public :
    //Constructeur, Destructeur
    Jeu();
    virtual ~Jeu(){std::cout<<"supp _fenetre"<<std::endl;delete this->_window;}

    //Accesseurs
    const bool getIsRunning() const;

    //Fonctions
    void update();
      void updateEvents();
    void render();
      void renderJoueurs();
};

#endif

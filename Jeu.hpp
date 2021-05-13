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
    //int _spaceuse;  //incrément pour changer de couleur avec la barre d'espace
    sf::Color _couleurFond; //Stockage de la couleur de fond du jeu

    sf::Vector2f _posEnt; //Position de la seul entité
    int _vitEnt; // vitesse de déplacement de l'entité /!\ si on augmemente trop ca ne sera plus continue


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
    void updateEvents();
    void update();
    void render();
      void renderJoueurs();
};

#endif

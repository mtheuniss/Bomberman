#ifndef JEU_HPP
#define JEU_HPP

#include "Plateau.hpp"
#include <list>

class Jeu{
  private :
    //Variables (pas besoin protected car pas classe dérivée)
    sf::RenderWindow* _window;
    sf::VideoMode _videoMode;
    sf::Event _ev;

    Plateau _grille;
    std::list<Element*> _listeBombes;

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
    virtual ~Jeu(){delete this->_window;delete _j1; delete _j2;
      for (std::list<Element*>::const_iterator it = _listeBombes.begin(); it!=_listeBombes.end(); ++it)
      {
        delete *it;
      }
      std::cout<<"supp _fenetre & joueurs"<<std::endl;}

    //Accesseurs
    bool getIsRunning() const;
        //x et y sont en pixels
    bool estFranchissable(const int& x,const int& y) const{
      return _grille.getElement(round(x/72), round(y/72))->getFranchissable();
    }

    //Fonctions
    void update();
    void updateEvents();
    void render();
    void renderJoueurs();
};

#endif

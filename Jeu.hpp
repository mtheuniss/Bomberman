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
    std::list<Bombe*> _listeBombes;

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
    virtual ~Jeu(){
      delete this->_window;
      delete _j1; delete _j2;
      for(Bombe* child : _listeBombes) {
        std::cout<<"supp _bombe"<<std::endl;
        delete child;
        }
      std::cout<<"supp _fenetre & joueurs"<<std::endl;
    }

    //Accesseurs
    bool getIsRunning() const;
        //x et y sont en pixels
    bool estFranchissable(const int& x,const int& y) const{
      return _grille.getElement(round(x/72), round(y/72))->getFranchissable();
    }

    //Fonctions
    void update();
      void updateEvents();
      void updateBombes();
    void render();
      void renderJoueurs();
      void renderBombes();
};

#endif

#ifndef JEU_HPP
#define JEU_HPP


#include "Animation.hpp"
#include "Plateau.hpp"

#include "PowerUpViePlus.hpp"
#include "PowerUpBombePlus.hpp"
#include "PowerUpVitessePlus.hpp"
#include "PowerUpFirePlus.hpp"

#include <list>

class Jeu{
  private :
    //Variables (pas besoin protected car pas classe dérivée)
    sf::RenderWindow* _window;
    sf::VideoMode _videoMode;
    sf::Event _ev;
    sf::RectangleShape _barreEtatJoueur;
    sf::Texture _imageBarreEtat;

    Plateau _grille;
    std::list<Bombe*> _listeBombes;
    std::list<PowerUp*> _listePowerUp;

    Joueur* _j1;
    Joueur* _j2;

    float tmpIncrement = 0.0f;

    // Fonctions privées (que pour l'initialisation)
    void initVariables();
    void initFenetre();
    void initEntity(); // Pour séparer l'init des entitées et des fenêtres qui stock les entitées
    void initJoueur();
    void initBarreEtatJoueur();

    void nouveauPowerUp(std::list<sf::Vector2i> liste);

  public :
    //Constructeur, Destructeur
    Jeu();
    Jeu(Joueur* j1 , Joueur* j2);
    virtual ~Jeu(){
      delete this->_window;
      delete _j1; delete _j2;
      for(Bombe* child : _listeBombes) {
        delete child;
      }
      for(PowerUp* child : _listePowerUp) {
        delete child;
      }
    }

    sf::Clock clock;
    //Accesseurs
    bool getIsRunning() const;
        //x et y sont en pixels
    bool estFranchissable(const int& x,const int& y) const{
      return _grille.getElement(round(x/72), round(y/72))->getFranchissable();
    }

    //Fonctions
    void update();
      void updateEvents();
      void updateIA();
      void updateBombes();
      void updatePowerUp();
    void render();
      void renderJoueurs();
      void renderBombes();
      void renderPowerUp();
      void renderBarreEtat();
      void renderFinJeu();
};

#endif

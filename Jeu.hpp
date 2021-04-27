#ifndef JEU_HPP
#define JEU_HPP

#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

class Jeu{
  private :
    //Variables (pas besoin protected car pas classe dérivéé)
    sf::RenderWindow* _window;
    sf::VideoMode _videoMode;
    sf::Event _ev;
    int _spaceuse;
    sf::Color _couleurFond;
    // Fonctions privées (que pour l'initialisation)
    void initVariables();
    void initFenetre();

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

#ifndef ECRANACCUEIL_HPP
#define ECRANACCUEIL_HPP
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

    void update();
    void render();

  protected :
    sf::RenderWindow* _window;
    sf::VideoMode _videoMode;
    sf::Event _ev;

    int _nperso1;
    int _nperso2;
};

#endif

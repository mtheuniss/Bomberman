#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

class Plateau{
  private :
    //Variables
    int _MAX_X;
    int _MAX_Y;
    int _TailleElementStandard;

    sf::RectangleShape** _grid;

  public :
    //Constructeur, Destructeur
    Plateau();

    void setMaxX(int x);
    void setMaxY(int y);
    void setGrid(sf::RectangleShape**);

    int getMaxX();
    getMaxY();
    getGrid();
};

#endif

#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

class Plateau{
  private :
    //Variables
    int _MAP; //Variable pour changer de generation de map
    int _MAX_X; //Variable de taille max en pixel en colonnes
    int _MAX_Y; //Variable de taille max en pixel en lignes
    int _TailleElementStandard; //Variable standrard pour un element

    std::array< std::array<sf::RectangleShape,15>,10> _grid; //Grid pour stocker les elements

  public :
    //Constructeur, Destructeur
    Plateau();

    void setMaxX(int x);
    void setMaxY(int y);
    void setGrid(sf::RectangleShape**);

    int getMaxX();
    int getMaxY();
    sf::RectangleShape** getGrid();
};

#endif

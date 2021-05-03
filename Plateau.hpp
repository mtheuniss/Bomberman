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


    //Fonction private

    void initPlateau();

  public :
    //Constructeur, Destructeur
    Plateau();

    void setMaxX(int mx);
    void setMaxY(int my);
    void setMapType(int mt); // /!\ changer la maptype avant l'init

    void setElement(int x , int y , sf::RectangleShape RectShape);

    int getMaxX() const;
    int getMaxY() const;
    int getMap()  const;
};

#endif

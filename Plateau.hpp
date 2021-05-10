#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include "MurCassable.hpp"
#include "MurVoid.hpp"
#include "MurDur.hpp"
#include "Mur.hpp"

class Plateau{
  private :
    //Variables
    int _MAP; //Variable pour changer de generation de map
    int _MAX_X; //Variable de taille max en pixel en colonnes
    int _MAX_Y; //Variable de taille max en pixel en lignes

    std::array< std::array<Element*,15>,10> _grid; //Grid pour stocker les elements


    //Fonction private

  public :
    //Constructeur, Destructeur
    Plateau();
    ~ Plateau();

    void setMaxX(int mx);
    void setMaxY(int my);
    void setMapType(int mt); // /!\ changer la maptype avant l'init


    void setElement( Element* ent);
    Element* getElement(int x, int y);

    int getMaxX() const;
    int getMaxY() const;
    int getMap()  const;

    void initPlateau();
    void renderPlateau(sf::RenderWindow* w);
};

#endif

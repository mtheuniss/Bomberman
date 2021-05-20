#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include "Joueur.hpp"
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

    std::array< std::array<Mur*,10>,15> _grid; //Grid pour stocker les elements


    //Fonction private
    void initPlateau();
  public :
    //Constructeur, Destructeur
    Plateau();
    ~ Plateau();

    //Accesseurs (const et non const)
    const int& maxX() const {return _MAX_X;}
    int& maxX() {return _MAX_X;}

    const int& maxY() const {return _MAX_Y;}
    int& maxY() {return _MAX_Y;}

    void setMaxX(int mx);
    void setMaxY(int my);
    void setMapType(int mt); // /!\ changer la maptype avant l'init


    void setElement( Mur* ent);
    Mur* getElement(int x, int y) const;

    int getMaxX() const;
    int getMaxY() const;
    int getMap()  const;

    void renderPlateau(sf::RenderWindow* w);
    void updateGrille(std::list<sf::Vector2i> liste);
};

#endif

#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include "Plateau.hpp"
#include <typeinfo>
#include <math.h>


class Joueur {
  public :
    //Constructeur, destructeur
    Joueur();
    Joueur(int x, int y, int num, int color);


    void affichage();
  protected :
    int _numplayer;
    int _couleur;
    Vector2i _pos;
    sf::RectangleShape _esthetique;
    sf::Texture _texture;

};
#endif

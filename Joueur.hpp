#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include "Element.hpp"
#include "Plateau.hpp"
#include <typeinfo>

class Joueur : public Element {
  public :
    //Constructeur, destructeur
    Joueur();
    Joueur(int x, int y, int num, int color);


    void affichage();
  protected :
    int _numplayer;
    int _couleur;

};
#endif

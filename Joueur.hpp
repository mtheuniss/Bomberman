#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include "Element.hpp"
#include "Plateau.hpp"
#include <typeinfo>
#include <math.h>


class Joueur : public Element {
  public :
    //Constructeur, destructeur
    Joueur();
    Joueur(int x, int y, int num, int color);

    int getPosOnGridX();
    int getPosOnGridY();


    void setPosinPixX(int x);
    void setPosinPixY(int y);




    void affichage();
  protected :
    int _numplayer;
    int _couleur;

};
#endif

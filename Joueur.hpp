#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <typeinfo>
#include <math.h>
# include <iostream>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

class Joueur {
  public :
    //Constructeur, destructeur
    Joueur();
    Joueur(int x, int y, int num, int color);


    int getPosX() const;
    int getPosY() const;
    int getPosOnGridX()const;
    int getPosOnGridY()const;
    int getVit()const;
    void setPosOnGridX(int x);
    void setPosOnGridY(int y);
    void setPosX(int x);
    void setPosY(int y);

    sf::RectangleShape getEsthetique() const {return this->_esthetique;}

    void affichage();
  protected :
    int _numplayer;
    int _couleur;
    int _vitesse; // vitesse de déplacement de l'entité /!\ si on augmemente trop ca ne sera plus continue
    sf::Vector2i _pos;
    sf::RectangleShape _esthetique;
    sf::Texture _texture;

};
#endif

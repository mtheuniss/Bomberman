#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <typeinfo>
#include <math.h>
# include <iostream>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include <list>

#include "Bombe.hpp"
#include "Animation.hpp"

class Joueur {
  public :
    //Constructeur, destructeur
    Joueur();
    Joueur(int x, int y, int num, int color);
    ~Joueur(){
      delete this->_animation;
      delete this->_esthetique;
    }

    int getPosX() const;
    int getPosY() const;
    int getPosOnGridX()const;
    int getPosOnGridY()const;
    Animation* getAnimation(){return this->_animation;}
    int getSensMarche(){return this-> _sensMarche;}
    int getNbBombes() const{return _nbBombes;}
    const int& getVit()const;
    const Bombe& getTypeBombe() const {return _typeBombe;}
    Bombe* getBombe() {return &_typeBombe;}

    //accesseurs _nbVies (const et non const)
    const int& nbVies() const{return _nbVies;}
    int& nbVies() {return _nbVies;}

    const int& getJoueurColor() const{return _couleur;}
    int& getJoueurColor() {return _couleur;}

    const int& getVitesse() const{return _vitesse;}
    int& getVitesse() {return _vitesse;}



    void setPosOnGridX(int x);
    void setPosOnGridY(int y);
    void setPosX(int x);
    void setPosY(int y);
    void setAnimation(sf::Texture* texture, sf::Vector2u nbImages, float tmp){
      this->_animation = new Animation(texture,nbImages,tmp);
    }
    void setSensMarche(int s){this->_sensMarche = s;}

    void setVitesse(int v){this->_vitesse = v;}


    void setNbBombes(int nb) {_nbBombes = nb;}
    void setPosBombe(int x, int y){_typeBombe.setPosX(x); _typeBombe.setPosY(y);}
    void estTouche(std::list<sf::Vector2i> liste);

    sf::RectangleShape* getEsthetique() const {return this->_esthetique;}

    void affichage();

  protected :
    int _numplayer;
    int _couleur;
    int _vitesse; // vitesse de déplacement de l'entité /!\ si on augmemente trop ca ne sera plus continue
    sf::Vector2i _pos; //position dans la grille
    int _nbVies; //nombre de vies du jeu au cours de la partie

    sf::RectangleShape* _esthetique;
    sf::Texture _texture;
    Animation* _animation;
    int _sensMarche;

    int _nbBombes;
    Bombe _typeBombe;


};
#endif

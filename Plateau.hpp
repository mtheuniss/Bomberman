#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include "Joueur.hpp"
#include "MurCassable.hpp"
#include "MurVoid.hpp"
#include "MurDur.hpp"

class Plateau{
  private :
    //Attributs
    std::array< std::array<Mur*,10>,15> _grid; //Grid pour stocker les murs


    //Fonction private
    /**
	 * Création du plateau de jeu : remplissage de _grid avec les 3 types de murs
	 */
    void initPlateau();

  public :
    //Constructeur, Destructeur
    Plateau();
    ~ Plateau();

    //Accesseurs aux éléments de la grille
    void setElement( Mur* ent);
    Mur* getElement(int x, int y) const;

    /**
    	 * Affichage du plateau dans la fenetre de jeu prise en argument par parcours de la grille
       * Il s'agit de l'arrière plan du jeu
    	 */
    void renderPlateau(sf::RenderWindow* w);

    /**
       * mise à jour de la grille lorsqu'une bombe explose : casser les murs cassables touchés par l'explosion des bombes
       *  argument = liste : liste des coordonnées des cases de la _grid possiblement touchés par la bombe
       *  la liste est passée par référence : à la sortie de la fonction : il ne restent que coordonnées des murs qui ont été réellement cassés
	 */
    void updateGrille(std::list<sf::Vector2i>& liste);
};

#endif

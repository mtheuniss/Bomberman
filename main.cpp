# include <iostream>

#include "Jeu.hpp"
#include "EcranAccueil.hpp"

int main()
{
  //Création d'un objet de la classe ecranAccueil
  EcranAccueil accueil;
  int perso1 = 0;
  int perso2 = 0;
  //Boucle de l'écran de l'écran d'acceuil

  while(accueil.getIsRunning()){
    //mise à jour de la fenetre
    accueil.update();
    //mise à jour des graphiques
    accueil.render();
    //mise à jour des personnages
    perso1 = accueil.getNperso1();
    perso2 = accueil.getNperso2();
  }

  //Création d'un objet jeu si les 2 peronnages choisi sont valides
  //si ce n'est pas le cas alors c'est que l'utilisateur ne veut plus jouer, il a fermé la fenetre
  if (perso1!=0 && perso2!=0){
    Jeu partieBomberman;
    std::cout << "jeu construit" << '\n';

    //boucle de Jeu
    while(partieBomberman.getIsRunning()){
      //mise à jour de la partie
      partieBomberman.update();

      //mise à jour des graphiques
      partieBomberman.render();
    }
  }
  //fin de la partie, la fenetre a été fermée
  return 0;
}

# include <iostream>

#include "Jeu.hpp"

int main()
{
  //Création d'un objet jeu
  Jeu partieBomberman;
  std::cout << "jeu construit" << '\n';
  //boucle de Jeu
  while(partieBomberman.getIsRunning()){
    //mise à jour de la partie
    partieBomberman.update();
    //mise à jour des graphiques
    partieBomberman.render();
  }
  //fin de la partie
  return 0;
}

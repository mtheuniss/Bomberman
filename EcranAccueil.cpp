#include EcranAccueil.hpp

EcranAccueil::EcranAccueil(){
  //initialisation des numéros de personnage : 0=pas de personnage sélectionné
  this->_nperso1 = 0;
  this->_nperso2 = 0;
  //initialisation de la fenetre
  this-> _window = nullptr;
  this->_videoMode.height =720 ;
  this->_videoMode.width = 1280;
  this-> _window = new sf::RenderWindow(this->_videoMode, "Bienvenue dans Bomberman", sf::Style::Close | sf::Style::Titlebar);
}

/* Fonction de mise à jour appellé dans la boucle du main
  on met à jour ici les événements de l'interface graphique*/

void EcranAccueil::update(){
  //gestion des événements
  while(this->_window->pollEvent(this->_ev)) {
    switch (this->_ev.type) { //On regarde l'envent en cours

      case sf::Event::Closed: // croix en haut ou echap on ferme le jeu en entier
        this->_window->close();
        break;

      case sf::Event::KeyPressed: //Si c'est une pression clavier, on regarde la quelle
        switch (_ev.key.code){//On verif le code /!\ qu'un touche à la fois pas ouf mais ok pour jeux 2d

          case sf::Keyboard::Escape: // Si echap :
            this->_window->close();
            break;

          default :
            break;
      //gestion des boutons : 5 boutons = selection d'un des 4 personnages et le bouton jouer
      case sf::Mouse::Right :
        //à chaque bouton est associée une zone dans la fenetre
        //cliquer dans la zone = cliquer sur le bouton
        //bouton cliqué => mise à jour des perso, désactivé la cliquabilité, griser la  (ajout gris en + de l'image)

      //gestion des boutons : clic gauche = changer le dernier joueur sélectionné
      //case sf::Mouse::Left :

      default :
        break;
}

#include "Jeu.hpp"

//Constructeur
Jeu::Jeu(){
  this->initVariables();
  std::cout<<"sortie de initVariables"<<std::endl;
  this->initFenetre();
  std::cout<<"sortie de initFenetre"<<std::endl;
  this->initEntity();
  std::cout<<"fin du constructeur du jeu"<<std::endl;
}

//Accesseurs
const bool Jeu::getIsRunning() const{
  return this->_window->isOpen();
}


void Jeu::initJoueur(){




  int randpos = rand() % 10;

  switch (randpos) {
    case 0:
      this->_j1 = new Joueur(0,0,1,1);
      this->_j2 = new Joueur(0,15,1,1);
      break;

    default :
      this->_j1 = new Joueur(0,0,1,1);
      this->_j2 = new Joueur(0,15,1,1);
      std::cout << "pas fini" << '\n';
      break;
  }



}
//Fonction private
void Jeu::initEntity(){

  initJoueur();
  //this->ent1.setSize(sf::Vector2f(72.f,72.f)); //.f -> float sans être float
  //this->ent1.setFillColor(sf::Color::Cyan); //On peut direct mettre la couleur c'est pas mal
  //this->ent1.affichage();
}

// Fonctions private
void Jeu::initVariables(){
  this-> _window = nullptr;
  this->_videoMode.height =720 ;
  this->_videoMode.width = 1280;

  this->_couleurFond = sf::Color::White; //blanc

  this->_posEnt = sf::Vector2f(0,0); // On init en haut a gauche
  this-> _vitEnt = 5; // Vitesse

  // initialisation du plateau en fonction de la carte ici 1
  this->_grille.setMapType(2); //modif du type de carte
  this->_grille.initPlateau(); // generation de la carte
  std::cout<<"sortie de initPlateau"<<std::endl;
}
void Jeu::initFenetre(){
  this-> _window = new sf::RenderWindow(this->_videoMode, "Bomberman", sf::Style::Close | sf::Style::Titlebar);
  this->_window->setFramerateLimit(144);


}
//Fonctions Public
//mise à jour du jeu (logique du jeu)
void Jeu::updateEvents(){

  while(this->_window->pollEvent(this->_ev)) {
    switch (this->_ev.type) { //On regarde l'envent en cours

      case sf::Event::Closed: // Si c'est l fermeture on ferme
        this->_window->close();
        break;

      case sf::Event::KeyPressed: //Si c'est une pression clavier, on regarde la quelle
        switch (_ev.key.code){//On verif le code /!\ qu'un touche à la fois pas ouf mais ok pour jeux 2d

          case sf::Keyboard::Escape: // Si espace :
            this->_window->close();
            break;


          // On init les fleches pour déplacer

         case sf::Keyboard::Left:
            this->_j1->setPosX(this->_j1->getEsthetique().getPosition().x - this->_vitEnt);  // Le repère image est déplacer on fait attention à mettre les vitesse dans le bon sens
             break;
         case sf::Keyboard::Right:
            this->_j1->setPosX(this->_j1->getEsthetique().getPosition().x + this->_vitEnt);
            std::cout << "pos in pixel " << this->_j1->getPosX() << "pos in grid : "  << this->_j1->getPosOnGridX() << '\n';
            break;
         case sf::Keyboard::Up:
            this->_j1->setPosY(this->_j1->getEsthetique().getPosition().y -this->_vitEnt);
            break;
          case sf::Keyboard::Down:
            this->_j1->setPosY(this->_j1->getEsthetique().getPosition().y + this->_vitEnt);
            break;


          break;
        }
      break;
    }
  }
}
void Jeu::update(){
  this->updateEvents();
}
//visualisation du jeu (interface)

void Jeu::renderJoueurs(){
  this->_window->draw(this->_j1->getEsthetique()); // On place l'element sur le plateau
  this->_window->draw(this->_j2->getEsthetique()); // On place l'element sur le plateau


}
void Jeu::render(){
  this->_window->clear(this->_couleurFond);//RGB+transparence
  //dessin des objets
  this->_grille.renderPlateau(this-> _window);

  //  renderJoueurs();

  //affichage de la fenetre
  this->_window->display();
}

#include "Jeu.hpp"

//Constructeur
Jeu::Jeu(){
  this->initVariables();
  this->initFenetre();
  this->initEntity();
}

//Accesseurs
bool Jeu::getIsRunning() const{
  return this->_window->isOpen();
}

void Jeu::initJoueur(){
    this->_j1 = new Joueur(0,0,0,0);
    this->_j2 = new Joueur(1080-30,720-31,1,0);
}
//Fonction private
void Jeu::initEntity(){

  initJoueur();
}

// Fonctions private
void Jeu::initVariables(){
  this-> _window = nullptr;
  this->_videoMode.height =720 ;
  this->_videoMode.width = 1280;

  // initialisation du plateau en fonction de la carte ici 1
  this->_grille.setMapType(1); //modif du type de carte
  std::cout<<"sortie de initPlateau"<<std::endl;
}
void Jeu::initFenetre(){
  this-> _window = new sf::RenderWindow(this->_videoMode, "Bomberman", sf::Style::Close | sf::Style::Titlebar);
  this->_window->setFramerateLimit(144);


}

void Jeu::updateBombes(){
  for (Bombe* b : _listeBombes){
    if(b->imBoum() && !b->explose()){
      std::cout << "boum" << '\n';
      b->explose() = 1;

      // ici faire sauter les murs
    }
  }
}








//Fonctions Public
//mise à jour du jeu (logique du jeu)
void Jeu::updateEvents(){
  int nouvelle_pos = 0;
  while(this->_window->pollEvent(this->_ev)) {
    switch (this->_ev.type) { //On regarde l'envent en cours

      case sf::Event::Closed: // Si c'est l fermeture on ferme
        this->_window->close();
        break;

      case sf::Event::KeyPressed: //Si c'est une pression clavier, on regarde la quelle
        switch (_ev.key.code){//On verif le code /!\ qu'un touche à la fois pas ouf mais ok pour jeux 2d

          case sf::Keyboard::Escape: // Si echap :
            this->_window->close();
            break;

          case sf::Keyboard::Space: // Si espace :
            this->_j1->setNbBombes(_j1->getNbBombes()-1);
            _j1->setPosBombe(this->_j1->getPosOnGridX(), this->_j1->getPosOnGridY());

          //on ajoute la bombe dans la liste pour l'affichage
            _listeBombes.push_back( new Bombe(_j1->getTypeBombe()));
            //_j1->getTypeBombe().affichage();
            break;

          // On init les fleches pour déplacer le joueur 1
          case sf::Keyboard::Left: //  <--
            //on verifie que le point est dans une case que l'on peut franchir
            nouvelle_pos = this->_j1->getPosX() - this->_j1->getVit();
            if(estFranchissable(nouvelle_pos, _j1->getPosY()) && estFranchissable(nouvelle_pos, _j1->getPosY()+30))
              this->_j1->setPosX(nouvelle_pos);  // Le repère image est déplacer on fait attention à mettre les vitesse dans le bon sens
            break;
          case sf::Keyboard::Right: //  -->
            nouvelle_pos = this->_j1->getPosX() + this->_j1->getVit() + 30;
            if(estFranchissable(nouvelle_pos, _j1->getPosY())&&estFranchissable(nouvelle_pos, _j1->getPosY()+30))
              this->_j1->setPosX(nouvelle_pos-30);
            break;
          case sf::Keyboard::Up:
            nouvelle_pos = this->_j1->getPosY() - this->_j1->getVit();
            if (estFranchissable(_j1->getPosX(),nouvelle_pos)&&estFranchissable(_j1->getPosX()+30, nouvelle_pos))
              this->_j1->setPosY(nouvelle_pos);
            break;
          case sf::Keyboard::Down:
            nouvelle_pos = this->_j1->getPosY() + this->_j1->getVit() + 30;
            if (estFranchissable(_j1->getPosX(),nouvelle_pos)&&estFranchissable(_j1->getPosX()+30, nouvelle_pos))
              this->_j1->setPosY(nouvelle_pos-30);
            break;


            // On init les touches ZQSD pour déplacer le deuxième joueur
            case sf::Keyboard::Q: //  <--
              //on verifie que le point est dans une case que l'on peut franchir
              nouvelle_pos = this->_j2->getPosX() - this->_j2->getVit();
              if(estFranchissable(nouvelle_pos, _j2->getPosY()) && estFranchissable(nouvelle_pos, _j2->getPosY()+30))
                this->_j2->setPosX(nouvelle_pos);  // Le repère image est déplacer on fait attention à mettre les vitesse dans le bon sens
              break;
            case sf::Keyboard::D: //  -->
              nouvelle_pos = this->_j2->getPosX() + this->_j2->getVit() + 30;
              if(estFranchissable(nouvelle_pos, _j2->getPosY())&&estFranchissable(nouvelle_pos, _j2->getPosY()+30))
                this->_j2->setPosX(nouvelle_pos-30);
              break;
            case sf::Keyboard::Z:
              nouvelle_pos = this->_j2->getPosY() - this->_j2->getVit();
              if (estFranchissable(_j2->getPosX(),nouvelle_pos)&&estFranchissable(_j2->getPosX()+30, nouvelle_pos))
                this->_j2->setPosY(nouvelle_pos);
              break;
            case sf::Keyboard::S:
              nouvelle_pos = this->_j2->getPosY() + this->_j2->getVit() + 30;
              if (nouvelle_pos<720){
                if (estFranchissable(_j2->getPosX(),nouvelle_pos)&&estFranchissable(_j2->getPosX()+30, nouvelle_pos))
                  this->_j2->setPosY(nouvelle_pos-30);
                }
              break;

            default :
              break;
        }
        default :
          break;
    }
  }
}
void Jeu::update(){
  updateEvents();
  updateBombes();
}
//visualisation du jeu (interface)

void Jeu::renderJoueurs(){

  this->_window->draw(this->_j1->getEsthetique()); // On place l'element sur le plateau
  this->_window->draw(this->_j2->getEsthetique()); // On place l'element sur le plateau
}
void Jeu::renderBombes(){
  for ( Bombe* b : _listeBombes){
    if (!b->explose()) this->_window->draw(b->getEsthetique()); // On place l'element sur le plateau
  }
}

void Jeu::render(){
  this->_window->clear(sf::Color::White);
  //dessin des objets
  this->_grille.renderPlateau(this->_window);
  renderJoueurs();
  renderBombes();



  //affichage de la fenetre
  this->_window->display();
}

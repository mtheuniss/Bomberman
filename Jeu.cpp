#include "Jeu.hpp"


//Constructeur
Jeu::Jeu(){
  this->initVariables();
  this->initFenetre();
  this->initEntity();
  // this->initBarreEtatJoueur();
}

Jeu::Jeu(Joueur* j1 , Joueur* j2){
  this->initVariables();
  this->initFenetre();
  this->_j1 = j1;
  this->_j2 = j2;
  this->initBarreEtatJoueur();
}




//Accesseurs
bool Jeu::getIsRunning() const{
  return this->_window->isOpen();
}
//fonction private
void Jeu::initJoueur(){
    this->_j1 = new Joueur(0,0,0,0);
    this->_j2 = new Joueur(1080-72,720-72,1,0);
}

//fonction private
void Jeu::initBarreEtatJoueur(){
  //initialisation du rectangle
  //la taille :
  this->_barreEtatJoueur.setSize(sf::Vector2f(200.f,720.f));
  //la position
  this->_barreEtatJoueur.setPosition(sf::Vector2f(1080,0));
  //la texture
  this->_imageBarreEtat.loadFromFile("Images/affichage_info_jeu.png");
  this->_barreEtatJoueur.setTexture(&(this->_imageBarreEtat));
}

//Fonction private

void Jeu::initEntity(){
  initJoueur();
  initBarreEtatJoueur();
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

//Création d'un powerUp qui est mis dans la liste
//tirage aléatoire du type de powerUp
void Jeu::nouveauPowerUp(std::list<sf::Vector2i> liste){
  //on parcours la liste des murs cassés et on met des powerup
  //création de powerup grace à une fonction aléatoire
  int type = ((int) rand()%(3)) + 1;
  for (sf::Vector2i coord : liste){
    switch (type) {
      case 1:
        _listePowerUp.push_back( new PowerUpViePlus(coord));
        break;
      case 2:
        _listePowerUp.push_back( new PowerUpBombePlus(coord));
        break;
      case 3: //pas de chance, pas de powerup
        break;
    }
  }
}

void Jeu::updateBombes(){
  //Note : pour supprimer d'une liste, il nous faut un itérateur
  //for (Bombe* b : _listeBombes){
  for (std::list<Bombe*>::iterator b = _listeBombes.begin(); b!=_listeBombes.end(); ++b){
    if((*b)->imBoum() && !(*b)->explose()){
      std::cout << "boum" << '\n';
      (*b)->explose() = 1;

      // ici faire sauter les murs
      //creation de la liste qui contient les cases de la grille touchées par l'explosion
      std::list<sf::Vector2i> liste;
      //on appelle la fonction qui met les cases dans la liste
      (*b)->degatsBombe(liste);//passage de la liste par référence
      //on regarde aussi si la bombe a explosé sur un des joueurs (= mise à jour du nb de vies)
      this->_j1->estTouche(liste);
      this->_j2->estTouche(liste);
      // on update la grille (destruction des murs cassables)
      _grille.updateGrille(liste);
      // A la sortie de updateGrille, il ne reste plus que les coordonées des murs cassés
      // on s'en sert pour la création des powerups
      nouveauPowerUp(liste);
      // verification de la liste renvoyée
      std::cout << "debut de la liste après modif" << '\n';
      for (sf::Vector2i b : liste){
        std::cout << "["<<b.x<< " ; "<< b.y<<"]" << '\n';
      }
      std::cout << "fin de la liste" << '\n';
      //création des powerups ICI
      //on vide la liste
      liste.clear();
      //la bombe a explosé, elle ne sert plus à rien alors on la supprime des objets à afficher
      delete (*b);
      _listeBombes.erase(b);
      b--;//on décrémente l'itérateur (segfault sinon)
      std::cout << "supp de b" << '\n';
    }
  }
}



//Fonctions Public
//mise à jour du jeu (logique du jeu)
void Jeu::updateEvents(){
  int nouvelle_pos = 0;
  Joueur* joueur = nullptr;
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

          case (sf::Keyboard::Space): case (sf::Keyboard::A): // Si espace :
            if (_ev.key.code==sf::Keyboard::A){
              joueur = _j2;}
            else {
              joueur = _j1;}
            if (joueur->getNbBombes()>0){
              joueur->setNbBombes(joueur->getNbBombes()-1);
              joueur->setPosBombe(joueur->getPosOnGridX(), joueur->getPosOnGridY());
              _listeBombes.push_back( new Bombe(joueur->getTypeBombe()));
            }

          //on ajoute la bombe dans la liste pour l'affichage
            //_j1->getTypeBombe().affichage();
            break;

          // On init les fleches pour déplacer le joueur 1
          case sf::Keyboard::Left: //  <--
            //on verifie que le point est dans une case que l'on peut franchir
            this->_j1->setSensMarche(1);
            nouvelle_pos = this->_j1->getPosX() - this->_j1->getVit();
            if(estFranchissable(nouvelle_pos, _j1->getPosY()) && estFranchissable(nouvelle_pos, _j1->getPosY()+30))
              this->_j1->setPosX(nouvelle_pos);  // Le repère image est déplacer on fait attention à mettre les vitesse dans le bon sens
            break;
          case sf::Keyboard::Right: //  -->
            this->_j1->setSensMarche(2);
            nouvelle_pos = this->_j1->getPosX() + this->_j1->getVit() + 30;
            if(estFranchissable(nouvelle_pos, _j1->getPosY())&&estFranchissable(nouvelle_pos, _j1->getPosY()+30))
              this->_j1->setPosX(nouvelle_pos-30);
            break;
          case sf::Keyboard::Up:
            this->_j1->setSensMarche(3);
            nouvelle_pos = this->_j1->getPosY() - this->_j1->getVit();
            if (estFranchissable(_j1->getPosX(),nouvelle_pos)&&estFranchissable(_j1->getPosX()+30, nouvelle_pos))
              this->_j1->setPosY(nouvelle_pos);
            break;
          case sf::Keyboard::Down:
            this->_j1->setSensMarche(0);
            nouvelle_pos = this->_j1->getPosY() + this->_j1->getVit() + 30;
            if (estFranchissable(_j1->getPosX(),nouvelle_pos)&&estFranchissable(_j1->getPosX()+30, nouvelle_pos))
              this->_j1->setPosY(nouvelle_pos-30);
            break;


            // On init les touches ZQSD pour déplacer le deuxième joueur
            case sf::Keyboard::Q: //  <--
              this->_j2->setSensMarche(1);
              nouvelle_pos = this->_j2->getPosX() - this->_j2->getVit();
              if(estFranchissable(nouvelle_pos, _j2->getPosY()) && estFranchissable(nouvelle_pos, _j2->getPosY()+30))
                this->_j2->setPosX(nouvelle_pos);  // Le repère image est déplacer on fait attention à mettre les vitesse dans le bon sens
              break;
            case sf::Keyboard::D: //  -->
              this->_j2->setSensMarche(2);
              nouvelle_pos = this->_j2->getPosX() + this->_j2->getVit();
              if(estFranchissable(nouvelle_pos, _j2->getPosY())&&estFranchissable(nouvelle_pos, _j2->getPosY()+30))
                this->_j2->setPosX(nouvelle_pos);
              break;
            case sf::Keyboard::Z:
              this->_j2->setSensMarche(3);
              nouvelle_pos = this->_j2->getPosY() - this->_j2->getVit();
              if (estFranchissable(_j2->getPosX(),nouvelle_pos)&&estFranchissable(_j2->getPosX()+30, nouvelle_pos))
                this->_j2->setPosY(nouvelle_pos);
              break;
            case sf::Keyboard::S:
              this->_j2->setSensMarche(0);
              nouvelle_pos = this->_j2->getPosY() + this->_j2->getVit() + 30;
              if (estFranchissable(_j2->getPosX(),nouvelle_pos)&&estFranchissable(_j2->getPosX()+30, nouvelle_pos))
                this->_j2->setPosY(nouvelle_pos-30);
              break;

            default :
              break;
        }
        default :
          break;
    }
  }
}

void Jeu::updatePowerUp(){

  for (std::list<PowerUp*>::iterator p = _listePowerUp.begin(); p!=_listePowerUp.end(); ++p){
    if ((*p)->powerUpAttrape(this->_j1) || (*p)->powerUpAttrape(this->_j2)){
      _listePowerUp.erase(p);
      delete (*p);
      p--;//on décrémente l'itérateur (segfault sinon)
    }
  }



}

void Jeu::update(){
  //mise à jour si le partie n'est pas finie
  if ((_j1->nbVies()!=0) && (_j2->nbVies()!=0 )){
    updateEvents();
    updateBombes();
    updatePowerUp();
  }
  //si la partie est finie, on peut seulement fermer la fenetre(+extension rejouer?)
  else{
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
            default :
              break;
            }
        default :
          break;
        }
      }
  }
}
//visualisation du jeu (interface)

void Jeu::renderJoueurs(){
  this->_j1->getAnimation()->update(this->_j1->getSensMarche(),this->tmpIncrement);
  this->_j1->getEsthetique()->setTextureRect(this->_j1->getAnimation()->_RectSelect  );
  this->_window->draw(*(this->_j1->getEsthetique())); // On place l'element sur le plateau

  this->_j2->getAnimation()->update(this->_j2->getSensMarche(),this->tmpIncrement);
  this->_j2->getEsthetique()->setTextureRect(this->_j2->getAnimation()->_RectSelect  );
  this->_window->draw(*(this->_j2->getEsthetique())); // On place l'element sur le plateau
}


void Jeu::renderBombes(){
  for ( Bombe* b : _listeBombes){
    if (!b->explose()){
      b->getAnimation()->update(0,this->tmpIncrement);
      b->getEsthetique()->setTextureRect(b->getAnimation()->_RectSelect  );

      this->_window->draw(*b->getEsthetique()); // On place l'element sur le plateau
    }
  }
}

void Jeu::renderPowerUp(){
  for ( PowerUp* b : _listePowerUp){
    this->_window->draw(*b->getEsthetique()); // On place l'element sur le plateau
  }
}

void Jeu::renderBarreEtat(){
  this->_window->draw(_barreEtatJoueur);
  //on écrit les nb de vies et nb de bombes
  sf::Font font;
  if (!font.loadFromFile("Polices/FogtwoNo5.ttf"))
  {
    std::cerr << "la police ne se charge pas" << std::endl;
  }
  sf::Text VieJ1;
  sf::Text VieJ2;
  sf::Text BombeJ1;
  sf::Text BombeJ2;
  // choix de la police à utiliser
  VieJ1.setFont(font);
  VieJ2.setFont(font);
  BombeJ1.setFont(font);
  BombeJ2.setFont(font);
  // choix de la chaîne de caractères à afficher
  VieJ1.setString(std::to_string(_j1->nbVies()));
  BombeJ1.setString(std::to_string(_j1->getNbBombes()));
  VieJ2.setString(std::to_string(_j2->nbVies()));
  BombeJ2.setString(std::to_string(_j2->getNbBombes()));
  // choix de la taille des caractères
  VieJ1.setCharacterSize(30); // exprimée en pixels, pas en points !
  BombeJ1.setCharacterSize(30);
  VieJ2.setCharacterSize(30); // exprimée en pixels, pas en points !
  BombeJ2.setCharacterSize(30);
  // choix de la couleur du texte
  VieJ1.setColor(sf::Color::Yellow);
  BombeJ1.setColor(sf::Color::Yellow);
  VieJ2.setColor(sf::Color::Yellow);
  BombeJ2.setColor(sf::Color::Yellow);
  // position du texte
  VieJ1.setPosition(sf::Vector2f(1080+102,225));
  BombeJ1.setPosition(sf::Vector2f(1080+102,300));
  VieJ2.setPosition(sf::Vector2f(1080+102,400));
  BombeJ2.setPosition(sf::Vector2f(1080+102,450));
  //affichage
  this->_window->draw(VieJ1);
  this->_window->draw(BombeJ1);
  this->_window->draw(VieJ2);
  this->_window->draw(BombeJ2);
}

//affichage du gagnant
void Jeu::renderFinJeu(){
  //texte de résultat
  sf::Font font;
  if (!font.loadFromFile("Polices/FogtwoNo5.ttf"))
  {
    std::cerr << "la police ne se charge pas" << std::endl;
  }
  sf::Text resultat;
  // choix de la police à utiliser
  resultat.setFont(font);
  // choix de la taille des caractères
  resultat.setCharacterSize(100);
  // choix de la couleur du texte
  resultat.setColor(sf::Color::Yellow);
  // position du texte
  resultat.setPosition(sf::Vector2f(340,60));
  //texte à écrire
  if (_j1->nbVies()==0)
    resultat.setString("Victoire! \nBravo Joueur 2");
  else
    resultat.setString("Victoire! \nBravo Joueur 1");
  //affichage
  this->_window->draw(resultat);
}

void Jeu::render(){
  //affichage change si un joueur à perdu
  //Si la partie n'est pas finie
  if (_j1->nbVies()!=0 && _j2->nbVies()!=0 ){
    this->tmpIncrement = clock.restart().asSeconds();
    this->_window->clear(sf::Color::White);
    //dessin des objets
    this->_grille.renderPlateau(this->_window);
    renderJoueurs();
    renderBombes();
    renderPowerUp();
    renderBarreEtat();
  }
  else{
    //dessin des objets
    this->_grille.renderPlateau(this->_window);
    renderJoueurs();
    renderBarreEtat();
    //on affiche à l'écran le joueur qui a gagné
    renderFinJeu();
  }

  //affichage de la fenetre
  this->_window->display();
}

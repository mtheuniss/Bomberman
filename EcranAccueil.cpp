#include "EcranAccueil.hpp"

EcranAccueil::EcranAccueil(){
  //initialisation des numéros de personnage : 0=pas de personnage sélectionné
  this->_nperso1 = 0;
  this->_nperso2 = 0;
  //initialisation de la fenetre
  this-> _window = nullptr;
  this->_videoMode.height =720 ;
  this->_videoMode.width = 1280;
  this-> _window = new sf::RenderWindow(this->_videoMode, "Bienvenue dans Bomberman", sf::Style::Close | sf::Style::Titlebar);
  //initialisation des boutons
  initbouton();
}

void EcranAccueil::initbouton(){
  this->_boutonperson1.setSize(sf::Vector2f(250.f,360.f));
  this->_boutonperson1.setPosition(sf::Vector2f(56,96));
  this->_boutonperson1.setOutlineThickness(3);
  this->_boutonperson1.setOutlineColor(sf::Color(0, 0, 0));
  //ajout de la texture
  if (!this->_textureB1.loadFromFile("Images/person1_cochon.jpg"))
  {
    std::cout<<"erreur lors de l'ouverture de l'image"<<std::endl;
  }
  this->_textureB1.setSmooth(true);//lissage de l'image
  this->_boutonperson1.setTexture(&this->_textureB1);

  this->_boutonperson2.setSize(sf::Vector2f(250.f,360.f));
  this->_boutonperson2.setPosition(sf::Vector2f(56*2+250, 96));
  this->_boutonperson2.setOutlineThickness(3);
  this->_boutonperson2.setOutlineColor(sf::Color(0, 0, 0));
  //ajout de la texture
  if (!this->_textureB2.loadFromFile("Images/person2_abeille.jpg"))
  {
    std::cout<<"erreur lors de l'ouverture de l'image"<<std::endl;
  }
  this->_textureB2.setSmooth(true);//lissage de l'image
  this->_boutonperson2.setTexture(&this->_textureB2);

  this->_boutonperson3.setSize(sf::Vector2f(250.f,360.f));
  this->_boutonperson3.setPosition(sf::Vector2f(56*3+250*2, 96));
  this->_boutonperson3.setOutlineThickness(3);
  this->_boutonperson3.setOutlineColor(sf::Color(0, 0, 0));
  //ajout de la texture
  if (!this->_textureB3.loadFromFile("Images/person3_dinosaure.jpg"))
  {
    std::cout<<"erreur lors de l'ouverture de l'image"<<std::endl;
  }
  this->_textureB3.setSmooth(true);//lissage de l'image
  this->_boutonperson3.setTexture(&this->_textureB3);

  this->_boutonperson4.setSize(sf::Vector2f(250.f,360.f));
  this->_boutonperson4.setPosition(sf::Vector2f(56*4+250*3, 96));
  this->_boutonperson4.setOutlineThickness(3);
  this->_boutonperson4.setOutlineColor(sf::Color(0, 0, 0));
  //ajout de la texture
  if (!this->_textureB4.loadFromFile("Images/person4_coq.jpg"))
  {
    std::cout<<"erreur lors de l'ouverture de l'image"<<std::endl;
  }
  this->_textureB4.setSmooth(true);//lissage de l'image
  this->_boutonperson4.setTexture(&this->_textureB4);

  //bouton play
  this->_jouer.setSize(sf::Vector2f(200.f,200.f));
  this->_jouer.setPosition(sf::Vector2f(1280/2-100, 520));
  this->_jouer.setFillColor(sf::Color(255, 255, 255,255));
  //ajout de la texture
  if (!this->_textureJouer.loadFromFile("Images/PLAY.png"))
  {
    std::cout<<"erreur lors de l'ouverture de l'image"<<std::endl;
  }
  this->_textureJouer.setSmooth(true);//lissage de l'image
  this->_jouer.setTexture(&this->_textureJouer);
}

/* Fonction de mise à jour appellé dans la boucle du main
  on met à jour ici les événements de l'interface graphique*/

void EcranAccueil::update(){
  //coordonnées de la souris
  int x0;
  int y0;
  //gestion des événements
  while(this->_window->pollEvent(this->_ev)) {
    switch (this->_ev.type) { //On regarde l'envent en cours

      case sf::Event::Closed: // croix en haut ou echap on ferme le jeu en entier
        _nperso1 = 0; _nperso2 = 0;
        this->_window->close();
        break;

      case sf::Event::KeyPressed: //Si c'est une pression clavier, on regarde la quelle
        switch (_ev.key.code){//On verif le code /!\ qu'un touche à la fois pas ouf mais ok pour jeux 2d
          case sf::Keyboard::Escape: // Si echap :
            _nperso1 = 0; _nperso2 = 0;
            this->_window->close();
            break;
          default :
            break;
          }
      //gestion des boutons : 5 boutons = selection d'un des 4 personnages et le bouton jouer
      case sf::Event::MouseButtonPressed :
        x0 = _ev.mouseButton.x;
        y0 = _ev.mouseButton.y;
        std::cout<<"["<<x0<<" ; "<<y0<<"]"<<std::endl;
        //à chaque bouton est associée une zone dans la fenetre
        //cliquer dans la zone = cliquer sur le bouton
        //bouton cliqué => mise à jour des perso, désactivé la cliquabilité, griser la  (ajout gris en + de l'image)
        //personnage1 cliqué?
        if (x0>=56 && x0<=306 && y0>=96 && y0<=456){
          std::cout<<"perso 1"<<std::endl;
          if (_nperso1 == 0) _nperso1 = 1;
          else if (_nperso2 == 0 && _nperso1 != 1) _nperso2 = 1;
        }
        //personnage2 cliqué?
        if (x0>=362 && x0<=612 && y0>=96 && y0<=456){
          std::cout<<"perso 2"<<std::endl;
          if (_nperso1 == 0) _nperso1 = 2;
          else if (_nperso2 == 0 && _nperso1 != 2) _nperso2 = 2;
        }
        //personnage3 cliqué?
        if (x0>=668 && x0<=918 && y0>=96 && y0<=456){
          std::cout<<"perso 3"<<std::endl;
          if (_nperso1 == 0) _nperso1 = 3;
          else if (_nperso2 == 0 &&_nperso1 != 3) _nperso2 = 3;
        }
        //personnage4 cliqué?
        if (x0>=974 && x0<=1224 && y0>=96 && y0<=456){
          std::cout<<"perso 4"<<std::endl;
          if (_nperso1 == 0) _nperso1 = 4;
          else if (_nperso2 == 0 && _nperso1 != 4) _nperso2 = 4;
        }
        //play cliqué, si oui, on vérifie que les 2 personnages sont choisis pour lancer le jeu
        if (x0>=540 && x0<=740 && y0>=520 && y0<=720){
          std::cout<<"jouer!!"<<std::endl;
          this->_window->close();
        }
      //gestion des boutons : clic gauche = changer le dernier joueur sélectionné
      //case sf::Mouse::Left :

      default :
        break;
    }
  }
}

void EcranAccueil::render(){
  this->_window->clear(sf::Color::Black);
  //on grise les boutons et contour en fonction des clics
  if (_nperso1 != 0){
    switch (_nperso1) {
      case 1:
        this->_boutonperson1.setFillColor(sf::Color(200, 200, 200,255));
        this->_boutonperson1.setOutlineColor(sf::Color(0, 255, 0));
        break;
      case 2:
        this->_boutonperson2.setFillColor(sf::Color(200, 200, 200,255));
        this->_boutonperson2.setOutlineColor(sf::Color(0, 255, 0));
        break;
      case 3:
        this->_boutonperson3.setFillColor(sf::Color(200, 200, 200,255));
        this->_boutonperson3.setOutlineColor(sf::Color(0, 255, 0));
        break;
      case 4:
        this->_boutonperson4.setFillColor(sf::Color(200, 200, 200,255));
        this->_boutonperson4.setOutlineColor(sf::Color(0, 255, 0));
        break;
      default:
        break;
    }
  }

  if (_nperso2 != 0){
    switch (_nperso2) {
      case 1:
        this->_boutonperson1.setFillColor(sf::Color(200, 200, 200,255));
        this->_boutonperson1.setOutlineColor(sf::Color(255, 0, 0));
        break;
      case 2:
        this->_boutonperson2.setFillColor(sf::Color(200, 200, 200,255));
        this->_boutonperson2.setOutlineColor(sf::Color(255, 0, 0));
        break;
      case 3:
        this->_boutonperson3.setFillColor(sf::Color(200, 200, 200,255));
        this->_boutonperson3.setOutlineColor(sf::Color(255, 0, 0));
        break;
      case 4:
        this->_boutonperson4.setFillColor(sf::Color(200, 200, 200,255));
        this->_boutonperson4.setOutlineColor(sf::Color(255, 0, 0));
        break;
      default:
        break;
    }
  }
  ////on met les boutons dans la fenetre
  this->_window->draw(_boutonperson1);
  this->_window->draw(_boutonperson2);
  this->_window->draw(_boutonperson3);
  this->_window->draw(_boutonperson4);
  this->_window->draw(_jouer);

  //affichage de la fenetre
  this->_window->display();
}

#ifndef POWERUP_HPP
#define POWERUP_HPP

#include "Element.hpp"
#include "Joueur.hpp"
//PowerUP, c'est une interface qui dévire d'Element
//ils doivent être capable de s'afficher ET de modifier les attributs du joueur

class PowerUp : public Element{
  public :
  virtual ~PowerUp(){}

  //méthodes virtuelles à redéfinir
    virtual void affichage() = 0;
    /**
	 * méthode permettant de modifier un attribut d'un joueur => type de powerup est totalement transparant au niveau du reste du code
	 * @param le joueur dont l'un des attributs sera modifié si il a attrappé le powerup
	 * @return vrai si le powerup est attrappé, faux sinon
	 */
    virtual bool powerUpAttrape(Joueur* j) = 0;

};
#endif

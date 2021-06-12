#include "catch.hpp"
#include "Joueur.hpp"

#include "PowerUpBombePlus.hpp"
#include "PowerUpFirePlus.hpp"
#include "PowerUpVitessePlus.hpp"
#include "PowerUpViePlus.hpp"


TEST_CASE( "PowerUpBombePlus", "[PowerUpBombePlus]" ) {

  Joueur j = Joueur(0,0,0,0);

  SECTION( "powerUpAttrape oui" ) {
    PowerUpBombePlus p_up = PowerUpBombePlus(sf::Vector2i(0,0));
    p_up.powerUpAttrape(&j);
    REQUIRE(j.getNbBombes() == 6);
  }

  SECTION( "powerUpAttrape non" ) {
    PowerUpBombePlus p_up = PowerUpBombePlus(sf::Vector2i(1,0));
    p_up.powerUpAttrape(&j);
    REQUIRE_FALSE(j.getNbBombes() == 6);
    REQUIRE(j.getNbBombes() == 5);

  }

}

TEST_CASE( "PowerUpFirePlus", "[PowerUpFirePlus]" ) {

  Joueur j = Joueur(0,0,0,0);


  SECTION( "powerUpAttrape oui" ) {
    PowerUpFirePlus p_up = PowerUpFirePlus(sf::Vector2i(0,0));
    p_up.powerUpAttrape(&j);
    REQUIRE(j.getBombe()->rayon() == 3);
  }

  SECTION( "powerUpAttrape oui" ) {
    PowerUpFirePlus p_up = PowerUpFirePlus(sf::Vector2i(1,0));
    p_up.powerUpAttrape(&j);
    REQUIRE(j.getBombe()->rayon() == 2);
  }

}

TEST_CASE( "PowerUpVitessePlus", "[PowerUpVitessePlus]" ) {

  Joueur j = Joueur(0,0,0,0);


  SECTION( "powerUpAttrape oui" ) {
    PowerUpVitessePlus p_up = PowerUpVitessePlus(sf::Vector2i(0,0));
    p_up.powerUpAttrape(&j);
    REQUIRE(j.getVitesse() == 6);
  }

  SECTION( "powerUpAttrape non" ) {
    PowerUpVitessePlus p_up = PowerUpVitessePlus(sf::Vector2i(1,0));
    p_up.powerUpAttrape(&j);
    REQUIRE_FALSE(j.getVitesse() == 6);
    REQUIRE(j.getVitesse() == 5);

  }

}

TEST_CASE( "PowerUpViePlus", "[PowerUpViePlus]" ) {

  Joueur j = Joueur(0,0,0,0);
  
  SECTION( "powerUpAttrape oui" ) {
    PowerUpViePlus p_up = PowerUpViePlus(sf::Vector2i(0,0));
    p_up.powerUpAttrape(&j);
    REQUIRE(j.nbVies() == 4);
  }

  SECTION( "powerUpAttrape non" ) {
    PowerUpViePlus p_up = PowerUpViePlus(sf::Vector2i(1,0));
    p_up.powerUpAttrape(&j);
    REQUIRE_FALSE(j.nbVies() == 4);
    REQUIRE(j.nbVies() == 3);

  }

}

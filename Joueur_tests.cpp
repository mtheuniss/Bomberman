#define CATCH_CONFIG_MAIN // Must only appear in ONE test file
#include "catch.hpp"
#include "Joueur.hpp"



TEST_CASE( "Positionnement Joueur", "[Joueur]" ) {

  Joueur j = Joueur(0,0,0,0);

  SECTION( "setPosOnGridX" ) {
    j.setPosOnGridX(144);
    REQUIRE(j.getPosOnGridX() == 2);
  }

  SECTION( "setPosX" ) {

      j.setPosX(1152);
      REQUIRE_FALSE(j.getPosX() == 16);
      REQUIRE(j.getPosOnGridX() == 0);

      j.setPosX(-1);
      REQUIRE_FALSE(j.getPosX() == -1);
      REQUIRE(j.getPosOnGridX() == 0);

      j.setPosX(144);
      REQUIRE(j.getPosX() == 144);
      REQUIRE(j.getPosOnGridX() == 2);

  }

}

TEST_CASE( "Vie Joueur", "[Joueur]" ) {

  Joueur j = Joueur(0,0,0,0);
  std::list<sf::Vector2i> l;


  SECTION( "estTouche oui " ) {
    sf::Vector2i coord = sf::Vector2i(0,0);
    l.push_back(coord);
    j.estTouche(l);
    REQUIRE(j.nbVies() == 2);
  }
  SECTION( "estTouche" ) {
    sf::Vector2i coord = sf::Vector2i(1,0);
    l.push_back(coord);
    j.estTouche(l);
    REQUIRE_FALSE(j.nbVies() == 2);
  }
}

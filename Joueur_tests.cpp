#define CATCH_CONFIG_MAIN // Must only appear in ONE test file
#include "catch.hpp"
#include "Joueur.hpp"



TEST_CASE( "Positionnement Joueur", "[Joueur]" ) {

  Joueur j = Joueur(0,0,0,0);

  SECTION( "setPosOnGridX" ) {

      j.setPosOnGridX(1);

      REQUIRE(j.getPosX() == 72);
      REQUIRE(j.getPosOnGridX() == 1);  // équivalent REQUIRE(!(p1 == p2)); -- voir https://github.com/catchorg/Catch2/blob/master/docs/assertions.md#natural-expressions
  }
/*
  SECTION( "operator!=" ) {
      REQUIRE_FALSE(p1 != p1bis);
      REQUIRE(p1 != p2);  // équivalent REQUIRE(!(p1 == p2));
  }

  SECTION( "distance" ) {
      // Comparaisons de float avec tolérance en utilisant Approx
      // Voir https://github.com/catchorg/Catch2/blob/master/docs/assertions.md#floating-point-comparisons pour plus d'infos et/ou plus de contrôle sur la tolérance
      REQUIRE(p1.dist(p2) == Approx(std::sqrt(5.)));
      REQUIRE(p1.dist(p1bis) == Approx(std::sqrt(0.)));
  }
*/
}

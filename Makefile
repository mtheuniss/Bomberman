CC=g++
CFLAGS=-W -Wall -g
LDFLAGS=
EXEC=main

all: $(EXEC)

main: EcranAccueil.o Bombe.o PowerUpBombePlus.o PowerUpFirePlus.o PowerUpViePlus.o PowerUpVitessePlus.o MurVoid.o MurCassable.o MurDur.o Plateau.o Animation.o Jeu.o Joueur.o main.o
		$(CC) -o $@ $^ $(LDFLAGS) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

EcranAccueil.o : EcranAccueil.cpp EcranAccueil.hpp
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

Jeu.o: Jeu.cpp Jeu.hpp Element.hpp Mur.hpp PowerUpViePlus.hpp PowerUpVitessePlus.hpp PowerUpBombePlus.hpp
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

Joueur.o: Joueur.cpp Joueur.hpp  Element.hpp Animation.o
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

Plateau.o: Plateau.cpp Plateau.hpp Element.hpp Mur.hpp MurCassable.o
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

MurCassable.o: MurCassable.cpp MurCassable.hpp Element.hpp Mur.hpp
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

MurDur.o: MurDur.cpp MurDur.hpp Element.hpp Mur.hpp
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

MurVoid.o: MurVoid.cpp MurVoid.hpp Element.hpp Mur.hpp
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

PowerUpViePlus.o: PowerUpViePlus.cpp PowerUpViePlus.hpp PowerUp.hpp Element.hpp Joueur.hpp
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

PowerUpBombePlus.o: PowerUpBombePlus.cpp PowerUpBombePlus.hpp PowerUp.hpp Element.hpp Joueur.hpp
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

PowerUpFirePlus.o: PowerUpFirePlus.cpp PowerUpFirePlus.hpp PowerUp.hpp Element.hpp Joueur.hpp
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

PowerUpVitessePlus.o: PowerUpVitessePlus.cpp PowerUpVitessePlus.hpp PowerUp.hpp Element.hpp Joueur.hpp
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

Bombe.o: Bombe.cpp Bombe.hpp Element.hpp
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

Animation.o: Animation.cpp Animation.hpp
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp Jeu.hpp
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio


# Tests :

test : tests_catch  #commande make ..

tests_catch: Joueur_tests.o Joueur.o PowerUp_tests.o Animation.o Bombe.o PowerUpBombePlus.o PowerUpFirePlus.o PowerUpVitessePlus.o PowerUpViePlus.o
	$(CC) -o $@ $^ $(LDFLAGS) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

Joueur_tests.o: Joueur_tests.cpp Joueur.hpp catch.hpp
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

PowerUp_tests.o: PowerUp_test.cpp Joueur.hpp PowerUpBombePlus.hpp PowerUpFirePlus.hpp PowerUpVitessePlus.hpp PowerUpViePlus.hpp Element.hpp Bombe.hpp catch.hpp
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system



clean:
	rm -rf *.o $(EXEC) tests_catch

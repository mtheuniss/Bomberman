CC=g++
CFLAGS=-W -Wall -g
LDFLAGS=
EXEC=main

all: $(EXEC)

main: EcranAccueil.o Bombe.o PowerUp.o MurVoid.o MurCassable.o MurDur.o Plateau.o Animation.o Jeu.o Joueur.o main.o
		$(CC) -o $@ $^ $(LDFLAGS) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

EcranAccueil.o : EcranAccueil.cpp EcranAccueil.hpp
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

Jeu.o: Jeu.cpp Jeu.hpp Element.hpp Mur.hpp
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

PowerUp.o: PowerUp.cpp PowerUp.hpp Element.hpp
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

Bombe.o: Bombe.cpp Bombe.hpp Element.hpp
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

Animation.o: Animation.cpp Animation.hpp
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp Jeu.hpp
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

clean:
	rm -rf *.o $(EXEC)

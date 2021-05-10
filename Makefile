CC=g++
CFLAGS=-W -Wall
LDFLAGS=
EXEC=main

all: $(EXEC)

main: MurVoid.o MurCassable.o MurDur.o Plateau.o Jeu.o  main.o
	$(CC) -o $@ $^ $(LDFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

Jeu.o: Jeu.cpp Jeu.hpp Element.hpp Mur.hpp
	$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

Plateau.o: Plateau.cpp Plateau.hpp Element.hpp Mur.hpp
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

MurCassable.o: MurCassable.cpp MurCassable.hpp Element.hpp Mur.hpp
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

MurDur.o: MurDur.cpp MurDur.hpp Element.hpp Mur.hpp
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

MurVoid.o: MurVoid.cpp MurVoid.hpp Element.hpp Mur.hpp
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp Jeu.hpp
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -rf *.o $(EXEC)

CC=g++
CFLAGS=-W -Wall
LDFLAGS=
EXEC=main

all: $(EXEC)

main: Plateau.o Jeu.o  main.o
	$(CC) -o $@ $^ $(LDFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

Jeu.o: Jeu.cpp Jeu.hpp
	$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

Plateau.o: Plateau.cpp Plateau.hpp
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system
main.o: main.cpp Jeu.hpp
		$(CC) -o $@ -c $< $(CFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -rf *.o $(EXEC)

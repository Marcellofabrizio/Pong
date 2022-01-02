all: pong_game

pong_game: main.o ui.o pong.o
	gcc -o pong_game main.o ui.o pong.o `sdl2-config --cflags --libs`

main.o: main.c ui.h pong.h
	gcc -o main.o main.c -c -W -Wall -ansi -pedantic `sdl2-config --cflags --libs`

ui.o: ui.c ui.h pong.h
	gcc -o ui.o ui.c -c -W -Wall -ansi -pedantic `sdl2-config --cflags --libs`

clean:
	rm -rf *.o *~ pong_game

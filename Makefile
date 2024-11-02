$CFLAGS = -Wall -pedantic -ansi -g

wireworld: wireworld.o simulation.o newSleep.o color.o terminal.o
	gcc wireworld.o simulation.o newSleep.o color.o terminal.o -o wireworld

wireworld.o: wireworld.c newSleep.h header.h color.h terminal.h
	gcc -c wireworld.c $(CFLAGS)

simulation.o: simulation.c header.h color.h
	gcc -c simulation.c $(CFLAGS)

newSleep.o: newSleep.c
	gcc -c newSleep.c

color.o: color.c
	gcc -c color.c

terminal.o: terminal.c
	gcc -c terminal.c

clean:
	rm -f wireworld wireworld.o simulation.o newSleep.o color.o terminal.o

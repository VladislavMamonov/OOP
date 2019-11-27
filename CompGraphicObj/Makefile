all: object

object: main.o Menu.o Game.o Animations.o
	g++ -Wall -g main.o Menu.o Game.o Animations.o -o object -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -Wall -c -g main.cpp -o main.o

Menu.o: Menu.cpp
	g++ -Wall -c -g Menu.cpp -o Menu.o

Game.o: Game.cpp
	g++ -Wall -c -g Game.cpp -o Game.o

Animations.o: Animations.cpp
	g++ -Wall -c -g Animations.cpp -o Animations.o

clean:
	rm -rf *.o object

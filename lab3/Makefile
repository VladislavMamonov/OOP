all: lab3

lab3: main.o menu.o
	g++ -Wall -v -g main.o menu.o -o lab3

main.o: main.cpp
	g++ -Wall -v -c -g main.cpp -o main.o

menu.o: menu.cpp
	g++ -Wall -v -c -g menu.cpp -o menu.o


.PHONY: clean
clean:
		rm -rf *.o lab3

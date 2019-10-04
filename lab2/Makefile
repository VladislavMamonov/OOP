all: lab2

lab2: main.o LinkedList.o add.o
	g++ -Wall -g main.o LinkedList.o add.o -o lab2

main.o: main.cpp
	g++ -Wall -c -g main.cpp -o main.o

LinkedList.o: LinkedList.cpp
	g++ -Wall -c -g LinkedList.cpp -o LinkedList.o

add.o: add.cpp
	g++ -Wall -c -g add.cpp -o add.o

.PHONY: clean
clean:
		rm -rf *.o lab2

all: lab2

lab2: main.o LinkedList.o
	g++ -Wall -g main.o LinkedList.o -o lab2

main.o: main.cpp
	g++ -Wall -c -g main.cpp -o main.o

LinkedList.o: LinkedList.cpp
	g++ -Wall -c -g LinkedList.cpp -o LinkedList.o

.PHONY: clean
clean:
		rm -rf *.o lab2

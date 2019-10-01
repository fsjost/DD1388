CC = g++
FLAGS = -std=c++11 -Wall -pedantic

all:
	$(CC) $(FLAGS) -c bintree.cpp -o bintree.o
	$(CC) $(FLAGS) testbalance.cpp bintree.cpp -o testbalance.o

bintree:
	$(CC) $(FLAGS) bintree.cpp -o bintree.o
	./bintree.o

balance:
	$(CC) $(FLAGS) testbalance2.cpp bintree.cpp -o testbalance.o
	./testbalance.o

bintest:
	cxxtestgen --error-printer -o generatedTest.cpp bintest.h
	$(CC) $(FLAGS) -c -o bintree.o bintree.cpp
	$(CC) $(FLAGS) -o runner.out generatedTest.cpp
	./runner.out

memtest:
	g++ -std=c++11 bintree.cpp testbalance2.cpp -o memtest.out
	valgrind --tool=memcheck --leak-check=yes ./memtest.out

CC = g++
FLAGS = -std=c++11 -g -Wall -pedantic

all:
	$(CC) $(FLAGS) matrix.cpp -o matrix.o
	./matrix.o

test:
	cxxtestgen --error-printer -o generatedTest.cpp cxx_test.cpp
	g++ -std=c++11 -c -o matrix.o matrix.cpp
	g++ -std=c++11 -o runner.out generatedTest.cpp
	./runner.out

valgrind:
		$(CC) $(FLAGS) matrix.cpp -o matrix.o
		valgrind --tool=memcheck --leak-check=full --track-origins=yes ./matrix.o

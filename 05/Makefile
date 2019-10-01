CC = g++
FLAGS = -std=c++11 -g -Wall -pedantic

all:
	$(CC) $(FLAGS) lambdas.cpp -o lambdas.o
	./lambdas.o

test:
	cxxtestgen --error-printer -o generatedTest.cpp cxx_test.cpp
	g++ -std=c++11 -c -o lambdas.o lambdas.cpp
	g++ -std=c++11 -o runner.out generatedTest.cpp
	./runner.out

valgrind:
		$(CC) $(FLAGS) lambdas.cpp -o lambdas.o
		valgrind --tool=memcheck --leak-check=full --track-origins=yes ./lambdas.o

orwell:
	$(CC) $(FLAGS) orwell.cpp -o orwell.o -pthread
	./orwell.o 

testorwell:
	cxxtestgen --error-printer -o generatedTest.cpp cxx_test.cpp
	g++ -std=c++11 -c -o orwell.o orwell.cpp
	g++ -std=c++11 -o runner.out generatedTest.cpp
	./runner.out

valgrindorwell:
	$(CC) $(FLAGS) orwell.cpp -o orwell.o
	valgrind --tool=memcheck --leak-check=full --track-origins=yes ./orwell.o

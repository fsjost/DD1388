CC = g++
FLAGS = -std=c++11 -g -Wall -pedantic

all:
	$(CC) $(FLAGS) knapsack.cpp -o knapsack.o
	./knapsack.o

test:
	cxxtestgen --error-printer -o generatedTest.cpp cxx_test.cpp
	g++ -std=c++11 -c -o knapsack.o knapsack.cpp
	g++ -std=c++11 -o runner.out generatedTest.cpp
	./runner.out

valgrind:
		$(CC) $(FLAGS) knapsack.cpp -o knapsack.o
		valgrind --tool=memcheck --leak-check=full --track-origins=yes ./knapsack.o 

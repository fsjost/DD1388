CC = g++
FLAGS = -std=c++11 -g -Wall -pedantic

all:
	$(CC) $(FLAGS) complex2.0.cpp -o complex2.0.o
	./complex2.0.o

test:
	cxxtestgen --error-printer -o generatedTest.cpp Test_Complex.h
	g++ -std=c++11 -c -o complex2.0.o complex2.0.cpp
	g++ -std=c++11 -o runner.out generatedTest.cpp
	./runner.out

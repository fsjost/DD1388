CC    = g++
#CC   = clang++-3.8 -L /usr/lib/gcc/x86_64-linux-gnu/5.4.0 -I /usr/include/x86_64-linux-gnu/c++/5.4.0 -I /usr/include/c++/5.4.0

FLAGS = -std=c++11 -g -Wall -pedantic

main.out: main.cpp hello.o
	 $(CC) $(FLAGS) main.cpp hello.o -o main.out

hello.o: hello.cpp
	$(CC) $(FLAGS) -c hello.cpp

clean:
	rm -f *.o *.out

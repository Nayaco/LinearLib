CXX = g++
FLAG = -g -Wall

main: main.o matrix.o
	$(CXX) $(FLAG) main.o matrix.o -o main

main.o: main.cpp
	$(CXX) $(FLAG) -c main.cpp -o main.o 

matrix.o: matrix.cpp
	$(CXX) $(FLAG) -c matrix.cpp -o matrix.o

clean:
	rm -f matrix.o main.o main
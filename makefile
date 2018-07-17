CXX = g++
CXXFLAG = -g -Wall

main: main.o matrix.o
	$(CXX) $(CXXFLAG) main.o matrix.o -o main

main.o: main.cpp
	$(CXX) $(CXXFLAG) -c main.cpp -o main.o 

matrix.o: matrix.cpp
	$(CXX) $(CXXFLAG) -c matrix.cpp -o matrix.o

clean:
	rm -f matrix.o main.o main

CXX=g++
CXXFLAGS=-Wall -O2
BIN=ultrachess

OBJS=algebra.o board.o boardref.o game.o main.o moves.o pieces.o

algebra.o: algebra.cpp algebra.h
	$(CXX) $(CXXFLAGS) -c algebra.cpp

ultrachess: $(OBJS)
	echo $@

clean:
	rm -f *.o core ultrachess

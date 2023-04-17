CPP=g++
LD=g++

CPPFLAGS=-std=c++14
LDFLAGS=-std=c++14
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio


all: testSFML

testSFML: testSFML.o Window.o Tile.o WalkableTile.o Character.o
	$(LD) $(LDFLAGS) testSFML.o Window.o Tile.o WalkableTile.o Character.o -o testSFML $(LIBS)

testSFML.o : testSFML.cpp Window.hpp Tile.hpp WalkableTile.hpp Character.hpp
	$(CPP) $(CPPFLAGS) -c testSFML.cpp

Window.o : Window.cpp Tile.hpp WalkableTile.hpp Character.hpp
	$(CPP) $(CPPFLAGS) -c Window.cpp

Tile.o : Tile.cpp
	$(CPP) $(CPPFLAGS) -c Tile.cpp

WalkableTile.o : WalkableTile.cpp Tile.hpp Character.hpp
	$(CPP) $(CPPFLAGS) -c WalkableTile.cpp

Character.o : Character.cpp Tile.hpp
	$(CPP) $(CPPFLAGS) -c Character.cpp

clean:
	rm -f *.o testSFML
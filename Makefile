# Makefile for code_analysis() problem
#
# To build:
#   make
#
# To run
#   make run
#
# To clean build:
#   make clean
.PHONY.: all
all: buildMaze

buildMaze: buildMaze.o DisjSets.o maze.o
	g++ buildMaze.o DisjSets.o maze.o -o buildMaze

buildMaze.o: buildMaze.cpp
	g++ -c buildMaze.cpp

DisjSets.o: DisJSets.h DisJSets.cpp
	g++ -c DisJSets.cpp

maze.o: maze.h maze.cpp
	g++ -c maze.cpp

.PHONY.: clean
clean :
	rm -f buildMaze buildMaze.o DisjSets.o maze.o


.PHONY.: run
run: buildMaze
	./buildMaze

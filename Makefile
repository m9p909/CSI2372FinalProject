# CSI2372A Fall 2020 - Final Project Makefile
# Run "make game" to make game.exe
# Run "make test" to make test.exe

# Running 'make' builds the game and test executables.
.PHONY: all 

all: game.exe debug.exe test.exe

# Primary game executable for evaluation
main: game.exe
game: game.exe
game.exe: main.cpp main.h cls/*.cpp util/*.cpp
	g++ -Wall -o game.exe \
		util/*.cpp cls/*.cpp main.cpp

# Game executable with debugging flag 
debug: debug.exe
debug.exe: main.cpp main.h cls/*.cpp util/*.cpp
	g++ -g3 -Wall -o debug.exe \
		util/*.cpp cls/*.cpp main.cpp

# Unit test executable
tests: test.exe
test: test.exe
test.exe: main.h cls/*.cpp util/*.cpp test/*.cpp
	g++ -g3 -Wall -o test.exe \
		util/*.cpp cls/*.cpp test/*.cpp

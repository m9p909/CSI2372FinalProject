# CSI2372A Fall 2020 - Final Project Makefile

# Running 'make' builds the game and test executables.
.PHONY: all 

all: game.exe test.exe

main: game.exe
game: game.exe
# Primary game executable for evaluation
game.exe: main.cpp main.h cls/*.cpp util/*.cpp
	g++ -Wall -o game.exe \
		util/*.cpp cls/*.cpp main.cpp

tests: test.exe
test: test.exe
# Run 'make test.exe' to create the test executable.
test.exe: main.h cls/*.cpp util/*.cpp test/*.cpp
	g++ -Wall -o test.exe \
		util/*.cpp cls/*.cpp test/*.cpp

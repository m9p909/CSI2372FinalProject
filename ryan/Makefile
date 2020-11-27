# CSI2372A Fall 2020 - Final Project Makefile
# Running 'make' builds the game executable.

.PHONY: all

all: game.exe

# Primary game executable for evaluation
game.exe: main.cpp main.h cls/*.cpp util/*.cpp
	g++ -Wall -o game.exe \
		util/*.cpp cls/*.cpp main.cpp

# Run 'make test.exe' to create the test executable.
test.exe: cls/*.cpp util/*.cpp
	g++ -Wall -o test.exe util/*.cpp cls/*.cpp

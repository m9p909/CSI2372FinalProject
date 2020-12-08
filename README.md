# CSI2372 Final Project

**Please read the marking instructions before proceeding.** This C++ program was written in a UNIX environment and may not run correctly on Windows.

![CI](https://github.com/JackClarkeUottawa/CSI2372FinalProject/workflows/CI/badge.svg?branch=master)

Group Members

- Jack Clarke - 3000080674
- Ryan Fleck - 8276723

## Marking Instructions

This program was built with g++, gcc version `8.3.0`.

Run `make` or `make game` to compile the game executable to `game.exe`.

Run `make all` or `make test` to compile the unit tests to `test.exe`.

```sh
# Building & running on GNU/Linux, WSL, or OSX:
# To run the game
make game && ./game.exe

# To run the unit tests (Doctest)
make test && ./test.exe
```

## Implementation Information

Tested with the [Doctest](https://github.com/onqtam/doctest) unit testing library.

Excluding the Doctest header, the solution is 1150 lines of C++ as of commit [9d59d0](https://github.com/JackClarkeUottawa/CSI2372FinalProject/commit/9d59d0a537d88d600cc1d1723548c4da2624b07d)

```
PS C:\Users\Ryan Fleck\Documents\CSI2372FinalProject> cloc .\ryan\ --exclude-list-file=..\exclude.txt
      23 text files.
      23 unique files.
       5 files ignored.

github.com/AlDanial/cloc v 1.82  T=0.50 s (44.0 files/s, 3182.0 lines/s)
-------------------------------------------------------------------------------
Language                     files          blank        comment           code
-------------------------------------------------------------------------------
C++                             20            182            152            904
C/C++ Header                     1             39             48            246
make                             1              4              4             12
-------------------------------------------------------------------------------
SUM:                            22            225            204           1162
-------------------------------------------------------------------------------
```

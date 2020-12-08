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

Our solution (excluding the Doctest library) is ~2000 lines of documented C++.

```
PS C:\Users\Ryan Fleck\Documents> cloc .\CSI2372FinalProject\ --exclude-list-file=.\exclude.txt
      32 text files.
      32 unique files.
       9 files ignored.

github.com/AlDanial/cloc v 1.82  T=0.50 s (58.0 files/s, 5728.0 lines/s)
-------------------------------------------------------------------------------
Language                     files          blank        comment           code
-------------------------------------------------------------------------------
C++                             25            342            278           1672
C/C++ Header                     1             58             60            341
Markdown                         1             15              0             36
YAML                             1              8              0             26
make                             1              5              7             16
-------------------------------------------------------------------------------
SUM:                            29            428            345           2091
-------------------------------------------------------------------------------
```

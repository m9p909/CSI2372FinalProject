/**
 * source file: main.h
 * ====================================
 * This primary header file is to be included in all other
 * source files within the project, and contains the definitions
 * for all classes that must be called or used in main.
 * 
 * CSI2372A - Fall 2020 - Final Project
 * ====================================
 * Collaborators:
 *  - Ryan Fleck   8272723
 *  - Jack Clarke  0000000 
 */

// Ensure this header is only defined once.
#ifndef MAINPROG
#define MAINPROG

// Include libraries for all C++ files.
#include <cstdlib>
#include <iostream>
#include <limits>

// Not used yet but may be useful:
#include <random>
#include <algorithm>

// Always use the standard namespace.
using namespace std;

/**
 * Class Definitions
 * =================
 * Classes corresponding to the game components
 * provided in the program description.
 */
class Card
{
public:
  // Pure Virtual Functions:
  virtual int getCardsPerCoin(int coints) = 0;
  virtual string getName() = 0;
  virtual void print(ostream &out) = 0;
};

class Deck;
class DiscardPile;
class Chain;
class Table;
class TradeArea;
class Coins;
class Hand;
class Players;

/**
 * Class Implementation Definitions
 * =================
 * Classes corresponding to the game components
 * provided in the program description.
 */
class Blue : public Card
{
public:
  int getCardsPerCoin(int coints);
  string getName();
  void print(ostream &out);
};

class Chili : public Card
{
public:
  int getCardsPerCoin(int coints);
  string getName();
  void print(ostream &out);
};

class Stink : public Card
{
public:
  int getCardsPerCoin(int coints);
  string getName();
  void print(ostream &out);
};

class Green : public Card
{
public:
  int getCardsPerCoin(int coints);
  string getName();
  void print(ostream &out);
};

class Soy : public Card
{
public:
  int getCardsPerCoin(int coints);
  string getName();
  void print(ostream &out);
};

class Black : public Card
{
public:
  int getCardsPerCoin(int coints);
  string getName();
  void print(ostream &out);
};

class Red : public Card
{
public:
  int getCardsPerCoin(int coints);
  string getName();
  void print(ostream &out);
};

class Garden : public Card
{
public:
  int getCardsPerCoin(int coints);
  string getName();
  void print(ostream &out);
};

/**
 * Function Definitions
 * ====================
 * Primarily helper functions from utils.cpp
 */

int hello();
int copyrightMessage();
int gameStartMessage();
int promptEnterToContinue();

// From card.cpp
struct valuePair
{
  int coins;
  int chainValue;
};
int calculateChainValue(int coins, valuePair *values, int numValues);

// End definition for MAINPROG, the whole program.
#endif
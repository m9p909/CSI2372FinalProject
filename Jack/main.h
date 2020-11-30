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
#include <algorithm>
#include <random>

// Always use the standard namespace.
using namespace std;

/**
 * Class Definitions
 * =================
 * Classes corresponding to the game components
 * provided in the program description.
 */
class Card {
public:
  // Pure Virtual Functions:
  int getCardsPerCoin(int);
  virtual string getName() = 0;
  virtual void print(ostream &out) = 0;
};


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

class CardFactory {
  vector<Card *> deck;
  static CardFactory* factory;
  
  private:
  
  CardFactory();
  
  public:

    static CardFactory *getFactory();
    vector<Card *> getDeck();
};

class Chain_Base {

public:
  Chain_Base(istream &, const CardFactory *);
  virtual Chain_Base &operator+=(Card *card);
  virtual int sell();
  friend ostream &operator<<(ostream &out, const Chain_Base &chain);
};

class Deck : public vector<Card *> {
  istream *stream;

public:
  Deck(istream &, CardFactory *);
  Card *draw();
  friend ostream &operator<<(ostream &out, const Deck &chain);
};

class DiscardPile : public vector<Card*> {
  istream *stream;
  const CardFactory *factory;
  DiscardPile(istream &, const CardFactory *);
  DiscardPile &operator+=(Card *);
  Card *pickUp();
  Card *top();
  void print(std::ostream &);
};

template <class T> class Chain : public Chain_Base {
  istream *stream;
  T *card_example;
  vector<T *> chainV;
  Chain(istream &, const CardFactory *);
  Chain &operator+=(Card *card);
  int sell();
  friend ostream &operator<<(ostream &out, const Chain &chain);
};

class Blue : public Card {
  istream *stream;

public:
  int getCardsPerCoin(int);
  string getName();
  void print(ostream &out);
};

class Chili : public Card {
  istream *stream;

public:
  int getCardsPerCoin(int );
  string getName();
  void print(ostream &out);
};

class Stink : public Card {
  istream *stream;

public:
  int getCardsPerCoin(int );
  string getName();
  void print(ostream &out);
};

class Green : public Card {
  istream *stream;

public:
  int getCardsPerCoin(int );
  string getName();
  void print(ostream &out);
};

class Soy : public Card {
  istream *stream;

public:
  int getCardsPerCoin(int );
  string getName();
  void print(ostream &out);
};

class Black : public Card {
  istream *stream;

public:
  int getCardsPerCoin(int );
  string getName();
  void print(ostream &out);
};

class Red : public Card {
  istream *stream;

public:
  int getCardsPerCoin(int );
  string getName();
  void print(ostream &out);
};

class Garden : public Card {
  istream *stream;

public:
  int getCardsPerCoin(int );
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

// End definition for MAINPROG, the whole program.
#endif
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

#ifndef MAINPROG
#define MAINPROG

// Include libraries for all C++ files.
#include <cstdlib>
#include <iostream>
#include <limits>
#include <typeinfo>
#include <random>
#include <algorithm>

// Always use the standard namespace in this program.
using namespace std;

/**
 * Class Definitions
 * =================
 * Classes corresponding to the game components
 * provided in the program description.
 */

class CardFactory; // Forward declaration of CardFactory required for correct compilation.

class Card
{
public:
  virtual int getCardsPerCoin(int coins) = 0;
  virtual string getName() = 0;
  virtual void print(ostream &out) = 0;
};

class Deck : public vector<Card *>
{
public:
  Deck();
  Deck(istream &, const CardFactory *);
  Card *draw();
  friend ostream &operator<<(ostream &, Deck &);
  void status(); // Debugging function.
};

class CardFactory
{
private:
  CardFactory(const CardFactory &); // Prevent usage by making private.
  ~CardFactory() = default;
  static CardFactory *internal;
  static Deck *deck;

public:
  CardFactory();
  static CardFactory *getFactory();
  Deck getDeck();
  // void status(); // Debugging function.
};

class DiscardPile : public vector<Card *>
{
public:
  DiscardPile() = default;
  ~DiscardPile() = default;
  DiscardPile(istream &, const CardFactory *);
  DiscardPile &operator+=(Card *);
  Card *pickUp();
  Card *top();
  void print(std::ostream &);
  friend ostream &operator<<(ostream &, Deck &);
  void status(); // Debugging function.
};

class Chain_Base
{
public:
  Chain_Base() = default;
  ~Chain_Base() = default;
  Chain_Base(istream &, const CardFactory *);
  virtual Chain_Base &operator+=(Card *) = 0;
  virtual int sell() = 0;
};

template <typename T>
class Chain : public Chain_Base
{
public:
  vector<T *> cards;
  Chain_Base &operator+=(Card *);
  int sell();
  void print(ostream &out);
};

class Hand : public vector<Card *>
{
public:
  Hand() = default;
  ~Hand() = default;
  Hand(istream &, const CardFactory *);
  Hand &operator+=(Card *);
  Card *play();
  Card *top();
  Card *operator[](int);
  friend ostream &operator<<(ostream &, Deck &);
  void status(); // Debugging function.
};

class Player
{
private:
  vector<Chain_Base *> *chains;
  string name;
  int coins;

public:
  Player();
  ~Player();
  Player(string &);
  Player(istream &, const CardFactory *);
  string getName();
  int getNumCoins();
  Player &operator+=(int);
  int getMaxNumChains();
  int getNumChains();
  Chain_Base &operator[](int i);
  void buyThirdChain();
  void printHand(ostream &, bool);
};

class Table;
class TradeArea;
class Coins;

/**
 * Class Implementation Definitions
 * ================================
 * Classes corresponding to the game components
 * provided in the program description.
 */
class Blue : public Card
{
public:
  int getCardsPerCoin(int coins);
  string getName();
  void print(ostream &out);
};
template class Chain<Blue>;

class Chili : public Card
{
public:
  int getCardsPerCoin(int coins);
  string getName();
  void print(ostream &out);
};
template class Chain<Chili>;

class Stink : public Card
{
public:
  int getCardsPerCoin(int coins);
  string getName();
  void print(ostream &out);
};
template class Chain<Stink>;

class Green : public Card
{
public:
  int getCardsPerCoin(int coins);
  string getName();
  void print(ostream &out);
};
template class Chain<Green>;

class Soy : public Card
{
public:
  int getCardsPerCoin(int coins);
  string getName();
  void print(ostream &out);
};
template class Chain<Soy>;

class Black : public Card
{
public:
  int getCardsPerCoin(int coins);
  string getName();
  void print(ostream &out);
};
template class Chain<Black>;

class Red : public Card
{
public:
  int getCardsPerCoin(int coins);
  string getName();
  void print(ostream &out);
};
template class Chain<Red>;

class Garden : public Card
{
public:
  int getCardsPerCoin(int coins);
  string getName();
  void print(ostream &out);
};
template class Chain<Garden>;

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
int calculateChainValue(int, valuePair *, int);

// From cardfactory.cpp
template <typename T>
void addCardsToDeck(Deck *, int, T);

/**
 * Deck Properties & Constants 
 * ===========================
 * Keep the deck parameters in a set of constants.
 */

const int BLUE_CARDS = 20;
const int CHILI_CARDS = 18;
const int STINK_CARDS = 16;
const int GREEN_CARDS = 14;
const int SOY_CARDS = 12;
const int BLACK_CARDS = 10;
const int RED_CARDS = 8;
const int GARDEN_CARDS = 6;
const int DECK_SIZE = BLUE_CARDS + CHILI_CARDS + STINK_CARDS + GREEN_CARDS + SOY_CARDS + BLACK_CARDS + RED_CARDS + GARDEN_CARDS;

/**
 * Exceptions 
 * ==========
 * Thrown from class implementations. 
 */

class IllegalType : public exception
{
public:
  const char *what() const throw()
  {
    return "Illegal type exception.";
  }
};

class CoinValueNotFound : public exception
{
public:
  const char *what() const throw()
  {
    return "A coin value for this number of coins was not found.";
  }
};

class Unimplemented : public exception
{
public:
  const char *what() const throw()
  {
    return "This required function has not yet been implemented.";
  }
};

// End definition for MAINPROG, the whole program.
#endif
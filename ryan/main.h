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
 *  - Jack Clarke  - - - - - 3000080674
 *  - Ryan Fleck   - - - - - -  8272723
 */

#ifndef MAINPROG
#define MAINPROG

// Include libraries for all C++ files.
#include <cstdlib>
#include <limits>
#include <typeinfo>

// Algorithms
#include <random>
#include <algorithm>
#include <list>
#include <iterator>

// Strings and Streams
#include <string>
#include <iostream>
#include <sstream>

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
  friend ostream &operator<<(ostream &, Card &);
  friend ostream &operator<<(ostream &, Card *);
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
  void print(ostream &);
  friend ostream &operator<<(ostream &, DiscardPile &);
  friend ostream &operator<<(ostream &, DiscardPile *);
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
  virtual void print(ostream &) = 0;
  virtual Card* getExampleItem() = 0;
  virtual int getSize() = 0;
  
  friend ostream &operator<<(ostream &, Chain_Base &);
};

template <typename T>
class Chain : public Chain_Base
{
public:
  vector<T *> cards;
  Chain_Base &operator+=(Card *);
  int sell();
  void print(ostream &);
  Card* getExampleItem();
  int getSize();
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
  void print(ostream &);
  friend ostream &operator<<(ostream &, Hand &);
  friend ostream &operator<<(ostream &, Hand *);
  void status(); // Debugging function.
};

class Player
{
private:
  
  string name;
  int coins;
  int maxNumChains;

public:
  vector<Chain_Base *> *chains;
  Hand *hand;

  // Functions
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
  Chain_Base * getChain(int);

  // Printing Methods
  void print(ostream &);
  friend ostream &operator<<(ostream &, Player &);
  friend ostream &operator<<(ostream &, Player *);

  // Functions not in requirements:
  void addChain(Chain_Base *);
};

class TradeArea : public list<Card *>
{
public:
  TradeArea() = default;
  ~TradeArea() = default;
  TradeArea(istream &, const CardFactory *);
  TradeArea &operator+=(Card *);
  bool legal(Card *);
  Card *trade(string);
  int numCards();

  // Printing Methods
  void print(ostream &);
  friend ostream &operator<<(ostream &, TradeArea &);
  friend ostream &operator<<(ostream &, TradeArea *);

  // Additional Methods
  void discardAll(DiscardPile &);
};

class Table
{
public:
  Player *player1;
  Player *player2;
  Deck deck;
  DiscardPile *discardPile;
  TradeArea *tradeArea;

  Table(istream &, const CardFactory *);
  Table(string player1Name, string player2Name);
  bool win(std::string &);
  void printHand(bool);
  friend ostream &operator<<(ostream &out, const Table &table);
};

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

class CardNotFound : public exception
{
public:
  const char *what() const throw()
  {
    return "The requested card was not found.";
  }
};

class ChainAtIndexNotFound : public exception
{
public:
  const char *what() const throw()
  {
    return "A chain does not exist at the called index.";
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

class PlayerChainsFull : public exception
{
public:
  const char *what() const throw()
  {
    return "Cannot add new chain, maybe try purchasing a new one?";
  }
};

// End definition for MAINPROG, the whole program.
#endif
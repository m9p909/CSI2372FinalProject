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
#include <exception>
#include <iostream>
#include <limits>
#include <bits/stdc++.h> 

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

class CardFactory;
class Card {
public:
  // Pure Virtual Functions:
  virtual int getCardsPerCoin(int) = 0;
  virtual string getName() = 0;
  virtual void print(ostream &out) = 0;
};


class Coins;

/**
 * Class Implementation Definitions
 * =================
 * Classes corresponding to the game components
 * provided in the program description.
 */


class Chain_Base {
public:
  Chain_Base(istream &, const CardFactory *){};
  virtual int getLength(){};
  virtual Chain_Base &operator+=(Card *card){};
  virtual int sell(){};
  virtual void print(ostream &out) const{};
  virtual string getName(){};
  Chain_Base(){};
  virtual ~Chain_Base(){};

  
  
  
  friend ostream &operator<<(ostream &out, const Chain_Base &chain);
};

template <class T> class Chain : virtual public Chain_Base {
  istream *stream;
  T *card_example;
  vector<T *> chainV;
  public:
  void print(ostream &out) const;
  string getName();
  Chain(istream &, const CardFactory *);
  Chain();
  Chain &operator+=(Card *card);
  int sell();
  int getLength();
  friend ostream &operator<<(ostream &out, const Chain &chain);
};



class Deck : public vector<Card *> {
  istream *stream;

public:
  Deck(istream &, CardFactory *);
  Deck();
  Card *draw();
  friend ostream &operator<<(ostream &out, const Deck &chain);
};

class CardFactory {
  Deck deck;
  static CardFactory *factory;

private:
  CardFactory();

public:
  static CardFactory *getFactory();
  static CardFactory *resetFactory();
  Deck* getDeck();
};


class DiscardPile : public vector<Card *> {
  istream *stream;
  const CardFactory *factory;
  public:
  DiscardPile(istream &, const CardFactory *);
  DiscardPile();
  DiscardPile &operator+=(Card *);
  Card *pickUp();
  Card *top();
  void print(std::ostream &);
};





class Hand {
public:
  vector<Card *> cards;
  Hand(istream &, const CardFactory *);
  Hand();
  Hand *operator+=(Card *);
  Card *play();
  Card *top();
  Card *operator[](int);
  friend ostream &operator<<(ostream &out, const Hand &hand);
};

class Player {
  string playerName;
  int numCoins;
  
  int numChains=2;
  
  

public:
  vector<Chain_Base*> chains;
  Player(std::string &);
  ostream& print(ostream&) const;
  Hand *hand;
  Player(istream &, const CardFactory *);
  string getName();
  int getNumCoins();
  Player &operator+=(int);
  int getMaxNumChains();
  int getNumChains();
  void addChain(Chain_Base*);
  Chain_Base* &operator[](int i);
  void buyThirdChain();
  void printHand(std::ostream &, bool);
  friend ostream &operator<<(ostream &out, const Player &player);
};

class TradeArea {
  public:
  vector<Card *> cards;
  TradeArea(istream &, const CardFactory *);
  TradeArea();
  TradeArea &operator+=(Card *);
  void discardAll(DiscardPile &discard);
  bool legal(Card *);
  Card *trade(string);
  int numCards();
  friend ostream &operator<<(ostream &out, const TradeArea &area);
};

class Table {
  public:
  Player *player1;
  Player *player2;
  Deck *deck;
  DiscardPile *discardPile;
  TradeArea* tradeArea;

  
  Table(istream &, const CardFactory *);
  Table(string player1Name, string player2Name);
  bool win(std::string &);
  void printHand(bool);
  friend ostream &operator<<(ostream &out, const Table &table);
};

class NotEnoughCoins : public exception {};

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
  int getCardsPerCoin(int);
  string getName();
  void print(ostream &out);
};

class Stink : public Card {
  istream *stream;

public:
  int getCardsPerCoin(int);
  string getName();
  void print(ostream &out);
};

class Green : public Card {
  istream *stream;

public:
  int getCardsPerCoin(int);
  string getName();
  void print(ostream &out);
};

class Soy : public Card {
  istream *stream;

public:
  int getCardsPerCoin(int);
  string getName();
  void print(ostream &out);
};

class Black : public Card {
  istream *stream;

public:
  int getCardsPerCoin(int);
  string getName();
  void print(ostream &out);
};

class Red : public Card {
  istream *stream;

public:
  int getCardsPerCoin(int);
  string getName();
  void print(ostream &out);
};

class Garden : public Card {
  istream *stream;

public:
  int getCardsPerCoin(int);
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
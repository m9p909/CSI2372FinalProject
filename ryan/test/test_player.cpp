#include "../main.h"
#include "doctest.h"

TEST_CASE("Instantiate Player")
{
  Player();
  string name = "Ryan";
  Player *y = new Player(name);
  delete y;
}

TEST_CASE("Player getName()")
{
  string name = "Ryan";
  Player p = Player(name);
  CHECK(p.getName() == name);
}

TEST_CASE("Player getNumCoins()")
{
  string name = "Bob";
  Player p = Player(name);
  CHECK(p.getNumCoins() == 0);
}

TEST_CASE("Player getNumChains()")
{
  string name = "Bob";
  Player p = Player(name);
  CHECK(p.getNumChains() == 0);
  Chain<Stink> s = Chain<Stink>();
  Chain<Blue> b = Chain<Blue>();
  Chain<Garden> g = Chain<Garden>();
}

TEST_CASE("Player += int")
{
  string name = "Bob";
  Player p = Player(name);
  p += 5;
  p += 10;
  CHECK(p.getNumCoins() == 15);
}

TEST_CASE("Player MaxChains buyThirdChain")
{
  string name = "Bob";
  Player p = Player(name);
  CHECK(p.getMaxNumChains() == 2);
  p += 10;
  p.buyThirdChain();
  CHECK(p.getMaxNumChains() == 3);
}

TEST_CASE("Player getNumChains, addChain")
{
  string name = "Bob";
  Player p = Player(name);
  Chain<Chili> *C = new Chain<Chili>();
  Chain<Green> *G = new Chain<Green>();
  Chain<Soy> *S = new Chain<Soy>();
  p.addChain(C);
  CHECK(p.getNumChains() == 1);
  p.addChain(G);
  CHECK(p.getNumChains() == 2);
  // At this point, adding another chain should throw a 'chains full' exception.
  CHECK_THROWS_AS(p.addChain(S), PlayerChainsFull);
  p += 10;
  p.buyThirdChain();
  p.addChain(S);
  CHECK(p.getNumChains() == 3);

  // Attempting to buy a third chain AGAIN will throw an exception.
  CHECK_THROWS_AS(p.buyThirdChain(), PlayerChainsFull);

  // Again, attempting to add another chain at this point should throw an exception.
  CHECK_THROWS_AS(p.addChain(S), PlayerChainsFull);
}

TEST_CASE("Player [] operator")
{
  // Create player with some chains.
  string name = "Bob";
  Player p = Player(name);
  Chain<Chili> *C = new Chain<Chili>();
  Chain<Green> *G = new Chain<Green>();
  Chain<Soy> *S = new Chain<Soy>();
  p.addChain(C);
  p.addChain(G);
  p += 10;
  p.buyThirdChain();
  p.addChain(S);

  CHECK(&p[0] == C);
  CHECK(&p[1] == G);
  CHECK(&p[2] == S);
}

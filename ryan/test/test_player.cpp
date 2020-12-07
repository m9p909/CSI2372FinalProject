#include "../main.h"
#include "doctest.h"

/**
 * The VERY SPECIFIC player spec for saving/loading:
 *
 * "Bob   3 coins" << endl;
 * Name - Three Spaces - Coin# - "coins" - endl; 
 * "Chili   C C C" << endl;
 * for chain in chains, print chain. - endl; 
 */

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

TEST_CASE("Print Player")
{
  string name = "Bob";
  Player p = Player(name);

  // Instantiate some chains and cards.
  Chain<Chili> *C = new Chain<Chili>();
  Chili *c = new Chili();
  Chain<Green> *G = new Chain<Green>();
  Green *g = new Green();
  Chain<Soy> *S = new Chain<Soy>();
  Soy *s = new Soy();

  // Add some cards to the players' hand.
  *p.hand += c;
  *p.hand += g;
  *p.hand += s;

  // Add 10 Chili cards.
  for (int i = 0; i < 10; i++)
    *C += c;

  // Add 8 Green cards
  for (int i = 0; i < 8; i++)
    *G += g;

  // Add 6 Soy cards
  for (int i = 0; i < 6; i++)
    *S += s;

  // Add the chains to the player
  p.addChain(C);
  p.addChain(G);
  p += 10;
  p.buyThirdChain();
  p.addChain(S);

  // Print the player
  stringstream out;
  p.print(out);
  string line;

  // Check the first line.
  getline(out, line);
  CHECK(line == "Bob   7 coins");

  // Check the second line.
  getline(out, line);
  CHECK(line == "Chili   C C C C C C C C C C");

  // Check the third line.
  getline(out, line);
  CHECK(line == "Green   G G G G G G G G");

  // Check the fourth line.
  getline(out, line);
  CHECK(line == "Soy   s s s s s s");
}

TEST_CASE("Print Player's Hand")
{
  string name = "Bob";
  Player p = Player(name);

  // Instantiate some cards.
  Chili *c = new Chili();
  Green *g = new Green();
  Soy *s = new Soy();

  // Add some cards to the players' hand.
  *p.hand += c;
  *p.hand += g;
  *p.hand += s;

  // Print the player
  stringstream out;
  p.printHand(out, true);
  CHECK(out.str() == "C G s");

  // Print the player
  stringstream out2;
  p.printHand(out2, false);
  CHECK(out2.str() == "s");
}
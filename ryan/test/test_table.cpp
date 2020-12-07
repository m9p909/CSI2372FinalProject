#include "../main.h"
#include "doctest.h"
#include <sstream>

TEST_CASE("Instantiate a Table.")
{
  Table();
  Table *t = new Table();
  
   
  delete t;

  Table test = Table("Andrew", "Mark");
  CHECK(test.deck.size() == 104);
}

TEST_CASE("Print Table with Nothing")
{
  Table t = Table("Ben", "Stuart");

  stringstream out;
  out << t;
  string line;

  // An empty table will only print the players, with no coins.
  getline(out, line);
  CHECK(line == "Ben   0 coins");
  getline(out, line);
  CHECK(line == "Stuart   0 coins");

  // Check for all the card letters in the third line, where the Deck is printed.
  getline(out, line);
  CHECK(line.find("B") != string::npos);
  CHECK(line.find("C") != string::npos);
  CHECK(line.find("S") != string::npos);
  CHECK(line.find("G") != string::npos);
  CHECK(line.find("s") != string::npos);
  CHECK(line.find("b") != string::npos);
  CHECK(line.find("R") != string::npos);
  CHECK(line.find("g") != string::npos);
}

TEST_CASE("Table win()")
{
  Table t = Table("Ben", "Stuart");
  string winner;

  stringstream out;
  out << t;
  string line;

  CHECK(t.win(winner) == false);

  // Add some coins to the players.
  t.player1 += 420;
  t.player2 += 69;

  // Remove card and check win condition.
  while (!t.deck.empty())
    t.deck.draw();
  CHECK(t.deck.size() == 0);
  CHECK(t.deck.empty() == true);

  // Check who the winner is
  CHECK(t.win(winner) == true);
  CHECK(winner == t.player1->getName());
}
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

  // The first line will contain the file header.
  getline(out, line);
  CHECK(line == TABLE_HEADER);

  // The next line will be the player header.
  getline(out, line);
  CHECK(line == PLAYERS_HEADER);

  // An empty table will only print the players, with no coins.
  getline(out, line);
  CHECK(line == "Ben   0 coins");
  getline(out, line);
  CHECK(line == "Stuart   0 coins");

  // The next line will be the end of the section.
  getline(out, line);
  CHECK(line == SECTION_END);

  // The next line will be
  getline(out, line);
  CHECK(line == DECK_HEADER);

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

  // The next line will be the end of the section.
  getline(out, line);
  CHECK(line == SECTION_END);

  // The next line will be
  getline(out, line);
  CHECK(line == TRADE_AREA_HEADER);

  // The next line will be the end of the section.
  getline(out, line);
  CHECK(line == SECTION_END);
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

TEST_CASE("Reload the Table from File")
{
  Table t = Table("Ben", "Stuart");
  string winner;

  // Add some coins to the players.
  *t.player1 += 420;
  *t.player2 += 69;

  REQUIRE(t.deck.size() == DECK_SIZE);

  // Deal five cards to each player.
  for (int i = 0; i < 5; i++)
  {
    Card *x = t.deck.draw();
    *t.player1->hand += x;
    Card *y = t.deck.draw();
    *t.player2->hand += y;
  }

  REQUIRE(t.deck.size() == DECK_SIZE - 10);

  // cout << "Drawing Deck..." << endl;
  // Draw half the deck.
  int draw_half_deck = DECK_SIZE / 2;
  for (int i = 0; i < draw_half_deck; i++)
    t.deck.draw();

  // TODO: Remove. Prints table file for debugging.
  // cout << t;

  // Load the table from a stream.
  stringstream io;
  io << t;
  Table reloadedTable = Table(io, CardFactory::getFactory());
}
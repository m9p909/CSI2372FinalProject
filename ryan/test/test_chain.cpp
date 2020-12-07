#include "../main.h"
#include "doctest.h"

TEST_CASE("Chain Instantiation")
{
  // Ensure the instantiation of a new chain does not raise errors.
  Chain<Stink>();
  Chain<Stink> *x = new Chain<Stink>();
  CHECK((*x).cards.empty());
}

TEST_CASE("Chain + operator overload")
{
  Chain<Stink> n = Chain<Stink>();
  Chain<Stink> *x = new Chain<Stink>();
  Stink *y = new Stink();
  *x += y;
  n += y;
  *x += y;
  n += y;
  CHECK((*x).cards.size() == 2);
  CHECK(n.cards.size() == 2);
}

TEST_CASE("Chain sell() function")
{
  Chain<Stink>();
  Chain<Stink> *x = new Chain<Stink>();
  Stink *y = new Stink();

  // Selling with no cards should return zero.
  CHECK((*x).sell() == 0);

  // Selling with two cards should return 0
  *x += y;
  *x += y;
  CHECK((*x).sell() == 0);

  // Selling with three Stink cards should return 1.
  *x += y;
  CHECK((*x).sell() == 1);

  // Selling with five cards should return 2
  *x += y;
  *x += y;
  CHECK((*x).sell() == 2);

  // Selling with seven cards should return 3
  *x += y;
  *x += y;
  CHECK((*x).sell() == 3);

  // Selling with eight cards should return 3
  *x += y;
  CHECK((*x).sell() == 4);

  // Selling with over eight cards should return 4
  for (int i = 0; i < 40; i++)
    *x += y;
  CHECK((*x).sell() == 4);

  // Test another type of card, just in case.
  Chain<Blue> bc = Chain<Blue>();
  Blue *b = new Blue();
  for (int i = 0; i < 9; i++)
    bc += b;
  CHECK(bc.sell() == 3);

  // With 10 cards, a Blue chain should return 4.
  bc += b;
  CHECK(bc.sell() == 4);

  // Garden only has two values, so let's check that too.
  Chain<Garden> gc = Chain<Garden>();
  Garden g = Garden();
  for (int i = 0; i < 30; i++)
  {
    gc += &g;
  }
  CHECK(gc.sell() == 3);
}

TEST_CASE("Test Chain print to stream.")
{
  // Create a five-element garden chain.
  Chain<Garden> gc = Chain<Garden>();
  Garden g = Garden();
  for (int i = 0; i < 5; i++)
    gc += &g;

  // Print to a sstream.
  stringstream out;
  out << gc;
  string output_string = out.str();
  CHECK(output_string == "Garden   g g g g g");
}
#include "../main.h"
#include "doctest.h"

TEST_CASE("Chain Instantiation")
{
  // Ensure the instantiation of a new chain does not raise errors.
  Chain<Stink> n = Chain<Stink>();
  Chain<Stink> *x = new Chain<Stink>();
  Stink *y = new Stink();
  *x += y;
  n += y;
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
}
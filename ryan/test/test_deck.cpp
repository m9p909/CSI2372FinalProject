#include "../main.h"
#include "doctest.h"

TEST_CASE("Instantiate Deck")
{
  Deck();
  Deck *x = new Deck();
  delete x;
}
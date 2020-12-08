#include "../main.h"
#include "doctest.h"

TEST_CASE("Instantiate Deck")
{
  Deck();
  Deck *x = new Deck();
  delete x;
}

TEST_CASE("Peel Cards off Deck")
{
  CardFactory *x = CardFactory::getFactory();
  Deck d = x->getDeck();
  d.draw();
}
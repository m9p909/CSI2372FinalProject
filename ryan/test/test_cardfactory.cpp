#include "../main.h"
#include "doctest.h"

TEST_CASE("Test CardFactory")
{
  CHECK(1 == 1);
  CardFactory *x = CardFactory::getFactory();
  Deck y = x->getDeck();

  // The deck should have a size of 104 cards.
  CHECK(y.size() == 104);
}
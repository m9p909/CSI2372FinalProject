#include "../main.h"
#include "doctest.h"
#include "../cls/Cards/Stink.cpp"

/**
 * These test cases are from the doctest guide:
 * https://github.com/onqtam/doctest/blob/master/doc/markdown/tutorial.md
 * 
 * It is here to provide a minimal example for contributors, and
 * ensure that the unit testing system is working properly.
 */

TEST_CASE("Testing the Stink card")
{
  Stink x = Stink();
  CHECK(x.getName() == "Stink");
  CHECK(x.getCardsPerCoin(3) == 3);
  // CHECK(x.print() == "Stink");
}
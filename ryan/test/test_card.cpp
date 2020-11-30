#include "../main.h"
#include "doctest.h"

/**
 * These test cases are from the doctest guide:
 * https://github.com/onqtam/doctest/blob/master/doc/markdown/tutorial.md
 * 
 * It is here to provide a minimal example for contributors, and
 * ensure that the unit testing system is working properly.
 */

TEST_CASE("Testing the calculateChainValue function.")
{
  valuePair values[] = {{1, 7}, {2, 8}, {3, 9}};
  CHECK(calculateChainValue(1, values, 3) == 7);
  CHECK(calculateChainValue(2, values, 3) == 8);
  CHECK(calculateChainValue(3, values, 3) == 9);

  valuePair values2[] = {{24, 8}, {192, 37}};
  CHECK(calculateChainValue(192, values2, 2) == 37);
}

TEST_CASE("Testing the Stink card")
{
  Stink x = Stink();
  CHECK(x.getName() == "Stink");
  CHECK(x.getCardsPerCoin(3) == 3);
  // CHECK(x.print() == "Stink");
}
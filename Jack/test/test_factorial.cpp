#include "../main.h"
#include "doctest.h"

/**
 * These test cases are from the doctest guide:
 * https://github.com/onqtam/doctest/blob/master/doc/markdown/tutorial.md
 * 
 * It is here to provide a minimal example for contributors, and
 * ensure that the unit testing system is working properly.
 */

int factorial2(int number) { return number <= 1 ? number : factorial2(number - 1) * number; }

TEST_CASE("testing the factorial2 function")
{
  CHECK(factorial2(1) == 1);
  CHECK(factorial2(2) == 2);
  CHECK(factorial2(3) == 6);
  CHECK(factorial2(10) == 3628800);
}
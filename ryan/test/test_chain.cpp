#include "../main.h"
#include "doctest.h"

TEST_CASE("Chain")
{
  CHECK(1 == 1);
  Chain<Stink>();
  Chain<Stink> *x = new Chain<Stink>();
  Stink *y = new Stink();
  *x += y;
  CHECK(1 == 1);
}
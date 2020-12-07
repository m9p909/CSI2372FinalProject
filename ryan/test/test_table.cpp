#include "../main.h"
#include "doctest.h"

TEST_CASE("Instantiate a Table.")
{
  Table();
  Table *t = new Table();
  delete t;
}
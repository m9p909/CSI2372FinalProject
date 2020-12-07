#include "../main.h"
#include "doctest.h"
#include <sstream>

TEST_CASE("Instantiate a Table.")
{
  Table();
  Table *t = new Table();
  stringstream s;
  s << t;
   
  delete t;
}
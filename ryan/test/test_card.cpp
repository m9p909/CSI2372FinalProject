#include "../main.h"
#include "doctest.h"

TEST_CASE("calculateChainValue")
{
  valuePair values[] = {{1, 7}, {2, 8}, {3, 9}};
  CHECK(calculateChainValue(1, values, 3) == 7);
  CHECK(calculateChainValue(2, values, 3) == 8);
  CHECK(calculateChainValue(3, values, 3) == 9);

  valuePair values2[] = {{24, 8}, {192, 37}};
  CHECK(calculateChainValue(192, values2, 2) == 37);
}

TEST_CASE("Stink Card")
{
  Stink x = Stink();
  CHECK(x.getName() == "Stink");
  CHECK(x.getCardsPerCoin(1) == 3);
  CHECK(x.getCardsPerCoin(2) == 5);
  CHECK(x.getCardsPerCoin(3) == 7);
  CHECK(x.getCardsPerCoin(4) == 8);
}

TEST_CASE("Get Card Names")
{
  // Also ensures all cards can be instantiated.
  CHECK(Blue().getName() == "Blue");
  CHECK(Chili().getName() == "Chili");
  CHECK(Stink().getName() == "Stink");
  CHECK(Green().getName() == "Green");
  CHECK(Soy().getName() == "Soy");
  CHECK(Black().getName() == "Black");
  CHECK(Red().getName() == "Red");
  CHECK(Garden().getName() == "Garden");
}

TEST_CASE("Print Cards")
{
  // A stringstream will allow us to read output.
  stringstream out;
  Blue B = Blue();
  Chili C = Chili();
  Stink S = Stink();
  Green G = Green();
  Soy s = Soy();
  Black b = Black();
  Red R = Red();
  Garden g = Garden();

  /// Send each to the stringstream.
  out << B << C << S << G << s << b << R << g;

  // Verify that the correct letters are printed.
  CHECK(out.str() == "BCSGsbRg");
}
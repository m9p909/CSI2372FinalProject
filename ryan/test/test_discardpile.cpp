#include "../main.h"
#include "doctest.h"

TEST_CASE("Instantiate DiscardPile")
{
  DiscardPile();
  DiscardPile *x = new DiscardPile();
  delete x;
}

TEST_CASE("Add a card to DiscardPile")
{
  DiscardPile d = DiscardPile();
  Stink s = Stink();
  CHECK(d.empty() == true);

  // Add the card to DiscardPile
  d += (&s);
  CHECK(d.empty() == false);
  CHECK(d.size() == 1);
}

TEST_CASE("Peek and pick up a card from discard pile")
{
  DiscardPile d = DiscardPile();

  // Create cards and add references to the DiscardPile.
  Stink s = Stink();
  Blue b = Blue();
  Garden g = Garden();
  d += (&s);
  d += (&b);
  d += (&g);

  // The discardpile should have three elements.
  CHECK(d.empty() == false);
  CHECK(d.size() == 3);

  // Ensure the size does not change when checking the top card.
  CHECK(d.top() == &g);
  CHECK(d.size() == 3);

  // Picking up the card should remove it from the discardpile.
  CHECK(d.pickUp() == &g);
  CHECK(d.size() == 2);
}
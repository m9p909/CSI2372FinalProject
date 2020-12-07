#include "../main.h"
#include "doctest.h"

TEST_CASE("Instantiate a TradeArea.")
{
  TradeArea();
  TradeArea *t = new TradeArea();
  delete t;
}

TEST_CASE("TradeArea += Card")
{
  TradeArea x = TradeArea();

  // Card pointers.
  Chili *c = new Chili();
  Green *g = new Green();

  // Add to the TradeArea
  x += c;
  x += g;

  // Ensure two cards are present.
  CHECK(x.numCards() == 2);
}

TEST_CASE("TradeArea - Card is legal()?")
{
  TradeArea x = TradeArea();

  // Card pointers.
  Chili *c = new Chili();
  Green *g = new Green();
  Soy *s = new Soy();

  x += c;
  x += g;

  // Ensure it is only legal to add another card that is already here.
  CHECK(x.legal(g) == true);
  CHECK(x.legal(s) == false);
}

TEST_CASE("TradeArea - Trade")
{
  TradeArea x = TradeArea();

  // Card pointers.
  Chili *c = new Chili();
  Green *g = new Green();
  Soy *s = new Soy();

  x += c;
  x += g;
  x += s;

  // Ensure the Cards have been added.
  CHECK(x.numCards() == 3);

  // "Trade" all the cards into pointers.
  Card *A = x.trade(c->getName());
  Card *B = x.trade(g->getName());
  Card *C = x.trade(s->getName());

  // No cards should remain in the TradeArea
  CHECK(x.numCards() == 0);

  // Ensure the pointers match back up with the original cards.
  CHECK(A == c);
  CHECK(B == g);
  CHECK(C == s);
}

TEST_CASE("TradeArea - Discard All")
{
  TradeArea x = TradeArea();

  // Card pointers.
  Chili *c = new Chili();
  Green *g = new Green();
  Soy *s = new Soy();

  x += c;
  x += g;
  x += s;

  // Ensure the Cards have been added.
  CHECK(x.numCards() == 3);

  DiscardPile d = DiscardPile();
  x.discardAll(d);

  // No cards should remain in the TradeArea
  CHECK(x.numCards() == 0);

  // All the cards should be in the DiscardPile
  CHECK(d.size() == 3);

  // Picking the cards back up from the discard pile should yield the same order they were discarded in.
  CHECK(d.pickUp() == s);
  CHECK(d.size() == 2);

  CHECK(d.pickUp() == g);
  CHECK(d.size() == 1);

  CHECK(d.pickUp() == c);
  CHECK(d.size() == 0);
}
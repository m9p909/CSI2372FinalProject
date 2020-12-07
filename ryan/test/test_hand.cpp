#include "../main.h"
#include "doctest.h"

TEST_CASE("Instantiate Hand")
{
  Hand();
  Hand *x = new Hand();
  delete x;
}

TEST_CASE("Add a card to Hand")
{
  Hand h = Hand();
  Stink s = Stink();
  CHECK(h.empty() == true);

  // Add the card to Hand
  h += (&s);
  CHECK(h.empty() == false);
  CHECK(h.size() == 1);
}

TEST_CASE("Test the [] operator.")
{
  Hand h = Hand();

  // Create cards and add references to the Hand.
  Stink s = Stink();
  Blue b = Blue();
  Garden g = Garden();

  h += (&s);
  h += (&b);
  h += (&g);
  h += (&s);
  h += (&b);
  h += (&g);

  // The discardpile should have three elements.
  CHECK(h.empty() == false);
  CHECK(h.size() == 6);

  // Test the [] operator.
  CHECK(h[1] == &b);
  CHECK(h[2] == &s);
  CHECK(h[0] == &s);
  CHECK(h[4] == nullptr);
  CHECK(h[-1] == nullptr);
  CHECK(h.size() == 3);
}

TEST_CASE("Peek and play a card from hand")
{
  Hand h = Hand();

  // Create cards and add references to the Hand.
  Stink s = Stink();
  Blue b = Blue();
  Garden g = Garden();
  h += (&s);
  h += (&b);
  h += (&g);

  // The discardpile should have three elements.
  CHECK(h.empty() == false);
  CHECK(h.size() == 3);

  // Ensure the size does not change when checking the top card.
  CHECK(h.top() == &g);
  CHECK(h.size() == 3);

  // Picking up the card should remove it from the discardpile.
  CHECK(h.play() == &g);
  CHECK(h.top() == &b);
  CHECK(h.size() == 2);
}

TEST_CASE("Print a Hand")
{
  Hand h = Hand();

  // Create cards and add references to the Hand.
  Stink s = Stink();
  Blue b = Blue();
  Garden g = Garden();
  h += (&s);
  h += (&b);
  h += (&g);
  h += (&s);
  h += (&b);
  h += (&g);

  // Passed as a reference to the stream.
  stringstream outOne;
  outOne << h;
  string output_string = outOne.str();
  CHECK(output_string == "SBgSBg");

  // Passed as a pointer to the stream.
  stringstream outTwo;
  outTwo << &h;
  output_string = outTwo.str();
  CHECK(output_string == "SBgSBg");
}
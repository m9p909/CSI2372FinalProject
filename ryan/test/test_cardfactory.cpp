#include "../main.h"
#include "doctest.h"

TEST_CASE("Test CardFactory")
{
  CHECK(1 == 1);
  CardFactory *x = CardFactory::getFactory();
  Deck y = x->getDeck();

  // The deck should have a size of 104 cards.
  CHECK(y.size() == 104);

  // Count the number of cards in the generated deck, ensure the numbers are correct.
  // There should be <STINK_CARDS> stink cards in the shuffled deck.
  unsigned int stink_cards = 0;
  for (int i = 0; i < 104; i++)
  {
    if (y.at(i)->getName() == "Stink")
    {
      stink_cards++;
    }
  }
  CHECK(stink_cards == STINK_CARDS);

  // Drawing a card should reduce the count of that card by one.
  Card *dc = y.draw();
  string cardTypeName = dc->getName();
  CHECK(y.size() == 103);
}
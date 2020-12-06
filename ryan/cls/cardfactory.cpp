#include "../main.h"

/* class CardFactory
{
private:
  CardFactory(const CardFactory &); // Prevent usage by making private.
  ~CardFactory();
  Deck *deck;

  // The static CardFactory instance:
  static CardFactory *c;

public:
  CardFactory();
  static CardFactory *getFactory();
  Deck getDeck();
}; */

// Initialize internal variables.
CardFactory *CardFactory::internal = new CardFactory();
Deck *CardFactory::deck = new Deck();

CardFactory::CardFactory()
{
}

CardFactory::~CardFactory()
{
}

CardFactory *CardFactory::getFactory()
{
  // Return the static card factory.
  return CardFactory::internal;
}

Deck CardFactory::getDeck()
{
  return *deck;
}

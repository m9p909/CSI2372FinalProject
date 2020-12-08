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

// Helper method to add cards
template <typename T>
void addCardsToDeck(Deck *d, int number, T card)
{
  for (int i = 0; i < number; i++)
    (*d).push_back(new T());
}

// Initialize internal variables.
CardFactory *CardFactory::internal = new CardFactory();
Deck *CardFactory::deck = nullptr;

CardFactory::CardFactory()
{
  delete deck; // There can only be one primary deck/factory.
  deck = new Deck();
  addCardsToDeck(deck, BLUE_CARDS, Blue());
  addCardsToDeck(deck, CHILI_CARDS, Chili());
  addCardsToDeck(deck, STINK_CARDS, Stink());
  addCardsToDeck(deck, GREEN_CARDS, Green());
  addCardsToDeck(deck, SOY_CARDS, Soy());
  addCardsToDeck(deck, BLACK_CARDS, Black());
  addCardsToDeck(deck, RED_CARDS, Red());
  addCardsToDeck(deck, GARDEN_CARDS, Garden());
}

CardFactory *CardFactory::getFactory()
{
  // Return the static card factory.
  return CardFactory::internal;
}

// Shuffle and return a copy of the deck. Does NOT shuffle internal deck.
Deck CardFactory::getDeck()
{
  // Copy vectors with assignment operator.
  Deck deckCopy = *deck;
  shuffle(begin(deckCopy), end(deckCopy), default_random_engine(chrono::system_clock::now().time_since_epoch().count()));
  return deckCopy;
}

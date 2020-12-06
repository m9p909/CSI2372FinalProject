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

template <typename T>
void addCardsToDeck(Deck *d, int number, T card)
{
  cout << "Adding cards to deck." << endl;
  for (int i = 0; i < number; i++)
    (*d).push_back(new T());
}

// Initialize internal variables.
CardFactory *CardFactory::internal = new CardFactory();
Deck *CardFactory::deck = nullptr;

CardFactory::CardFactory()
{
  cout << "Instantiating CardFactory..." << endl;
  deck = new Deck();
  cout << "Deck check is fine..." << endl;
  if ((*deck).empty())
  {
    cout << "Making deck..." << endl;
    addCardsToDeck(deck, BLUE_CARDS, Blue());
    addCardsToDeck(deck, CHILI_CARDS, Chili());
    addCardsToDeck(deck, STINK_CARDS, Stink());
    addCardsToDeck(deck, GREEN_CARDS, Green());
    addCardsToDeck(deck, SOY_CARDS, Soy());
    addCardsToDeck(deck, BLACK_CARDS, Black());
    addCardsToDeck(deck, RED_CARDS, Red());
    addCardsToDeck(deck, GARDEN_CARDS, Garden());
  }

  int deck_size = (*deck).size();
  cout << "Created deck of " << deck_size << " cards: ";
  for (int i = 0; i < deck_size; i++)
  {
    if (i != 0)
      cout << ", ";
    (*deck).at(i)->print(cout);
  }
  cout << endl;
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

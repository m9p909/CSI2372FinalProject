#include "../main.h"

// Reconstructs the deck from a file.
Deck::Deck(istream &, const CardFactory *)
{
  // TODO: Implement. Requires the card factory class.
  cerr << "Unimplemented" << endl;
}

// Returns and removes the top card from the deck.
Card *Deck::draw()
{
  if (empty())
    return nullptr;

  // If the deck is not empty, send the last card.
  Card *x = back();
  pop_back();
  return x;
}

#include "../main.h"

// Simple constructor makes it easy to instantiate.
Deck::Deck()
{
}

// Reconstructs the deck from a file.
Deck::Deck(istream &, const CardFactory *)
{
  // TODO: Implement. Requires the card factory class.
  throw Unimplemented();
}

// Returns and removes the top card from the deck.
Card *Deck::draw()
{
  if (empty())
    throw DeckEmpty();

  // If the deck is not empty, send the last card.
  Card *x = back();
  pop_back();
  return x;
}

// Prints the content of the deck. Debugging function.
void Deck::status()
{
  if (!empty())
  {
    const int deck_size = size();
    cout << "Deck consists of " << deck_size << " cards. Content: ";
    for (int i = 0; i < deck_size; i++)
    {
      if (i != 0)
        cout << ", ";
      at(i)->print(cout);
    }
    cout << endl;
    {
    }
  }
  else
    cout << "Deck is empty.";
}

void Deck::print(ostream &out)
{
  if (!empty())
  {
    int length = size();
    for (int i = 0; i < length; i++)
      out << (i == 0 ? "" : " ") << at(i);
    out << endl;
  }
}

ostream &operator<<(ostream &out, Deck &deck)
{
  deck.print(out);
  return out;
}

ostream &operator<<(ostream &out, Deck *deck)
{
  deck->print(out);
  return out;
}
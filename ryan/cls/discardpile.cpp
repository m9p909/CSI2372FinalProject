#include "../main.h"

// Reconstructs the deck from a file.
DiscardPile::DiscardPile(istream &, const CardFactory *)
{
  // TODO: Implement. Requires the card factory class.
  throw Unimplemented();
}

DiscardPile &DiscardPile::operator+=(Card *c)
{
  push_back(c);
  return *this;
}

// Returns and removes the top card from the deck.
Card *DiscardPile::top()
{
  if (empty())
    return nullptr;

  Card *x = back();
  return x;
}

// Returns and removes the top card from the deck.
Card *DiscardPile::pickUp()
{
  if (empty())
    return nullptr;

  Card *x = back();
  pop_back();
  return x;
}

void DiscardPile::print(ostream &out)
{
  if (!empty())
  {
    for (long unsigned int i = 0; i < size(); i++)
      out << at(i);
    out << endl;
  }
}

ostream &operator<<(ostream &out, DiscardPile &pile)
{
  if (!pile.empty())
    out << pile.back();
  return out;
}

ostream &operator<<(ostream &out, DiscardPile *pile)
{
  if (!pile->empty())
    out << pile->back();
  return out;
}
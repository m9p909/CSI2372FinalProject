#include "../main.h"

// Reconstructs the deck from a file.
Hand::Hand(istream &, const CardFactory *)
{
  // TODO: Implement. Requires the card factory class.
  throw Unimplemented();
}

Hand &Hand::operator+=(Card *c)
{
  push_back(c);
  return *this;
}

// Returns but does not remove the top card from the deck.
Card *Hand::top()
{
  if (empty())
    return nullptr;

  Card *x = back();
  return x;
}

// Returns and removes the top card from the deck.
Card *Hand::play()
{
  if (empty())
    return nullptr;

  Card *x = back();
  pop_back();
  return x;
}

Card *Hand::operator[](int position)
{
  // Return a nullptr if position is invalid.
  if (position < 0)
    return nullptr;
  if (empty())
    return nullptr;
  if (static_cast<long unsigned int>(position) >= size())
    return nullptr;

  // Finally, if all requirements are satisfied, remove and return the card.
  Card *returnedCard = at(position);
  erase(begin() + position);
  return returnedCard;
}

void Hand::print(ostream &out)
{
  if (!empty())
    for (long unsigned int i = 0; i < size(); i++)
      out << at(i);
}

ostream &operator<<(ostream &out, Hand &hand)
{
  hand.print(out);
  return out;
}

ostream &operator<<(ostream &out, Hand *hand)
{
  hand->print(out);
  return out;
}
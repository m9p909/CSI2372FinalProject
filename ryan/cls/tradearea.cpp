#include "../main.h"

/**
 * TradeArea implementation.
 */

TradeArea::TradeArea(istream &in, const CardFactory *cf)
{
    throw Unimplemented();
}

TradeArea &TradeArea::operator+=(Card *c)
{
    push_back(c);
    return *this;
}

bool TradeArea::legal(Card *newCard)
{
    const string newCardName = newCard->getName();

    // Iterate through the cards in the trade area, and if a match is found, return true.
    for (list<Card *>::iterator it = this->begin(); it != this->end(); ++it)
        if ((*it)->getName() == newCardName)
            return true;

    // Otherwise, return false.
    return false;
}

// Removes a card (referenced by name) from the trade-area and returns a pointer to it.
Card *TradeArea::trade(string removeCardName)
{
    // Iterate through the cards in the trade area, and if a match is found, return true.
    for (list<Card *>::iterator it = this->begin(); it != this->end(); ++it)
    {
        if ((*it)->getName() == removeCardName)
        {
            remove(*it);
            return *it;
        }
    }

    // If the card is not found, raise an exception.
    throw CardNotFound();
}

int TradeArea::numCards()
{
    return size();
}

// Printing Methods
void TradeArea::print(ostream &) {}

ostream &operator<<(ostream &out, TradeArea &ta)
{
    return out;
}

ostream &operator<<(ostream &out, TradeArea *ta)
{
    return out;
}

// Additional Methods

// Discards all cards in the trade area into the discard pile.
void TradeArea::discardAll(DiscardPile &discard)
{
    // Add every card to the discard pile
    for (list<Card *>::iterator it = this->begin(); it != this->end(); ++it)
        discard += *it;

    // Clear the list
    clear();
}
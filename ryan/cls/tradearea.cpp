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

Card *TradeArea::trade(string)
{
    return new Stink();
}

int TradeArea::numCards()
{
    return 0;
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

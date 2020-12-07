#include "../main.h"

/**
 * TradeArea ipmlementation.
 */

TradeArea::TradeArea(istream &in, const CardFactory *cf)
{
    throw Unimplemented();
}

bool TradeArea::legal(Card *)
{
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

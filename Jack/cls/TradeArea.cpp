#include "../main.h";

TradeArea::TradeArea(istream &out, const CardFactory *) {
  // not sure what to do here
}

TradeArea::TradeArea() {
  
}

TradeArea &TradeArea::operator+=(Card *card) { cards.push_back(card); }
bool TradeArea::legal(Card *card) {

  for (const auto value : cards) {
    if (value->getName() == card->getName()) {
      return false;
    }

    return true;
  }
}

void TradeArea::discardAll(DiscardPile &discard){
  for(auto card : cards){
    discard.push_back(card);
  }
  for(auto card : cards){
    cards.pop_back();
  }

}

Card *TradeArea::trade(string cardName) {
  Card *card;

  for (int i = 0; i < cards.size(); i++) {
    card = cards[i];
    if (cardName == card->getName()) {
      cards.erase(cards.begin() + i);
      return card;
    }
  }
}

int TradeArea::numCards() { return cards.size(); }

ostream &operator<<(ostream &out, const TradeArea &area) {
  for (const auto value : area.cards) {
    cout << value << ' ';
  }
}
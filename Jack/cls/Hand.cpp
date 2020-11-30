#include "../main.h"

Hand::Hand(istream &, const CardFactory *){

};
Hand &Hand::operator+=(Card *c) { cards.push_back(c); };
Card *Hand::play() {
  Card *output = cards.front();
  cards.erase(cards.begin());
  return output;
};
Card *Hand::top() { return cards.front(); };
Card *Hand::operator[](int index) {
  Card *output = cards[index];
  cards.erase(cards.begin() + index);
  return output;
};

ostream &operator<<(ostream &out, const Hand &hand) {
  out << "Hand:\t";
  for (const auto &value : hand.cards) {
    out << value;
  }
  return out;
};
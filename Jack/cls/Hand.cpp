#include "../main.h"

Hand::Hand(istream &, const CardFactory *){

};

Hand::Hand() = default;

Hand *Hand::operator+=(Card *c) { cards.push_back(c); };

Card *Hand::play() {
  Card *output = cards.back();
  cards.pop_back();
  return output;
};

Card *Hand::top() { return cards.back(); };

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
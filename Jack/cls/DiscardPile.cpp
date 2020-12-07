#include "../main.h"

DiscardPile::DiscardPile(istream &input, const CardFactory *facto) {
  factory = facto;
  stream = &input;
}

DiscardPile::DiscardPile(){
  factory = factory->getFactory();
}

DiscardPile &DiscardPile::operator+=(Card *card) { this->push_back(card); };
Card *DiscardPile::pickUp() {
  Card * output = this->back();
    pop_back();
  return output;
}



Card *DiscardPile::top() { return this->back(); }
void DiscardPile::print(std::ostream &stream) {
  for (const auto &value : *this) {
    stream << value << " ";
  }
  stream << "\n";
}

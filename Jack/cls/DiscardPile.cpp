#include "../main.h"

DiscardPile::DiscardPile(istream &input, const CardFactory *facto) {
  factory = facto;
  stream = &input;
}

DiscardPile::DiscardPile(){
  factory = factory->getFactory();
}

DiscardPile &DiscardPile::operator+=(Card *card) { this->push_back(card); }
Card *DiscardPile::pickUp() {
  Card *output = this->front();
  this->erase(this->begin()); // not sure if this erases the output variable,
                              // might need to deep copy
  return output;
}



Card *DiscardPile::top() { return this->front(); }
void DiscardPile::print(std::ostream &stream) {
  for (const auto &value : *this) {
    stream << value << " ";
  }
  stream << "\n";
}

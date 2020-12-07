#include "../main.h"

CardFactory *CardFactory::factory = nullptr;

CardFactory::CardFactory() = default;

CardFactory *CardFactory::getFactory() {

  if (!CardFactory::factory) {
    CardFactory::factory = new CardFactory();
    return CardFactory::factory;
  } else {
    return CardFactory::factory;
  }
}

CardFactory *CardFactory::resetFactory() {

  CardFactory::factory = new CardFactory();
  return CardFactory::factory;
}

Deck *CardFactory::getDeck() {
  shuffle(deck.begin(), deck.end(), default_random_engine(123));
  return &this->deck;
}
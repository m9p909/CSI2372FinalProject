#include "../main.h"

CardFactory * CardFactory::factory = nullptr;

CardFactory::CardFactory() {

  Card *card;

  for (int i = 0; i < 20; i++) {
    card = new Blue();
    deck.push_back(card);
  }
  for (int i = 0; i < 18; i++) {
    card = new Chili();
    deck.push_back(card);
  }
  for (int i = 0; i < 16; i++) {
    card = new Stink();
    deck.push_back(card);
  }
  for (int i = 0; i < 14; i++) {
    card = new Green();
    deck.push_back(card);
  }
  for (int i = 0; i < 12; i++) {
    card = new Soy();
    deck.push_back(card);
  }
  for (int i = 0; i < 10; i++) {
    card = new Black();
    deck.push_back(card);
  }
  for (int i = 0; i < 8; i++) {
    card = new Red();
    deck.push_back(card);
  }
  for (int i = 0; i < 6; i++) {
    card = new Garden();
    deck.push_back(card);
  }
}

CardFactory *CardFactory::getFactory(){
     
    if(!CardFactory::factory){
        CardFactory::factory= new CardFactory();
        return CardFactory::factory;
    } else{
        return CardFactory::factory;
    }
 }

vector<Card *> CardFactory::getDeck() {

  return this->deck;
 
}
#include "../main.h"

Deck::Deck(istream &a,  CardFactory *factory) {
    this->stream = &a;
    Deck* deckunshuffled = factory->getDeck();
    
    for(int i = 0; i < deckunshuffled->size(); i++){
        
        push_back(deckunshuffled->operator[](i));
    }
    
    
    
  shuffle(this->begin(), this->end(), default_random_engine(123));
}

Deck::Deck() {
    
  Card *card;

  for (int i = 0; i < 20; i++) {
    card = new Blue();
    push_back(card);
  }
  for (int i = 0; i < 18; i++) {
    card = new Chili();
    push_back(card);
  }
  for (int i = 0; i < 16; i++) {
    card = new Stink();
    push_back(card);
  }
  for (int i = 0; i < 14; i++) {
    card = new Green();
    push_back(card);
  }
  for (int i = 0; i < 12; i++) {
    card = new Soy();
    push_back(card);
  }
  for (int i = 0; i < 10; i++) {
    card = new Black();
    push_back(card);
  }
  for (int i = 0; i < 8; i++) {
    card = new Red();
    push_back(card);
  }
  for (int i = 0; i < 6; i++) {
    card = new Garden();
    push_back(card);
  }
  
}

Card *Deck::draw() {
  Card *output = this->front();
  this->erase(this->begin()); // not sure if this erases the output variable,
                              // might need to deep copy
  return output;
}

ostream &operator<<(ostream &out, const Deck &chain) {}

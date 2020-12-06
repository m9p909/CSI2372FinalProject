#include "../main.h"

Deck::Deck(istream &a,  CardFactory *factory) {
    this->stream = &a;
    vector<Card *> deckunshuffled = factory->getDeck();
    
    for(int i = 0; i < deckunshuffled.size(); i++){
        
        push_back(deckunshuffled[i]);
    }
    
    
    
  shuffle(this->begin(), this->end(), default_random_engine(123));
}

Deck::Deck() {
    CardFactory* factory = factory->getFactory();
    
    vector<Card *> deckunshuffled = factory->getDeck();
    
    for(int i = 0; i < deckunshuffled.size(); i++){
        
        push_back(deckunshuffled[i]);
    }
    
    
    
  shuffle(this->begin(), this->end(), default_random_engine(123));
}

Card *Deck::draw() {
  Card *output = this->front();
  this->erase(this->begin()); // not sure if this erases the output variable,
                              // might need to deep copy
  return output;
}

ostream &operator<<(ostream &out, const Deck &chain) {}

#include "globalHeader.h"
#include "./Cards/Cards.cpp"
#include "./CardFactory.cpp"
class Deck: public vector<Card>{
    
    Deck(istream&, const CardFactory*);
    Card* draw(){
        Card* output = &this->front();
        this->erase(this->begin()); //not sure if this erases the output variable, might need to deep copy
        return output;
    }

    friend ostream & operator << (ostream &out, const Deck &chain){
        
        
    }
};
#include "../main.h"


    
    Deck::Deck(istream&, const CardFactory*){

    }

    Card* Deck::draw(){
        Card* output = this->front();
        this->erase(this->begin()); //not sure if this erases the output variable, might need to deep copy
        return output;
    }

    ostream & operator << (ostream &out, const Deck &chain){
        
        
    }

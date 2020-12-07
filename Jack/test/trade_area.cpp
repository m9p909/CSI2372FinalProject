#include "../main.h"
#include "doctest.h"

TEST_CASE("trade area"){
   
    TradeArea* trade = new TradeArea();
    DiscardPile *discard = new DiscardPile;
    CHECK(trade->numCards() == 0);
    trade->cards.push_back(new Blue);
    trade->cards.push_back(new Stink);
    trade->cards.push_back(new Garden);
    CHECK(trade->numCards() == 3);
    
    //check legal function
    CHECK(trade->legal(new Stink) == true);
    CHECK(trade->legal(new Black) == true);
    //check discard pile
    trade->discardAll(*discard);
    int bluecards = 0;
    int stinkcards = 0;
    int gardencards = 0;
    int othercards = 0;
    for(auto card : *discard){
        if(card->getName() == "Blue"){
            bluecards++;
        } else if(card->getName() == "Stink"){
            stinkcards++;
        } else if(card->getName() == "Garden" ){
            gardencards++;
        }
        
    }
    CHECK(bluecards == 1);
    CHECK(stinkcards == 1);
    CHECK(gardencards == 1);
    CHECK(othercards == 0);
    CHECK(trade->numCards() == 0);

    
   
    
    

}


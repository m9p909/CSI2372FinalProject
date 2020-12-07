#include "../main.h"
#include "doctest.h"


TEST_CASE("Discard pile test"){
    DiscardPile discardpile;
    discardpile += new Garden();
    for(int i = 0;i < 3; i++){
        discardpile += new Stink();
    }
    
    CHECK(discardpile.top()->getName() == "Stink");

    CHECK(discardpile.pickUp()->getName() == "Stink");
    discardpile.pickUp();
    discardpile.pickUp();
    CHECK(discardpile.pickUp()->getName() == "Garden");
    
    
    //needs test for print

}
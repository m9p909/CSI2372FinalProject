#include "doctest.h"
#include "../main.h"



TEST_CASE("cardfactory test"){
    CardFactory *factory = CardFactory::resetFactory();
    Deck *deck  = factory->getDeck();
    CHECK(deck->size() == 104);
    int gardenCards = 0;
    for(int i = 0; i < deck->size(); i++){
        if(deck->operator[](i)->getName() == "Garden"){
            gardenCards++;
        }
    }
    CHECK(gardenCards == 6);

    Card* card1 = deck->operator[](0);
    Card* card2 = deck->operator[](1);
    Card* card3 = deck->operator[](2);
    //check if shuffled
    bool isShuffled = card1->getName() != card2->getName() || card3->getName() != card1->getName(); 
    CHECK(isShuffled);





    

}
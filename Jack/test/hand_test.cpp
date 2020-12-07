#include "../main.h"
#include "doctest.h"

TEST_CASE("testing the Hand class"){
    Hand hand;

    hand += new Blue();
    hand += new Red();
    hand  += new Stink();
    CHECK(hand.cards.size() == 3);
    CHECK(hand.top()->getName() == "Stink");
    CHECK(hand.play()->getName() == "Stink");
    CHECK(hand.top()->getName() == "Red");

    CHECK(hand[0]->getName() == "Blue");
    CHECK(hand.cards.size() == 1);
}
#include "../main.h"
#include "doctest.h"

TEST_CASE("Play Card")
{
    Table *table = new Table("Spaghetti", "MacandCHeese");
    auto player1 = table->player1;
    auto player2 = table->player2;
    auto deck = table->deck;
    // auto tradeArea = table->tradeArea;
    for (int i = 0; i < 5; i++)
    {
        player1->hand->push_back(new Blue());
        player2->hand->push_back(new Red);
    }

    playCard(player1, player1->chains);

    CHECK(true == true);
    CHECK(player1->chains->at(0)->getExampleItem()->getName() == "Blue");
    CHECK(player1->chains[0][0]->getSize() == 1);
}

TEST_CASE("Make New Chain")
{
    Stink *x = new Stink();
    Chain_Base *b = makeNewChain(x);
    b->operator+=(x);
    CHECK(b->getSize() == 1);
}
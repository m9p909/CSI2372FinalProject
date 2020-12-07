#include "../main.h"
#include "doctest.h"

TEST_CASE("Table Test"){
    string player1name = "Jack";
    string player2Name = "Ryan";
    Table *table = new Table(player1name,player2Name);
    string winString;
    CHECK(table->win(winString) == false);
    table->player2->operator+=(3);
    CHECK(table->player2->getNumCoins() == 3);
    for(auto card : *table->deck){
        table->deck->pop_back();
    }
    CHECK(table->win(winString) == true);
    CHECK(winString == player2Name);
    CHECK(winString == player2Name);



}
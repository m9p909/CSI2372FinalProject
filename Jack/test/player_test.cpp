#include "../main.h"
#include "doctest.h"

TEST_CASE("Player"){
    string playername = "Jack";
    Player* player = new Player(playername);
    CHECK(player->getName() == "Jack");
    CHECK(player->getNumCoins() == 0);
    CHECK(player->getNumChains() == 0);
    CHECK(player->getMaxNumChains() == 2);
    player->operator+=(3);
    CHECK(player->getNumCoins() == 3);
    player->buyThirdChain();
    CHECK(player->getNumCoins() == 0);
    
    
    CHECK(player->getMaxNumChains() == 3);


}
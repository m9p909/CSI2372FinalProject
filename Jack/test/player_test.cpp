#include "../main.h"
#include "doctest.h"
#include <ostream>

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
    Chain_Base * chain = new Chain<Red>();
    chain->operator+=(new Red);
    chain->operator+=(new Red);
    player ->addChain(chain);

    string line;
    stringstream out;
    //out << player;
    player->print(out);
    getline(out, line);
    CHECK(line == "Jack\t0 coins");
    getline(out, line);
    CHECK(line == "Red\tR R");

    
    
    


}
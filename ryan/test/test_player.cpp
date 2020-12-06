#include "../main.h"
#include "doctest.h"

TEST_CASE("Instantiate Player")
{
  Player();
  string name = "Ryan";
  Player *y = new Player(name);
  delete y;
}

TEST_CASE("Player getName()")
{
  string name = "Ryan";
  Player p = Player(name);
  CHECK(p.getName() == name);
}

TEST_CASE("Player getNumCoins()")
{
  string name = "Bob";
  Player p = Player(name);
  CHECK(p.getNumCoins() == 0);
}

TEST_CASE("Player getNumChains()")
{
  string name = "Bob";
  Player p = Player(name);
  CHECK(p.getNumChains() == 0);
}

TEST_CASE("Player += int")
{
  string name = "Bob";
  Player p = Player(name);
  p += 5;
  p += 10;
  CHECK(p.getNumCoins() == 15);
}
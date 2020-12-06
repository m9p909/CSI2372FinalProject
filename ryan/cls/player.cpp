#include "../main.h"

Player::Player()
{
  chains = new vector<Chain_Base *>();
}

Player::~Player()
{
  delete chains;
}

Player::Player(string &playerName)
{
  chains = new vector<Chain_Base *>();
  name = playerName;
}

Player::Player(istream &, const CardFactory *)
{
  throw Unimplemented();
}

string Player::getName()
{
  return name;
}

int Player::getNumCoins()
{
  return 0;
}

Player &Player::operator+=(int)
{
  return *this;
}

int Player::getMaxNumChains()
{
  return 0;
}

int Player::getNumChains()
{
  return 0;
}

Chain_Base &Player::operator[](int i)
{
  Chain<Stink> *x = new Chain<Stink>();
  return (*x);
}

void buyThirdChain()
{
  return;
}

void printHand(std::ostream &, bool)
{
  return;
}

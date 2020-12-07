#include "../main.h"

Player::Player() : coins(0), maxNumChains(2)
{
  chains = new vector<Chain_Base *>();
  name = "Anonymous";
}

Player::Player(string &playerName) : coins(0), maxNumChains(2)
{
  chains = new vector<Chain_Base *>();
  name = playerName;
}

Player::~Player()
{
  delete chains;
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
  return coins;
}

// Adds coins to the player.
Player &Player::operator+=(int newCoins)
{
  coins += newCoins;
  return *this;
}

int Player::getMaxNumChains()
{
  return 0;
}

int Player::getNumChains()
{
  return chains->size();
}

Chain_Base &Player::operator[](int i)
{
  Chain<Stink> *x = new Chain<Stink>();
  return (*x);
}

void Player::buyThirdChain()
{
  return;
}

void Player::printHand(std::ostream &, bool)
{
  return;
}

void Player::addChain(Chain_Base *newChain)
{
  return;
}
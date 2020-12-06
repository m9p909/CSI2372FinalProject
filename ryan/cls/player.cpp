#include "../main.h"

Player::Player()
{
  chains = new vector<Chain_Base *>();
  name = "Anonymous";
  coins = 0;
}

Player::Player(string &playerName)
{
  chains = new vector<Chain_Base *>();
  name = playerName;
  coins = 0;
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
  cout << "Adding " << newCoins << " to player." << endl;
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

void buyThirdChain()
{
  return;
}

void printHand(std::ostream &, bool)
{
  return;
}

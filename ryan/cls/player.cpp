#include "../main.h"

Player::Player() : coins(0), maxNumChains(2)
{
  chains = new vector<Chain_Base *>();
  hand = new Hand();
  name = "Anonymous";
}

Player::Player(string &playerName) : coins(0), maxNumChains(2)
{
  chains = new vector<Chain_Base *>();
  hand = new Hand();
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
  return maxNumChains;
}

int Player::getNumChains()
{
  return chains->size();
}

Chain_Base &Player::operator[](int i)
{
  if (!chains->empty() && static_cast<long unsigned int>(i) < chains->size())
    return *chains->at(i);

  // If the above doesn't return a chain, raise an exception.
  throw ChainAtIndexNotFound();
}

void Player::buyThirdChain()
{
  if (coins >= 3 && maxNumChains == 2)
  {
    coins -= 3;
    maxNumChains = 3;
  }
  else
    throw PlayerChainsFull();
}

void Player::addChain(Chain_Base *newChain)
{
  if (chains->size() < static_cast<unsigned long int>(maxNumChains))
    chains->push_back(newChain);
  else
    throw PlayerChainsFull();
}

void Player::printHand(std::ostream &out, bool wholeHand)
{
  if (!hand->empty())
  {
    if (wholeHand)
      out << hand;
    else
      out << hand->back();
  }
}

void Player::print(std::ostream &out)
{
  out << name << "   " << coins << " coins" << endl;
  if (!chains->empty())
  {
    for (long unsigned int i = 0; i < chains->size(); i++)
    {
      out << *chains->at(i) << endl;
    }
  }
}

ostream &
operator<<(ostream &out, Player &player)
{
  player.print(out);
  return out;
}

ostream &operator<<(ostream &out, Player *player)
{
  player->print(out);
  return out;
}
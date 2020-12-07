#include "../main.h";

Player::Player(std::string &name) { playerName = name;
numCoins = 0; }

Player::Player(istream &, const CardFactory *) {
  // do stuff to import from somewhere else
}

string Player::getName() { return playerName; }

int Player::getNumCoins() { return numCoins; }

Player &Player::operator+=(int coin) {
  numCoins += coin;
  return *this;
}

int Player::getMaxNumChains() {
  return numChains; // I have no idea what this is supposed to do
}

int Player::getNumChains() { return chains.size(); }

Chain_Base &Player::operator[](int i) { return chains[i]; }

void Player::buyThirdChain() {
  if (numCoins >= 3) {
    numCoins -= 3;
    numChains++;
  } else {
    throw new NotEnoughCoins;
  }
}

void Player::printHand(std::ostream &out, bool printEntireHand) {
  if (printEntireHand) {
    out << hand;
  } else {
    out << hand->top();
  }
}

ostream &operator<<(ostream &out, const Player &player) {

  out << player.playerName << "\t";
  out << player.numCoins << " "
      << "coins\n";
  for (auto &value : player.chains) {
    out << value;
  }
  return out;
}
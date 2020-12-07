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

Chain_Base* &Player::operator[](int i) { return chains[i]; }

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
//adds a chain to the player list of chains
void Player::addChain(Chain_Base* chain){
  chains.push_back(chain);
}
ostream &Player::print(ostream &out ) const{
    out << playerName << "\t";
  out << numCoins << " "
      << "coins\n";
  for (auto &value : chains) {
    value->print(out);
  }
  return out;
  
}

ostream &operator<<(ostream &out, const Player &player) {

  player.print(out);
  return out;
}
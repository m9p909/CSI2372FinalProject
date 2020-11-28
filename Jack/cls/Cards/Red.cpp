#include "../../globalHeader.h"

int Red::getCardsPerCoin(int coins) {
  if (coins == 0) {
    return 0;
  } else if (coins == 1) {
    return 2;
  } else if (coins == 2) {
    return 3;
  } else if (coins == 3) {
    return 4;
  } else if (coins == 4) {
    return 5;
  }
  return -1;
}
string Red::getName() { return "Red"; }

void Red::print(ostream &out) { out << "R"; }

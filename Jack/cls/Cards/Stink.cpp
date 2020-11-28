#include "../../main.h"

int Stink::getCardsPerCoin(int coins) {
  if (coins == 0) {
    return 0;
  } else if (coins == 1) {
    return 3;
  } else if (coins == 2) {
    return 5;
  } else if (coins == 3) {
    return 7;
  } else if (coins == 4) {
    return 8;
  }
  return -1;
}
string Stink::getName() { return "Stink"; }

void Stink::print(ostream &out) { out << "S"; }

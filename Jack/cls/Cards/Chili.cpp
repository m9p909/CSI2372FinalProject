#include "../../globalHeader.h"

int Chili::getCardsPerCoin(int coins) {
  if (coins == 0) {
    return 0;
  } else if (coins == 1) {
    return 3;
  } else if (coins == 2) {
    return 6;
  } else if (coins == 3) {
    return 8;
  } else if (coins == 4) {
    return 9;
  }
  return -1;
}
string Chili::getName() { return "Chili"; }

void Chili::print(ostream &out) { out << "C"; }
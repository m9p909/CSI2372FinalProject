#include "../../globalHeader.h"

int Soy::getCardsPerCoin(int coins) {
  if (coins == 0) {
    return 0;
  } else if (coins == 1) {
    return 2;
  } else if (coins == 2) {
    return 4;
  } else if (coins == 3) {
    return 6;
  } else if (coins == 4) {
    return 7;
  }
  return -1;
}
string Soy::getName() { return "Soy"; }

void Soy::print(ostream &out) { out << "s"; }

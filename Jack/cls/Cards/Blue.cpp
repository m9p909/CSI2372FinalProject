#include "../../main.h"

int Blue::getCardsPerCoin(int coins) {
  if (coins == 0) {
    return 0;
  } else {
    return 2 + 2 * coins;
  }
}
string Blue::getName() { return "Blue"; }

void Blue::print(ostream &out) { out << "B"; }

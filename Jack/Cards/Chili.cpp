#include "./Card.cpp";
class Chili : public Card {
  int getCardsPerCoin(int coins) {
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
  string getName() { return "Chili"; }

  void print(ostream &out) { out << "C"; }
};
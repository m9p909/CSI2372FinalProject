#include "./Card.cpp";
class Garden : public Card {
  int getCardsPerCoin(int coins) {
    if (coins == 0) {
      return 0;
    } else if (coins == 1) {
      return 0;
    } else if (coins == 2) {
      return 2;
    } else if (coins == 3) {
      return 3;
    } else if (coins == 4) {
      return 0;
    }
    return -1;
  }
  string getName() { return "Garden"; }

  void print(ostream &out) { out << "g"; }
};
#include "./Card.cpp";
class Green : public Card {
  int getCardsPerCoin(int coins) {
    if (coins == 0) {
      return 0;
    } else if (coins == 1) {
      return 3;
    } else if (coins == 2) {
      return 5;
    } else if (coins == 3) {
      return 6;
    } else if (coins == 4) {
      return 7;
    }
    return -1;
  }
  string getName() { return "Green"; }

  void print(ostream &out) { out << "G"; }
};
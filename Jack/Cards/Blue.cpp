#include "./Card.cpp";
class Blue : public Card {
  int getCardsPerCoin(int coins) {
    if (coins == 0) {
      return 0;
    } else {
      return 2 + 2 * coins;
    }
  }
  string getName() { return "Blue"; }

  void print(ostream &out) { out << "B"; }
};
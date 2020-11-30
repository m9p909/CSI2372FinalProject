#include "../main.h"

Table::Table(istream &i, const CardFactory *factory){

    // no idea what to do
};

bool Table::win(std::string &str) {
  if (deck->empty()) {
    if (player1->getNumCoins() > player2->getNumCoins()) {
      str = player1->getName();
    } else {
      str = player2->getName();
    }
    return true;
  } else {
    return false;
  }
};

ostream &operator<<(ostream &out, const Table &table) {

  out << table.player1;
  out << table.player2;
  out << table.deck;
  out << table.discardPile;
};
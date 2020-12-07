#include "../main.h"
#include "../main.h"

Table::Table(istream &i, const CardFactory *factory){

    // no idea what to do
};

Table::Table(string player1Name, string player2Name)
{
  player1 = new Player(player1Name);
  player2 = new Player(player2Name);
  CardFactory *factory = factory->getFactory();
  deck = (factory->getDeck());
  discardPile = new DiscardPile();
  tradeArea = new TradeArea();
}

bool Table::win(std::string &str)
{
  if (deck.empty())
  {
    if (player1->getNumCoins() > player2->getNumCoins())
    {
      str = player1->getName();
    }
    else
    {
      str = player2->getName();
    }
    return true;
  }
  return false;
};

ostream &operator<<(ostream &out, const Table &table)
{
  out << table.player1;
  out << table.player2;
  // out << table.deck;
  out << table.discardPile;
  return out;
};
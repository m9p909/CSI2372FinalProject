#include "../main.h"
#include "../main.h"

Table::Table(istream &i, const CardFactory *factory)
{
  throw Unimplemented();
}

// Instantiate a new table with players Player1 and Player2.
Table::Table(string player1Name, string player2Name)
{
  // Set up new players.
  player1 = new Player(player1Name);
  player2 = new Player(player2Name);

  // Get the CardFactory from the Factory.
  CardFactory *factory = factory->getFactory();

  // Grab and store a new Deck from the factory.
  Deck internal = (factory->getDeck());
  deck = &internal;

  // Create a new DiscardPile and TradeArea
  discardPile = new DiscardPile();
  tradeArea = new TradeArea();
}

bool Table::win(std::string &str)
{
  if (deck->empty())
  {
    if (player1->getNumCoins() > player2->getNumCoins())
      str = player1->getName();
    else
      str = player2->getName();

    return true;
  }
  return false;
};

void Table::print(ostream &out)
{
  out << player1;
  out << player2;
  out << deck;
  out << discardPile;
}

ostream &operator<<(ostream &out, Table &table)
{
  table.print(out);
  return out;
};

ostream &operator<<(ostream &out, Table *table)
{
  table->print(out);
  return out;
};
#include "../main.h"
#include "../main.h"

Table::Table(istream &i, const CardFactory *factory)
{
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
  deck = (factory->getDeck());

  // Create a new DiscardPile and TradeArea
  discardPile = new DiscardPile();
  tradeArea = new TradeArea();
}

// Returns true and adds the player name to the given string if they won.
bool Table::win(string &str)
{
  if (deck.empty())
  {
    if (player1->getNumCoins() > player2->getNumCoins())
      str = player1->getName();
    else
      str = player2->getName();

    return true;
  }
  return false;
};

// Prints the contents of the table.
void Table::prettyPrint(ostream &out)
{
  out << player1;
  out << player2;

  out << "\nTrade Area:\t" << tradeArea;
  out << "\ndiscard Pile:\t" << discardPile;
}

// Prints the contents of the table.
void Table::print(ostream &out)
{
  // Print a file header so the file looks cool.
  out << TABLE_HEADER << endl;

  // Print Players
  out << PLAYERS_HEADER << endl;
  out << player1;
  out << player2;
  out << SECTION_END << endl;

  // Print Deck
  out << DECK_HEADER << endl;
  out << deck;
  out << SECTION_END << endl;

  // Print TradeArea
  out << TRADE_AREA_HEADER << endl;
  out << tradeArea;
  out << SECTION_END << endl;

  // Print Discard Pile
  out << DISCARD_PILE_HEADER << endl;
  out << discardPile;
  out << SECTION_END << endl;

  // End File
  out << FILE_END << endl;
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
#include "../main.h"

Chain_Base *makeNewChain(Card *card) {
  if (card->getName() == "Blue") {
    return new Chain<Blue>;
  } else if (card->getName() == "Black") {
    return new Chain<Black>;
  } else if (card->getName() == "Green") {
    return new Chain<Green>;
  } else if (card->getName() == "Stink") {
    return new Chain<Stink>;
  } else if (card->getName() == "Soy") {
    return new Chain<Soy>;
  } else if (card->getName() == "Red") {
    return new Chain<Red>;
  } else {
    return new Chain<Garden>;
  }
}

// adds card to chain, sells chains if necessary
void chainCard(Card *card, Player *currentPlayer,
               vector<Chain_Base *> *chains) {
  if (card == nullptr) {
    return;
  }

  Card *currentPlay = card;
  bool playable = false;
  // is there a chain for top card
  for (int i = 0; i < currentPlayer->getNumChains(); i++) {
    Chain_Base *currChain = currentPlayer->getChain(i);
    if (currChain->getExampleItem()->getName() == currentPlay->getName()) {
      playable = true;
      if (currChain->getSize() >= 4) {
        // sells curr chains if biggest chain is at max size
        currentPlayer += currChain->sell();
        // remove the chain

        chains->push_back(makeNewChain(currChain->getExampleItem()));
        currChain = chains->back();
        // erase the chain in question
        chains->erase(chains->begin() + i);
      }

      currChain->operator+=(currentPlay);
      playable = true;
      break;
    };
  }

  // auto sells the biggest chain if the card played can't play into any
  // chains
  if (playable == false) {
    int maxChainLength = 0;
    Chain_Base *maxChain;
    // if there are no chains add one
    if (currentPlayer->getNumChains() <= 0) {
      chains->push_back(makeNewChain(currentPlay));
      (*chains)[0]->operator+=(currentPlay);
      return;
    }
    // check if there is a chain that the card can be played on
    for (int i = 0; i < currentPlayer->getNumChains(); i++) {
      Chain_Base *currChain = currentPlayer->getChain(i);
      // chain length should never be greater than 4
      // finds largest chain
      if (currChain->getSize() > maxChainLength && currChain->getSize() <= 4) {
        maxChainLength = currChain->getSize();
        maxChain = currChain;
      }
    }

    // sells max chain, gives money to player
    currentPlayer->operator+=(maxChain->sell());
    // removes the card chain that was sold
    (void)remove(chains->begin(), chains->end(), maxChain);

    // add a new chain with the card
    chains->push_back(makeNewChain(currentPlay));
    chains->back()->operator+=(currentPlay);
  }
}

void playCard(Player *currentPlayer, vector<Chain_Base *> *chains) {
  Card *currentPlay =
      currentPlayer->hand->play(); // gets the top card in the hand
  chainCard(currentPlay, currentPlayer, chains); // adds the card to a chain
}

bool handContainsCard(Hand hand, string str, long unsigned &index) {
  for (long unsigned i = 0; i < hand.size(); i++) {
    if (hand[i]->getName() == str) {
      index = i;
      return true;
    }
  }
  return false;
}

bool topCardisInTradeArea(DiscardPile discardPile, TradeArea trade) {
  if (discardPile.empty()){
    return false;
  }
    

  for (auto card : trade) {
    if (discardPile.top()->getName() == card->getName()) {
      return true;
    }
  }
  return false;
}

void pauseGame() { throw new Unimplemented; }

void runGame(string player1, string player2, ostream &outputStream,
             istream &inputStream) {
  Table *table = new Table(player1, player2);
  string winner;
  string input = "";
  Player *currentPlayer;

  // Draw five cards for each player
  for (int i = 0; i < 5; i++) {
    table->player1->hand->push_back(table->deck.draw());
    table->player2->hand->push_back(table->deck.draw());
  }

  while (!table->win(winner)) {
    outputStream << "Would you like to pause (y/n)? \n";
    while (input != "y" && input != "n") {
      inputStream >> input;
      if (input == "y") {
        pauseGame();
      } else if (input == "n") {
        continue;
      }
    }
    input = "";
    // runs for each player's turn
    for (int i = 0; i < 2; i++) {

      if (i == 0) {
        currentPlayer = table->player1;
      } else {
        currentPlayer = table->player2;
      }
      outputStream << "It is " << currentPlayer->getName() << "'s turn";
      vector<Chain_Base *> *chains = currentPlayer->chains;
      outputStream << "\n";
      table->prettyPrint(outputStream);
      currentPlayer->hand->operator+=(table->deck.draw());

      if (table->tradeArea->numCards() >= 0) {
        outputStream <<endl<<"Trade Area: "<< table->tradeArea;
        outputStream
            << "\nWould you like to add the cards from the trade area to your "
               "chains(1) or discard them?(2)\n ";
        while (input != "1" && input != "2") {
          inputStream >> input;
        }
        // add to chains or discard cards
        if (input == "1") {
          // add cards from table to chains
          if((*chains).size() <= 0){
            outputStream <<"\nYou dont have any chains to add the cards to\n!";
            
            table->tradeArea->discardAll(*table->discardPile);
          }
          for (int i = 0; i < currentPlayer->getNumChains(); i++) {
            Chain_Base *chain = currentPlayer->getChain(i);

            if (table->tradeArea->legal(chain->getExampleItem())) {
              table->tradeArea->trade(chain->getExampleItem()->getName());

              if (chain->getSize() >= 4) {
                // sells curr chains if biggest chain is at max size
                currentPlayer += chain->sell();
                // remove the chain

                chains->push_back(makeNewChain(chain->getExampleItem()));
                chain = chains->back();
                // erase the chain in question
                chains->erase(chains->begin() + i);
              }

              *chain += chain->getExampleItem();
            }
            
          }

        } else {
          table->tradeArea->discardAll(*table->discardPile);
        }
      }
      // play top card
      playCard(currentPlayer, chains);
      outputStream << currentPlayer->getName()
                   << " played a card from their hand";

      outputStream << "\nthe top card of your hand is "
                   << (*currentPlayer->hand->top()) << endl;
      outputStream << "These are your Chains: ";
      for (auto chain : *chains) {
        outputStream << *chain;
        outputStream << endl;
      }
      outputStream << endl;
      input = "";
      outputStream << "do you want to play the top card of your hand? y/n\n";
      while (input != "n" && input != "y") {
        inputStream >> input;
      }
      if (input == "y") {
        playCard(currentPlayer, chains);
      }
      outputStream
          << "do you want to show your hand and discard a card?  y/n\n";
      input = "";
      while (input != "n" && input != "y") {
        inputStream >> input;
      }
      Hand *hand = currentPlayer->hand;
      if (input == "y") {
        currentPlayer->hand->print(outputStream);
        outputStream
            << "\nwhich card do you want to pick? Please enter the full name\n";
        input = "";
        bool validCardNotPicked = true;
        while (validCardNotPicked) {
          inputStream >> input;
          long unsigned index;

          if (handContainsCard(*hand, input, index)) {
            table->discardPile->push_back(hand->at(index));
            hand->erase(hand->begin() + index);
            validCardNotPicked = false;
          }
        }
      }
      //adds 3 new cards to trade area
      for (int i = 0; i < 3; i++) {
        table->tradeArea->push_back(table->deck.draw());
      }
      
      
      while (topCardisInTradeArea(*table->discardPile, *table->tradeArea)) {
        Card *tradeCard = table->discardPile->back();
        table->tradeArea->push_back(tradeCard);
        table->discardPile->pop_back();
      }
      
      
      outputStream << "do you want any cards from the trade area to add to "
                      "your chains?\n";
      outputStream << "trade area:\n";
      table->tradeArea->print(outputStream);
      outputStream << endl;
      outputStream << "Chains: ";
      for (auto chain : *chains) {
        chain->print(outputStream);
        outputStream << endl;
      }
      outputStream << endl;
      for (auto card : *table->tradeArea) {
        outputStream << card << endl;
        outputStream << "Do you want to chain this card? y/n";
        input = "";
        inputStream >> input;
        while (input != "y" && input != "n") {
          inputStream >> input;
        }

        if (input == "y") {
          chainCard(card, currentPlayer, chains);
          (void)remove(table->tradeArea->begin(),table->tradeArea->end(),card);
        }
      }
      currentPlayer->hand->push_back(table->deck.draw());
      
    }
  }
}

void loadPreviousGame(string filename) { int i = 0; }
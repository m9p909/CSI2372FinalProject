#include "main.h";

void pauseGame();

void makeNewChain(vector<Chain_Base> &chain, Card* card){
    
}

void runGame(string player1, string player2) {
  Table *table = new Table(player1, player2);
  string winner;
  string input = "";
  Player *currentPlayer;
  while (!table->win(winner)) {
    cout << "Would you like to pause (y/n)? \n";
    while (input != "y" && input != "n") {
      cin >> input;
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
      vector<Chain_Base> *chains = &currentPlayer->chains;
      cout << "\n" << table;
      currentPlayer->hand->operator+=(table->deck->draw());
      if (table->tradeArea->numCards() <= 0) {
        cout << table->tradeArea;
        cout << "\nWould you like to add the cards from the trade area to your "
                "chains(1) or discard them?(2)\n ";
        while (input != "1" && input != "2") {
          cin >> input;
        }
        if (input == "1") {
          for (auto &value : table->tradeArea->cards) {
            for (auto &currChain : currentPlayer->chains) {
              if (value->getName() == currChain.getName()) {
                currChain += table->tradeArea->trade(currChain.getName());
              }
            }
          }
        } else {
          table->tradeArea->discardAll(*table->discardPile);
        }
        // play top card
        Card *currentPlay = currentPlayer->hand->play();
        bool playable = false;
        for (int i = 0; i < currentPlayer->chains.size(); i++) {
          Chain_Base *currChain = &currentPlayer->chains[i];
          if (currChain->getName() == currentPlay->getName()) {
            playable = true;
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
          for (int i = 0; i < currentPlayer->chains.size(); i++) {
            Chain_Base *currChain = &currentPlayer->chains[i];
            // chain length should never be greater than 3
            if (currChain->getLength() > maxChainLength &&
                currChain->getLength() <= 3) {
              maxChainLength = currChain->getLength();
              maxChain = currChain;
            }
          }
          currentPlayer += maxChain->sell();
          // removes the card chain that was sold
          (void)remove(chains->begin(), chains->end(), maxChain);
          // add a new chain with the card

        }
      }
    }
  }
}

void loadPreviousGame(string filename) { int i = 0; }

int main() {
  bool onwards = true;
  string userInput = "";
  string player1Name;
  string player2Name;
  CardFactory *factory = factory->getFactory();
  while (onwards) {
    cout << "Do you want to play a new game (1), or load a saved game(2)? \n";
    cin >> userInput;
    if (userInput == "1") {
      onwards = false;
      cout << "Please input a name for player 1";
      cin >> player1Name;
      cout << "Please input a name for player 2";
      cin >> player2Name;
      runGame(player1Name, player2Name);

    } else if (userInput == "2") {
      cout << "Please enter the file you would like to load";
      cin >> userInput;
      loadPreviousGame(userInput);
      onwards = false;

    } else {
      cout << "Please input only 1 or 2";
    };
  }
}
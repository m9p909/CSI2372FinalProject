#include "main.h"

void pauseGame();


Chain_Base* makeNewChain( Card* card){
  if(card->getName() == "Blue"){
    return new Chain<Blue>;
  } else if(card->getName() == "Black"){
    return new Chain<Black>;
  } else if(card->getName() == "Green"){
    return new Chain<Green>;
  } else if(card -> getName() == "Stink"){
    return new Chain<Stink>;
  } else if(card -> getName() == "Soy"){
    return new Chain<Soy>;
  } else if (card -> getName() == "Red"){
    return new Chain<Red>;
  } else {
    return new Chain<Garden>;
  }
    
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
      vector<Chain_Base *>* chains = currentPlayer->chains; 
      cout << "\n" << table;
      currentPlayer->hand->operator+=(table->deck.draw());
      if (table->tradeArea->numCards() <= 0) {
        cout << table->tradeArea;
        cout << "\nWould you like to add the cards from the trade area to your "
                "chains(1) or discard them?(2)\n ";
        while (input != "1" && input != "2") {
          cin >> input;
        }
        //add to chains or discard cards
        if (input == "1") {
          //add cards from table to chains
          for(int i = 0; i < currentPlayer->getNumChains(); i++){
            Chain_Base * chain = currentPlayer->getChain(i);
            
            if(table -> tradeArea ->legal(chain->getExampleItem())){
              table->tradeArea->trade(chain->getExampleItem()->getName());

              if(chain->getSize() >= 3){
              //sells curr chains if biggest chain is at max size
              currentPlayer += chain->sell();
              //remove the chain
              
              chains->push_back(makeNewChain(chain->getExampleItem()));
              chain = chains->back();
              //erase the chain in question
              chains->erase(chains->begin()+i);
              }

              *chain += chain->getExampleItem();
              
              
           
            }
          }
          
        } else {
          table->tradeArea->discardAll(*table->discardPile);
        }
        // play top card
        Card *currentPlay = currentPlayer->hand->play();
        bool playable = false;
        //is there a chain for top card
        for (int i = 0; i < currentPlayer->getNumChains(); i++) {
          Chain_Base *currChain = currentPlayer->getChain(i);
          if (currChain->getExampleItem()->getName() == currentPlay->getName()) {
            playable = true;
            if(currChain->getSize() >= 3){
              //sells curr chains if biggest chain is at max size
              currentPlayer += currChain->sell();
              //remove the chain
              
              chains->push_back(makeNewChain(currChain->getExampleItem()));
              currChain = chains->back();
              //erase the chain in question
              chains->erase(chains->begin()+i);
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
          for (int i = 0; i < currentPlayer->getNumChains(); i++) {
            Chain_Base *currChain = currentPlayer->getChain(i);
            // chain length should never be greater than 3
            if (currChain->getSize() > maxChainLength &&
                currChain->getSize() <= 3) {
              maxChainLength = currChain->getSize();
              maxChain = currChain;
            }
          }
          currentPlayer += maxChain->sell();
          // removes the card chain that was sold
          (void)remove(chains->begin(), chains->end(), maxChain);
          // add a new chain with the card
          chains->push_back(makeNewChain(currentPlay));

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
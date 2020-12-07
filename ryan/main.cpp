#include "main.h"



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
      runGame(player1Name, player2Name, cout, cin);

    } else if (userInput == "2") {
      cout << "Please enter the file you would like to load";
      cin >> userInput;
      //load previous game function goes here    
      onwards = false;

    } else {
      cout << "Please input only 1 or 2";
    };
  }
}
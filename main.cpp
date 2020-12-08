#include "main.h"

int main()
{
  // Print intro message and familiarize player with controls.
  gameStartMessage();
  copyrightMessage();
  bool onwards = true;
  string userInput = "";
  string player1Name;
  string player2Name;
  CardFactory *factory = factory->getFactory();

  // Loop until the player makes a choice.
  while (onwards)
  {
    logo();
    cout << "Welcome. Would you like to play a new game?";
    bool play_newgame = promptYesOrNo();

    // If the user does not want to play a new game, prompt him to load from file.
    if (play_newgame)
    {
      onwards = false;
      cout << "Please input a name for player 1\t";
      cin >> player1Name;
      cout << "Please input a name for player 2\t";
      cin >> player2Name;
      runGame(player1Name, player2Name, cout, cin);
    }
    else
    {
      cout << "Alright. Would you like to load an old game from file?";
      bool load_fromfile = promptYesOrNo();
      if (load_fromfile)
        throw Unimplemented();
    }

    // If the player reaches this point, the game loops.
  }
}
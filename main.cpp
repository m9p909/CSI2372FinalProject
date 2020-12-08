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
    cout << "Welcome. Would you like to play a new game? (A) Or load an old one from file? (B)";
    bool play_newgame = promptAOrB();

    // If the user does not want to play a new game, prompt him to load from file.
    if (play_newgame)
    {
      onwards = false;
      cout << "Please input a name for Player 1";
      player1Name = promptString();
      cout << "Please input a name for Player 2";
      player2Name = promptString();
      runGame(player1Name, player2Name, cout, cin);
    }
    else
    {
      cout << "Alright. Let's load an old game from file.";
      cout << "Please enter a filename";
      string file_name = promptString();
      cout << "Loading " << file_name << " from disk..." << endl;
      ifstream inFile(file_name);
      stringstream x;
      x << inFile.rdbuf();
      inFile.close();

      string game_file = x.str();

      cout << "Got the following game file:" << endl;
      cout << game_file << endl;
      cout << endl;
      cout << "...end of file" << endl;
    }

    // If the player reaches this point, the game loops.
  }
}
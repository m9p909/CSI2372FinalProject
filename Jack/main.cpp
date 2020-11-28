#include "globalHeader.h";

void setupNewGame(){

}

void loadPreviousGame(string filename){

}

int main(){
    bool onwards = true;
    string userInput = "";
    string player1Name;
    string player2Name;
    
    while(onwards){
        cout << "Do you want to play a new game (1), or load a saved game(2)? \n";
        cin >> userInput;
        if(userInput == "1"){
            onwards = false;
            cout << "Please input a name for player 1";
            cin >> player1Name;
            cout << "Please input a name for player 2";
            cin >> player2Name;

            setupNewGame();

            

        } else if (userInput == "2"){
            cout << "Please enter the file you would like to load";
            cin >> userInput;
            loadPreviousGame(userInput);
            onwards = false;
            

        } else{
            cout << "Please input only 1 or 2";
        };
    }


}
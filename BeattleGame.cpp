/*************************************************************************
 *
 * Project 1: Beattle game
 *
 * File Name:   BeattleGame.cpp
 * Username:  	taylad, Adam Taylor
 * Course:      CPTR 142
 *
 *
 * A little difficult to understand
 *
 * This is the file contains main game creation. It uses all other files and
 * makes them interact to form the rules and the workings of beattle game. It
 * collects the number of players and then creates a storage mechanism so that
 * each player's beattle and number of turns is stored for them. It gives each
 * player a turn before returning to the first player. After someone has won it
 * outputs the winner and the output how many turns it took and what everyone
 * else's beattles looked like.
 *
 *
 */
#include <iostream>
#include <vector>

using namespace std;

#include "Beattle.h"
#include "dice.h"

int main() {
  cout << endl;
  int numPlayers;

  // repeats till valid input is entered
  while (true) {
    // asks for number of players and checks for valid entry
    cout << "How many people will be playing? ";
    cin >> numPlayers;
    // error checking
    if (cin.fail() || numPlayers <= 0) {
      cin.clear();
      cin.ignore(100, '\n');
      cerr << "That is not a valid input, please try again." << endl;
    } else {
      break;
    }
  }

  // stores all player information
  vector<Beattle> Players(numPlayers);

  // setup each player's name
  for (int i = 0; i < Players.size(); i++) {
    Players.at(i).setPlayerName();
  }

  // sets the die seed by asking the user for the seed they want
  Dice gameDie;
  gameDie.getSeed();

  while (true) {
    bool Winner = false;
    // iterate through the elements of Players so each gets a turn
    for (int i = 0; i < Players.size(); i++) {
      // check if any player changes from flase to true in their turn
      Winner = Players.at(i).playTurn(gameDie.getDiceNumber());
      if (Winner) {
        // output winning message whem someone wins
        Players.at(i).winnerText();
        break;
      }
    }
    // completely exits loop if there is a winner
    if (Winner) {
      break;
    }
  }

  cout << endl;

  // print all the stats of each player
  for (int i = 0; i < Players.size(); i++) {
    Players.at(i).Statistics();
  }
}
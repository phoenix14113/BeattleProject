/*************************************************************************
 *
 * Project 1: Beattle game
 *
 * File Name:   Beattle.h
 * Username:  	taylad, Adam Taylor
 * Course:      CPTR 142
 *
 * This very easy to understand
 *
 * This file initializes the class Beattle, initializes needed variables, and
 * holds the declarations for its members. Also contains one liners for testing
 * purposes.
 *
 */
#ifndef BEATTLE_H
#define BEATTLE_H

#include "dice.h"
#include <string>

using namespace std;

class Beattle {
public:
  // zeros out the start of the game
  Beattle();

  // asks each player for a name and error checks
  void setPlayerName();

  /* plays each turn one by one. collects the dice number as input and if that
  part can be added to the body it changes the variable of the corresponding
  number/limb */
  bool playTurn(int);

  // prints who the winner is and how many turns it took
  void winnerText();

  // for printing the game results
  void Statistics();

  // for functionality test
  int getPlayerTurns() { return PlayerTurns; }
  bool getIsThereASix() {return isThereASix;}
  bool getIsThereAFive() {return isThereAFive;}
  int getNumOnes() {return numOnes;}
  int getNumTwos() {return numTwos;}
  int getNumThrees() {return numThrees;}
  int getNumFours() {return numFours;}

private:
  // keeps track of the players name and how many turns they have taken
  string PlayerName;
  int PlayerTurns;

  /* playTurn variables keeping track how many body parts the player's beattle
   has and if more of each part can be added */
  bool isThereASix;
  bool isThereAFive;
  int numOnes;
  int numTwos;
  int numThrees;
  int numFours;

  // checks if the player won
  bool winner;
};

#endif
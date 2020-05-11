/*************************************************************************
 *
 * Project 1: Beattle game
 *
 * File Name:   Beattle.cpp
 * Username:  	taylad, Adam Taylor
 * Course:      CPTR 142
 *
 *
 * Fairly complicated
 *
 * This file holdes the definitions for the member functions of the class
 * Beattle held in Beattle.h. The functions in this file allow for player
 * creation, game creation and game rules, and end of game messages, including
 * statistics about who won with how many moves and how many peices of the
 * beattle the other players have.
 *
 *
 */
#include "Beattle.h"
#include <iostream>
#include <string>
using namespace std;

Beattle::Beattle() {
  // automatically sets board to blank and turns taken to zero
  PlayerTurns = 0;
  isThereAFive = false;
  isThereASix = false;
  numOnes = 0;
  numTwos = 0;
  numThrees = 0;
  numFours = 0;
}
void Beattle::setPlayerName() {
  // collect a player name for each instance and check for correct input
  string name;
  // repeats till valid input is given
  while (true) {
    cout << "What is your name? ";
    cin >> name;
    // if incorrect input is given tell the user and clear the memory
    if (cin.fail()) {
      cin.clear();
      cin.ignore(100, '\n');
      cerr << "That is not a valid input, please try again." << endl;
    } else {
      break;
    }
  }
  PlayerName = name;
}

bool Beattle::playTurn(int dieFace) {
  ++PlayerTurns;

  /*Checks for a body, to see if anything can be added on. Then checks for a
   * head just in case so that eyes and antennae can be added as soon as there
   * is a head. Then checks for other appendages and sees if there are already
   * enough of each part. */

  // checks if you already have a body
  if (isThereASix == false && dieFace == 6) {
    isThereASix = true;
  }
  if (isThereASix == true) {
    // checks if you can place an head
    if (isThereAFive == false && dieFace == 5) {
      isThereAFive = true;
    }
    // check if you can place an eyes
    if (isThereAFive == true && dieFace == 1 && numOnes < 2) {
      ++numOnes;
    }
    // checks if you can place an antennae
    if (isThereAFive == true && dieFace == 2 && numTwos < 2) {
      ++numTwos;
    }
    // checks if you can place an legs
    if (dieFace == 3 && numThrees < 6) {
      ++numThrees;
    }
    // checks if you can place an wings
    if (dieFace == 4 && numFours < 2) {
      ++numFours;
    }
  }
  // check at the end of the turn if all parts of the body are present
  if (isThereAFive == true && isThereAFive == true && numOnes == 2 &&
      numTwos == 2 && numThrees == 6 && numFours == 2) {
    winner = true;
    return true;
  }
  return false;
}

void Beattle::winnerText() {
  // This is the text that will print if someone wins the game
  cout << endl
       << "The winner is " << PlayerName << " with " << PlayerTurns << " rolls."
       << endl;
}

void Beattle::Statistics() {
  // if the person won print out a winning message
  if (winner) {
    cout << PlayerName << ": \tYou won! You collected all the parts in "
         << PlayerTurns << " turns!!" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
  }
  // if the person did not win and the function is called output what their
  // beattle would have looked like and how many turns they took
  else {
    cout << PlayerName << ": \t"
         << "Head: " << isThereASix << ", Body: " << isThereAFive
         << ", Eyes: " << numOnes << ", Antennae: " << numTwos
         << ", Legs: " << numThrees << ", Wings: " << numFours
         << ", Turns: " << PlayerTurns << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
  }
}
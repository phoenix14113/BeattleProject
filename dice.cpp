/*************************************************************************
 *
 * Project 1: Beattle game
 *
 * File Name:   dice.cpp
 * Username:  	taylad, Adam Taylor
 * Course:      CPTR 142
 *
 *
 * Pretty easy to understand
 *
 * This file contains the function definitions for the declarations in the Dice
 * class held in dice.h. It uses random numbers to create a dice and it collects
 * data to create those random numbers.
 *
 *
 *
 */
#include <cstdlib> // for random numbers
#include <iostream>

#include "dice.h"
using namespace std;

int Dice::getDiceNumber() {
  // generates a random number between 1 and 6 bassed on the user collected seed
  srand(diceSeed + rand());
  diceNumber = (rand() % 6) + 1;
  return diceNumber;
}
void Dice::getSeed() {
  int seed;
  // repeats till a valid seed is input
  while (true) {
    cout << "What seed would you like? ";
    cin >> seed;
    // performs error checking to make sure there is valid input
    if (cin.fail()) {
      cin.clear();
      cin.ignore(100, '\n');
      cerr << "That is not a valid input, please try again." << endl;
    } else {
      break;
    }
  }
  diceSeed = seed;
}
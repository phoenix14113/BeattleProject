/*************************************************************************
 *
 * Project 1: Beattle game
 *
 * File Name:   test.cpp
 * Username:  	taylad, Adam Taylor
 * Course:      CPTR 142
 *
 *
 * quite difficult to understand
 *
 * this file is designed to test the limits and correctness of the combination
 * of Beattle.cpp, Beattle.h, dice.cpp, and dice.h. This file runs tests using
 * both assert and if statement checks to see if the desired output and/or
 * procedure is followed correctly. Vectors are used to save dice rolls so they
 * can be checked and for loops simulate the game being played.
 *
 *
 *
 */

#include "Beattle.h"
#include "dice.h"
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  Dice test;
  cout << endl << "begin Dice class tests" << endl << endl;

  // test 1: test dice range
  cout << "test 1" << endl;
  int dice1;
  int dice2;

  srand(1);
  dice1 = test.getDiceNumber();
  dice2 = test.getDiceNumber();

  // test that dice number is between and including 1 and 6
  if (!(dice1 <= 6 && dice1 >= 1)) {
    cout << "Error, " << dice1 << " is not between 1 and 6." << endl;
  }
  if (!(dice2 <= 6 && dice2 >= 1)) {
    cout << "Error, " << dice2 << " is not between 1 and 6." << endl;
  }

  // test 2: test that the dice change for every seed
  cout << "test 2" << endl;
  vector<int> diceChange(20);
  srand(1);
  for (int i = 0; i < 20; i++) {
    // set vector values equal to dice random numbers
    diceChange.at(i) = test.getDiceNumber();
  }
  bool Change = false;
  for (int i = 0; i < 20; i++) {
    // change to true if there is something not equal to the first term
    if (diceChange.at(0) != diceChange.at(i)) {
      Change = true;
    }
  }
  // if the vectors are equal somthing is wrong with seed generation
  if (!Change) {
    cout << "Error, the value of the dice never changes" << endl;
  }

  // begin test 3: test that same seeds have the same output
  cout << "test 3" << endl;

  srand(1);
  vector<int> diceChange2(20);

  for (int i = 0; i < 20; i++) {
    // set vector values equal to dice random numbers
    diceChange2.at(i) = test.getDiceNumber();
  }

  // test that the same seed has the same output
  if (diceChange2 != diceChange) {
    cout << "Error, the vectors should be equal." << endl;
  }

  // begin test 4: test that different seed have different output
  cout << "test 4" << endl;
  srand(1);
  // set a string of random die roles to the vector
  vector<int> diceNumOne(20);
  for (int i = 0; i < 20; i++) {
    diceNumOne.at(i) = test.getDiceNumber();
  }

  srand(2);
  // set a different string of random die roles to the vector
  vector<int> diceNumtwo(20);
  for (int i = 0; i < 20; i++) {
    diceNumtwo.at(i) = test.getDiceNumber();
  }
  // if the two vectors are equal something is wrong
  if (diceNumOne == diceNumtwo) {
    cout << "Error, these should have unique numbers.";
  }
  cout << endl << "end of Dice class tests" << endl;

  cout << "begin Beattle tests." << endl << endl;

  /* begin test 5: test that the dice outputs correctly, turns incrembents and
  / isThereASix is turned to true */
  cout << "test 5" << endl;
  Beattle testMeBeattle;
  Dice testMeRoll;

  // check player turn function
  srand(0);
  cout << "use the input 2" << endl;
  testMeRoll.getSeed();
  int face = testMeRoll.getDiceNumber();
  testMeBeattle.playTurn(face);

  // test boolians and acculmulator
  assert(testMeBeattle.getPlayerTurns() == 1);
  assert(face == 6);
  assert(testMeBeattle.getIsThereASix() == true);

  // test 6: test that the conditions for a winner are really met
  cout << "test 6" << endl;
  Beattle testMeBeattle2;
  Dice testMeRoll2;

  testMeRoll2.getSeed();
  bool Winner = false;
  while (!Winner) {
    Winner = testMeBeattle2.playTurn(testMeRoll2.getDiceNumber());
  }
  // test that the conditions for a winner are really met
  assert(testMeBeattle2.getIsThereASix() == true);
  assert(testMeBeattle2.getIsThereAFive() == true);
  assert(testMeBeattle2.getNumOnes() == 2);
  assert(testMeBeattle2.getNumTwos() == 2);
  assert(testMeBeattle2.getNumThrees() == 6);
  assert(testMeBeattle2.getNumFours() == 2);
  cout << "End of tests" << endl;
}
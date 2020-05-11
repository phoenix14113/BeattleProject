/*************************************************************************
 *
 * Project 1: Beattle game
 *
 * File Name:   dice.h
 * Username:  	taylad, Adam Taylor
 * Course:      CPTR 142
 *
 * Etremely easy to understand
 *
 * This file creates the class Dice and declares the functions and variables
 * that it needs.
 *
 *
 */

#ifndef DICE_H
#define DICE_H

class Dice {
public:
  // sets the seed for the random number generator and resets diceRolls to zero
  void getSeed();

  // generates a random number between 1 and 6 and adds 1 to diceRolls
  int getDiceNumber();

private:
  int diceNumber;
  int diceSeed;
};

#endif
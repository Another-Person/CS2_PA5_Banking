/*	myrandom.h
 *	Header file for myrandom.cpp
 *	Exposes getRandomInteger and that's all. All these lines for one function.
 */

#ifndef MYRANDOM_H
#define MYRANDOM_H

/* getRandomInteger
 * Selects a random integer between a provided min and max.
 * Parameters:
 * int min -- the minimum integer that could be selected
 * int max -- the maximim integer that could be selected
 * Return:
 * Returns an int with the selected random integer.
 */
int getRandomInteger(int min, int max);

#endif
/*
Authors: Vladislav Martin and Michael Wong
Filename: RollEight.cpp
Assignment: C++ Lab #6
Description --> This program is meant to determine the percentage of total rolls of  two "fair" dice that add up to 8.
				In order to simulate enough trials to generate a sufficiently accurate estimation of the theoretical probability that
				the sum of two dice rolls is 8, 100,000,000 trials are run before the final experimental probability is calculated and displayed to the user.
	1. Specifics: In order to ensure a random seed for the srand() function, the time(NULL) function is called;
	2. Inputs: None
	3. Outputs: A count of the number of times two dice rolls summed up to 8 and the percentage of such rolls out of all trials run.
	4. Functions: int main(), int roll_two()
	5. Updated: October 20th, 2014
*/

#include <iostream>
#include <cstdlib> //for srand() and rand()
#include <time.h>

using namespace std;

const int TRIALS = 100000000;
int eights = 0;

//Declares and intializes two values that containing a random value between (0 + 1) and (5 + 1), simply 1 through 6
int roll_two()
{
	int die1 = rand()%6 + 1; //These serve as the results of each roll of the two dice
	int die2 = rand()%6 + 1;
	
	return die1 + die2;
}

int main(void)
{
	srand(time(NULL));
	
	for(int i=0;i<TRIALS;i++)
	{
		if (roll_two() == 8) //Increase the total count of eights rolled when the sum of two rolls adds up to eight
		{
			eights++;
		}
	}
	
	//Display the simulation's results to the user
	cout << "The sum of two dice rolls is found to be eight " << eights << " times after " << TRIALS << " trials are run." << endl;
	cout << (double)eights/TRIALS * 100 << "%" << " of all trails resulted in a sum of 8." << endl;
	
	system("pause");
	return(0);
}

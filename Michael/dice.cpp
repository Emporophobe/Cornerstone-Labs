//Michael Wong and Vlad Martin
//Inputs: None
//Outputs: A percentage and count of successes
//Determines the percentage of times the sum of two dice is 8 through a large number of random trials

#include <iostream>
#include <cstdlib> //for srand() and rand()
#include <time.h>

using namespace std;

const int TRIALS = 100000000;
int eights = 0;

int roll2()
{
	int die1 = rand()%6 + 1;
	int die2 = rand()%6 + 1;
	
	return die1 + die2;
}

int main(void)
{
	srand(time(NULL));
	
	for(int i=0;i<TRIALS;i++)
	{
		if (roll2() == 8)
		{
			eights++;
		}
	}
	
	cout << "There are " << eights << " eights after " << TRIALS << " trials. (" << (double)eights/TRIALS * 100 << "%)"<< endl;
	
	system("pause");
	return(0);
}

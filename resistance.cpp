/*
Michael Wong, Vladislav Martin

resistance.cpp

The user is asked to input the number of resistors in parallel, and then the resistance of each resistor. 
The program outputs the equivalent resistance of the resistors, calculated using the formula provided

               1. Specifics: all values are given in ohms
               2. Input: the number of resistors and their resistances
               3. Output: equivalent resistance in ohms
               4. Functions: main()
               5. Updated: 10/8/14
*/

#include <iostream>

using namespace std;

int main(void)
{
	double resistors=0, resistance=0, newResistor=0;
	
	//get the number of resistors so you know how many times to ask for a resistance
	cout << "How many resistors are there? ";
	cin >> resistors;
	//get the value of each resistor
	
	//the first value should be input seperately or else the equivalent resistance formula has no starting value to work with	
	cout << "Value of resistor 1 : ";
	cin >> resistance;
	
	//get the rest of the resistances, and calculate the new resistance immediately
	for (int i=1; i<resistors; i++)
	
	{
		cout << "Value of resistor " << i+1 << " : ";
		cin >> newResistor;
		resistance = (resistance * newResistor) / (resistance + newResistor);	
	}
	
	//output the total equivalent resistance
	cout << "The equivalent resistance of the " << resistors << " resistors is " << resistance << " ohms.\n";
	
	//clean up
	system("pause");
	return 0;
}

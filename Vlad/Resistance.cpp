/*
Authors: Michael Wong, Vladislav Martin
 
Filename: Resistance.cpp
 
Description: The user is asked to input the number of resistors in parallel, and then the resistance of each resistor.
The program outputs the equivalent resistance of the resistors, calculated using the formula provided
               1. Specifics: all values are given in ohms
               2. Input: the number of resistors and their resistances
               3. Output: equivalent resistance in ohms
               4. Functions: main()
               5. Updated: 10/8/14
*/
 
#include <iostream>
#include <iomanip>
 
using namespace std;
 
int main(void)
{
	int number_of_resistors = 0;
	double resistance = 0, next_resistor = 0;
	
	//Get the number of resistors so you know how many times to ask for a resistance
	cout << "How many resistors are there? ";
	cin >> number_of_resistors;
	
	//The first value should be input seperately or else the equivalent resistance formula has no starting value to work with      
	cout << "The resistance of resistor #1, in ohms, is: ";
	cin >> resistance;
	
	//Get the rest of the resistances, and calculate the new resistance immediately
	for (int i = 1; i < number_of_resistors; i++)
	{
		cout << "The resistance of resistor #" << i+1 << ", in ohms, is: ";
		cin >> next_resistor;
		resistance = (resistance * next_resistor) / (resistance + next_resistor);  
	}
	
	//Output the total equivalent resistance
	cout << fixed << setprecision(3) << "The equivalent resistance of the " << number_of_resistors << " resistors is " << resistance << " ohms.\n";
	
	//Clean up
	system("pause");
	return 0;
}

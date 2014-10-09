//Michael Wong

#include <iostream>
#include <cmath> //for exponents

using namespace std;

int main(void)
{
	double interestRate = 0.10, dollarsMade, startDollars;
	double numberYears = 0;
	
	//get the principle amount
	cout << "Enter your starting money (no commas): ";
	cin >> startDollars;
	
	//check how much money would be made each year until the total amount is at least one million
	while (dollarsMade < 1000000)
	{
		dollarsMade = startDollars * pow(1+interestRate, numberYears);
		numberYears += 1;
	}
	
	//output the results
	cout << "It will take you " << numberYears-1 << " years to make one million dollars \n";
	cout << "for a starting amout of $" << startDollars << " and an interest rate of " << interestRate << ". \n";
	
	//exit
	system("pause");
	return 0;
}

#include <iostream>
#include <cmath>

using namespace std;

int main (void)
{
	double interest_rate = 0.10, dollars_made, start_dollars;
	double number_years = 1;
	
	cout << "Enter your starting amount of money, no commas and I will tell you how many years to make a million: ";
	cin >> start_dollars;
	
	while (dollars_made < 1000000)
	{
		dollars_made = start_dollars*pow((1+interest_rate), number_years);
		number_years++;
	}
	
	cout << "\nIt will take you " << number_years << " years to earn a million dollars.\n";
	cout << "For an interest rate of " << interest_rate << " and starting amount of " << start_dollars << " dollars.\n\n";
	
	system("pause");
	
	return 0;
}

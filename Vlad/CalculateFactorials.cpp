/*
Authors: Vladislav Martin and Michael Wong
Filename: CalculateFactorials.cpp
Assignment: C++ Lab #6
Description --> This program is meant to find the factorial of a user inputted number, n.
				Next, permutations and combinations are calculated after the user provides a second number, k, less than n.
				These values are displayed to the user once calculations are completed, at the end of the program.
	1. Specifics: The recursive_factorial() function is not implemented in this program but is included to show that we know how to implement recursion in a function;
				  The total in factorial() is initialized to the value of 1 so that if the users input is 0 or 1, the output of the function is 1;
				  All values are declared as unsigned longs to avoid casting errors when calculating the factorial (the largest calculated value in this program) 
	2. Inputs: Positive integers n and k, where n is less than 13 and k is less than n
	3. Outputs: n!, nPk, and nCk
	4. Functions: int main(), unsigned long recursive_factorial(unsigned long n), unsigned long factorial(unsigned long n), 
				  unsigned long permutation(unsigned long n, unsigned long k), unsigned long combination(unsigned long n, unsigned long k)
	5. Updated: October 20th, 2014
*/

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

///Calculates the factorial of the input parameter by recursively calling the function within itself
unsigned long recursive_factorial(unsigned long n)
{
	if (n == 1 || n == 0) //break here, also 0! = 1
	{
		return 1;
	}
	else
	{
		return n * recursive_factorial(n-1);
	}
}

//Calculates the factorial of the input parameter by using a for loop
unsigned long factorial(unsigned long n)
{
	unsigned long total = 1;
	
	for (unsigned long i = n; i > 0; i--)
	{
		total *= i;
	}
	return total;
}


//Calculates a permutation of k size out of a total size of n
unsigned long permutation(unsigned long n, unsigned long k)
{
	unsigned long final_value = 1;
	
	for (unsigned long i = n; i > (n-k); i--) //n!/(n-k)! = n*(n-1)*... until k+1
	{
		final_value *= i;
	}
	return final_value;
}

//Calculates a combination of k size out of a total size of n, making use of the previously declared permutation() and factorial() functions
unsigned long combination(unsigned long n, unsigned long k)
{
	return (permutation(n, k))/(factorial(k));
}

int main(void)
{
	unsigned long n, k;
	
	cout << "Input n (less than 13): ";
	cin >> n;
	
	cout << "Input k (less than " << n << "): "; 
	cin >> k;
	
	//Display the calculated values to the user
	cout << n << "! = " << factorial(n) << endl;
	cout << n << "P" << k << " = " << permutation(n, k) << endl;
	cout << n << "C" << k << " = " <<combination(n, k) << endl;
	
	system("pause");
	return 0;
}

//Michael Wong and Vlad Martin
//Inputs: Positive integers n and k
//Outputs: n!, nPk, nCk
//Finds the factorial of one number, and the permutaions and combinations for a pair of numbers

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

///Calculates the factorial of the input parameter
unsigned long recursive_factorial(unsigned long n)
{
	if (n == 1 || n == 0) //break here, also 0! = 1
	{
		return 1;
	}
	else
	{
		return n * recursive_factorial(n-1); //recursion is "fun"
	}
}

unsigned long boring_factorial(unsigned long n)
{
	unsigned long total = 1;
	
	for (unsigned long i = n; i > 0; i-- )
	{
		total *= i;
	}
	return total;
}


//Calculates a permutation of k size out of a total size of n
unsigned long permutation(unsigned long n, unsigned long k)
{
	//return (factorial(n))/(factorial(n-k));
	unsigned long final_value = 1;
	
	for (unsigned long i = n; i > (n-k); i--) //n!/(n-k)! = n*(n-1)*... until k+1
	{
		final_value *= i;
	}
	return final_value;
}

//Calculates a combination of k size out of a total size of n
unsigned long combination(unsigned long n, unsigned long k)
{
	return (permutation(n, k))/(recursive_factorial(k));
}

int main(void)
{
	unsigned long n, k;
	
	cout << "Input n (less than 13): ";
	cin >> n;
	
	cout << "Input k (less than " << n << "): "; 
	cin >> k;
	
	cout << n << "! = " << boring_factorial(n) << endl;
	
	cout << n << "P" << k << " = " << permutation(n, k) << endl;
	
	cout << n << "C" << k << " = " <<combination(n, k) << endl;
	
	system("pause");
	return 0;
}
/*
a. 6C2 = 15
b. 5P4 = 120
c. 5P3 = 60
d. 52P4 = 270725
e. 12! = 479001600
*/

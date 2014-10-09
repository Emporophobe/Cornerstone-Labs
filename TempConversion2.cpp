#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
	//Declare variables
	double fahren, celsius, kelvin, rankine;
	
	//Take user input for a Fahrenheit temperature
	cout << "Input the temperature in Fahrenheit: ";  //prompt the user
	cin >> fahren;
	
	//Convert the input into Celsius, Kelvin, and Rankine
	celsius = (5.0/9.0) * (fahren - 32.0);
	kelvin = celsius + 273.15;
	rankine = (9.0/5.0) * kelvin;
	
	//print temperatures to the console
	cout << "The temperature in Celsius is: " << celsius << " degrees C. \n\n";
	cout << "The temperature in Kelvin is: " << kelvin << " K. \n\n";
	cout << "The temperature in Rankine is: " << rankine << " rankine. \n\n";
	
	return 0; //exit the program
}

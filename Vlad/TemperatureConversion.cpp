#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>

using namespace std;

int main ()
{
	//TODO: Add headers to outfile, format files so that all inputted values take up exactly a width of "padding" characters (so that everything is neat)
	
	
	//Declare variables
	int fahren[], celsius[], kelvin[], rankine[];
	int padding, length;
	
	ifstream infile(".\\Input\\fahrenheit.txt"); //Find the input file containing the fahrenheit values located in the "Input" folder relative to the directory containing this program
	ofstream outfile(".\\Output\\converted_values.txt"); //Create the output file containing the converted temperature values located in the "Output" folder
	
	//Take user input for a Fahrenheit temperature
	cout << "Input the temperature in Fahrenheit: ";
	cin >> fahren;
	
	//Convert the input into Celsius, Kelvin, and Rankine
	celsius = (5.0/9.0) * (fahren - 32.0);
	kelvin = celsius + 273.15;
	rankine = (9.0/5.0) * kelvin;
	
	//Print the temperatures in all of the converted units to the console
	cout << "The temperature in Celsius is: " << setprecision(3) << fixed << celsius << " degrees C. \n\n";
	cout << "The temperature in Kelvin is: " << kelvin << " K. \n\n";
	cout << "The temperature in Rankine is: " << rankine << " rankine. \n\n";
	
	outfile << setw(padding) << celsius << " degrees C. \n\n";
	outfile << setw(padding) << kelvin << " K. \n\n";
	outfile << setw(padding) << rankine << " rankine. \n\n";
	
	//Exit the program
	return 0;
}


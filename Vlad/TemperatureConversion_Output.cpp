/*
Authors: Vladislav Martin and Michael Wong
Filename: TemperatureConversion_Output.cpp
Assignment: C++ Lab #4
Description --> This program is meant to take a list of fahrenheit temperatures provided in a text file.
				From these temperatures, the equivalent temperatures are calculated in Celsius, Kelvin, and Rankine.
				These calculated temperatures and the original fahrenheit temperatures are then output
				in another text file for the user to view in formatted columns, titled appropriately.
	1. Specifics: All files contained in the input file are fahrenheit temperatures;
				  Each column in the temperatures[][] array refers to a different units of temperature (i.e., Fahrenheit, Celsius, Kelvin, and Rankine)
	2. Inputs: infile (fahrenheit.txt)
	3. Outputs: outfile (converted_temperatures.txt)
	4. Functions: int main()
	5. Updated: October 4th, 2014
*/

#include <iostream>
#include <fstream>
#include <iomanip>
 
using namespace std;
 
int main ()
{
	//Declare variables pertaining to the input & output files containing the temperature data
	ifstream infile_findLength(".\\Input\\fahrenheit.txt");
	ifstream infile(".\\Input\\fahrenheit.txt");
	ofstream outfile(".\\Output\\converted_temperatures.txt");
	
	        int number_of_rows = 0;
	        int file_content = 0;
	       
	        while(infile_findLength >> file_content)
	        {
	                number_of_rows++;
	        }
	       
	//Declare variables pertaining to the 2D array containing all the temperature values
	const int ARRAY_HEIGHT = number_of_rows;
	const int ARRAY_WIDTH = 4;
	double temperatures[ARRAY_HEIGHT][ARRAY_WIDTH];
	double fahrenheit = 0;
	int counter = 0;
	
	/*Fill in the fahrenheit values into the temperatures array. If file does not exist or don't have read permissions, the user is informed that the file
	stream could not be opened.*/
	if(infile.is_open())
	{
	        cout << "File opened successfully! Reading data from the file... " << endl << endl;
	        while(infile >> fahrenheit)
	        {
	                temperatures[counter][0] = fahrenheit;
	                counter++;
	        }
	}
	//Provide an error message in case the input file could not be found and opened
	else
	{
	        cout << "File could not be opened." << endl;
	        return 0;
	}
	
	/*Calculate the celsius, kelvin, and rankine values and place them in the 2nd, 3rd, and 4th columns,
	respectively, of the temperature array.*/
	for (int i = 0; i < ARRAY_HEIGHT; i++)
	{
	        temperatures[i][1] = (5.0/9.0) * (temperatures[i][0] - 32.0); //Calculate the celsius equivalent of the fahrenheit value
	        temperatures[i][2] = (temperatures[i][1] + 273.15); //Calculate the kelvin equivalent of the celsius value
	        temperatures[i][3] = (9.0/5.0) * temperatures[i][2]; //Calculate the rankine equivalent of the kelvin value
	}
	
	/*setw() must be repeated for each output string because the value is not 'sticky'.
	In other words, the value is not set and applied when the function is used until a new value is set*/
	outfile << left <<  setw(15) << "Fahrenheit" << setw(12) << "Celsius" << setw(11) << "Kelvin" << setw(12) << "Rankine" << endl;
	cout << left << setw(15) << "Fahrenheit" << setw(12) << "Celsius" << setw(11) << "Kelvin" << setw(12) << "Rankine" << endl;
	for (int i = 0; i < ARRAY_HEIGHT; i++)
	{
	        outfile << fixed << setprecision(3);
	        outfile << setw(15) << temperatures[i][0] << setw(12) << temperatures[i][1] << setw(11) << temperatures[i][2] << setw(12) << temperatures[i][3] << endl;
	        cout << left << setw(15) << temperatures[i][0] << setw(12) << temperatures[i][1] << setw(11) << temperatures[i][2] << setw(12) << temperatures[i][3] << endl;
	}
	
	infile.close();
	outfile.close();
	
	system("pause");
	return 0;
}

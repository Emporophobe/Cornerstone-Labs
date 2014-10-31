#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

double arrayAvg(double array[], int size) // I don't understand the purpose of this function, but as it is this "works"... it's never called but whatever
{	
	double filled_array[size];
	double total = 0.0;
	
	for (int i = 0; i < size; ++i)
	{
		total += array[i];
		filled_array[i] = array[i];
	}
	cout << "Calculated a total of: " << total << endl << endl;
	
	//int size = sizeof array / sizeof *array; <-- This one is technically what a better programmer would write
	//int size = sizeof array / sizeof array[0];
	int total_byte_size = sizeof(filled_array) / sizeof(*filled_array);
	
	return total / total_byte_size;
}

void printArray(double array[], int size) //This will print arrays are tell you how many bytes are contained in things. Returns increments of 8 instead of 4 for some reason...
{
	double filled_array[size];
	
	for (int i = 0; i < size; ++i)
	{
		cout << array[i] << " ";
		filled_array[i] = array[i];
	}
	cout << endl << endl;
	cout << "The number of bytes in the entire array (all indices): " << sizeof(filled_array) << endl;
	cout << "The number of bytes in the first index of the array: " << sizeof(*filled_array) << endl;
	cout << "\n";
}

int main(void)
{
	int counter = 0;
	int countercounter = 0;
	double maxSteepness = 1/7;
	
	double year, month, day, hour, minute, height, length;
	
	ifstream readings("data.txt");
	ifstream readings_findLength("data.txt");
	ofstream warning("Warning.txt");
	
	string heading, line;
	getline(readings, line);
	getline(readings_findLength, line);
	heading = line;
	
	int total_size = 0;
	double file_content = 0.0;
	
	while(getline(readings_findLength, line))
	{
		total_size++;
		if (total_size > 100)
		{
			cout << "There are too many values contained in this input file. Please limit the number of rows in this file to 100." << endl;
			return 1;
		}
	}
	
	const int SIZE = total_size;
	double steepness[SIZE], warnings[SIZE], years[SIZE], months[SIZE], days[SIZE], hours[SIZE], minutes[SIZE], heights[SIZE], lengths[SIZE];
	
	if(readings.is_open())
	{
		cout << "File opened successfully! Reading data from the file... " << endl << endl;
		
		while(readings >> year >> month >> day >> hour >> minute >> height >> length)
		{
			steepness[counter] = height / length;
			
			years[counter] = year;
			months[counter] = month;
			days[counter] = day;
			hours[counter] = hour;
			minutes[counter] = minute;
			heights[counter] = height;
			lengths[counter] = length;
			
			if (steepness[counter] > maxSteepness)
			{
				warnings[countercounter] = counter;
				countercounter++;
			}
			
			counter++;
		}
	}
	else
	{
		cout << "Everything is horrible. Try a different file. \n";
		return 1;
	}
	cout << "The result of the printArray function: ";
	
	printArray(years, SIZE);
	
}

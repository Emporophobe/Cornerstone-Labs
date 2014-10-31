#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

double arrayAvg(double array[], int size) // I don't understand the purpose of this function, but as it is this "works"... it's never called but whatever
{	
	double total;
	for(int i=0; i<size; i++)
	{
		total+=array[i];
	}
	
	return total/size;
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
	//cout << "The number of bytes in the entire array (all indices): " << sizeof(filled_array) << endl;
	//cout << "The number of bytes in the first index of the array: " << sizeof(*filled_array) << endl;
	//cout << "\n";
}

int main(void)
{
	int counter = 0;
	int countercounter = 0;
	double maxSteepness = 1.0 / 7;
	
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
				
				//cout << counter << ". " << steepness[counter] << " > " << maxSteepness << endl;
			}
			
			counter++;
		}
	}
	else
	{
		cout << "Everything is horrible. Try a different file. \n";
		return 1;
	}
	
	cout << "The following " << countercounter << " readings indicate dangerously steep waves: \n\n";
	warning << "The following " << countercounter << " readings indicate dangerously steep waves: \n\n";
		
	
	for(int i=0; i<countercounter; i++)
	{
		int n = warnings[i];
		
		warning << years[n] << " "<< months[n] << " " << days[n] << " " << hours[n] << " " << minutes[n] << " " << heights[n] << " " << lengths[n] << endl;
		cout << years[n] << " "<< months[n] << " " << days[n] << " " << hours[n] << " " << minutes[n] << " " << heights[n] << " " << lengths[n] << endl;
	}
	
	cout << "The average wave height is " << arrayAvg(heights, SIZE) << endl;
	cout << "The average wave length is " << arrayAvg(lengths, SIZE) << endl;
	cout << "The average steepness of the waves is " << arrayAvg(steepness, SIZE) << endl;	
}

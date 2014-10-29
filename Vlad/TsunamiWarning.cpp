#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

string header, reading;
int counter = 0;
int countercounter = 0;
double maxSteepness = 1/7;

ifstream readings("data.txt");
ifstream readings_size("data.txt");
ofstream warning("Warning.txt");

double year, month, day, hour, minute, height, length;

double arrayAvg(double array[])
{
	double total = 0.0;
	
	int size = sizeof array / sizeof *array;
	for (int i = 0; i < size; i++)
	{
		total += array[i];
	}
	return total / size;
}

int main(void)
{
	string heading, line;
	getline(readings, line);
	heading = line;
	
	int number_of_rows = 0;
	int file_content = 0;
	
	while(readings_size >> file_content)
	{
	        number_of_rows++;
	        if (number_of_rows > 100)
			{
				cout << "HEY! THIS INPUT FILE HAS TOO MUCH IN IT!!" << endl;
				return 1;
			}
	}
	
	const int SIZE = number_of_rows;
	
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
}

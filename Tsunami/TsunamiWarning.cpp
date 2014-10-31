/*
Authors: Michael Wong, Vladislav Martin
Filename: TsunamiWarning.cpp
Description: Data, organized into columns, is gathered from an input file, analyzed, and stored into separate arrays for each column. The steepness of the waves is calculated from the wave height and length and if the steepness is greater than 1/7 then the data associated to the wave is stored in a separate array, warnings[]. The warnings array is the output of this program to warn when there are signs of a tsunami, whenever waves of too great of a steepness are detected.
               1. Specifics: manipulated values are all doubles
               2. Input: data.txt
               3. Output: Warning.txt containing data associated with waves where the steepness is greater than 1/7
               4. Functions: int main(), double arrayAvg(double array[], int size), printArray (double array[], int size)
               5. Updated: 10/31/2014
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
 
using namespace std;

double arrayAvg(double array[], int size) //Returns the average of all of the values contained in the inputted 1-D array
{      
       double total;
       for(int i=0; i<size; i++)
       {
              total+=array[i];
       }
       
       return total/size;
}
 
void printArray(double array[], int size) //Prints the values of the inputted 1-D array
{
       double filled_array[size];
       
       for (int i = 0; i < size; ++i)
       {
              cout << array[i] << " ";
              filled_array[i] = array[i];
       }
       cout << endl << endl;
}
 
int main(void)
{
       int counter = 0;
       int warning_counter = 0;
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
                           warnings[warning_counter] = counter;
                           warning_counter++;
                     }
                     counter++;
              }
       }
       else
       {
              cout << "Everything is horrible. Try a different file. \n";
              return 1;
       }
       
       cout << "The following " << warning_counter << " readings indicate dangerously steep waves: \n\n";
       warning << "The following " << warning_counter << " readings indicate dangerously steep waves: \n\n";
              
	   warning << "YEAR" << setw(8) << "MONTH" << setw(8) << "DAY" << setw(8) << "HOUR" << setw(8) << "MINUTE" << setw(8) << "HEIGHT" << setw(8) << "LENGTH" << endl << endl;
	   cout << "YEAR" << setw(8) << "MONTH" << setw(8) << "DAY" << setw(8) << "HOUR" << setw(8) << "MINUTE" << setw(8) << "HEIGHT" << setw(8) << "LENGTH" << endl << endl;
       
       for(int i=0; i<warning_counter; i++)
       {
              int n = warnings[i];
              
//Print out the data pertaining to the waves that are too steep in the Warning.txt output file

              warning << years[n] << setw(8) << months[n] << setw(8) << days[n] << setw(8) << hours[n] << setw(8) << minutes[n] << setw(8) << heights[n] << setw(8) << lengths[n] << endl;
              cout << years[n] << setw(8) << months[n] << setw(8) << days[n] << setw(8) << hours[n] << setw(8) << minutes[n] << setw(8) << heights[n] << setw(8) << lengths[n] << endl;
       }
       
    //Print out the contents of the Warnings.txt output file to the console
       cout << "\nThe average wave height is " << arrayAvg(heights, SIZE) << endl;
       cout << "The average wave length is " << arrayAvg(lengths, SIZE) << endl;
       cout << "The average steepness of the waves is " << arrayAvg(steepness, SIZE) << endl;  
       
       system("pause");
       return 0;
}

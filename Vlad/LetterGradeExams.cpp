/*
Author: Vladislav Martin and Michael Wong
Filename: LetterGradeExams.cpp
Assignment: C++ Lab #3
Description -->
	1. Specifics: 
	2. Inputs: score, choice, scale, and weight
	3. Outputs: letter[array_size]
	4. Functions: string findLetterGrade 
	5. Updated: October 4th, 2014

This program is meant to give the user an option to scale their exam grade by either proportion or addition.
By the end of the program, the user is provided with the corresponding letter grade for their numeric exam grade.
*/

#include <iostream>
#include <cstring>

using namespace std;

const int array_size = 12;
string letter [array_size] = {"A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "D-", "F"};
int percent [array_size] = {93, 90, 87, 83, 80, 77, 73, 70, 67, 63, 60, 0};

double score = 0;
string choice = "";
string scale = "";

//Determines the letter grade corresponding to the numerical grade inputted by the user
string findLetterGrade (double score, int array_size)
{
    string letter_grade = "";
	
	for (int n = 0; n < array_size; ++n)
	{
		if (score >= percent[n])
		{
			letter_grade = letter[n];
		    break; //Once the score is found to be greater than the specified percent value, we have arrived at the correct letter grade and this loop's purpose is fulfilled
		}
	}
	return letter_grade;
} 

int main (void)
{
	//Prompt the user for their exam grade
    cout << "What is the numeric value of the exam grade? ";
	cin >> score;
	
	//Ask the user if they wish to apply a scale to their exam grade
	cout << "\nWould you like this exam to be scaled? (yes, y, no, n): ";
	cin >> choice;
	
	//Convert user input for the value of choice into lowercase characters
	for(unsigned int n = 0; n < choice.length(); ++n) 
	{
		choice[n] = tolower(choice[n]);
    }
	
	//Ask the user which of the available scales they wish to apply to their exam grade
	if (choice == "yes" || choice == "y")
	{
		cout << "\nBy what method is this exam scaled? (add, proportion): ";
		cin >> scale;	
	}
	
	//Convert user input for the value of scale into lowercase characters
	for(unsigned int n = 0; n < scale.length(); ++n) 
	{
		scale[n] = tolower(scale[n]);
    }

	double weight = 0;
	
	if (scale == "add")
	{
		cout << "\nHow many points are added to the numeric grade? (integer): ";
		cin >> weight;
		
		score += weight;
		
		cout << "\nThe corresponding letter grade to this scaled numeric grade of " << score << " is: " << findLetterGrade(score, array_size) << endl;
	}
	else if (scale == "proportion")
	{
		cout << "\nBy what percentage is the numeric grade increased? (double): ";
		cin >> weight;
		
		score *= ((100+weight)*0.01);
		
		cout << "\nThe corresponding letter grade to this scaled numeric grade " << score << " is: " << findLetterGrade(score, array_size) << endl;
	}
	//If the user did not wish for the exam to be scaled, their final calculated grade will still be displayed
	else
	{
		cout << "\nThis exam is not scaled. The final calculated grade is " << score << " ("  << findLetterGrade(score, array_size) << ")" << ". \n\n";
	}
	
	system("pause");
	
	return 0;
}
